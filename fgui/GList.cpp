#include "GList.h"
#include "PackageManager.h"
#include "Controller.h"
#include "GContainer.h"
#include "GTweener.h"
#include "TweenManager.h"
#include "FguiUtils.h"
namespace fgui {
	GList::GList():
	_touchBeginTime(0.0f)
	, _container(NULL){

	}



	GList::~GList() {

	}

	void GList::setLayoutInfo(const ListLayoutInfo& info) {
		_container->setLayoutType(info.layoutType);
		_container->setLineCount(info.lineCount);
		_container->setColumnCount(info.columnCount);
		_container->setLineGap(info.lineGap);
		_container->setColumnGap(info.columnGap);
		_container->setMargin(Margin(info.left, info.top, info.right, info.bottom));
	}

	bool GList::init() {
		GComponent::init();
		_container = new GContainer();
		addChild(_container);
		return true;
	}

	void GList::addChild(Node* child, int localZOrder, const std::string& name) {
		if (child == _container) {
			Node::addChild(child, localZOrder, name);
		}
		else {
			_container->addChild(child, localZOrder, name);
			GComponent* comp = dynamic_cast<GComponent*>(child);
			if (comp) {
				comp->setSwallowTouch(false);
			}
		}
	}

	void GList::addChild(Node* child, int localZOrder, int tag) {
		if (child == _container) {
			Node::addChild(child, localZOrder, tag);
		}
		else {
			_container->addChild(child, localZOrder, tag);
			GComponent* comp = dynamic_cast<GComponent*>(child);
			if (comp) {
				comp->setSwallowTouch(false);
			}
		}
	}

	void GList::addChild(Node* child, int localZOrder) {
		Node::addChild(child, localZOrder);
	}

	void GList::addChild(Node* child) {
		Node::addChild(child);
	}

	void GList::setCreateNodeCallback(std::function<void(cocos2d::Node*, int)> handler) {
		_container->setUpdateNodeCallback(handler);
	}

	void GList::setNodeUrl(const std::string& url) {
		_container->setNodeUrl(url);
	}

	void GList::setVirtual() {
		_container->setVirtual();
	}

	bool GList::isVirtual() {
		return _container->isVirtual();
	}

	void GList::setVirtualItemCount(int count) {
		_container->setVirtualItemCount(count);
	}

	int GList::getVirtualItemCount() {
		return _container->getVirtualItemCount();
	}

	void GList::constructFromResource(UIPackage* pkg, PackageItem* pt) {
		GObject::constructFromResource(pkg, pt);
	}

	void GList::setupOverflow(OverflowType overflow) {
		if (_overflowType != overflow) {
			_overflowType = overflow;
			this->setTouchable(true);
			_container->setContentSize(getContentSize());
		}
	}

	bool GList::onTouchBegin(cocos2d::Touch* touch, cocos2d::Event* event) {
		bool ret = GComponent::onTouchBegin(touch, event);
		if (ret) {
			_touchBeginTime = getSystemTime();
			TweenManager::getInstance() ->killTweens(_container, TweenPropType::None, false);
		}
		return ret;
	}

