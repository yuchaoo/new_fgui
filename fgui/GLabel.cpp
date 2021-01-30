#include "GLabel.h"
#include "UIConfig.h"
#include "PackageManager.h"
#include "BitmapFont.h"
#include "PkgItem.h"
#include "FguiUtils.h"
#include "ComponentData.h"

static cocos2d::Color3B toGrayed(const cocos2d::Color3B& source)
{
	cocos2d::Color3B c = source;
	c.r = c.g = c.b = c.r*0.299f + c.g*0.587f + c.b*0.114f;
	return c;
}

static cocos2d::Color4B toGrayed(const cocos2d::Color4B& source)
{
	cocos2d::Color4B c = source;
	c.r = c.g = c.b = c.r * 0.299f + c.g * 0.587f + c.b * 0.114f;

	return c;
}


namespace fgui {
	GLabel::GLabel()
	:_bmFontCanTint(false)
	, _bUpdateContentSize(false)
	, _bSingleLine(false){
		_textFormat = new TextFormat;
	}

	GLabel::~GLabel() {
		delete _textFormat;
	}

	void GLabel::onEnter() {
		Label::onEnter();
		GObject::onEnter();
	}

	void GLabel::onExit() {
		Label::onExit();
		GObject::onExit();
	}

	void GLabel::setContentSize(const cocos2d::Size& size) {
		if (_bUpdateContentSize) {
			Label::setContentSize(size);
			return;
		}
		cocos2d::Size oldSize = getContentSize();
		Label::setContentSize(size);
		const cocos2d::Size& newSize = getContentSize();
		if (!oldSize.equals(newSize)) {
			GObject::onContentSizeChanged(this, oldSize, newSize);
		}
	}

	void GLabel::setup(const ObjectInfo* inf, cocos2d::Node* parent) {
		GObject::setup(inf, parent);
		const LabelInfo* info = dynamic_cast<const LabelInfo*>(inf);
		*_textFormat = info->format;

		const cocos2d::Size& size = getContentSize();
		switch (info->autoSize)
		{
		case AutoSizeType::NONE: {
			this->setOverflow(cocos2d::Label::Overflow::CLAMP);
			this->setDimensions(size.width, size.height);
			break;
		}
		case AutoSizeType::BOTH: {
			this->setOverflow(cocos2d::Label::Overflow::NONE);
			this->setDimensions(0, 0);
			break;
		}
		case AutoSizeType::HEIGHT: {
			this->setOverflow(cocos2d::Label::Overflow::RESIZE_HEIGHT);
			this->setDimensions(size.width, 0);
			break;
		}	
		case AutoSizeType::SHRINK: {
			this->setOverflow(cocos2d::Label::Overflow::SHRINK);
			this->setDimensions(size.width, size.height);
			break;
		}
		}

		setSingleLine(info->bSingleLine);

		if (info->bOutLine) {
			_textFormat->enableEffect(TextFormat::OUTLINE);
		}
		if (info->bShadow) {
			_textFormat->enableEffect(TextFormat::SHADOW);
		}
		applyTextFormat();

		setString(info->str);

		if (info->blendMode != BlendMode::NORMAL) {
			setBlendMode(info->blendMode);
		}
		if (info->bGray) {
			setGrayed(info->bGray);
		}
		if (info->hsv) {
			setHSVMode(true);
			setHSVValue(info->hsv->x, info->hsv->y, info->hsv->z, info->hsv->w);
		}
	}

	TextFormat* GLabel::getTextFormat() {
		return _textFormat;
	}

	void GLabel::setTextFormat(const TextFormat* format) {
		_textFormat->setFormat(*format);
		applyTextFormat();
	}

	void GLabel::applyTextFormat() {
		setFontName(_textFormat->face);
		setFontSize(_textFormat->fontSize);
		setFontColor(_textFormat->color);
			
		if (_textFormat->underline) {
			enableUnderline();
		}
		else {
			disableEffect(cocos2d::LabelEffect::UNDERLINE);
		}

		if (_textFormat->italics)
			enableItalics();
		else
			disableEffect(cocos2d::LabelEffect::ITALICS);

		if (_textFormat->bold)
			enableBold();
		else
			disableEffect(cocos2d::LabelEffect::BOLD);

		setLineSpacing(_textFormat->lineSpacing);


		if (_currentLabelType == cocos2d::Label::LabelType::TTF) {
			if (_textFormat->hasEffect(TextFormat::OUTLINE)) {
				enableOutline(_isGray ? toGrayed( _textFormat->outlineColor) : _textFormat->outlineColor, _textFormat->outlineSize);
			}
			else {
				disableEffect(cocos2d::LabelEffect::OUTLINE);
			}
		}
		
		if (_textFormat->hasEffect(TextFormat::SHADOW)) {
			enableShadow( _isGray ? toGrayed( _textFormat->shadowColor) : _textFormat->shadowColor, _textFormat->shadowOffset);
		}
		else {
			disableEffect(cocos2d::LabelEffect::SHADOW);
		}

		if (_textFormat->hasEffect(TextFormat::GLOW)) {
			enableGlow(_isGray ? toGrayed(_textFormat->glowColor) : _textFormat->glowColor);
		}
		else {
			disableEffect(cocos2d::LabelEffect::GLOW);
		}

		setHorizontalAlignment(_textFormat->align);
		setVerticalAlignment(_textFormat->verticalAlign);
	}

