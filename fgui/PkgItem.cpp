#include "PkgItem.h"
#include "ByteBuffer.h"
#include "Package.h"
#include "2d/CCSpriteFrame.h"
#include "HitTest.h"
#include "renderer/CCTexture2D.h"
#include "BitmapFont.h"
#include "ComponentData.h"

namespace fgui {
	PkgItem::PkgItem()
	:_owner(NULL)
	,_type(PackageItemType::UNKNOWN)
	, _objectType(ObjectType::UNKNOWN){

	}

	PkgItem::~PkgItem() {

	}

	Package* PkgItem::getOwner() {
		return _owner;
	}

	void PkgItem::setOwner(Package* pkg) {
		_owner = pkg;
	}

	PackageItemType PkgItem::getType() const {
		return _type;
	}

	void PkgItem::setType(PackageItemType type) {
		_type = type;
	}

	const std::string& PkgItem::getId() const {
		return _id;
	}

	const std::string& PkgItem::getName() const {
		return _name;
	}

	const std::string& PkgItem::getFileName() const {
		return _file;
	}

	const cocos2d::Size& PkgItem::getSize() const {
		return _size;
	}

	ObjectType PkgItem::getObjType() const {
		return _objectType;
	}

	void PkgItem::setup(ByteBuffer* buffer) {
		_id = buffer->ReadS();
		_name = buffer->ReadS();
		 buffer->Skip(2); //path
		_file = buffer->ReadS();
		bool exported = buffer->ReadBool(); //exported
		_size.width = buffer->ReadInt();
		_size.height = buffer->ReadInt();
	}

	AtlasItem::AtlasItem()
	:_texture(NULL){
	}

	AtlasItem::~AtlasItem() {
		if (_texture) {
			_texture->release();
		}
	}

	cocos2d::Texture2D* AtlasItem::getTexture() {
		if (!_texture) {
			loadRes();
		}
		return _texture;
	}

	const std::string& AtlasItem::getFilePath() {
		return _fullpath;
	}

	void AtlasItem::setup(ByteBuffer* buffer) {
		PkgItem::setup(buffer);
		_fullpath = _owner->getAssetsPath() + "_" + _file;
	}

	void AtlasItem::loadRes() {
		if (_texture) {
			return;
		}
		std::shared_ptr<cocos2d::Image> image = std::shared_ptr<cocos2d::Image>(new cocos2d::Image());
		if (!image->initWithImageFile(_fullpath)) {
			CCLOG("load image file failed, %s", _file.c_str());
			return;
		}
		cocos2d::Texture2D* texture = new cocos2d::Texture2D();
		if (!texture->initWithImage(image.get())) {
			CCLOG("init texture failed, %s", _file.c_str());
			return;
		}
		_texture = texture;
	}

	/**************************************************************/

	ImageItem::ImageItem()
	:_spriteFrame(NULL)
	, _scale9Rect(NULL)
	, _scaleByTile(false)
	, _tileGridIndice(0)
	, _bRotated(false)
	, _hitTest(NULL)
	, _atlasItem(NULL){
		_objectType = ObjectType::IMAGE;
	}

	ImageItem::~ImageItem() {
		if (_spriteFrame) {
			_spriteFrame->release();
		}
		if (_scale9Rect) {
			delete _scale9Rect;
		}
		if (_hitTest) {
			delete _hitTest;
		}
	}

	cocos2d::SpriteFrame* ImageItem::getSpriteFrame() {
		if (_spriteFrame == NULL) {
			loadRes();
		}
		return _spriteFrame;
	}

	const cocos2d::Rect* ImageItem::getScale9Rect() {
		return _scale9Rect;
	}

	bool ImageItem::isScaleByTile() const {
		return _scaleByTile;
	}

	cocos2d::Texture2D* ImageItem::getTexture() {
		return _atlasItem->getTexture();
	}

	const cocos2d::Rect& ImageItem::getTextureRect() const {
		return _textureRect;
	}

	bool ImageItem::isRotated() const {
		return _bRotated;
	}

	PixelHitTestData* ImageItem::getHitTestData() {
		return _hitTest;
	}

	void ImageItem::setup(ByteBuffer* buffer) {
		PkgItem::setup(buffer);
		int scaleOption = buffer->ReadByte();
		if (scaleOption == 1) {
			_scale9Rect = new cocos2d::Rect();
			_scale9Rect->origin.x = buffer->ReadInt();
			_scale9Rect->origin.y = buffer->ReadInt();
			_scale9Rect->size.width = buffer->ReadInt();
			_scale9Rect->size.height = buffer->ReadInt();
			_tileGridIndice = buffer->ReadInt();
		}
		else if(scaleOption == 2){
			_scaleByTile = true;
		}
		buffer->ReadBool();
	}

