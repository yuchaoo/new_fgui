#include "GRichText.h"
#include <sstream>
#include <vector>
#include <locale>
#include <algorithm>

#include "ToolSet.h"
#include "TextFormat.h"
#include "GLabel.h"
#include "GSprite.h"
#include "GLoader.h"
#include "PackageManager.h"
#include "PkgItem.h"
#include "ComponentData.h"

namespace fgui {
	USING_NS_CC;

	using namespace std;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
#define strcasecmp _stricmp
#endif

	static const int GUTTER_X = 2;
	static const int GUTTER_Y = 2;

	static int getPrevWord(const std::string& text, int idx)
	{
		// start from idx-1
		for (int i = idx - 1; i >= 0; --i)
		{
			if (!std::isalnum(text[i], std::locale()))
				return i;
		}
		return -1;
	}

	static bool isWrappable(const std::string& text)
	{
		for (size_t i = 0, size = text.length(); i < size; ++i)
		{
			if (!std::isalnum(text[i], std::locale()))
				return true;
		}
		return false;
	}

	static float getPaddingAmount(TextHAlignment alignment, const float leftOver) {
		switch (alignment) {
		case TextHAlignment::CENTER:
			return leftOver / 2.f;
		case TextHAlignment::RIGHT:
			return leftOver;
		default:
			CCASSERT(false, "invalid horizontal alignment!");
			return 0.f;
		}
	}

	static bool isWhitespace(char c) {
		return std::isspace(c, std::locale());
	}

	static void ltrim(std::string& s) {
		s.erase(s.begin(), std::find_if_not(s.begin(),
			s.end(),
			isWhitespace));
	}

	static void rtrim(std::string& s) {
		s.erase(std::find_if_not(s.rbegin(),
			s.rend(),
			isWhitespace).base(),
			s.end());
	}

	static float stripTrailingWhitespace(const std::vector<cocos2d::Node*>& row) {
		if (!row.empty()) {
			if (auto label = dynamic_cast<Label*>(row.back())) {
				const auto width = label->getContentSize().width;
				auto str = label->getString();
				rtrim(str);
				if (label->getString() != str) {
					label->setString(str);
					return label->getContentSize().width - width;
				}
			}
		}
		return 0.0f;
	}

	static std::string getSubStringOfUTF8String(const std::string& str, std::string::size_type start, std::string::size_type length)
	{
		std::u32string utf32;
		if (!StringUtils::UTF8ToUTF32(str, utf32)) {
			CCLOGERROR("Can't convert string to UTF-32: %s", str.c_str());
			return "";
		}
		if (utf32.size() < start) {
			CCLOGERROR("'start' is out of range: %ld, %s", static_cast<long>(start), str.c_str());
			return "";
		}
		std::string result;
		if (!StringUtils::UTF32ToUTF8(utf32.substr(start, length), result)) {
			CCLOGERROR("Can't convert internal UTF-32 string to UTF-8: %s", str.c_str());
			return "";
		}
		return result;
	}

	

	GRichElement::GRichElement(Type type) :
		_type(type),
		width(0),
		height(0),
		link(nullptr)
	{
	};


	GXMLVisitor::GXMLVisitor(GRichText* richText)
		: _richText(richText),
		_textFormatStackTop(0),
		_skipText(0),
		_ignoreWhiteSpace(false)
	{
		_format = *_richText->_textFormat;
	}

	GXMLVisitor::~GXMLVisitor()
	{
	}

	void GXMLVisitor::pushTextFormat()
	{
		if (_textFormatStack.size() <= _textFormatStackTop)
			_textFormatStack.push_back(_format);
		else
			_textFormatStack[_textFormatStackTop] = _format;
		_textFormatStackTop++;
	}

	void GXMLVisitor::popTextFormat()
	{
		if (_textFormatStackTop > 0)
		{
			_format = _textFormatStack[_textFormatStackTop - 1];
			_textFormatStackTop--;
		}
	}

