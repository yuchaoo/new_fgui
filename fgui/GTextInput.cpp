#include "fgui/GTextInput.h"
#include "fgui/ByteBuffer.h"
#include "fgui/TextFormat.h"
#include "fgui/UIConfig.h"
#include "ObjectData.h"
#include "ComponentData.h"
using namespace cocos2d::ui;

namespace fgui {
	GTextInput::GTextInput()
	:_isSingleLine(true){
		_textFormat = new TextFormat();
	}

	GTextInput::~GTextInput() {
		delete _textFormat;
	}

	bool GTextInput::init() {
		EditBox::init();
		Scale9Sprite* sprite = Scale9Sprite::create("ty_sort_list.png");
		initWithSizeAndBackgroundSprite(cocos2d::Size(100,100), sprite);
		this->addChild(sprite);
		setDelegate(this);
		return true;
	}

	std::string GTextInput::getString() const
	{
		return _text;
	}

	void GTextInput::setString(const std::string& value)
	{
		if (_text != value) {
			_text = value;
			EditBox::setText(_text.c_str());
		}
	}

	void GTextInput::applyTextFormat()
	{
		setFontName(UIConfig::getRealFontName(_textFormat->face).c_str());
		setFontSize(_textFormat->fontSize);
		setPlaceholderFontSize(_textFormat->fontSize);
		setFontColor((cocos2d::Color3B)_textFormat->color);
	}

	bool GTextInput::isSingleLine() const
	{
		return _isSingleLine;
	}

	void GTextInput::setSingleLine(bool value)
	{
		_isSingleLine = value;
		if (_isSingleLine) {
			setInputMode(EditBox::InputMode::SINGLE_LINE);
		}
		else {
			setInputMode(EditBox::InputMode::ANY);
		}
	}

	void GTextInput::setPassword(bool value)
	{
		_password = value;
		if (_password) {
			setInputFlag(EditBox::InputFlag::PASSWORD);
		}
		else {
			setInputFlag(EditBox::InputFlag::SENSITIVE);
		}
	}

	void GTextInput::setupBefore(ByteBuffer* buffer, int pos, cocos2d::Node* parent) {
		GObject::setupBefore(buffer, pos, parent);
		buffer->Seek(pos, 5);

		_textFormat->face = buffer->ReadS();
		_textFormat->fontSize = buffer->ReadShort();
		_textFormat->color = buffer->ReadColor();
		_textFormat->align = (cocos2d::TextHAlignment)buffer->ReadByte();
		_textFormat->verticalAlign = (cocos2d::TextVAlignment)buffer->ReadByte();
		_textFormat->lineSpacing = buffer->ReadShort();
		_textFormat->letterSpacing = buffer->ReadShort();

		_ubbEnabled = buffer->ReadBool();

		AutoSizeType autoType = (AutoSizeType)buffer->ReadByte();

		_textFormat->underline = buffer->ReadBool();
		_textFormat->italics = buffer->ReadBool();
		_textFormat->bold = buffer->ReadBool();
		if (buffer->ReadBool()) {
			setSingleLine(true);
		}
		if (buffer->ReadBool()){
			_textFormat->outlineColor = buffer->ReadColor();
			_textFormat->outlineSize = buffer->ReadFloat();
			_textFormat->enableEffect(TextFormat::OUTLINE);
		}

		if (buffer->ReadBool()){
			_textFormat->shadowColor = buffer->ReadColor();
			float f1 = buffer->ReadFloat();
			float f2 = buffer->ReadFloat();
			_textFormat->shadowOffset = cocos2d::Vec2(f1, -f2);
			_textFormat->enableEffect(TextFormat::SHADOW);
		}
		applyTextFormat();

		if (buffer->ReadBool()) {
			
		}

		buffer->Seek(pos, 4);

		const std::string* str;
		if ((str = buffer->ReadSP())) {
			setPlaceHolder(str->c_str());
			CCLOG("%s",str->c_str());
		}
			
		if ((str = buffer->ReadSP())) {
			
		}
			
		int iv = buffer->ReadInt();
		if (iv != 0) {
			setMaxLength(iv);
		}
			
		iv = buffer->ReadInt();
		if (iv != 0) {
			
		}
			
		if (buffer->ReadBool()) {
			setPassword(true);
		}	
	}

	void GTextInput::setupAfter(ByteBuffer* buffer, int pos) {
		GObject::setupAfter(buffer, pos);
		buffer->Seek(pos, 6);

		const std::string& str = buffer->ReadS();
		setString(str);
		cocos2d::Size size = getContentSize();
		CCLOG("%s",str.c_str());
	}

	void GTextInput::setup(const ObjectInfo* inf, cocos2d::Node* parent) {
		GObject::setup(inf, parent);
		const TextInputInfo* info = dynamic_cast<const TextInputInfo*>(inf);
		*_textFormat = info->format;
		applyTextFormat();
		if (!info->placeHolder.empty()) {
			setPlaceHolder(info->placeHolder.c_str());
		}
		if (info->maxLength > 0) {
			setMaxLength(info->maxLength);
		}
		_ubbEnabled = info->bUbbEnabled;
		setSingleLine(info->bSingleLine);
		setPassword(info->bPassword);
	}

	void GTextInput::editBoxReturn(EditBox* editBox) {

	}

	void GTextInput::editBoxTextChanged(EditBox* editBox, const std::string& text) {
		_text.clear();
		_text.append(EditBox::getText());
	}
}