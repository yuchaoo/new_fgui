#pragma once
#include "base/CCRef.h"
#include "base/ccTypes.h"
#include <string>

namespace fgui {
	class TextFormat : public cocos2d::Ref
	{
	public:
		TextFormat();
		TextFormat(const TextFormat & other);
		TextFormat &operator =(const TextFormat & other);

		void setFormat(const TextFormat& format);
		void enableEffect(int effectFlag) { effect |= effectFlag; }
		void disableEffect(int effectFlag) { effect &= ~effectFlag; }
		bool hasEffect(int effectFlag) const { return (effect & effectFlag) != 0; }

		static const int OUTLINE = 1;
		static const int SHADOW = 2;
		static const int GLOW = 4;

		std::string face;
		float fontSize;
		cocos2d::Color4B color;
		bool bold;
		bool italics;
		bool underline;
		int lineSpacing;
		int letterSpacing;
		cocos2d::TextHAlignment align;
		cocos2d::TextVAlignment verticalAlign;

		int effect;
		cocos2d::Color4B outlineColor;
		int outlineSize;
		cocos2d::Color4B shadowColor;
		cocos2d::Size shadowOffset;
		int shadowBlurRadius;
		cocos2d::Color4B glowColor;

		//internal use
		bool _hasColor;
	};

}

