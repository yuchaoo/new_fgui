#include "GComponent.h"
#include "UIPackage.h"
#include "PackageManager.h"
#include "HitTest.h"
#include "Controller.h"
#include "Relations.h"
#include "GContainer.h"
#include "base/CCStencilStateManager.h"
#include "FguiUtils.h"
#include "TweenManager.h"
#include "GTweener.h"
#include "GTransition.h"
#include "GSprite.h"
#include "GLoader.h"
#include "PkgItem.h"
#include "Package.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
#define CC_CLIPPING_NODE_OPENGLES 0
#else
#define CC_CLIPPING_NODE_OPENGLES 1
#endif

using namespace cocos2d;

#if CC_CLIPPING_NODE_OPENGLES
static void setProgram(Node* n, GLProgram* p)
{
	n->setGLProgram(p);

	auto& children = n->getChildren();
	for (const auto& child : children) {
		setProgram(child, p);
	}
}
#endif

namespace fgui {
	GComponent::GComponent()
	:m_applyingController(NULL)
	, m_constructing(false)
	, _overflowType(OverflowType::VISIBLE)
	, _stencil(NULL)
	, _alphaThreshold(0)
	, _isInverted(false)
	, _scissorOldState(false)
	, _stencilOldProgram(NULL)
	, _groupCommand(NULL)
	, _beforeVisitCmd(NULL)
	, _afterDrawStencilCmd(NULL)
	, _afterVisitCmd(NULL)
	, _stencilStateManager(NULL)
	, _beforeVisitCmdScissor(NULL)
	, _afterVisitCmdScissor(NULL)
	, _bouncebackEffect(true)
	, _hitTest(NULL)
	{
		
	}

	GComponent::~GComponent() {
		if (_stencil) {
			setStencil(NULL);
		}
		if (_groupCommand) {
			delete _groupCommand;
		}
		if (_beforeVisitCmd) {
			delete _beforeVisitCmd;
		}
		if (_afterDrawStencilCmd) {
			delete _afterDrawStencilCmd;
		}
		if (_afterVisitCmd) {
			delete _afterVisitCmd;
		}
		if (_stencilStateManager) {
			delete _stencilStateManager;
		}
		if (_beforeVisitCmdScissor) {
			delete _beforeVisitCmdScissor;
		}
		if (_afterVisitCmdScissor) {
			delete _afterVisitCmdScissor;
		}
		if (_hitTest) {
			delete _hitTest;
		}
		for (size_t i = 0; i < _transitions.size(); ++i) {
			delete _transitions[i];
		}
	}

	bool GComponent::init() {
		Node::init();
		
		return true;
	}

	void GComponent::onEnter() {
		Node::onEnter();
		GObject::onEnter();
		if (_stencil) {
			_stencil->onEnter();
		}
		updateClippingRect();
		for (size_t i = 0; i < _transitions.size(); ++i) {
			_transitions[i]->onOwnerAddedToStage();
		}
		_initEdgeRect = getEdgeRectangle();
	}

	void GComponent::onEixt() {
		Node::onExit();
		GObject::onExit();
		if (_stencil) {
			_stencil->onExit();
		}
		for (size_t i = 0; i < _transitions.size(); ++i) {
			_transitions[i]->onOwnerRemovedFromStage();
		}
	}

	void GComponent::onEnterTransitionDidFinish() {
		cocos2d::Node::onEnterTransitionDidFinish();
		if (_stencil) {
			_stencil->onEnterTransitionDidFinish();
		}
	}

	void GComponent::onExitTransitionDidStart() {
		cocos2d::Node::onExitTransitionDidStart();
		if (_stencil) {
			_stencil->onExitTransitionDidStart();
		}
	}

	GController* GComponent::getController(const std::string& name) {
		for (auto iter = m_controllers.begin(); iter != m_controllers.end(); ++iter) {
			if ((*iter)->getName() == name) {
				return *iter;
			}
		}
		return NULL;
	}

	GController* GComponent::getControllerAt(int index) {
		if (index < m_controllers.size()) {
			return m_controllers[index];
		}
		return NULL;
	}

	void GComponent::setGrayed(bool value) {
		GObject::setGrayed(value);
		auto& children = m_nodeSelf->getChildren();
		for (auto iter = children.begin(); iter != children.end(); ++iter) {
			GObject* obj = dynamic_cast<GObject*>(*iter);
			if (obj) {
				obj->setGrayed(value);
			}
		}
	}

	void GComponent::setBlendMode(BlendMode blendMode) {
		for (ssize_t i = 0; i < _children.size(); ++i) {
			GObject* obj = dynamic_cast<GObject*>(_children.at(i));
			if (obj) {
				obj->setBlendMode(blendMode);
			}
		}
	}

