#include "GObject.h"
#include "PackageManager.h"
#include "UIPackage.h"
#include "HitTest.h"
#include "Controller.h"
#include "base/CCEventListenerTouch.h"
#include "GearBase.h"
#include "GearColor.h"
#include "GearDisplay.h"
#include "GearIcon.h"
#include "GearLook.h"
#include "GearSize.h"
#include "GearText.h"
#include "GearXY.h"
#include "GearAnimation.h"
#include "GComponent.h"
#include "Relations.h"
#include "GGroup.h"
#include "Package.h"
#include "PkgItem.h"
#include "GSprite.h"
#include "GSlider.h"
#include "GAnimation.h"
#include "GText.h"
#include "GButton.h"
#include "GComponent.h"
#include "GLabel.h"
#include "GTextInput.h"
#include "GRichText.h"
#include "GList.h"
#include "GGraph.h"
#include "GLoader.h"
#include "GProgressBar.h"

namespace fgui {

	cocos2d::Node* createObjectByType(ObjectType type)
	{
		switch (type)
		{
		case ObjectType::IMAGE:
			return GSprite::create();

		case ObjectType::MOVIECLIP:
			return GAnimation::create();

		case ObjectType::COMPONENT:
			return GComponent::create();

		case ObjectType::TEXT:
			return GLabel::create();

		case ObjectType::RICHTEXT:
			return GRichText::create();

		case ObjectType::INPUTTEXT:
			return GTextInput::create();

		case ObjectType::GROUP:
			return GGroup::create();

		case ObjectType::LIST:
			return GList::create();

		case ObjectType::GRAPH:
			return GGraph::create();

		case ObjectType::LOADER:
			return GLoader::create();

		case ObjectType::BUTTON:
			return GButton::create();

		case ObjectType::LABEL:
			return GText::create();

		case ObjectType::PROGRESSBAR:
			return GProgressBar::create();

		case ObjectType::SLIDER:
			return GSlider::create();

		case ObjectType::SCROLLBAR:
			return NULL;

		case ObjectType::COMBOBOX:
			return NULL;

		default:
			return nullptr;
		}
		return NULL;
	}

	GObject::GObject()
	:_pkgItem(NULL)
	,_uiPackage(NULL)
	,_isTouchEnabled(false)
	,m_listener(NULL)
	,m_nodeSelf(NULL)
	,_groupId(0)
	,_isGray(false)
	,_relations(NULL)
	, _isPivotAsAchorPoint(false)
	, m_blendMode(BlendMode::NORMAL)
	, _isHsvMode(false)
	, _isRelationValid(true)
	, _minSize(-1.0f,-1.0f)
	, _maxSize(-1.0f,-1.0f)
	, _item(NULL)
	, _objType(ObjectType::UNKNOWN)
	, _pkg(NULL)
	, _dataInfo(NULL){
		memset(m_gears, 0, sizeof(m_gears));
	}

	GObject::~GObject() {
		if (_uiPackage) {
			_uiPackage->release();
		}
		if (_relations) {
			_relations->release();
		}
		clearAllRelationObserver();
		if (_pkg) {
			_pkg->release();
		}
	}

	void GObject::onEnter() {

	}

	void GObject::onExit() {
		clearAllRelationObserver();
	}

	void GObject::addRelationObserver(RelationObserver* observer) {
		for (auto iter = m_relationObservers.begin(); iter != m_relationObservers.end(); ++iter) {
			if (*iter == observer) {
				return;
			}
		}
		m_relationObservers.push_back(observer);
	}

	void GObject::removeRelationObserver(RelationObserver* observer) {
		for (auto iter = m_relationObservers.begin(); iter != m_relationObservers.end(); ++iter) {
			if (*iter == observer) {
				m_relationObservers.erase(iter);
				return;
			}
		}
	}

	void GObject::setRelationIsValid(bool isRelationValid) {
		_isRelationValid = isRelationValid;
	}

