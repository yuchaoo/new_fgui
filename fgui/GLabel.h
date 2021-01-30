#pragma once
#include "GObject.h"
#include "2d/CCLabel.h"

namespace fgui {
	class TextFormat;

	class GLabel 
		: public cocos2d::Label
		, public fgui::GObject {
	public:
		CREATE_FUNC(GLabel);
		virtual void onEnter();
		virtual void onExit();

		virtual void setContentSize(const cocos2d::Size& size);
		TextFormat* getTextFormat();
		void setTextFormat(const TextFormat* format);
		virtual void applyTextFormat();
		virtual bool setBMFontFilePath(const std::string& bmfontFilePath, const cocos2d::Vec2& imageOffset = cocos2d::Vec2::ZERO, float fontSize = 0);

		void setFontSize(int size);
		int getFontSize() const ;
		void setFontName(const std::string& name);
		const std::string& getFontName() const;
		void setFontColor(const cocos2d::Color4B& color);
		const cocos2d::Color4B& getFontColor() const;

		void setAutoSize(AutoSizeType autoSize);
		void setSingleLine(bool bSingleLine);
		void setUnderLine(bool bUnderLine);
		bool isUnderLine();
		void setBold(bool bBold);
		bool isBold();
		void setItalics(bool bItalics);
		bool isItalics();
		void setOutline(const cocos2d::Color4B& outlineColor, int outlineSize);
		bool hasOutline();
		void setShadow(const cocos2d::Color4B& shadowColor, const cocos2d::Size& offset = cocos2d::Size(2,-2), int blurRadius = 0);
		bool hasShadow();
		void setGlow(const cocos2d::Color4B& glowColor);
		bool isGlow();
		void setHAlign(cocos2d::TextHAlignment hAlign);
		void setVAlign(cocos2d::TextVAlignment vAlign);

		virtual void setString(const std::string& text);
		virtual void setPosition(float x, float y);
	public:
		virtual void setGrayed(bool value);
		virtual void updateBMFontScale() override;
	protected:
		virtual void updateContent();
		virtual void setup(const ObjectInfo* inf, cocos2d::Node* parent);
	private:
		GLabel();
		~GLabel();
	private:
		TextFormat* _textFormat;
		bool _bmFontCanTint;
		bool _bUpdateContentSize;
		bool _bSingleLine;
	};
}