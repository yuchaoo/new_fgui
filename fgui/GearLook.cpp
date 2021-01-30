#include "GearLook.h"
#include "GObject.h"
#include "ByteBuffer.h"
#include "TweenManager.h"
#include "Controller.h"
#include "GTweener.h"
#include "GComponent.h"
#include "GearData.h"

namespace fgui {
	struct GearInfo;

	GearLookValue::GearLookValue() 
		:alpha(0), 
		rotation(0), 
		grayed(false), 
		touchable(false)
	{

	}

	GearLookValue::GearLookValue(float alpha, float rotation, bool grayed, bool touchable)
	{
		this->alpha = alpha;
		this->rotation = rotation;
		this->grayed = grayed;
		this->touchable = touchable;
	}

	GearLook::GearLook(GObject * owner) :GearBase(owner)
	{

	}

	GearLook::~GearLook()
	{
	}

	void GearLook::init()
	{
		_default = GearLookValue(_node->getOpacity(), _node->getRotation(), _owner->isGrayed(), _owner->isTouchable());
		_storage.clear();
	}

	void GearLook::addStatus(const std::string&  pageId, ByteBuffer* buffer)
	{
		GearLookValue gv;
		gv.alpha = buffer->ReadFloat();
		gv.rotation = buffer->ReadFloat();
		gv.grayed = buffer->ReadBool();
		gv.touchable = buffer->ReadBool();

		if (pageId.size() == 0)
			_default = gv;
		else
			_storage[pageId] = gv;
	}

	void GearLook::apply()
	{
		GearLookValue gv;
		auto it = _storage.find(_controller->getSelectedPageId());
		if (it != _storage.end())
			gv = it->second;
		else
			gv = _default;

		GComponent* comp = _controller->getParent();
		if (_tweenConfig && !comp->isConstructing()) {
			if (_tweenConfig->_tweener != nullptr)
			{
				if (_tweenConfig->_tweener->endValue.x != gv.alpha || _tweenConfig->_tweener->endValue.y != gv.rotation)
				{
					_tweenConfig->_tweener->kill(true);
					_tweenConfig->_tweener = nullptr;
				}
				else {
					return;
				}
			}

			bool a = gv.alpha != _node->getOpacity();
			bool b = gv.rotation != _node->getRotation();
			if (a || b){
				GTweener* tweener = TweenManager::getInstance()->createTween();
				tweener->toVec2(cocos2d::Vec2(_node->getOpacity(), _node->getRotation()), cocos2d::Vec2(gv.alpha * 255, gv.rotation), _tweenConfig->duration);
				tweener->setDelay(_tweenConfig->delay);
				tweener->setEase(_tweenConfig->easeType);
				tweener->setTargetAny(this);
				tweener->setUserData(cocos2d::Value((a ? 1 : 0) + (b ? 2 : 0)));
				tweener->onUpdate(CC_CALLBACK_1(GearLook::onTweenUpdate, this));
				tweener->onComplete(CC_CALLBACK_0(GearLook::onTweenComplete, this));
				_tweenConfig->_tweener = tweener;
			}
		}
		else
		{
			_node->setOpacity(GLbyte(gv.alpha * 255));
			_node->setRotation(gv.rotation);
		}
		_owner->setGrayed(gv.grayed);
		//_owner->setTouchable(gv.touchable);
	}

	void GearLook::onTweenUpdate(GTweener* tweener)
	{
		int flag = tweener->getUserData().asInt();
		if ((flag & 1) != 0)
			_node->setOpacity(tweener->value.x);
		if ((flag & 2) != 0)
			_node->setRotation(tweener->value.y);
	}

	void GearLook::onTweenComplete()
	{
		_tweenConfig->_tweener = nullptr;
	}

	void GearLook::updateState()
	{
		_storage[_controller->getSelectedPageId()] = GearLookValue(_node->getOpacity(), _node->getRotation(),
			_owner->isGrayed(), _owner->isTouchable());
	}

	void GearLook::initWithInfo(const GearInfo* inf){
		const GearLookInfo* info = dynamic_cast<const GearLookInfo*>(inf);
		for (auto iter = info->values.begin(); iter != info->values.end(); ++iter) {
			_storage.insert(std::make_pair(iter->first, *iter->second));
		}
		if (info->defaultValue) {
			_default = *info->defaultValue;
		}
	}



}