	void GObject::clearAllRelationObserver() {
		if (m_relationObservers.size() > 0) {
			std::vector<RelationObserver*> tmp(m_relationObservers.size());
			std::copy(m_relationObservers.begin(), m_relationObservers.end(), tmp.begin());
			for (auto iter = tmp.begin(); iter != tmp.end(); ++iter) {
				(*iter)->onTargetExit(m_nodeSelf);
			}
			m_relationObservers.clear();
		}
	}

	void GObject::constructFromResource(UIPackage* pkg, PackageItem* pt) {
		_uiPackage = pkg;
		_pkgItem = pt;
		if (_uiPackage) {
			_uiPackage->retain();
		}
		m_nodeSelf = dynamic_cast<cocos2d::Node*>(this);
		m_nodeSelf->setCascadeOpacityEnabled(true);
		m_nodeSelf->setCascadeColorEnabled(true);
		m_nodeSelf->setAnchorPoint(cocos2d::Vec2(0, 1.0f));
		m_nodeSelf->setIgnoreAnchorPointForPosition(false);
		_relations = new Relations(m_nodeSelf);
	}

	void GObject::constructFromItem(Package* pkg, PkgItem* item) {
		_pkg = pkg;
		_item = item;
		_pkg->retain();
		m_nodeSelf = dynamic_cast<cocos2d::Node*>(this);
		m_nodeSelf->setCascadeOpacityEnabled(true);
		m_nodeSelf->setCascadeColorEnabled(true);
		_relations = new Relations(m_nodeSelf);
	}

	void GObject::setup(const ObjectInfo* info, cocos2d::Node* parent) {
		_dataInfo = info;
		_objType = info->objectType;
		_id = info->id;
		const cocos2d::Size& parentSize = parent->getContentSize();

		m_nodeSelf->setName(info->name);

		if (info->size) {
			m_nodeSelf->setContentSize(*info->size);
		}

		if (info->pivot) {
			m_nodeSelf->setAnchorPoint(*info->pivot);
			m_nodeSelf->setIgnoreAnchorPointForPosition(!info->bPivotAsAchorPoint);
		}
		else {
			m_nodeSelf->setAnchorPoint(cocos2d::Vec2(0, 1.0f));
			m_nodeSelf->setIgnoreAnchorPointForPosition(false);
		}

		if (parent) {
			const cocos2d::Size& parentSize = parent->getContentSize();
			if (!m_nodeSelf->isIgnoreAnchorPointForPosition()) {
				m_nodeSelf->setPosition(cocos2d::Vec2(info->pos.x, parentSize.height - info->pos.y));
			}
			else {
				const cocos2d::Size& selfSize = m_nodeSelf->getContentSize();
				m_nodeSelf->setPosition(cocos2d::Vec2(info->pos.x, (parentSize.height - info->pos.y) - selfSize.height));
			}
		}

		if (info->minSize && info->maxSize) {
			_minSize = *info->minSize;
			_maxSize = *info->maxSize;
		}
		if (info->scale) {
			m_nodeSelf->setScaleX(info->scale->x);
			m_nodeSelf->setScaleY(info->scale->y);
		}
		if (info->skew) {
			m_nodeSelf->setSkewX(info->skew->x);
			m_nodeSelf->setSkewY(-info->skew->y);
		}
		if (info->opacity != 1) {
			m_nodeSelf->setCascadeOpacityEnabled(true);
			m_nodeSelf->setOpacity(info->opacity * 255);
		}
		if (info->rotation != 0) {
			m_nodeSelf->setRotation(info->rotation);
		}
		if (!info->bVisible) {
			m_nodeSelf->setVisible(info->bVisible);
		}

		if (info->groupId >= 0) {
			_groupId = info->groupId;
			const cocos2d::Vector<cocos2d::Node*>& children = parent->getChildren();
			GGroup* group = dynamic_cast<GGroup*>(children.at(_groupId));
			if (group) {
				group->addNode(m_nodeSelf);
			}
		}

		for (size_t i = 0; i < info->gears.size(); i++) {
			GearInfo* gearInfo = info->gears[i];
			GearBase* gear = getGear((int)gearInfo->type);
			GComponent* comParent = dynamic_cast<GComponent*>(parent);
			gear->setup(gearInfo, comParent);
		}

		m_customData = info->customData;
	}