	void GComponent::setupScroll(ByteBuffer* buffer) {
		_scrollType = (ScrollType)buffer->ReadByte();
		ScrollBarDisplayType scrollBarDisplay = (ScrollBarDisplayType)buffer->ReadByte();
		int flags = buffer->ReadInt();
		if (buffer->ReadBool()){
			int top = buffer->ReadInt();
			int bottom = buffer->ReadInt();
			int left = buffer->ReadInt();
			int right = buffer->ReadInt();
		}
		const std::string& vtScrollBarRes = buffer->ReadS();
		const std::string& hzScrollBarRes = buffer->ReadS();
		const std::string& headerRes = buffer->ReadS();
		const std::string& footerRes = buffer->ReadS();

		_isPageMode = (flags & 8) != 0;
		if ((flags & 64) != 0)
			_bouncebackEffect = true;
		else if ((flags & 128) != 0)
			_bouncebackEffect = false;
		_isInertiaEnabled = (flags & 256) == 0;
		bool isClipEnabled = (flags & 512) == 0;
	}

	void GComponent::setupOverflow(OverflowType overflow) {
		if (_overflowType != overflow) {
			_overflowType = overflow;
			if (_overflowType == OverflowType::SCROLL) {
				this->setTouchable(true);
			}
			else {
				this->setTouchable(false);
			}
			updateClippingRect();
		}
	}

	void GComponent::setContentSize(const cocos2d::Size& size) {
		if (_contentSize.equals(size)) {
			return;
		}
		cocos2d::Size oldSize = _contentSize;
		cocos2d::Size newSize = size;
		if (_minSize.width > 0 && _minSize.height > 0) {
			if (size.width < _minSize.width) {
				newSize.width = _minSize.width;
			}
			if (size.height < _minSize.height) {
				newSize.height = _minSize.height;
			}
		}
		if (_maxSize.width > 0 && _maxSize.height > 0) {
			if (size.width > _maxSize.width) {
				newSize.width = _maxSize.width;
			}
			if (size.height > _maxSize.height) {
				newSize.height = _maxSize.height;
			}
		}
		cocos2d::Node::setContentSize(newSize);
		updateClippingRect();
		onContentSizeChanged(this, oldSize, newSize);
	}

	void GComponent::setPosition(const cocos2d::Vec2& pos) {
		if (_position.equals(pos)) {
			return;
		}
		cocos2d::Vec2 oldPos = _position;
		cocos2d::Node::setPosition(pos);
		updateClippingRect();
		onPositionChanged(this, oldPos, pos);
	}

	void GComponent::setPosition(float x, float y) {
		cocos2d::Vec2 pos(x, y);
		if (_position.equals(pos)) {
			return;
		}
		cocos2d::Vec2 oldPos = _position;
		Node::setPosition(x,y);
		updateClippingRect();
		onPositionChanged(this, oldPos, pos);
	}

	void GComponent::onTransionPositionChanged(cocos2d::Node* node,float dx,float dy) {
		for (size_t i = 0; i < _transitions.size(); ++i) {
			_transitions[i]->updateFromRelations(node, dx, dy);
		}
	}

	cocos2d::Node* GComponent::getChildById(const std::string& id) {
		for (ssize_t i = 0; i < _children.size(); ++i) {
			cocos2d::Node* node = _children.at(i);
			GObject* obj = dynamic_cast<GObject*>(node);
			if (obj->getId() == id) {
				return node;
			}
		}
		return NULL;
	}

	cocos2d::Rect GComponent::getEdgeRectangle(){
		const cocos2d::Size& size = getContentSize();
		if (_children.size() <= 0) {
			return cocos2d::Rect(0, 0, size.width, size.height);
		}
		float l = FLT_MAX, r = -FLT_MAX, t = -FLT_MAX, b = FLT_MAX;
		for (ssize_t i = 0; i < _children.size(); ++i) {
			cocos2d::Node* node = _children.at(i);
			cocos2d::Vec2 lb = getPointWithAnchorPoint(node, 0.0f, 0.0f);
			cocos2d::Vec2 rt = getPointWithAnchorPoint(node, 1.0f, 1.0f);
			if (l > lb.x) l = lb.x;
			if (b > lb.y) b = lb.y;
			if (t < rt.y) t = rt.y;
			if (r < rt.x) r = rt.x;
		}
		return cocos2d::Rect(l, b, r - l, t - b);
	}

	cocos2d::Node* GComponent::getStencil() {
		return _stencil;
	}