	AtlasItem* ImageItem::getAtlasItem() {
		return _atlasItem;
	}

	void ImageItem::setAtlasItem(AtlasItem* item) {
		_atlasItem = item;
	}

	void ImageItem::setupSpriteFrame(ByteBuffer* buffer) {
		_textureRect.origin.x = buffer->ReadInt();
		_textureRect.origin.y = buffer->ReadInt();
		_textureRect.size.width = buffer->ReadInt();
		_textureRect.size.height = buffer->ReadInt();
		_bRotated = buffer->ReadBool();
	}

	void ImageItem::setupHitTest(ByteBuffer* buffer) {
		_hitTest = new PixelHitTestData();
		_hitTest->load(buffer);
	}

	void ImageItem::loadRes() {
		if (_spriteFrame) {
			return;
		}
		CCASSERT(_atlasItem, "the texture atlasitem is empty");
		cocos2d::Texture2D* texture = _atlasItem->getTexture();
		if (!texture) {
			CCLOG("load image res failed");
			return;
		}
		_spriteFrame = new cocos2d::SpriteFrame();
		_spriteFrame->initWithTexture(texture, _textureRect);
	}

	/***************************************************************/

	AnimateItem::AnimateItem()
	:rawData(NULL)
	, _swing(false)
	, _interval(0.0f)
	, _repeatDealy(0.0f){
		_objectType = ObjectType::MOVIECLIP;
	}

	AnimateItem::~AnimateItem() {
		if (rawData) {
			delete rawData;
		}
		for (size_t i = 0; i < _frames.size(); ++i) {
			_frames.at(i)->release();
		}
	}

	const std::vector<cocos2d::AnimationFrame*>& AnimateItem::getAnimateFrames() {
		if (_frames.size() <= 0) {
			loadRes();
		}
		return _frames;
	}

	void AnimateItem::setup(ByteBuffer* buffer) {
		PkgItem::setup(buffer);
		buffer->ReadBool();
		rawData = buffer->ReadBuffer();
	}

	void AnimateItem::loadRes() {
		if (!rawData) {
			return;
		}
		ByteBuffer* buffer = rawData;
		buffer->Seek(0, 0);
		_interval = buffer->ReadInt() / 1000.0f;
		_swing = buffer->ReadBool();
		_repeatDealy = buffer->ReadInt() / 1000.0f;
		
		buffer->Seek(0, 1);
		int frameCount = buffer->ReadShort();
		_frames.resize(frameCount);

		const cocos2d::Size& sizeInPixel = this->getSize();
		cocos2d::Size sizeInPoint = CC_SIZE_PIXELS_TO_POINTS(sizeInPixel);

		for (int i = 0; i < frameCount; i++) {
			int size = buffer->ReadShort();
			int nextPos = buffer->position + size;

			cocos2d::Rect rect;
			rect.origin.x = buffer->ReadInt();
			rect.origin.y = buffer->ReadInt();
			rect.size.width = buffer->ReadInt();
			rect.size.height = buffer->ReadInt();
			float addDelay = buffer->ReadInt() / 1000.0f;

			const std::string& itemId = buffer->ReadS();

			ImageItem* imageItem = dynamic_cast<ImageItem*>(_owner->getPkgItemById(itemId));
			CCASSERT(imageItem, cocos2d::StringUtils::format("the item is not image item , id:%s", itemId.c_str()).c_str());

			const cocos2d::Rect& textRect = imageItem->getTextureRect();
			cocos2d::SpriteFrame* spriteFrame = cocos2d::SpriteFrame::createWithTexture(
				imageItem->getTexture(),
				textRect,
				imageItem->isRotated(), 
				cocos2d::Vec2(0,0), textRect.size);

			spriteFrame->setOriginalSize(sizeInPoint);
			spriteFrame->setOriginalSizeInPixels(sizeInPixel);
			spriteFrame->setOffset(cocos2d::Vec2(rect.origin.x - (sizeInPoint.width - rect.size.width) / 2, 
				-(rect.origin.y - (sizeInPoint.height - rect.size.height) / 2)));

			cocos2d::AnimationFrame* frame = new cocos2d::AnimationFrame();
			frame->initWithSpriteFrame(spriteFrame, addDelay + _interval, cocos2d::ValueMapNull);
			_frames[i] = frame;
			buffer->position = nextPos;
		}
		delete rawData;
		rawData = NULL;
	}

	/*******************************************************************/

	FontItem::FontItem()
	:_fontAtlas(NULL)
	,_bitmapFont(NULL)
	, rawData(NULL){

	}