	void GList::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) {
		cocos2d::Vec2 p = touch->getLocation() - touch->getPreviousLocation();
		const cocos2d::Size& size = getContentSize();
		const cocos2d::Size& containSize = _container->getContentSize();

		auto layoutType = _container->getLayoutType();
		if (layoutType == ListLayoutType::SINGLE_COLUMN || layoutType == ListLayoutType::FLOW_HORIZONTAL) {
			float y = _container->getPositionY() + p.y * 0.3f;
			float limit = size.height * 0.2f;
			y = std::max(-containSize.height + size.height - limit, std::min(y, limit));
			_container->setPositionY(y);
		}
		else if (layoutType == ListLayoutType::SINGLE_ROW || layoutType == ListLayoutType::FLOW_VERTICAL) {
			float x = _container->getPositionX() + p.x * 0.3f;
			float limit = size.width * 0.2f;
			x = std::max(-containSize.width + size.width - limit, std::min(x, limit));
			_container->setPositionX(x);
		}

		if (_container->isVirtual()) {
			_container->updateVirtualLayout();
		}

		GObject::onTouchMoved(touch, event);
	}

	void GList::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) {
		cocos2d::Vec2 p;
		cocos2d::Vec2 pos = _container->getPosition();
		if (!p.equals(pos)) {
			bool isNeedDrag = false;
			float inertiaTime = 1.0f;
			double dt = getSystemTime() - _touchBeginTime;
			auto layoutType = _container->getLayoutType();

			if (layoutType == ListLayoutType::SINGLE_COLUMN || layoutType == ListLayoutType::FLOW_HORIZONTAL) {
				float b = -_container->getContentSize().height + getContentSize().height;
				if (pos.y > 0 || pos.y < b) {
					isNeedDrag = true;
					p.y = pos.y > 0 ? 0 : b;
				}
				else {
					p.y = pos.y + (touch->getLocation().y - touch->getStartLocation().y) / (dt * 100) * inertiaTime;
					p.y = std::min(0.0f, std::max(b, p.y));
				}
			}
			else if (layoutType == ListLayoutType::SINGLE_ROW || layoutType == ListLayoutType::FLOW_VERTICAL) {
				float b = -_container->getContentSize().width + getContentSize().width;
				if (pos.x > 0 || pos.x < b) {
					isNeedDrag = true;
					p.x = pos.x > 0 ? 0 : b;
				}
				else {
					p.x = pos.x + (touch->getLocation().x - touch->getStartLocation().x) / (dt * 100) * inertiaTime;
					p.x = std::min(0.0f, std::max(b, p.x));
				}
			}

			if (isNeedDrag) {
				GTweener* tweener = TweenManager::getInstance()->createTween();
				tweener->toVec2(pos, p, 0.2f);
				tweener->setTarget(_container, TweenPropType::Position);
				if (_container->isVirtual()) {
					tweener->onUpdate([this](GTweener*) {
						_container->updateVirtualLayout();
					});
				}
			}
			else {
				GTweener* tweener = TweenManager::getInstance()->createTween();
				tweener->toVec2(pos, p, inertiaTime);
				tweener->setEase(EaseType::CubicOut);
				if (_container->isVirtual()) {
					static cocos2d::Vec2 lastPos;
					lastPos.set(0, 0);
					tweener->onUpdate([p,pos,this](GTweener* tw) {
						cocos2d::Vec2 v = (p - pos) * tw->getNormalizedTime();
						_container->setPosition(_container->getPosition() + v - lastPos);
						_container->updateVirtualLayout();
						lastPos = v;
					});
				}
			}
		}
		GObject::onTouchEnded(touch, event);
	}

	void GList::setupBefore(ByteBuffer* buffer, int pos, cocos2d::Node* parent) {
		GComponent::setupBefore(buffer, pos, parent);
		buffer->Seek(pos, 5);

		auto layout = (ListLayoutType)buffer->ReadByte();
		_container->setLayoutType(layout);
		auto selectMode = (ListSelectionMode)buffer->ReadByte();
		auto hAlign = (cocos2d::TextHAlignment)buffer->ReadByte();
		_container->setHAlignment(hAlign);
		auto vAlign = (cocos2d::TextVAlignment)buffer->ReadByte();
		_container->setVAlignment(vAlign);

		int lineGap = buffer->ReadShort();
		_container->setLineGap(lineGap);

		int columnGap = buffer->ReadShort();
		_container->setColumnGap(columnGap);

		int lineCount = buffer->ReadShort();
		_container->setLineCount(lineCount);

		int columnCount = buffer->ReadShort();
		_container->setColumnCount(columnCount);

		auto autoResizeItem = buffer->ReadBool();
		auto childrenRenderOrder = (ChildrenRenderOrder)buffer->ReadByte();
		auto apexIndex = buffer->ReadShort();

		if (buffer->ReadBool()){
			Margin margn;
			margn.top = buffer->ReadInt();
			margn.bottom = buffer->ReadInt();
			margn.left = buffer->ReadInt();
			margn.right = buffer->ReadInt();
			_container->setMargin(margn);
		}

		OverflowType overflow = (OverflowType)buffer->ReadByte();
		setupOverflow(overflow);
		if (overflow == OverflowType::SCROLL){ 
			int savedPos = buffer->position;
			buffer->Seek(pos, 7);
			setupScroll(buffer);
			buffer->position = savedPos;
		}

		if (buffer->ReadBool()) {
			buffer->Skip(8);
		}
		
		buffer->Seek(pos, 8);

		const std::string* str;

		std::string defaultItem = buffer->ReadS();
		_container->setNodeUrl(defaultItem);

		int itemCount = buffer->ReadShort();
		for (int i = 0; i < itemCount; i++){
			int nextPos = buffer->ReadShort();
			nextPos += buffer->position;

			str = buffer->ReadSP();
			if (!str || (*str).empty()){
				str = &defaultItem;
				if ((*str).empty()){
					buffer->position = nextPos;
					continue;
				}
			}

			cocos2d::Node* obj = PackageManager::getInstance()->createObjectByURL(*str);
			
			if (obj != nullptr){
				addChild(obj);
				str = buffer->ReadSP();
				str = buffer->ReadSP();
				str = buffer->ReadSP();
				str = buffer->ReadSP();
				str = buffer->ReadSP();
				if (str) {
					obj->setName(*str);
				}
				int cnt = buffer->ReadShort();
				if (cnt > 0){
					GComponent* gcom = dynamic_cast<GComponent*>(obj);
					if (gcom){
						for (int j = 0; j < cnt; j++){
							GController* cc = gcom->getController(buffer->ReadS());
							const std::string& pageId = buffer->ReadS();
							cc->setSelectedPageId(pageId);
						}
					}
				}
			}
			buffer->position = nextPos;
		}
	}

	void GList::setupAfter(ByteBuffer* buffer, int pos) {
		GComponent::setupAfter(buffer, pos);
		buffer->Seek(pos, 6);

		int i = buffer->ReadShort();
		if (i != -1) {
			//_selectionController = _parent->getControllerAt(i);
		}
	}

	void GList::setup(const ObjectInfo* inf, cocos2d::Node* parent) {
		GObject::setup(inf, parent);
		const ListInfo* info = dynamic_cast<const ListInfo*>(inf);
		_container->setLayoutType(info->layoutType);
		_container->setHAlignment(info->hAlign);
		_container->setVAlignment(info->vAlign);
		_container->setLineGap(info->lineGap);
		_container->setLineCount(info->lineCount);
		_container->setColumnGap(info->columnGap);
		_container->setColumnCount(info->columnCount);
		_container->setNodeUrl(info->defaultItem);
		if (info->margin) {
			_container->setMargin(*info->margin);
		}

		setupOverflow(info->overflow);
		if (info->overflow == OverflowType::SCROLL) {
			_isPageMode = info->bPageMode;
			_scrollType = info->scrollType;
			_bouncebackEffect = info->bBouncebackEffect;
			_isInertiaEnabled = info->bInertiaEnabled;
		}

		auto& items = info->items;
		for (size_t i = 0; i < items.size(); ++i) {
			const std::string& url = items[i]->url.empty() ? info->defaultItem : items[i]->url;
			if (url.empty()) {
				continue;
			}
			cocos2d::Node* obj = PackageManager::getInstance()->createNodeByUrl(url);
			obj->setName(items[i]->name);
			_container->addChild(obj);
			GComponent* gcom = dynamic_cast<GComponent*>(obj);
			if (!gcom) {
				continue;
			}
			for (auto iter = items[i]->controllerInfo.begin(); iter != items[i]->controllerInfo.end(); ++iter) {
				GController* cc = gcom->getController(iter->first);
				cc->setSelectedPageId(iter->second);
			}
		}
	}
}