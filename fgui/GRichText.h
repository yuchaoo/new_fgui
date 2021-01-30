#pragma once

#include "cocos2d.h"
#include "GObject.h"
#include "TextFormat.h"
#include "platform/CCSAXParser.h"

namespace fgui {
	class GXMLVisitor;
	class GRichElement;
	class GSprite;
	class GLabel;
	class GLoader;

	class GRichElement
	{
	public:
		enum class Type
		{
			TEXT,
			IMAGE,
			LINK
		};

		GRichElement(Type type);
		virtual ~GRichElement() {};

		Type _type;
		std::string text;
		TextFormat textFormat;
		int width;
		int height;
		GRichElement* link;
	};

	class GRichText;
	class GXMLVisitor : public cocos2d::SAXDelegator
	{
	public:
		explicit GXMLVisitor(GRichText* richText);
		virtual ~GXMLVisitor();

		virtual void startElement(void* ctx, const char* name, const char** atts) override;
		virtual void endElement(void* ctx, const char* name) override;
		virtual void textHandler(void* ctx, const char* s, size_t len) override;

	private:
		cocos2d::ValueMap tagAttrMapWithXMLElement(const char** attrs);
		int attributeInt(const cocos2d::ValueMap& vm, const std::string& key, int defaultValue);

		void pushTextFormat();
		void popTextFormat();
		void addNewLine(bool check);
		void finishTextBlock();

		GRichText* _richText;
		std::vector<TextFormat> _textFormatStack;
		std::vector<GRichElement*> _linkStack;
		TextFormat _format;
		size_t _textFormatStackTop;
		int _skipText;
		bool _ignoreWhiteSpace;
		std::string _textBlock;
	};

	class GRichText : public cocos2d::Node , public GObject
	{
	public:
		GRichText();
		virtual ~GRichText();

		CREATE_FUNC(GRichText);
		virtual void onEnter();
		virtual void onExit();

		const cocos2d::Size& getDimensions() const { return _dimensions; }
		void setDimensions(float width, float height);

		void setString(const std::string& value);
		void setAutoSize(AutoSizeType value);

		TextFormat* getTextFormat() const { return _textFormat; }
		void setTextFormat(const TextFormat* format);

		bool isTextUnderline() { return _textUnderline; }
		void setTextUnderline(bool enable);

		const cocos2d::Color4B& getFontColor() { return _fontColor; }
		void setFontColor(const cocos2d::Color4B& color);

		virtual void visit(cocos2d::Renderer* renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags) override;

		virtual const cocos2d::Size& getContentSize();
		virtual void setContentSize(const cocos2d::Size& size);
		virtual void setPosition(float x, float y);

	protected:
		virtual void setup(const ObjectInfo* inf, cocos2d::Node* parent);
		virtual bool init() override;
		void updateFormatText();
		void addNewLine();
		GLabel* createLabel(GRichElement* element, const TextFormat& format, const std::string& text);
		GLoader* createLoader(GRichElement* element);
		void addLabelAtCurLine(GRichElement* element, const TextFormat& format, const std::string& text);
		void addImageAtCurLine(GRichElement* element);
		void adjustLineNodePosition();
	private:
		std::vector<GRichElement*> _richElements;
		std::vector<std::vector<Node*>> _elementRenders;
		bool _formatTextDirty;
		bool _textChanged;
		bool _textUnderline;
		bool _ubbEnabled;

		cocos2d::Size _dimensions;
		cocos2d::Color4B _fontColor;
		std::string _text;
		TextFormat* _textFormat;
		AutoSizeType _autoSize;
		
		float _curPosX, _curPosY;
		float _curLineLeftWidth;
		float _totalHeight;
		std::vector<std::vector<cocos2d::Node*>> _lines;

		friend class GXMLVisitor;
	};

}