	void GXMLVisitor::addNewLine(bool check)
	{
		GRichElement* lastElement = _richText->_richElements.empty() ? nullptr : _richText->_richElements.back();
		if (lastElement && lastElement->_type == GRichElement::Type::TEXT)
		{
			if (!check || lastElement->text.back() != '\n')
				lastElement->text += "\n";
			return;
		}

		GRichElement* element = new GRichElement(GRichElement::Type::TEXT);
		element->textFormat = _format;
		element->text = "\n";
		_richText->_richElements.push_back(element);
		if (!_linkStack.empty())
			element->link = _linkStack.back();
	}

	void GXMLVisitor::finishTextBlock()
	{
		if (!_textBlock.empty())
		{
			GRichElement* element = new GRichElement(GRichElement::Type::TEXT);
			element->textFormat = _format;
			element->text = _textBlock;
			_textBlock.clear();
			_richText->_richElements.push_back(element);
			if (!_linkStack.empty())
				element->link = _linkStack.back();
		}
	}

	void GXMLVisitor::startElement(void* /*ctx*/, const char *elementName, const char **atts)
	{
		finishTextBlock();

		if (strcasecmp(elementName, "b") == 0)
		{
			pushTextFormat();
			_format.bold = true;
		}
		else if (strcasecmp(elementName, "i") == 0)
		{
			pushTextFormat();
			_format.italics = true;
		}
		else if (strcasecmp(elementName, "u") == 0)
		{
			pushTextFormat();
			_format.underline = true;
		}
		else if (strcasecmp(elementName, "font") == 0)
		{
			pushTextFormat();
			ValueMap&& tagAttrValueMap = tagAttrMapWithXMLElement(atts);
			_format.fontSize = attributeInt(tagAttrValueMap, "size", _format.fontSize);

			auto it = tagAttrValueMap.find("color");
			if (it != tagAttrValueMap.end())
			{
				_format.color = ToolSet::convertFromHtmlColor(it->second.asString().c_str());
				_format._hasColor = true;
			}
			it = tagAttrValueMap.find("underline");
			if (it != tagAttrValueMap.end()) {
				_format.underline = true;
			}
		}
		else if (strcasecmp(elementName, "br") == 0)
		{
			addNewLine(false);
		}
		else if (strcasecmp(elementName, "img") == 0)
		{
			std::string src;
			ValueMap&& tagAttrValueMap = tagAttrMapWithXMLElement(atts);

			int width = 0;
			int height = 0;

			auto it = tagAttrValueMap.find("src");
			if (it != tagAttrValueMap.end()) {
				src = it->second.asString();
			}

			if (!src.empty()) {
				//PackageItem* pi = PackageManager::getInstance()->getPackageItemByURL(src);
				ImageItem* item = (ImageItem*)PackageManager::getInstance()->getItemByUrl(src);
				if (item)
				{
					width = item->getSize().width;
					height = item->getSize().height;
				}
			}

			width = attributeInt(tagAttrValueMap, "width", width);
			height = attributeInt(tagAttrValueMap, "height", height);
			if (width == 0)
				width = 5;
			if (height == 0)
				height = 10;

			GRichElement* element = new GRichElement(GRichElement::Type::IMAGE);
			element->width = width;
			element->height = height;
			element->text = src;
			_richText->_richElements.push_back(element);
			if (!_linkStack.empty())
				element->link = _linkStack.back();
		}
		else if (strcasecmp(elementName, "a") == 0)
		{
			pushTextFormat();

			std::string href;
			ValueMap&& tagAttrValueMap = tagAttrMapWithXMLElement(atts);
			auto it = tagAttrValueMap.find("href");
			if (it != tagAttrValueMap.end())
				href = it->second.asString();

			GRichElement* element = new GRichElement(GRichElement::Type::LINK);
			element->text = href;
			_richText->_richElements.push_back(element);
			_linkStack.push_back(element);

			if (_richText->_textUnderline)
				_format.underline = true;
			if (!_format._hasColor)
				_format.color = _richText->_fontColor;
		}
		else if (strcasecmp(elementName, "p") == 0 || strcasecmp(elementName, "ui") == 0 || strcasecmp(elementName, "div") == 0
			|| strcasecmp(elementName, "li") == 0)
		{
			addNewLine(true);
		}
		else if (strcasecmp(elementName, "html") == 0 || strcasecmp(elementName, "body") == 0)
		{
			//full html
			_ignoreWhiteSpace = true;
		}
		else if (strcasecmp(elementName, "head") == 0 || strcasecmp(elementName, "style") == 0 || strcasecmp(elementName, "script") == 0
			|| strcasecmp(elementName, "form") == 0)
		{
			_skipText++;
		}
	}