	void GComponent::setStencil(cocos2d::Node* node) {
		if (_stencil) {
			if (_stencil->isRunning()) {
				_stencil->onExitTransitionDidStart();
				_stencil->onExit();
			}
#if CC_CLIPPING_NODE_OPENGLES
			setProgram(_stencil, _stencilOldProgram);
#endif
			_stencil->release();

		}
		_stencil = node;
		if (_stencil) {
			_stencil->retain();
			if (_stencil->getParent()) {
				_stencil->getParent()->removeChild(_stencil, false);
			}
			if (this->isRunning()) {
				_stencil->onEnter();
				if (this->_isTransitionFinished) {
					_stencil->onEnterTransitionDidFinish();
				}
			}
			_stencilOldProgram = _stencil->getGLProgram();
		}
	}

	GLfloat GComponent::getAlphaThreshold() const {
		return _alphaThreshold;
	}

	void GComponent::setAlphaThreshold(GLfloat alphaThreshold) {
		_alphaThreshold = alphaThreshold;
	}

	bool GComponent::isStencilInverted() const {
		return _isInverted;
	}

	void GComponent::setStencilInverted(bool inverted) {
		_isInverted = inverted;
	}

	void GComponent::setCameraMask(unsigned short mask, bool applyChildren ){
		Node::setCameraMask(mask, applyChildren);
		if (_stencil) {
			_stencil->setCameraMask(mask, applyChildren);
		}
	}

	void GComponent::setHitArea(IHitTest* value) {
		if (_hitTest) {
			delete _hitTest;
		}
		_hitTest = value;
	}

	void GComponent::setHSVMode(bool isHsv) {
		GObject::setHSVMode(isHsv);
		for (ssize_t i = 0; i < _children.size(); ++i) {
			cocos2d::Node* node = _children.at(i);
			GSprite* sprite = dynamic_cast<GSprite*>(node);
			if (sprite) {
				sprite->setHSVMode(isHsv);
				continue;
			}
			GLoader* loader = dynamic_cast<GLoader*>(node);
			if (loader) {
				loader->setHSVMode(isHsv);
				continue;
			}
		}
	}

	void GComponent::setHSVValue(float hue, float saturation, float brightness, float contrast) {
		GObject::setHSVValue(hue, saturation, brightness, contrast);
		for (ssize_t i = 0; i < _children.size(); ++i) {
			cocos2d::Node* node = _children.at(i);
			GSprite* sprite = dynamic_cast<GSprite*>(node);
			if (sprite) {
				sprite->setHSVValue(hue,saturation,brightness,contrast);
				continue;
			}
			GLoader* loader = dynamic_cast<GLoader*>(node);
			if (loader) {
				loader->setHSVValue(hue, saturation, brightness, contrast);
				continue;
			}
		}
	}

	GTransition* GComponent::getTransition(const std::string& name) {
		for (size_t i = 0; i < _transitions.size(); ++i) {
			if (_transitions[i]->getName() == name) {
				return _transitions[i];
			}
		}
		return NULL;
	}

	void GComponent::applyAllControllers() {
		for (auto iter = m_controllers.begin(); iter != m_controllers.end(); ++iter) {
			applyController(*iter);
		}
	}

	void GComponent::applyController(GController* controller) {
		m_applyingController = controller;
		auto& children = getChildren();

		for (auto iter = children.begin(); iter != children.end(); ++iter) {
			GObject* obj = dynamic_cast<GObject*>(*iter);
			if (obj) {
				obj->onControllerChanged(controller);
			}
		}
		m_applyingController = nullptr;

		controller->runActions();
	}