	void GObject::setupBefore(ByteBuffer* buffer, int beginPos, cocos2d::Node* parent) {
		cocos2d::Node* node = dynamic_cast<cocos2d::Node*>(this);
		if (!node) {
			return;
		}
		float f1, f2;

		buffer->Seek(beginPos, 0);
		buffer->Skip(5);

		_id = buffer->ReadS();
		std::string name = buffer->ReadS();
		node->setName(name);

		float posx = buffer->ReadInt();
		float posy = buffer->ReadInt();

		if (buffer->ReadBool()){
			cocos2d::Size s;
			s.width = buffer->ReadInt();
			s.height = buffer->ReadInt();
			node->setContentSize(s);
		}

		if (buffer->ReadBool()){
			_minSize.width = buffer->ReadInt();
			_maxSize.width = buffer->ReadInt();
			_minSize.height = buffer->ReadInt();
			_maxSize.height = buffer->ReadInt();
		}

		if (buffer->ReadBool()){
			f1 = buffer->ReadFloat();
			f2 = buffer->ReadFloat();
			node->setScale(f1, f2);
		}

		if (buffer->ReadBool()){
			f1 = buffer->ReadFloat();
			f2 = buffer->ReadFloat();
			node->setSkewX(f1);
			node->setSkewY(f2);
		}

		const cocos2d::Size& parentSize = parent->getContentSize();
		if (buffer->ReadBool()){
			f1 = buffer->ReadFloat();
			f2 = buffer->ReadFloat();
			node->setAnchorPoint(cocos2d::Vec2(f1, 1.0f - f2));
			_isPivotAsAchorPoint = buffer->ReadBool();
			m_nodeSelf->setIgnoreAnchorPointForPosition(false);
		}
		if (_isPivotAsAchorPoint) {
			node->setPosition(posx, parentSize.height - posy);
		}
		else {
			const cocos2d::Size& size = node->getContentSize();
			const cocos2d::Vec2& ap = node->getAnchorPoint();
			node->setPosition(posx + ap.x * size.width, parentSize.height - posy + (ap.y - 1.0f) * size.height);
		}

		f1 = buffer->ReadFloat();
		if (f1 != 1) {
			node->setCascadeOpacityEnabled(true);
			node->setOpacity(f1 * 255);
		}

		f1 = buffer->ReadFloat();
		if (f1 != 0) {
			node->setRotation(f1);
		}

		if (!buffer->ReadBool()) {
			node->setVisible(false);
		}
		
		bool isTouchEnabled = buffer->ReadBool();
		_isGray = buffer->ReadBool();

		BlendMode blendMode = (BlendMode)buffer->ReadByte(); //blendMode
		if (blendMode != BlendMode::NORMAL) {

		}

		bool isHsv = buffer->ReadBool(); //filter
		if (isHsv) {
			float f1 = buffer->ReadFloat();
			float f2 = buffer->ReadFloat();
			float f3 = buffer->ReadFloat();
			float f4 = buffer->ReadFloat();
			setHSVMode(isHsv);
			setHSVValue(f4, f3, f1, f2);
		}
		const std::string& str = buffer->ReadS();
		if (!str.empty()) {
			m_customData = cocos2d::Value(str);
		}
	}