	void GXMLVisitor::endElement(void* /*ctx*/, const char *elementName)
	{
		finishTextBlock();

		if (strcasecmp(elementName, "b") == 0 || strcasecmp(elementName, "i") == 0 || strcasecmp(elementName, "u") == 0
			|| strcasecmp(elementName, "font") == 0)
		{
			popTextFormat();
		}
		else if (strcasecmp(elementName, "a") == 0)
		{
			popTextFormat();

			if (!_linkStack.empty())
				_linkStack.pop_back();
		}
		else if (strcasecmp(elementName, "head") == 0 || strcasecmp(elementName, "style") == 0 || strcasecmp(elementName, "script") == 0
			|| strcasecmp(elementName, "form") == 0)
		{
			_skipText--;
		}
	}

	void GXMLVisitor::textHandler(void* /*ctx*/, const char *str, size_t len)
	{
		if (_skipText != 0)
			return;

		if (_ignoreWhiteSpace)
		{
			string s(str, len);
			ltrim(s);
			rtrim(s);
			_textBlock += s;
		}
		else
			_textBlock += string(str, len);
	}

	ValueMap GXMLVisitor::tagAttrMapWithXMLElement(const char ** attrs)
	{
		ValueMap tagAttrValueMap;
		for (const char** attr = attrs; *attr != nullptr; attr = (attrs += 2)) {
			if (attr[0] && attr[1]) {
				tagAttrValueMap[attr[0]] = attr[1];
			}
		}
		return tagAttrValueMap;
	}

	int GXMLVisitor::attributeInt(const ValueMap& valueMap, const std::string& key, int defaultValue)
	{
		auto it = valueMap.find(key);
		if (it != valueMap.end()) {
			string str = it->second.asString();
			if (!str.empty() && str.back() == '%')
				return ceil(atoi(str.substr(0, str.size() - 1).c_str()) / 100.0f*defaultValue);
			else
				return atoi(str.c_str());
		}
		else
			return defaultValue;
	}

	/***************************************************************/

	GRichText::GRichText() :
		_formatTextDirty(true),
		_textChanged(false),
		_textUnderline(true),
		_fontColor(Color3B::BLUE)
	{
		_textFormat = new TextFormat();
	}

	GRichText::~GRichText()
	{
		for (auto &it : _richElements)
			delete it;
		delete _textFormat;
	}

	bool GRichText::init()
	{
		if (!Node::init())
			return false;

		return true;
	}

	void GRichText::onEnter() {
		Node::onEnter();
		GObject::onEnter();
	}

	void GRichText::onExit() {
		Node::onExit();
		GObject::onExit();
	}

	void GRichText::setAutoSize(AutoSizeType value) {
		if (_autoSize == value) {
			return;
		}
		const cocos2d::Size& size = getContentSize();
		_autoSize = value;
		switch (value)
		{
		case AutoSizeType::NONE:
			this->setDimensions(size.width, size.height);
			break;
		case AutoSizeType::BOTH:
			this->setDimensions(0, 0);
			break;
		case AutoSizeType::HEIGHT:
			this->setDimensions(size.width, 0);
			break;
		case AutoSizeType::SHRINK:
			this->setDimensions(size.width, 0);
			break;
		}
	}

	void GRichText::setup(const ObjectInfo* inf, cocos2d::Node* parent) {
		GObject::setup(inf, parent);
		const RichTextInfo* info = dynamic_cast<const RichTextInfo*>(inf);
		setAutoSize(info->autoSizeType);
		_ubbEnabled = info->bUbbEnabled;
		setTextFormat(&(info->format));
		if (!info->str.empty()) {
			setString(info->str);
		}
	}

	void GRichText::setDimensions(float width, float height)
	{
		if (width != _dimensions.width || height != _dimensions.width) {
			_formatTextDirty = true;
			_dimensions.setSize(width, height);
		}
	}

