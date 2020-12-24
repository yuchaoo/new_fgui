#pragma once

#include "cocos2d.h"
#include "UIPackage.h"

namespace fgui {
	class BitmapFont : public cocos2d::Font
	{
	public:
		BitmapFont();
		virtual ~BitmapFont();

		static BitmapFont* create();
		virtual int* getHorizontalKerningForTextUTF32(const std::u32string& text, int &outNumLetters) const;
		virtual cocos2d::FontAtlas *createFontAtlas() override { return _fontAtlas; }
		void releaseAtlas() { _fontAtlas->release(); }
		void setFontSize(float fontSize) {}
		int getOriginalFontSize()const { return _originalFontSize; }
		void setOriginalFontSize(int size) { _originalFontSize = size; }
		bool isResizable() { return _resizable; }
		void setIsResizeable(bool bResizeable) { _resizable = bResizeable; }
		bool canTint() { return _canTint; }
		void setIsTint(bool bTint) { _canTint = bTint; }
		void setFontAtlas(cocos2d::FontAtlas* fontAtlas) { _fontAtlas = fontAtlas; }
		cocos2d::FontAtlas* getFontAtlas() { return _fontAtlas; }
	private:
		float _originalFontSize;
		bool _resizable;
		bool _canTint;
		cocos2d::FontAtlas* _fontAtlas;

		friend class UIPackage;
	};

}
