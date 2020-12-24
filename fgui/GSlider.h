#pragma once

#include "fgui/GObject.h"
#include "fgui/GComponent.h"

namespace fgui {
	class GLabel;
	class GSlider
		: public GComponent
	{
	public:
		CREATE_FUNC(GSlider);
		GSlider();
		~GSlider();
		void setValue(float value);
		void setMax(float max);
		void setPercent(float percent);
		virtual void setupAfter(ByteBuffer* buffer, int pos);
		virtual void setupExtend(ByteBuffer* buffer);
		virtual void setup(const ObjectInfo* info, cocos2d::Node* parent);

		virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
		void setSlidingCallback(std::function<void(float)> handler);
		void update();
	private:
		float _value;
		float _max;
		float _barMaxWidth;
		float _barMaxHeight;
		ProgressTitleType _titleType;
		bool _reverse;
		GLabel* _title;
		cocos2d::Node* _barH;
		cocos2d::Node* _barV;
		cocos2d::Node* _grip;
		std::function<void(float)> _slidingHandler;
	};
}