	void GRichText::setString(const std::string & value)
	{
		if (_text != value) {
			_formatTextDirty = true;
			_textChanged = true;
			_text = value;
		}
	}

	void GRichText::setTextFormat(const TextFormat* format) {
		_textChanged = true;
		_formatTextDirty = true;
		_textFormat->setFormat(*format);
	}

	const Size & GRichText::getContentSize()
	{
		if (_formatTextDirty) {
			updateFormatText();
		}
		return Node::getContentSize();
	}

	void GRichText::setContentSize(const cocos2d::Size& size) {
		cocos2d::Size oldSize = getContentSize();
		if (oldSize.equals(size)) {
			return;
		}
		Node::setContentSize(size);
		onContentSizeChanged(this, oldSize, size);
	}

	void GRichText::setPosition(float x, float y) {
		cocos2d::Vec2 oldPos = getPosition();
		cocos2d::Vec2 pos(x, y);
		if (oldPos.equals(pos)) {
			return;
		}
		Node::setPosition(x,y);
		onPositionChanged(this, oldPos, pos);
	}

	void GRichText::setTextUnderline(bool enable)
	{
		if (_textUnderline != enable)
		{
			_textUnderline = enable;
			_formatTextDirty = true;
		}
	}

	void GRichText::setFontColor(const cocos2d::Color4B & color)
	{
		_fontColor = color;
		_formatTextDirty = true;
	}

	void GRichText::visit(cocos2d::Renderer * renderer, const cocos2d::Mat4 & parentTransform, uint32_t parentFlags)
	{
		if (_visible) {
			updateFormatText();
		}
		Node::visit(renderer, parentTransform, parentFlags);
	}

	void GRichText::addNewLine() {
		if (_autoSize == AutoSizeType::BOTH) {
			_curLineLeftWidth = FLT_MAX;
		}
		else {
			_curLineLeftWidth = _dimensions.width;
		}
		_lines.push_back(std::vector<cocos2d::Node*>());
	}

	GLabel* GRichText::createLabel(GRichElement* element, const TextFormat& format, const std::string& text) {
		GLabel* textRenderer = GLabel::create();
		textRenderer->setCascadeOpacityEnabled(true);
		textRenderer->setCascadeColorEnabled(true);
		textRenderer->setAutoSize(AutoSizeType::BOTH);
		textRenderer->setString(text);
		textRenderer->setTextFormat(&format);
		
		const cocos2d::Size& size = textRenderer->getContentSize();
		textRenderer->setUserData(element);
		return textRenderer;
	}

	GLoader* GRichText::createLoader(GRichElement* element) {
		GLoader* loader = GLoader::create();
		loader->setLoadFillType(LoaderFillType::SCALE_FREE);
		loader->setContentSize(cocos2d::Size(element->width, element->height));
		loader->setURL(element->text);
		loader->setAnchorPoint(cocos2d::Vec2(0,0));
		return loader;
	}

	void GRichText::addLabelAtCurLine(GRichElement* element, const TextFormat& format, const std::string& text) {
		GLabel* label = createLabel(element, format, text);
		float width = label->getContentSize().width;
		if (_curLineLeftWidth >= width) {
			_lines.back().push_back(label);
			_curLineLeftWidth -= width;
			return;
		}
		for (int i = text.size() - 2; i >= 0; --i) {
			std::string str = getSubStringOfUTF8String(text,0, i + 1);
			label->setString(str);
			if (label->getContentSize().width <= _curLineLeftWidth) {
				_lines.back().push_back(label);
				addNewLine();
				std::string leftStr = getSubStringOfUTF8String(text, i + 1, text.size() - i - 1);
				addLabelAtCurLine(element, format, leftStr);
				return;
			}
		}
		std::string str = getSubStringOfUTF8String(text, 0, 1);
		label->setString(str);
		_lines.back().push_back(label);
		addNewLine();
	}

	void GRichText::addImageAtCurLine(GRichElement* element) {
		GLoader* loader = createLoader(element);
		if (_curLineLeftWidth >= element->width) {
			_lines.back().push_back(loader);
		}
		else {
			addNewLine();
			_lines.back().push_back(loader);
			_curLineLeftWidth -= element->width;
		}
	}