	FontItem::~FontItem() {
		if (rawData) {
			delete rawData;
		}
		if (_bitmapFont) {
			_bitmapFont->release();
		}
		if (_fontAtlas) {
			_fontAtlas->release();
		}
	}

	BitmapFont* FontItem::getBitmapFont() {
		if (!_bitmapFont) {
			loadRes();
		}
		return _bitmapFont;
	}

	void FontItem::setup(ByteBuffer* buffer) {
		PkgItem::setup(buffer);
		rawData = buffer->ReadBuffer();
	}

	void FontItem::loadRes() {
		if (_bitmapFont) {
			return;
		}
		_bitmapFont = new BitmapFont();
		_fontAtlas = new cocos2d::FontAtlas(*_bitmapFont);
		_bitmapFont->setFontAtlas(_fontAtlas);

		ByteBuffer* buffer = rawData;
		buffer->Seek(0, 0);

		bool ttf = buffer->ReadBool();
		_bitmapFont->setIsTint(buffer->ReadBool());
		_bitmapFont->setIsResizeable(buffer->ReadBool());

		buffer->ReadBool();

		int fontSize = buffer->ReadInt();
		int xadvance = buffer->ReadInt();
		int lineHeight = buffer->ReadInt();

		cocos2d::FontLetterDefinition def;
		int bx = 0, by = 0, bw = 0, bh = 0;
		cocos2d::Texture2D* texture = NULL;

		int cnt = buffer->ReadInt();
		for (int i = 0; i < cnt; ++i) {
			int nextPos = buffer->ReadShort();
			nextPos += buffer->position;

			memset(&def, 0, sizeof(def));
			unsigned short ch = buffer->ReadUshort();
			const std::string& img = buffer->ReadS();

			bx = buffer->ReadInt();
			by = buffer->ReadInt();
			def.offsetX = buffer->ReadInt();
			def.offsetY = buffer->ReadInt();
			bw = buffer->ReadInt();
			bh = buffer->ReadInt();
			def.xAdvance = buffer->ReadInt();
			buffer->ReadByte();
	
			ImageItem* imageItem = dynamic_cast<ImageItem*>(_owner->getPkgItemById(img));
			cocos2d::SpriteFrame* spriteFrame = imageItem->getSpriteFrame();
			const cocos2d::Rect& rectInPixel = spriteFrame->getRectInPixels();
			if (texture == NULL) {
				texture = imageItem->getTexture();
			}

			bw = rectInPixel.size.width;
			bh = rectInPixel.size.height;
			def.U = rectInPixel.origin.x;
			def.V = rectInPixel.origin.y;
			def.width = rectInPixel.size.width;
			def.height = rectInPixel.size.height;
			def.validDefinition = true;
			if (def.xAdvance == 0) {
				def.xAdvance = (xadvance == 0) ? (def.offsetX + bw) : xadvance;
			}
			if (fontSize == 0) {
				fontSize = bh;
			}
			lineHeight = std::max(fontSize, lineHeight);
			_fontAtlas->addLetterDefinition(ch, def);
			buffer->position = nextPos;
		}

		_fontAtlas->addTexture(texture,0);
		_fontAtlas->setLineHeight(lineHeight);
		_bitmapFont->setOriginalFontSize(fontSize);
	}

	/******************************************************************/

	CompItem::CompItem()
	:_rawData(NULL)
	, _infoData(NULL){
		_objectType = ObjectType::COMPONENT;
	}

	CompItem::~CompItem() {
		if (_rawData) {
			delete _rawData;
		}
		if (_infoData) {
			delete _infoData;
		}
	}

	void CompItem::setup(ByteBuffer* buffer) {
		PkgItem::setup(buffer);
		ObjectType objType = ObjectType::COMPONENT;
		int extension = buffer->ReadByte();
		if (extension > 0) {
			objType = (ObjectType)extension;
		}
		_objectType = objType;
		_rawData = buffer->ReadBuffer();
	}

	void CompItem::loadRes() {
		if (!_rawData || _infoData) {
			return;
		}
		_infoData = static_cast<ComponentInfo*>(createComponentInfo(_objectType));
		ByteBuffer* buffer = _rawData;
		_infoData->setup(_owner, this);
		delete _rawData;
		_rawData = NULL;
	}

	const ComponentInfo* CompItem::getDataInfo() {
		if (!_infoData) {
			loadRes();
		}
		return _infoData;
	}

	/**************************************************/
	FileItem::FileItem(){

	}

	FileItem::~FileItem() {

	}

	void FileItem::setup(ByteBuffer* buffer) {
		PkgItem::setup(buffer);
		_fullpath = _owner->getAssetsPath() + "_" + _file;
	}

	const std::string& FileItem::getFilePath() {
		return _fullpath;
	}

}

