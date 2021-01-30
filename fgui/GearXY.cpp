#include "GearXY.h"
#include "GObject.h"
#include "ByteBuffer.h"
#include "Controller.h"
#include "GearBase.h"
#include "TweenManager.h"
#include "GTweener.h"
#include "GComponent.h"
#include "FguiUtils.h"
#include "GearData.h"

namespace fgui {

	GearXY::GearXY(GObject * owner) 
		: GearBase(owner)
		
	{

	}

	GearXY::~GearXY()
	{
	}

	void GearXY::init(){
		m_default = _node->getPosition();
		m_storage.clear();
	}

	void GearXY::addStatus(const std::string&  pageId, ByteBuffer* buffer){
		cocos2d::Vec2 gv;
		gv.x = buffer->ReadInt();
		gv.y = buffer->ReadInt();
		gv = coordF2C(gv, _node);

		if (pageId.size() == 0) {
			m_default = gv;
		}
		else {
			m_storage[pageId] = gv;
		}
	}

	void GearXY::apply()
	{
		cocos2d::Node* node = dynamic_cast<cocos2d::Node*>(_owner);

		cocos2d::Vec2 gv;
		auto it = m_storage.find(_controller->getSelectedPageId());
		if (it != m_storage.end()) {
			gv = it->second;
		}
		else {
			gv = m_default;
		}
		GComponent* comp = _controller->getParent();
		if (_tweenConfig && !comp->isConstructing()){
			if (_tweenConfig->_tweener != nullptr){
				if (_tweenConfig->_tweener->endValue.x != gv.x || _tweenConfig->_tweener->endValue.y != gv.y){
					_tweenConfig->_tweener->kill(true);
					_tweenConfig->_tweener = nullptr;
				}
				else {
					return;
				}
			}

			if (node->getPositionX() != gv.x || node->getPositionY() != gv.y){
				GTweener* tweener = TweenManager::getInstance()->createTween();
				tweener->toVec2(node->getPosition(), gv, _tweenConfig->duration);
				tweener->setDelay(_tweenConfig->delay);
				tweener->setEase(_tweenConfig->easeType);
				tweener->setTargetAny(this);
				tweener->onUpdate(CC_CALLBACK_1(GearXY::onTweenUpdate, this));
				tweener->onComplete(CC_CALLBACK_0(GearXY::onTweenComplete, this));
				_tweenConfig->_tweener = tweener;
			}
		}
		else
		{
			node->setPosition(gv);
		}
	}

	void GearXY::onTweenUpdate(GTweener* tweener)
	{
		_node->setPosition(_tweenConfig->_tweener->value.x, _tweenConfig->_tweener->value.y);
	}

	void GearXY::onTweenComplete()
	{
		_tweenConfig->_tweener = nullptr;
	}

	void GearXY::updateState()
	{
		m_storage[_controller->getSelectedPageId()] = _node->getPosition();
	}

	void GearXY::updateFromRelations(float dx, float dy)
	{
		if (_controller != nullptr && !m_storage.empty()){
			for (auto it = m_storage.begin(); it != m_storage.end(); ++it){
				it->second = cocos2d::Vec2(it->second.x + dx, it->second.y + dy);
			}
			m_default.x += dx;
			m_default.y += dy;
			updateState();
		}
	}
	void GearXY::initWithInfo(const GearInfo* inf) {
		const GearXYInfo* info = dynamic_cast<const GearXYInfo*>(inf);
		for (auto iter = info->values.begin(); iter != info->values.end(); ++iter) {
			m_storage.insert(std::make_pair(iter->first, coordF2C (*iter->second, _node)));
		}
		if (info->defaultValue) {
			m_default = coordF2C(*info->defaultValue, _node);
		}
	}
}