	void GRichText::adjustLineNodePosition() {
		float maxWidth = 0, totalHeight = 0.0f;
		std::vector<float> linesWidth(_lines.size());
		std::vector<float> linesHeight(_lines.size());

		for (size_t i = 0; i < _lines.size(); ++i) {
			float lineHeight = 0.0f, lineWidth = 0.0f;
			for (size_t j = 0; j < _lines[i].size(); ++j) {
				const cocos2d::Size& size = _lines[i][j]->getContentSize();
				if (lineHeight < size.height) {
					lineHeight = size.height;
				}
				lineWidth += size.width;
			}

			if (_dimensions.height > 0 && totalHeight + lineHeight > _dimensions.height && i > 0) {
				_lines.resize(i);
				break;
			}

			linesWidth[i] = lineWidth;
			linesHeight[i] = lineHeight;

			if (maxWidth < lineWidth) {
				maxWidth = lineWidth;
			}
			totalHeight += lineHeight;
		}

		for (size_t i = 0; i < _lines.size(); ++i) {
			for (size_t j = 0; j < _lines[i].size(); ++j) {
				addChild(_lines[i][j]);
			}
		}

		float width = _dimensions.width > 0 ? _dimensions.width : maxWidth;
		float height = _dimensions.height > 0 ? _dimensions.height : totalHeight;
		float offsetY = height;
		if (_textFormat->verticalAlign == TextVAlignment::CENTER) {
			offsetY = height - (height - totalHeight) / 2;
		}
		else if (_textFormat->verticalAlign == TextVAlignment::BOTTOM) {
			offsetY = height - (height - totalHeight);
		}

		for (size_t i = 0; i < _lines.size(); ++i) {
			float offsetX = 0.0f;
			if (_textFormat->align == TextHAlignment::CENTER) {
				offsetX = (width- linesWidth[i]) / 2;
			}
			else if (_textFormat->align == TextHAlignment::RIGHT) {
				offsetX = width - linesWidth[i];
			}
			
			for (size_t j = 0; j < _lines[i].size(); j++) {
				const cocos2d::Size& size = _lines[i][j]->getContentSize();
				_lines[i][j]->setAnchorPoint(cocos2d::Vec2(0,0));
				_lines[i][j]->setIgnoreAnchorPointForPosition(false);
				//_lines[i][j]->setPosition(offsetX,offsetY - linesHeight[i] + (linesHeight[i]- size.height)/2);
				_lines[i][j]->setPosition(offsetX, offsetY - linesHeight[i]);
				offsetX += size.width;
			}
			offsetY -= linesHeight[i];
		}

		this->setContentSize(cocos2d::Size(width, height));
	}

	void GRichText::updateFormatText() {
		if (!_formatTextDirty) {
			return;
		}
		_formatTextDirty = false;
		if (_textChanged) {
			_textChanged = false;
			_totalHeight = 0;
			for (auto& it : _richElements) {
				delete it;
			}
			_richElements.clear();
			if (!_text.empty()) {
				std::string xmlText = "<dummy>" + _text + "</dummy>";
				GXMLVisitor visitor(this);
				SAXParser parser;
				parser.setDelegator(&visitor);
				parser.parseIntrusive(&xmlText.front(), xmlText.length());
			}
		}

		_lines.clear();
		removeAllChildrenWithCleanup(true);
		addNewLine();

		for (size_t i = 0; i < _richElements.size(); ++i) {
			GRichElement* element = static_cast<GRichElement*>(_richElements.at(i));
			if (element->_type == fgui::GRichElement::Type::TEXT) {
				FastSplitter fs;
				fs.start(element->text.c_str(), (int)element->text.size(), '\n');
				bool first = true;
				while (fs.next()) {
					if (!first) {
						addNewLine();
					}
					std::string text(fs.getText(), fs.getTextLength());
					addLabelAtCurLine(element, element->textFormat, text);
					first = false;
				}
			}
			else if (element->_type == fgui::GRichElement::Type::IMAGE) {
				addImageAtCurLine(element);
			}
		}
		adjustLineNodePosition();
	}
}