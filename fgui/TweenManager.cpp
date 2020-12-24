#include "TweenManager.h"
#include "GTweener.h"

namespace fgui {

	TweenManager* TweenManager::getInstance() {
		static TweenManager mgr;
		return &mgr;
	}

	TweenManager::TweenManager()
	:_inited(false)
	, _arrayLength(0)
	, _totalActiveTweens(0)
	, _activeTweens(NULL){

	}

	TweenManager::~TweenManager() {

	}

	GTweener* TweenManager::createTween()
	{
		if (!_inited) {
			init();
		}
			
		GTweener* tweener;
		int cnt = (int)_tweenerPool.size();
		if (cnt > 0){
			tweener = _tweenerPool[cnt - 1];
			_tweenerPool.pop_back();
		}
		else {
			tweener = new GTweener();
		}
			
		tweener->init();
		_activeTweens[_totalActiveTweens++] = tweener;

		if (_totalActiveTweens == _arrayLength){
			int newLen = _arrayLength + ceil(_arrayLength * 0.5f);
			GTweener** newArray = new GTweener*[newLen];
			memcpy(newArray, _activeTweens, _arrayLength * sizeof(GTweener*));
			delete _activeTweens;
			_activeTweens = newArray;
			_arrayLength = newLen;
		}
		return tweener;
	}

	bool TweenManager::isTweening(cocos2d::Ref * target, TweenPropType propType)
	{
		if (target == nullptr)
			return false;

		bool anyType = propType == TweenPropType::None;
		for (int i = 0; i < _totalActiveTweens; i++){
			GTweener* tweener = _activeTweens[i];
			if (tweener != nullptr && tweener->_target == target && !tweener->_killed 
				&& (anyType || tweener->_propType == propType))
				return true;
		}

		return false;
	}

	bool TweenManager::killTweens(cocos2d::Ref * target, TweenPropType propType, bool completed)
	{
		if (target == nullptr)
			return false;

		bool flag = false;
		int cnt = _totalActiveTweens;
		bool anyType = propType == TweenPropType::None;
		for (int i = 0; i < cnt; i++){
			GTweener* tweener = _activeTweens[i];
			if (tweener != nullptr && tweener->_target == target && !tweener->_killed
				&& (anyType || tweener->_propType == propType))
			{
				tweener->kill(completed);
				flag = true;
			}
		}

		return flag;
	}

	GTweener * TweenManager::getTween(cocos2d::Ref * target, TweenPropType propType)
	{
		if (target == nullptr)
			return nullptr;

		int cnt = _totalActiveTweens;
		bool anyType = propType == TweenPropType::None;
		for (int i = 0; i < cnt; i++){
			GTweener* tweener = _activeTweens[i];
			if (tweener != nullptr && tweener->_target == target && !tweener->_killed
				&& (anyType || tweener->_propType == propType))
			{
				return tweener;
			}
		}

		return nullptr;
	}

	void TweenManager::update(float dt)
	{
		int cnt = _totalActiveTweens;
		int freePosStart = -1;
		for (int i = 0; i < cnt; i++)
		{
			GTweener* tweener = _activeTweens[i];
			if (tweener == nullptr){
				if (freePosStart == -1)
					freePosStart = i;
			}
			else if (tweener->_killed){
				tweener->reset();
				_tweenerPool.push_back(tweener);
				_activeTweens[i] = nullptr;
				if (freePosStart == -1)
					freePosStart = i;
			}
			else{
				if (tweener->_refTarget != nullptr && tweener->_refTarget->getReferenceCount() == 1)
					tweener->_killed = true;
				else if (!tweener->_paused)
					tweener->update(dt);
				if (freePosStart != -1){
					_activeTweens[freePosStart] = tweener;
					_activeTweens[i] = nullptr;
					freePosStart++;
				}
			}
		}

		if (freePosStart >= 0){
			if (_totalActiveTweens != cnt){ //new tweens added
				int j = cnt;
				cnt = _totalActiveTweens - cnt;
				for (int i = 0; i < cnt; i++)
					_activeTweens[freePosStart++] = _activeTweens[j++];
			}
			_totalActiveTweens = freePosStart;
		}
	}

	void TweenManager::clean()
	{
		auto scheduler = cocos2d::Director::getInstance()->getScheduler();
		scheduler->unscheduleUpdate(this);

		for (auto it = _tweenerPool.begin(); it != _tweenerPool.end(); it++) {
			(*it)->release();
		}
		_tweenerPool.clear();
		
		_arrayLength = 0;
		delete _activeTweens;

		_inited = false;
	}

	void TweenManager::init()
	{
		_inited = true;
		if (_arrayLength <= 0) {
			_arrayLength = 30;
			_activeTweens = new GTweener*[_arrayLength];
		}
		auto scheduler = cocos2d::Director::getInstance()->getScheduler();
		scheduler->scheduleUpdate(this, 0, false);
	}

}