	void GComponent::setup(const ObjectInfo* inf, cocos2d::Node* parent) {
		m_constructing = true;
		const ComponentInfo* info = dynamic_cast<const ComponentInfo*>(inf);
		this->setName(info->name);

		/*if (info->size) {
			m_nodeSelf->setContentSize(*info->size);
		}
		else {
			m_nodeSelf->setContentSize(cocos2d::Size(info->width, info->height));
		}*/

		m_nodeSelf->setContentSize(cocos2d::Size(info->width, info->height));

		if (info->pivot) {
			m_nodeSelf->setAnchorPoint(*info->pivot);
			m_nodeSelf->setIgnoreAnchorPointForPosition(!info->bPivotAsAchorPoint);
		}
		else {
			m_nodeSelf->setAnchorPoint(cocos2d::Vec2(0,1.0f));
			m_nodeSelf->setIgnoreAnchorPointForPosition(false);
		}

		if (parent) {
			const cocos2d::Size& parentSize = parent->getContentSize();
			if (!m_nodeSelf->isIgnoreAnchorPointForPosition()) {
				m_nodeSelf->setPosition(cocos2d::Vec2(info->pos.x, parentSize.height - info->pos.y));
			}
			else {
				const cocos2d::Size& selfSize = m_nodeSelf->getContentSize();
				m_nodeSelf->setPosition(cocos2d::Vec2(info->pos.x , (parentSize.height - info->pos.y) - selfSize.height));
			}
		}
		if (info->scale) {
			m_nodeSelf->setScaleX(info->scale->x);
			m_nodeSelf->setScaleY(info->scale->y);
		}
		if (info->rotation != 0) {
			m_nodeSelf->setRotation(info->rotation);
		}
		if (info->skew) {
			m_nodeSelf->setSkewX(info->skew->x);
			m_nodeSelf->setSkewY(info->skew->y);
		}
		if (info->opacity != 1) {
			m_nodeSelf->setCascadeOpacityEnabled(true);
			m_nodeSelf->setOpacity(info->opacity * 255);
		}
		if (!info->bVisible) {
			m_nodeSelf->setVisible(info->bVisible);
		}
		if (info->minSize && info->maxSize) {
			_minSize = *info->minSize;
			_maxSize = *info->maxSize;
		}
		if (info->margin) {
			_margin = *info->margin;
		}
		if (info->overflow != OverflowType::VISIBLE) {
			setupOverflow(info->overflow);
		}
		if (info->overflow == OverflowType::SCROLL) {
			_scrollType = info->scrollType;
			_isPageMode = info->bPageMode;
			_bouncebackEffect = info->bBouncebackEffect;
			_isInertiaEnabled = info->bInertiaEnabled;
		}
		for (size_t i = 0; i < info->controllers.size(); ++i) {
			GController* controller = new GController();
			m_controllers.push_back(controller);
			controller->setParent(this);
			controller->setup(info->controllers[i]);
		}
		std::vector<GObject*> children;
		Package* pkg = NULL;
		PkgItem* item = NULL;
		PackageManager* mgr = PackageManager::getInstance();

		for (size_t i = 0; i < info->children.size(); ++i) {
			ObjectInfo* childInfo = info->children.at(i);
			cocos2d::Node* childNode = createObjectByType(childInfo->objectType);
			GObject* obj = dynamic_cast<GObject*>(childNode);

			pkg = !childInfo->pkgId.empty() ? mgr->getPkg(childInfo->pkgId) : _pkg;
			if (!childInfo->temId.empty() && pkg) {
				item = pkg->getPkgItemById(childInfo->temId);
			}
			obj->constructFromItem(pkg, item);

			addChild(childNode);
			children.push_back(obj);
		}

		for (size_t i = 0; i < children.size(); ++i) {
			GObject* obj = children[i];
			ObjectInfo* childInfo = info->children[i];
			obj->setup(childInfo, this);
		}

		_relations->setup(info->relation , true);

		for (size_t i = 0; i < children.size(); ++i) {
			GObject* obj = children[i];
			ObjectInfo* childInfo = info->children[i];
			obj->_relations->setup(childInfo->relation, false);
		}

		if (info->maskId != -1) {
			bool inverted = info->bInverted;
			cocos2d::Node* comp = dynamic_cast<cocos2d::Node*>(children[info->maskId]);
			setStencil(comp);
			setStencilInverted(inverted);
		}

		if (!info->hitTestId.empty()) {
			for (size_t i = 0; i < children.size(); ++i) {
				ObjectInfo* childInfo = info->children[i];
				GObject* obj = children[i];
				if (obj->_item->getId() == info->hitTestId) {
					ImageItem* imgItem = dynamic_cast<ImageItem*>(obj->_item);
					CCASSERT(imgItem, "the item is not imageitem");
					cocos2d::Node* node = dynamic_cast<cocos2d::Node*>(children[i]);
					cocos2d::Vec2 p = getPointWithAnchorPoint(node, 0.0f, 0.0f);
					setHitArea(new PixelHitTest(imgItem->getHitTestData(), p.x, p.y));
					break;
				}
			}
		}

		for (int i = 0; i < info->transitions.size(); ++i) {
			GTransition* trans = new GTransition(this);
			trans->setup(info->transitions[i]);
			_transitions.push_back(trans);
		}

		if (info->blendMode != BlendMode::NORMAL) {
			setBlendMode(info->blendMode);
		}
		if (info->bGray) {
			setGrayed(info->bGray);
		}
		if (info->hsv) {
			setHSVMode(true);
			setHSVValue(info->hsv->x, info->hsv->y, info->hsv->z, info->hsv->w);
		}

		if (info->size && info->width != info->size->width && info->width != info->height) {
			setContentSize(*info->size);
		}

		applyAllControllers();
		m_constructing = false;
	}

