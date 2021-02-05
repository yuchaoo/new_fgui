#include "GTextInput.h"
#include "ByteBuffer.h"
#include "TextFormat.h"
#include "UIConfig.h"
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
		Scale9Sprite* sprite = Scale9Sprite::create();
		initWithSizeAndBackgroundSprite(cocos2d::Size(100,100), sprite);
		sprite->setAnchorPoint(cocos2d::Vec2(0, 1.0f));
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
		setTextHorizontalAlignment(_textFormat->align);
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