	void GObject::setupAfter(ByteBuffer* buffer, int beginPos) {
		buffer->Seek(beginPos, 1);

		const std::string& str = buffer->ReadS();
		if (!str.empty()) {
			//setTooltips(str);
		}	

		int groupId = buffer->ReadShort();
		if (groupId >= 0) {
			_groupId = groupId;
			const cocos2d::Vector<cocos2d::Node*>& children = m_nodeSelf->getParent()->getChildren();
			GGroup* group = dynamic_cast<GGroup*>(children.at(groupId));
			if (group) {
				group->addNode(m_nodeSelf);
			}
		}

		buffer->Seek(beginPos, 2);

		int cnt = buffer->ReadShort();
		for (int i = 0; i < cnt; i++){
			int nextPos = buffer->ReadShort();
			nextPos += buffer->position;

			GearBase* gear = getGear(buffer->ReadByte());
			GComponent* parent = dynamic_cast<GComponent*>(m_nodeSelf->getParent());
			gear->setup(buffer,parent);

			buffer->position = nextPos;
		}

		if (_isGray) {
			setGrayed(_isGray);
		}
		if (_isTouchEnabled) {
			setTouchable(_isTouchEnabled);
		}
	}

	void GObject::setupExtend(ByteBuffer* buffer) {

	}

	void GObject::setupScroll(ByteBuffer* buffer) {

	}

	void GObject::setupOverflow(OverflowType overflow) {

	}

	void GObject::setGrayed(bool value) {
		_isGray = value;
	}

	void GObject::setHSVMode(bool isHsv) {
		if (_isHsvMode == isHsv) {
			return;
		}
		_isHsvMode = isHsv;
	}

	bool GObject::isHSVMode() {
		return _isHsvMode;
	}

	void GObject::setHSVValue(float hue, float saturation, float brightness, float contrast) {
		_hsvValue.set(hue, saturation, brightness, contrast);
	}

	const cocos2d::Vec4& GObject::getHSVValue() {
		return _hsvValue;
	}

	void GObject::onContentSizeChanged(cocos2d::Node* target, const cocos2d::Size& oldSize, const cocos2d::Size& newSize) {
		if (!_isRelationValid) {
			return;
		}
		if (_relations) {
			_relations->onOwnerSizeChanged(oldSize, newSize);
		}
		if (m_relationObservers.size() <= 0) {
			return;
		}
		std::vector<RelationObserver*> tmp(m_relationObservers.size());
		std::copy(m_relationObservers.begin(), m_relationObservers.end(), tmp.begin());
		for (auto iter = tmp.begin(); iter != tmp.end(); ++iter) {
			(*iter)->onTargetSizeChanged(target, oldSize, newSize);
		}
	}

	void GObject::onPositionChanged(cocos2d::Node* target, const cocos2d::Vec2& oldPos, const cocos2d::Vec2& newPos) {
		if (!_isRelationValid) {
			return;
		}
		if (_relations) {
			_relations->onTargetPosisitonChanged(target, oldPos, newPos);
		}
		if (m_relationObservers.size() <= 0) {
			return;
		}
		std::vector<RelationObserver*> tmp(m_relationObservers.size());
		std::copy(m_relationObservers.begin(), m_relationObservers.end(), tmp.begin());
		for (auto iter = tmp.begin(); iter != tmp.end(); ++iter) {
			(*iter)->onTargetPosisitonChanged(target, oldPos, newPos);
		}
	}

	GearBase* GObject::getGear(int index)
	{
		GearBase* gear = m_gears[index];
		if (gear == nullptr)
		{
			switch (index)
			{
			case 0:
				gear = new GearDisplay(this);
				break;
			case 1:
				gear = new GearXY(this);
				break;
			case 2:
				gear = new GearSize(this);
				break;
			case 3:
				gear = new GearLook(this);
				break;
			case 4:
				gear = new GearColor(this);
				break;
			case 5:
				gear = new GearAnimation(this);
				break;
			case 6:
				gear = new GearText(this);
				break;
			case 7:
				gear = new GearIcon(this);
				break;
			}
			m_gears[index] = gear;
		}
		return gear;
	}