	void GComponent::constructFromResource(UIPackage* pkg, PackageItem* pt) {
		m_constructing = true;
		GObject::constructFromResource(pkg, pt);
		ByteBuffer* buffer = pt->rawData;
		if (!buffer) {
			return;
		}

		buffer->Seek(0, 0);

		cocos2d::Size contentSize;
		contentSize.width = buffer->ReadInt();
		contentSize.height = buffer->ReadInt();
		this->setContentSize(contentSize);

		if (buffer->ReadBool()) {
			_minSize.width = buffer->ReadInt();
			_maxSize.width = buffer->ReadInt();
			_minSize.height = buffer->ReadInt();
			_maxSize.height = buffer->ReadInt();
		}
		if (buffer->ReadBool()) {
			cocos2d::Vec2 ap;
			ap.x = buffer->ReadFloat();
			ap.y = 1.0f - buffer->ReadFloat();
			this->setAnchorPoint(ap);
			_isPivotAsAchorPoint = buffer->ReadBool();
			this->setIgnoreAnchorPointForPosition(false);
		}
		if (buffer->ReadBool()) {
			_margin.top = buffer->ReadInt();
			_margin.bottom = buffer->ReadInt();
			_margin.left = buffer->ReadInt();
			_margin.right = buffer->ReadInt();
		}

		OverflowType overflow = (OverflowType)buffer->ReadByte();
		setupOverflow(overflow);
		if (overflow == OverflowType::SCROLL) {
			int savedPos = buffer->position;
			buffer->Seek(0, 7);
			setupScroll(buffer);
			buffer->position = savedPos;
		}

		if (buffer->ReadBool()) {
			buffer->Skip(8);
		}

		buffer->Seek(0, 1);
		int controllerCount = buffer->ReadShort();
		for (int i = 0; i < controllerCount; ++i) {
			int nextPos = buffer->ReadShort();
			nextPos += buffer->position;

			GController* controller = new GController();
			m_controllers.push_back(controller);
			controller->setParent(this);
			controller->setup(buffer);

			buffer->position = nextPos;
		}

		buffer->Seek(0, 2);
		GObject* child = NULL;
		PackageManager* pkgMgr = PackageManager::getInstance();
		int childCount = buffer->ReadShort();
		std::vector<GObject*> children(childCount);

		for (int i = 0; i < childCount; ++i) {
			int dataLen = buffer->ReadShort();
			int curPos = buffer->position;
			buffer->Seek(curPos, 0);

			ObjectType type = (ObjectType)buffer->ReadByte();
			const std::string& src = buffer->ReadS();
			const std::string& pkgId = buffer->ReadS();

			UIPackage* childPkg = pkgId.empty() ? pt->owner : pkgMgr->getPackageById(pkgId);
			PackageItem* childPt = src.empty() ? NULL : childPkg->getPackageItemById(src);
			if (!src.empty() && !childPt) {
				cocos2d::log("the item can not find , name:%s",src.c_str());
				CCASSERT(false, "check the item");
				return;
			}
			if (childPkg && childPt) {
				child = dynamic_cast<GObject*>( childPkg->createObjectByType(childPt->objectType));
				child->constructFromResource(childPkg, childPt);
			}
			else {
				child = dynamic_cast<GObject*>(childPkg->createObjectByType(type));
				child->constructFromResource(childPkg, childPt);
			}
			child->setupBefore(buffer, curPos, this);
			cocos2d::Node* childNode = dynamic_cast<cocos2d::Node*>(child);
			CCASSERT(childNode, "the component is not CCNode");
			this->addChild(childNode);

			buffer->position = curPos + dataLen;
			children[i] = child;
		}

		//¹ØÁª
		buffer->Seek(0, 3);
		_relations->setup(buffer, true);

		buffer->Seek(0, 2);
		buffer->Skip(2);

		for (int i = 0; i < childCount; ++i) {
			int nextPos = buffer->ReadShort();
			nextPos += buffer->position;
			buffer->Seek(buffer->position, 3);

			GObject* childObj = children[i];
			childObj->_relations->setup(buffer, false);
			buffer->position = nextPos;
		}

		buffer->Seek(0, 2);
		buffer->Skip(2);

		for (int i = 0; i < childCount; i++){
			int nextPos = buffer->ReadShort();
			nextPos += buffer->position;
			child = children[i];
			child->setupAfter(buffer, buffer->position);
			buffer->position = nextPos;
		}

		buffer->Seek(0, 4);
		buffer->Skip(2);

		bool isVisible = buffer->ReadBool();
		this->setVisible(isVisible);

		int maskId = buffer->ReadShort();
		if (maskId != -1) {
			bool inverted = buffer->ReadBool();
			cocos2d::Node* comp = dynamic_cast<cocos2d::Node*>(children[maskId]);
			setStencil(comp);
			setStencilInverted(inverted);
		}

		const std::string& hitTestId = buffer->ReadS();
		if (!hitTestId.empty()) {
			for (size_t i = 0; i < children.size(); ++i) {
				PackageItem* pt = children[i]->_pkgItem;
				if (pt && pt->id == hitTestId) {
					cocos2d::Node* node = dynamic_cast<cocos2d::Node*>(children[i]);
					cocos2d::Vec2 p = getPointWithAnchorPoint(node, 0.0f, 0.0f);
					setHitArea(new PixelHitTest(pt->pixelHitTestData, p.x, p.y));
					break;
				}
			}
			PackageItem* pi = pkg->getPackageItemById(hitTestId);
			if (pi && pi->pixelHitTestData) {
				int i1 = buffer->ReadInt();
				int i2 = contentSize.height - buffer->ReadInt();
			}
		}

		//±ä»»
		buffer->Seek(0, 5);
		int transitionCount = buffer->ReadShort();
		for (int i = 0; i < transitionCount; ++i) {
			int nextPos = buffer->ReadShort();
			nextPos += buffer->position;

			GTransition* trans = new GTransition(this);
			trans->setup(buffer);
			_transitions.push_back(trans);
			buffer->position = nextPos;
		}
		if (pt->objectType != ObjectType::COMPONENT) {
			setupExtend(buffer);
		}

		applyAllControllers();
		m_constructing = false;
	}

