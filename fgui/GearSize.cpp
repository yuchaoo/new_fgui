#include "GearSize.h"
#include "GObject.h"
#include "ByteBuffer.h"
#include "TweenManager.h"
#include "Controller.h"
#include "GTweener.h"
#include "GComponent.h"
#include "GearData.h"

namespace fgui {

	GearSize::GearSize(GObject * owner) :GearBase(owner)
	{
	}

	GearSize::~GearSize()
	{
	}

	void GearSize::init()
	{
		const cocos2d::Size& size = _node->getContentSize();
		_default = cocos2d::Vec4(size.width, size.height,_node->getScaleX(), _node->getScaleY());
		_storage.clear();
	}

	void GearSize::addStatus(const std::string&  pageId, ByteBuffer* buffer)
	{
		cocos2d::Vec4 gv;
		gv.x = buffer->ReadInt();
		gv.y = buffer->ReadInt();
		gv.z = buffer->ReadFloat();
		gv.w = buffer->ReadFloat();

		if (pageId.size() == 0)
			_default = gv;
		else
			_storage[pageId] = gv;
	}

	void GearSize::apply()
	{
		cocos2d::Vec4 gv;
		auto it = _storage.find(_controller->getSelectedPageId());
		if (it != _storage.end())
			gv = it->second;
		else
			gv = _default;
		GComponent* comp = _controller->getParent();
		if (_tweenConfig && !comp->isConstructing()) {
			if (_tweenConfig->_tweener != nullptr){
				if (_tweenConfig->_tweener->endValue.getVec4() != gv){
					_tweenConfig->_tweener->kill(true);
					_tweenConfig->_tweener = nullptr;
				}
				else {
					return;
				}	
			}

			const cocos2d::Size& size = _node->getContentSize();
			bool a = gv.x != size.width || gv.y != size.height;
			bool b = gv.z != _node->getScaleX() || gv.w != _node->getScaleY();
			if (a || b){
				GTweener* tweener = TweenManager::getInstance()->createTween();
				const cocos2d::Size& size = _node->getContentSize();
				tweener->toVec4(cocos2d::Vec4(size.width, size.height, _node->getScaleX(), _node->getScaleY()), gv, _tweenConfig->duration);
				tweener->setDelay(_tweenConfig->delay);
				tweener->setEase(_tweenConfig->easeType);
				tweener->setTargetAny(this);
				tweener->setUserData(cocos2d::Value((a ? 1 : 0) + (b ? 2 : 0)));
				tweener->onUpdate(CC_CALLBACK_1(GearSize::onTweenUpdate, this));
				tweener->onComplete(CC_CALLBACK_0(GearSize::onTweenComplete, this));
				_tweenConfig->_tweener = tweener;
			}
		}
		else
		{
			_node->setContentSize(cocos2d::Size(gv.x, gv.y));
			_node->setScale(gv.z, gv.w);
		}
	}

	void GearSize::onTweenUpdate(GTweener* tweener)
	{
		int flag = tweener->getUserData().asInt();
		if ((flag & 1) != 0) {
			_node->setContentSize(cocos2d::Size(tweener->value.x, tweener->value.y));
		}
			
		if ((flag & 2) != 0) {
			_node->setScale(tweener->value.z, tweener->value.w);
		}
	}

	void GearSize::onTweenComplete()
	{
		_tweenConfig->_tweener = nullptr;
	}

	void GearSize::updateState()
	{
		const cocos2d::Size& size = _node->getContentSize();
		_storage[_controller->getSelectedPageId()] = cocos2d::Vec4(size.width, size.height,_node->getScaleX(), _node->getScaleY());
	}

	void GearSize::updateFromRelations(float dx, float dy)
	{
		if (_controller != nullptr && !_storage.empty())
		{
			for (auto it = _storage.begin(); it != _storage.end(); ++it)
			{
				it->second = cocos2d::Vec4(it->second.x + dx, it->second.y + dy,
					it->second.z, it->second.w);
			}
			_default.x += dx;
			_default.y += dy;

			updateState();
		}
	}

	void GearSize::initWithInfo(const GearInfo* inf) {
		const GearSizeInfo* info = dynamic_cast<const GearSizeInfo*>(inf);
		for (auto iter = info->values.begin(); iter != info->values.end(); ++iter) {
			_storage.insert(std::make_pair(iter->first, *iter->second));
		}
		if (info->defaultValue) {
			_default = *info->defaultValue;
		}
	}

}