	void GLabel::setFontSize(int size) {
		if (_currentLabelType == Label::LabelType::TTF) {
			_fontConfig.fontSize = size;
			setTTFConfig(_fontConfig);
		}
		else if (_currentLabelType == Label::LabelType::CHARMAP) {
			
		}
		else if (_currentLabelType == Label::LabelType::BMFONT) {
			setBMFontSize(_textFormat->fontSize);
		}
		else if (_currentLabelType == Label::LabelType::STRING_TEXTURE) {
			setSystemFontSize(size);
		}
	}

	int GLabel::getFontSize() const {
		return _textFormat->fontSize;
	}

	void GLabel::setFontName(const std::string& name) {
		_textFormat->face = name;
		if (name.find("ui://") != -1) {
			setBMFontFilePath(name);
		}
		else {
			bool ttf = false;
			const std::string& fontName = UIConfig::getRealFontName(name, &ttf);
			if (ttf) {
				_fontConfig.fontFilePath = fontName;
				setTTFConfig(_fontConfig);
			}
			else {
				setSystemFontName(fontName);
			}
		}
	}

	const std::string& GLabel::getFontName() const {
		return _textFormat->face;
	}

	void GLabel::setFontColor(const cocos2d::Color4B& color) {
		_textFormat->color = color;
		if (_currentLabelType != cocos2d::Label::LabelType::BMFONT) {
			cocos2d::Color4B c = (_isGray ? toGrayed(color) : color);
			setTextColor(c);
			setColor((cocos2d::Color3B)c);
		}
		else if (_bmFontCanTint) {
			setColor((cocos2d::Color3B)(_isGray ? toGrayed(color) : color));
		}
	}

	const cocos2d::Color4B& GLabel::getFontColor() const {
		return _textFormat->color;
	}

	void GLabel::setSingleLine(bool bSingleLine) {
		if (_bSingleLine != bSingleLine) {
			_bSingleLine = bSingleLine;
			moveAnchorPoint(this, 0.5f, 0.5f);
			this->setDimensions(0, 0);
		}
	}

	void GLabel::setAutoSize(AutoSizeType autoSize) {
		switch (autoSize)
		{
		case AutoSizeType::NONE: {
			this->setOverflow(cocos2d::Label::Overflow::CLAMP);
			break;
		}
		case AutoSizeType::BOTH: {
			this->setOverflow(cocos2d::Label::Overflow::NONE);
			break;
		}
		case AutoSizeType::HEIGHT: {
			this->setOverflow(cocos2d::Label::Overflow::RESIZE_HEIGHT);
			break;
		}
		case AutoSizeType::SHRINK: {
			this->setOverflow(cocos2d::Label::Overflow::SHRINK);
			break;
		}
		}
	}

	void GLabel::setUnderLine(bool bUnderLine) {
		if (!_textFormat->underline && bUnderLine) {
			_textFormat->underline = bUnderLine;
			this->enableUnderline();
		}
		else if (_textFormat->underline && !bUnderLine) {
			_textFormat->underline = bUnderLine;
			this->disableEffect(cocos2d::LabelEffect::UNDERLINE);
		}
	}

	bool GLabel::isUnderLine() {
		return _textFormat->underline;
	}

	void GLabel::setBold(bool bBold) {
		if (!_textFormat->bold && bBold) {
			_textFormat->bold = bBold;
			this->enableBold();
		}
		else if(!_textFormat->bold && bBold){
			_textFormat->bold = bBold;
			this->disableEffect(cocos2d::LabelEffect::BOLD);
		}
	}

	bool GLabel::isBold() {
		return _textFormat->bold;
	}

	void GLabel::setItalics(bool bItalics) {
		if (!_textFormat->italics && bItalics) {
			_textFormat->italics = bItalics;
			this->enableItalics();
		}
		else if (_textFormat->italics && !bItalics) {
			_textFormat->italics = bItalics;
			this->disableEffect(cocos2d::LabelEffect::ITALICS);
		}
	}

	bool GLabel::isItalics() {
		return _textFormat->italics;
	}

	void GLabel::setOutline(const cocos2d::Color4B& outlineColor, int outlineSize) {
		_textFormat->enableEffect(TextFormat::OUTLINE);
		_textFormat->outlineColor = outlineColor;
		_textFormat->outlineSize = outlineSize;
		this->enableOutline(_isGray ? toGrayed(outlineColor) : outlineColor, outlineSize);
	}