	void GComponent::setupBefore(ByteBuffer* buffer, int pos, cocos2d::Node* parent) {
		GObject::setupBefore(buffer, pos,parent);
	}

	void GComponent::setupAfter(ByteBuffer* buffer, int beginPos) {
		GObject::setupAfter(buffer, beginPos);
		buffer->Seek(beginPos, 4);

		int pageController = buffer->ReadShort();

		int cnt = buffer->ReadShort();
		for (int i = 0; i < cnt; i++) {
			const std::string& controllerName = buffer->ReadS();
			GController* cc = getController(controllerName);
			const std::string& pageId = buffer->ReadS();
			if (cc) {
				cc->setSelectedPageId(pageId);
			}	
		}
	}

	void GComponent::setupExtend(ByteBuffer* buffer) {

	}

	void GComponent::visit(cocos2d::Renderer* renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags) {
		if (_stencil) {
			if (!_visible || _children.empty()) {
				return;
			}
			uint32_t flags = processParentFlags(parentTransform, parentFlags);
			cocos2d::Director* director = cocos2d::Director::getInstance();
			director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
			director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewTransform);
			if (_groupCommand == NULL) {
				_groupCommand = new GroupCommand();
			}
			_groupCommand->init(_globalZOrder);
			renderer->addCommand(_groupCommand);
			renderer->pushGroup(_groupCommand->getRenderQueueID());
			
			if (_stencilStateManager == NULL) {
				_stencilStateManager = new cocos2d::StencilStateManager();
			}
			_stencilStateManager->setInverted(_isInverted);
			_stencilStateManager->setAlphaThreshold(_alphaThreshold);

			if (_beforeVisitCmd == NULL) {
				_beforeVisitCmd = new cocos2d::CustomCommand();
			}
			_beforeVisitCmd->init(_globalZOrder);
			_beforeVisitCmd->func = CC_CALLBACK_0(StencilStateManager::onBeforeVisit, _stencilStateManager);
			renderer->addCommand(_beforeVisitCmd);
			auto alphaThreshold = getAlphaThreshold();
			if (alphaThreshold < 1) {
#if CC_CLIPPING_NODE_OPENGLES
				GLProgram* program = GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_TEXTURE_ALPHA_TEST_NO_MV);
				GLint alphaValueLocation = glGetUniformLocation(program->getProgram(), GLProgram::UNIFORM_NAME_ALPHA_TEST_VALUE);
				program->use();
				program->setUniformLocationWith1f(alphaValueLocation, alphaThreshold);
				setProgram(_stencil, program);
#endif
			}
			_stencil->visit(renderer, _modelViewTransform, flags);

			if (_afterDrawStencilCmd == NULL) {
				_afterDrawStencilCmd = new cocos2d::CustomCommand();
			}
			_afterDrawStencilCmd->init(_globalZOrder);
			_afterDrawStencilCmd->func = CC_CALLBACK_0(StencilStateManager::onAfterDrawStencil, _stencilStateManager);
			renderer->addCommand(_afterDrawStencilCmd);

