#pragma once

#include "cocos2d.h"

namespace fgui {
	class TweenValue
	{
	public:
		float x;
		float y;
		float z;
		float w;
		double d;

		TweenValue();

		cocos2d::Vec2 getVec2() const;
		void setVec2(const cocos2d::Vec2& value);
		cocos2d::Vec3 getVec3() const;
		void setVec3(const cocos2d::Vec3& value);
		cocos2d::Vec4 getVec4() const;
		void setVec4(const cocos2d::Vec4& value);
		cocos2d::Color4B getColor() const;
		void setColor(const cocos2d::Color4B& value);
		float operator[] (int index) const;
		float& operator[] (int index);
		void setZero();
	};

}


