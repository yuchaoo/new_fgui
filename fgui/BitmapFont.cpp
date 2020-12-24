#include "BitmapFont.h"

namespace fgui {
	BitmapFont::BitmapFont() :_fontAtlas(nullptr), _originalFontSize(0), _resizable(false)
	{
	}

	BitmapFont::~BitmapFont()
	{
	}

	BitmapFont * BitmapFont::create()
	{
		BitmapFont *font = new BitmapFont();
		font->autorelease();

		return font;
	}

	int * BitmapFont::getHorizontalKerningForTextUTF32(const std::u32string & text, int & outNumLetters) const
	{
		return nullptr;
	}
}