			int i = 0;
			bool visibleByCamera = isVisitableByVisitingCamera();
			if (!_children.empty()) {
				sortAllChildren();
				for (auto size = _children.size(); i < size; ++i) {
					auto node = _children.at(i);
					if (node && node->getLocalZOrder() < 0) {
						node->visit(renderer, _modelViewTransform, flags);
					}
					else {
						break;
					}
				}
				if (visibleByCamera) {
					this->draw(renderer, _modelViewTransform, flags);
				}
				for (; i < _children.size(); ++i) {
					auto node = _children.at(i);
					node->visit(renderer, _modelViewTransform, flags);
				}
			}
			else if(visibleByCamera){
				this->draw(renderer, _modelViewTransform, flags);
			}

			if (_afterVisitCmd == NULL) {
				_afterVisitCmd = new cocos2d::CustomCommand();
			}
			_afterVisitCmd->init(_globalZOrder);
			_afterVisitCmd->func = CC_CALLBACK_0(StencilStateManager::onAfterVisit, _stencilStateManager);
			renderer->addCommand(_afterVisitCmd);

			renderer->popGroup();
			director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
		}
		else if(_overflowType != OverflowType::VISIBLE){
			if (_beforeVisitCmdScissor == NULL) {
				_beforeVisitCmdScissor = new cocos2d::CustomCommand();
			}
			_beforeVisitCmdScissor->init(_globalZOrder);
			_beforeVisitCmdScissor->func = CC_CALLBACK_0(GComponent::onBeforeVisitScissor, this);
			renderer->addCommand(_beforeVisitCmdScissor);

			Node::visit(renderer, parentTransform, parentFlags);

			if (_afterVisitCmdScissor == NULL) {
				_afterVisitCmdScissor = new cocos2d::CustomCommand();
			}
			_afterVisitCmdScissor->init(_globalZOrder);
			_afterVisitCmdScissor->func = CC_CALLBACK_0(GComponent::onAfterVisitScissor, this);
			renderer->addCommand(_afterVisitCmdScissor);
		}
		else {
			Node::visit(renderer, parentTransform, parentFlags);
		}
	}

	void GComponent::onBeforeVisitScissor() {
		auto glview = cocos2d::Director::getInstance()->getOpenGLView();
		_scissorOldState = glview->isScissorEnabled();
		if (!_scissorOldState) {
			glEnable(GL_SCISSOR_TEST);
		}
		else {
			_scissorOldRect = glview->getScissorRect();
		}
		glview->setScissorInPoints(_clippingRect.origin.x, _clippingRect.origin.y, _clippingRect.size.width, _clippingRect.size.height);
	}

	void GComponent::onAfterVisitScissor() {
		if (_scissorOldState) {
			auto glview = cocos2d::Director::getInstance()->getOpenGLView();
			glview->setScissorInPoints(_scissorOldRect.origin.x, _scissorOldRect.origin.y, _scissorOldRect.size.width, _scissorOldRect.size.height);
		}
		else {
			glDisable(GL_SCISSOR_TEST);
		}
	}

	void GComponent::updateClippingRect() {
		if (this->isRunning() && _overflowType != OverflowType::VISIBLE) {
			const cocos2d::Size& size = getContentSize();
			cocos2d::AffineTransform t = getNodeToWorldAffineTransform();
			cocos2d::Vec2 worldPos = convertToWorldSpace(cocos2d::Vec2(0, 0));
			_clippingRect.setRect(worldPos.x + _margin.left, worldPos.y + _margin.bottom, (size.width - _margin.left - _margin.right) * t.a, (size.height - _margin.top - _margin.bottom) * t.d);
		}
	}

	bool GComponent::onTouchBegin(cocos2d::Touch* touch, cocos2d::Event* event) {
		cocos2d::Node* node = this;
		while (node) {
			GComponent* comp = dynamic_cast<GComponent*>(node);
			if (comp && !checkTouchStencilClippingRegion(comp, touch)) {
				return false;
			}
			node = node->getParent();
		}
		if (_hitTest) {
			bool ret = _hitTest->hitTest(this, this->convertTouchToNodeSpace(touch));
			return ret;
		}
		return GObject::onTouchBegin(touch, event);
	}

	void GComponent::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) {
		if (_overflowType == OverflowType::SCROLL) {
			cocos2d::Vec2 d = touch->getLocation() - touch->getPreviousLocation();
			cocos2d::Rect rect = this->getEdgeRectangle();
			const cocos2d::Size& size = this->getContentSize();
			float dx = 0, dy = 0;
			if (_scrollType == ScrollType::BOTH || _scrollType == ScrollType::HORIZONTAL) {
				float spaceX = _bouncebackEffect ? size.width / 2 : 0;
				float maxX = std::max(_initEdgeRect.origin.x, 0.0f) + spaceX;
				float minX = _initEdgeRect.origin.x + std::min(_initEdgeRect.getMaxX(), size.width) - spaceX - _initEdgeRect.getMaxX();
				dx = std::min(maxX, std::max(minX, rect.origin.x + d.x)) - rect.origin.x;
			}
			
			if (_scrollType == ScrollType::BOTH || _scrollType == ScrollType::VERTICAL) {
				float spaceY = _bouncebackEffect ? size.height / 2 : 0;
				float maxY = std::max(_initEdgeRect.origin.y, 0.0f) + spaceY;
				float minY = _initEdgeRect.origin.y + std::min(_initEdgeRect.getMaxY(), size.height) - spaceY - _initEdgeRect.getMaxY();
				dy = std::min(maxY, std::max(minY, rect.origin.y + d.y)) - rect.origin.y;
			}

			if (dx == 0 && dy == 0) {
				GObject::onTouchMoved(touch, event);
				return;
			}
			for (ssize_t i = 0; i < _children.size(); ++i) {
				GObject* obj = dynamic_cast<GObject*>(_children.at(i));
				if (obj) {
					obj->setRelationIsValid(false);
				}
			}
			for (ssize_t i = 0; i < _children.size(); ++i) {
				cocos2d::Node* node = _children.at(i);
				node->setPosition(node->getPositionX() + dx,node->getPositionY() + dy);
			}
			for (ssize_t i = 0; i < _children.size(); ++i) {
				GObject* obj = dynamic_cast<GObject*>(_children.at(i));
				if (obj) {
					obj->setRelationIsValid(true);
				}
			}
		}
		GObject::onTouchMoved(touch, event);
	}

	void GComponent::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) {
		if (_overflowType == OverflowType::SCROLL && _bouncebackEffect) {
			const cocos2d::Size& size = this->getContentSize();
			cocos2d::Rect rect = this->getEdgeRectangle();
			cocos2d::Vec2 p = rect.origin;
			
			if (_scrollType == ScrollType::BOTH || _scrollType == ScrollType::HORIZONTAL) {
				float maxX = std::max(_initEdgeRect.origin.x, 0.0f);
				float minX = _initEdgeRect.origin.x + std::min(_initEdgeRect.getMaxX(), size.width) - _initEdgeRect.getMaxX();
				p.x = std::max(minX, std::min(maxX, rect.origin.x));
			}
			if (_scrollType == ScrollType::BOTH || _scrollType == ScrollType::VERTICAL) {
				float maxY = std::max(_initEdgeRect.origin.y, 0.0f);
				float minY = _initEdgeRect.origin.y + std::min(_initEdgeRect.getMaxY(), size.height) - _initEdgeRect.getMaxY();
				p.y = std::max(minY, std::min(maxY, rect.origin.y));
			}

			if (!p.equals(rect.origin)) {
				cocos2d::Vec2 dp = p - rect.origin;
				for (ssize_t i = 0; i < _children.size(); ++i) {
					cocos2d::Node* node = _children.at(i);
					const cocos2d::Vec2& pos = node->getPosition();
					GTweener* tweener = TweenManager::getInstance()->createTween();
					tweener->toVec2(pos, dp + pos, 0.2f);
					tweener->setTarget(node, TweenPropType::Position);
					tweener->onStart([node](GTweener* tweener) {
						GObject* obj = dynamic_cast<GObject*>(node);
						if (obj) {
							obj->setRelationIsValid(false);
						}
					});
					tweener->onComplete([node]() {
						GObject* obj = dynamic_cast<GObject*>(node);
						if (obj) {
							obj->setRelationIsValid(true);
						}
					});
				}
			}
		}
		GObject::onTouchEnded(touch, event);
	}

	bool GComponent::checkTouchStencilClippingRegion(GComponent* comp, cocos2d::Touch* touch) {
		if (comp) {
			cocos2d::Node* stencil = comp->getStencil();
			if (stencil) {
				 cocos2d::Vec2 pos = comp->convertTouchToNodeSpace(touch);
				 return stencil->getBoundingBox().containsPoint(pos);
			}
			if(comp->_overflowType != OverflowType::VISIBLE){
			 	 cocos2d::Vec2 pos = comp->convertTouchToNodeSpace(touch);
				 return comp->_clippingRect.containsPoint(touch->getLocation());
			}
		}
		return true;
	}
}
