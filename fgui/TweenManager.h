#pragma once
#include <vector>
#include "FieldTypes.h"

namespace cocos2d {
	class Ref;
}

namespace fgui {
	class GTweener;

	class TweenManager
	{
	public:
		static TweenManager* getInstance();
		void init();
		GTweener* createTween();
		bool isTweening(cocos2d::Ref* target, TweenPropType propType);
		bool killTweens(cocos2d::Ref* target, TweenPropType propType, bool completed);
		GTweener* getTween(cocos2d::Ref* target, TweenPropType propType);
		void update(float dt);
		void clean();
	private:
		TweenManager();
		~TweenManager();
	private:
		GTweener** _activeTweens;
		std::vector<GTweener*> _tweenerPool;
		int _totalActiveTweens;
		int _arrayLength;
		bool _inited;
	};
}


