#pragma once
#include "GObject.h"
#include "GComponent.h"

namespace fgui {
	class GLabel;
	class GTweener;
	struct ObjectInfo;

	class GProgressBar
		: public GComponent {
	public:
		CREATE_FUNC(GProgressBar);
		GProgressBar();
		~GProgressBar();
		void setTitleType(ProgressTitleType value);
		void setValue(double value);
		void setMax(double value);
		void setIsReverse(bool reverse);
		GTweener* tweenValue(double value, float duration);
		void update(double newValue);
	protected:
		virtual void setup(const ObjectInfo* inf, cocos2d::Node* parent);
	private: 
		ProgressTitleType _titleType;
		bool _reverse;
		GLabel* _title;
		cocos2d::Node* _barH;
		cocos2d::Node* _barV;
		float _barMaxWidth;
		float _barMaxHeight;
		double _value;
		double _max;
	};
}