	void GObject::updateGear(int index){
		GearBase* gear = m_gears[index];
		if (gear != nullptr && gear->getController() != nullptr) {
			gear->updateState();
		}
	}

	void GObject::updateGearFromRelations(int index, float dx, float dy){
		if (m_gears[index] != nullptr) {
			m_gears[index]->updateFromRelations(dx, dy);
		}
	}

	void GObject::onControllerChanged(GController* controller) {
		for (int i = 0; i < 8; i++){
			GearBase* gear = m_gears[i];
			if (gear != nullptr && gear->getController() == controller) {
				gear->apply();
			}
		}
	}

	void GObject::setTouchable(bool enabled) {
		if (_isTouchEnabled == enabled) {
			return;
		}
		_isTouchEnabled = enabled;
		if (_isTouchEnabled) {
			if (!m_listener) {
				m_listener = cocos2d::EventListenerTouchOneByOne::create();
				m_listener->onTouchBegan = std::bind(&GObject::onTouchBegin, this, std::placeholders::_1, std::placeholders::_2);
				m_listener->onTouchMoved = std::bind(&GObject::onTouchMoved, this, std::placeholders::_1, std::placeholders::_2);
				m_listener->onTouchEnded = std::bind(&GObject::onTouchEnded, this, std::placeholders::_1, std::placeholders::_2);
				m_listener->setSwallowTouches(true);
				m_nodeSelf->getEventDispatcher()->addEventListenerWithSceneGraphPriority(m_listener, m_nodeSelf);
			}
			else {
				m_listener->setEnabled(true);
			}
		}
		else if (!_isTouchEnabled && m_listener) {
			m_listener->setEnabled(false);
		}
	}

	void GObject::setSwallowTouch(bool bSwallow) {
		if (m_listener) {
			m_listener->setSwallowTouches(bSwallow);
		}
	}

	bool GObject::isSwallowTouch() const {
		if (m_listener) {
			return m_listener->isSwallowTouches();
		}
		return false;
	}

	void GObject::setBlendMode(BlendMode blend) {
		if (m_blendMode == blend) {
			return;
		}
		m_blendMode = blend;
	}

	void GObject::setTouchBeginCallback(std::function<bool(cocos2d::Touch*, cocos2d::Event*)> handler) {
		m_touchBeganHandler = handler;
	}
	
	void GObject::setTouchMovedCallback(std::function<void(cocos2d::Touch*, cocos2d::Event*)> handler) {
		m_touchMoveHandler = handler;
	}

	void GObject::setTouchEndedCallback(std::function<void(cocos2d::Touch*, cocos2d::Event*)> handler) {
		m_touchEndedHandler = handler;
	}

	void GObject::setTouchCancelCallback(std::function<void(cocos2d::Touch*, cocos2d::Event*)> handler) {
		m_touchCancelHandler = handler;
	}

	bool GObject::onTouchBegin(cocos2d::Touch* touch, cocos2d::Event* event) {
		if (m_touchBeganHandler) {
			return m_touchBeganHandler(touch, event);
		}
		else {
			cocos2d::Vec2 p = m_nodeSelf->getParent()->convertTouchToNodeSpace(touch);
			return m_nodeSelf->getBoundingBox().containsPoint(p);
		}
	}

	void GObject::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) {
		if (m_touchMoveHandler) {
			m_touchMoveHandler(touch, event);
		}
	}

	void GObject::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) {
		cocos2d::Vec2 p = m_nodeSelf->getParent()->convertTouchToNodeSpace(touch);
		bool ret = m_nodeSelf->getBoundingBox().containsPoint(p);
		if (ret) {
			if (m_touchEndedHandler) {
				m_touchEndedHandler(touch, event);
			}
		}
		else {
			if (m_touchCancelHandler) {
				m_touchCancelHandler(touch, event);
			}
		}
	}
}