	bool GLabel::hasOutline() {
		return _textFormat->hasEffect(TextFormat::OUTLINE);
	}

	void GLabel::setShadow(const cocos2d::Color4B& shadowColor, const cocos2d::Size& offset, int blurRadius) {
		_textFormat->shadowColor = shadowColor;
		_textFormat->shadowOffset = offset;
		_textFormat->shadowBlurRadius = blurRadius;
		this->enableShadow(_isGray ? toGrayed( shadowColor ) : shadowColor, offset, blurRadius);
	}

	bool GLabel::hasShadow() {
		return _textFormat->hasEffect(TextFormat::SHADOW);
	}

	void GLabel::setGlow(const cocos2d::Color4B& glowColor) {
		_textFormat->glowColor = glowColor;
		this->enableGlow(_isGray ? toGrayed(glowColor) : glowColor);
	}

	bool GLabel::isGlow() {
		return _textFormat->hasEffect(TextFormat::GLOW);
	}

	void GLabel::setHAlign(cocos2d::TextHAlignment hAlign) {
		if (_textFormat->align == hAlign) {
			return;
		}
		_textFormat->align = hAlign;
		this->setHorizontalAlignment(hAlign);
	}

	void GLabel::setVAlign(cocos2d::TextVAlignment vAlign) {
		if (_textFormat->verticalAlign == vAlign) {
			return;
		}
		_textFormat->verticalAlign = vAlign;
		this->setVerticalAlignment(vAlign);
	}

	bool GLabel::setBMFontFilePath(const std::string & bmfontFilePath, const cocos2d::Vec2 & imageOffset, float fontSize){
		if (bmfontFilePath == _bmFontPath) {
			return true;
		}
		auto pkgMgr = PackageManager::getInstance();
		FontItem* fontItem = dynamic_cast<FontItem*>( pkgMgr->getItemByUrl(bmfontFilePath) );

		if (!fontItem || !(fontItem->getBitmapFont())){
			reset();
			return false;
		}
		BitmapFont* bmFont = fontItem->getBitmapFont();
		
		if (fontSize == 0) {
			float originalFontSize = bmFont->getOriginalFontSize();
			_bmFontSize = originalFontSize / CC_CONTENT_SCALE_FACTOR();
		}

		if (fontSize > 0.0f && bmFont->isResizable()) {
			_bmFontSize = fontSize;
		}
		_bmFontPath = bmfontFilePath;
		_bmFontCanTint = bmFont->canTint();

		_currentLabelType = cocos2d::Label::LabelType::BMFONT;
		setFontAtlas(bmFont->createFontAtlas());

		return true;
	}

	void GLabel::setGrayed(bool value) {
		GObject::setGrayed(value);

		if (_currentLabelType != cocos2d::Label::LabelType::BMFONT) {
			Label::setTextColor(_isGray ? toGrayed(_textColor) : _textColor);
		}
		else if (_bmFontCanTint) {
			setColor((cocos2d::Color3B) (_isGray ? toGrayed(_textColor) : _textColor));
		}

		if (_textFormat->hasEffect(TextFormat::OUTLINE)) {
			enableOutline(_isGray ? toGrayed(_textFormat->outlineColor) : _textFormat->outlineColor, _textFormat->outlineSize);
		}
			
		if (_textFormat->hasEffect(TextFormat::SHADOW)) {
			enableShadow(_isGray ? toGrayed(_textFormat->shadowColor) : _textFormat->shadowColor,  _textFormat->shadowOffset);
		}

		if (_textFormat->hasEffect(TextFormat::GLOW)) {
			enableGlow(_isGray ? toGrayed(_textFormat->glowColor) : _textFormat->glowColor);
		}
	}

	void GLabel::updateBMFontScale(){
		auto font = _fontAtlas->getFont();
		if (_currentLabelType == LabelType::BMFONT) {
			BitmapFont *bmFont = (BitmapFont*)font;
			float originalFontSize = bmFont->getOriginalFontSize();
			_bmfontScale = _bmFontSize * CC_CONTENT_SCALE_FACTOR() / originalFontSize;
		}
		else {
			_bmfontScale = 1.0f;
		}
	}

	void GLabel::updateContent() {
		if (!_bUpdateContentSize) {
			_bUpdateContentSize = true;
			Label::updateContent();
			_bUpdateContentSize = false;
		}
	}

	void GLabel::setString(const std::string& text) {
		if (_utf8Text.compare(text) != 0) {
			cocos2d::Size s = getContentSize();
			Label::setString(text);
			cocos2d::Size size2 = getContentSize();
			if (!s.equals(size2)) {
				onContentSizeChanged(this, s, size2);
			}
		}
	}

	void GLabel::setPosition(float x, float y) {
		cocos2d::Vec2 oldPos = getPosition();
		cocos2d::Vec2 pos(x, y);
		if (oldPos.equals(pos)) {
			return;
		}
		Label::setPosition(x,y);
		onPositionChanged(this, oldPos, pos);
	}
}