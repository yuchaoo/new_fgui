#include "cocos2d.h"
#include "UIPackage.h"
#include "HitTest.h"
#include "BitmapFont.h"
#include "GObject.h"
#include "GComponent.h"
#include "GLabel.h"
#include "GSprite.h"
#include "GLoader.h"
#include "GButton.h"
#include "GRichText.h"
#include "GTextInput.h"
#include "GAnimation.h"
#include "GText.h"
#include "GProgressBar.h"
#include "GGraph.h"
#include "GSlider.h"
#include "GList.h"
#include "GGroup.h"
#include "PkgItem.h"

namespace fgui {

	PackageItem::~PackageItem() {
		if (spriteFrame) {
			spriteFrame->release();
		}
	}

	UIPackage* UIPackage::create() {
		UIPackage* rp = new UIPackage();
		rp->autorelease();
		return rp;
	}

	UIPackage::UIPackage() {

	}

	UIPackage::~UIPackage() {
		for (auto iter = m_items.begin(); iter != m_items.end(); ++iter) {
			delete *iter;
		}
		for (auto iter = m_sprites.begin(); iter != m_sprites.end(); ++iter) {
			delete iter->second;
		}
	}

	PackageItem* UIPackage::getPackageItemById(const std::string& id) {
		auto iter = m_itemById.find(id);
		if (iter != m_itemById.end()) {
			return iter->second;
		}
		return NULL;
	}

	PackageItem* UIPackage::getPackageItemByName(const std::string& name) {
		auto iter = m_itemByName.find(name);
		if (iter != m_itemByName.end()) {
			return iter->second;
		}
		return NULL;
	}

	cocos2d::Node* UIPackage::createObjectByType(ObjectType type)
	{
		switch (type)
		{
		case ObjectType::IMAGE:
			return GSprite::create();

		case ObjectType::MOVIECLIP:
			return GAnimation::create();

		case ObjectType::COMPONENT:
			return GComponent::create();

		case ObjectType::TEXT:
			return GLabel::create();

		case ObjectType::RICHTEXT:
			return GRichText::create();

		case ObjectType::INPUTTEXT:
			return GTextInput::create();

		case ObjectType::GROUP:
			return GGroup::create();

		case ObjectType::LIST:
			return GList::create();

		case ObjectType::GRAPH:
			return GGraph::create();

		case ObjectType::LOADER:
			return GLoader::create();

		case ObjectType::BUTTON:
			return GButton::create();

		case ObjectType::LABEL:
			return GText::create();

		case ObjectType::PROGRESSBAR:
			return GProgressBar::create();

		case ObjectType::SLIDER:
			return GSlider::create();

		case ObjectType::SCROLLBAR:
			return NULL;

		case ObjectType::COMBOBOX:
			return NULL;

		default:
			return nullptr;
		}
		return NULL;
	}
	cocos2d::Node* UIPackage::createObjectByName(const std::string& name) {
		PackageItem* pt = getPackageItemByName(name);
		if (!pt) {
			CCLOG("Cannot find the package item:%s",name.c_str());
			return NULL;
		}
		return createObject(pt);
	}

	cocos2d::Node* UIPackage::createObjectById(const std::string& id) {
		PackageItem* pt = getPackageItemById(id);
		if (!pt) {
			CCLOG("Cannot find the package id item:%s",id.c_str());
			return NULL;
		}
		return createObject(pt);
	}

	cocos2d::Node* UIPackage::createObject(PackageItem* pt) {
		cocos2d::Node* node =  createObjectByType(pt->objectType);
		GObject* obj = dynamic_cast<GObject*>(node);
		if (!obj) {
			CCLOG("Create component failed by type:%d", pt->objectType);
			return NULL;
		}
		//ObjectInfo* data = createComponentInfo(pt->objectType);
		//data->setup(pt->rawData,pt);

		this->loadItemAsset(pt);
		obj->constructFromResource(this, pt);
		return node;
	}

	bool UIPackage::loadPackage(const std::string& filepath) {
		m_assetPath = filepath;
		cocos2d::Data data = cocos2d::FileUtils::getInstance()->getDataFromFile(m_assetPath + ".fui");
		if (data.isNull()) {
			CCLOG("Get file data failed, %s", filepath.c_str());
			return 0;
		}
		ByteBuffer buffer((char*)data.getBytes(), 0, data.getSize(), false);
		return loadPackage(&buffer);
	}

	bool UIPackage::loadItemAsset(PackageItem* pt) {
		switch (pt->type) {
		case PackageItemType::IMAGE:
			if (pt->spriteFrame == NULL) {
				loadImage(pt);
			}
			return pt->spriteFrame == NULL;
		case PackageItemType::ATLAS:
			if (pt->texture == NULL) {
				loadAtlas(pt);
			}
			return pt->texture == NULL;
		case PackageItemType::FONT:
			if (pt->bitmapFont == NULL) {
				loadFont(pt);
			}
			return pt->bitmapFont == NULL;
		case PackageItemType::MOVIECLIP:
			if (pt->animation == NULL) {
				loadAnimation(pt);
			}
			return pt->animation == NULL;
		default:
			return false;
		}
		return false;
	}

	bool UIPackage::loadPackage(ByteBuffer* buffer) {
		if (buffer->ReadUint() != 0x46475549)
		{
			CCLOG("FairyGUI: old package format found");
			return false;
		}

		buffer->version = buffer->ReadInt();
		buffer->ReadBool(); //compressed

		m_id = buffer->ReadString();
		m_name = buffer->ReadString();

		buffer->Skip(20);
		int indexTablePos = buffer->position;
		int cnt;

		buffer->Seek(indexTablePos, 4);

		cnt = buffer->ReadInt();
		m_stringTable.resize(cnt);

		for (int i = 0; i < cnt; i++) {
			m_stringTable[i] = buffer->ReadString();
		}
		buffer->stringTable = &m_stringTable;

		buffer->Seek(indexTablePos, 1);

		PackageItem* pi;

		cnt = buffer->ReadShort();
		for (int i = 0; i < cnt; i++)
		{
			int nextPos = buffer->ReadInt();
			nextPos += buffer->position;

			pi = new PackageItem();
			pi->owner = this;
			pi->type = (PackageItemType)buffer->ReadByte();
			pi->id = buffer->ReadS();
			pi->name = buffer->ReadS();
			buffer->Skip(2); //path
			pi->file = buffer->ReadS();
			buffer->ReadBool(); //exported
			pi->width = buffer->ReadInt();
			pi->height = buffer->ReadInt();

			switch (pi->type)
			{
			case PackageItemType::IMAGE:{
				pi->objectType = ObjectType::IMAGE;
				int scaleOption = buffer->ReadByte();
				if (scaleOption == 1){
					pi->scale9Grid = new cocos2d::Rect();
					pi->scale9Grid->origin.x = buffer->ReadInt();
					pi->scale9Grid->origin.y = buffer->ReadInt();
					pi->scale9Grid->size.width = buffer->ReadInt();
					pi->scale9Grid->size.height = buffer->ReadInt();
					pi->tileGridIndice = buffer->ReadInt();
				}
				else if (scaleOption == 2) {
					pi->scaleByTile = true;
				}
				buffer->ReadBool(); //smoothing
				break;
			}

			case PackageItemType::MOVIECLIP:{
				buffer->ReadBool(); //smoothing
				pi->objectType = ObjectType::MOVIECLIP;
				pi->rawData = buffer->ReadBuffer();
				break;
			}

			case PackageItemType::FONT:{
				pi->rawData = buffer->ReadBuffer();
				break;
			}

			case PackageItemType::COMPONENT:{
				int extension = buffer->ReadByte();
				if (extension > 0) {
					pi->objectType = (ObjectType)extension;
				}
				else {
					pi->objectType = ObjectType::COMPONENT;
				}
				pi->rawData = buffer->ReadBuffer();
				break;
			}

			case PackageItemType::ATLAS:
			case PackageItemType::SOUND:
			case PackageItemType::MISC:{
				pi->file = m_assetPath + "_" + pi->file;
			}
			default:
				break;
			}
			m_items.push_back(pi);
			m_itemById[pi->id] = pi;
			if (!pi->name.empty()) {
				m_itemByName[pi->name] = pi;
			}
			buffer->position = nextPos;
		}

		buffer->Seek(indexTablePos, 2);

		cnt = buffer->ReadShort();
		for (int i = 0; i < cnt; i++)
		{
			int nextPos = buffer->ReadShort();
			nextPos += buffer->position;

			const std::string& itemId = buffer->ReadS();
			const std::string& id = buffer->ReadS();
			pi = m_itemById[id];

			AtlasSprite* sprite = new AtlasSprite();
			sprite->atlas = pi;
			sprite->rect.origin.x = buffer->ReadInt();
			sprite->rect.origin.y = buffer->ReadInt();
			sprite->rect.size.width = buffer->ReadInt();
			sprite->rect.size.height = buffer->ReadInt();
			sprite->rotated = buffer->ReadBool();
			m_sprites[itemId] = sprite;

			buffer->position = nextPos;
		}

		if (buffer->Seek(indexTablePos, 3))
		{
			cnt = buffer->ReadShort();
			for (int i = 0; i < cnt; i++)
			{
				int nextPos = buffer->ReadInt();
				nextPos += buffer->position;

				auto it = m_itemById.find(buffer->ReadS());
				if (it != m_itemById.end())
				{
					pi = it->second;
					if (pi->type == PackageItemType::IMAGE)
					{
						pi->pixelHitTestData = new PixelHitTestData();
						pi->pixelHitTestData->load(buffer);
					}
				}
				buffer->position = nextPos;
			}
		}
		return true;
	}

	AtlasSprite* UIPackage::getAtlasSprite(const std::string& id) {
		auto iter = m_sprites.find(id);
		if (iter != m_sprites.end()) {
			return iter->second;
		}
		return NULL;
	}

	bool UIPackage::loadAtlas(PackageItem* pt) {
		if (pt->texture) {
			return true;
		}

		std::shared_ptr<cocos2d::Image> image(new cocos2d::Image());
		if (!image->initWithImageFile(pt->file)) {
			CCLOG("Cannot find the image:%s", pt->file.c_str());
			return false;
		}
		cocos2d::Texture2D* tex = new cocos2d::Texture2D();
		tex->initWithImage(image.get());
		pt->texture = tex;

		size_t pos = pt->file.rfind(".");
		std::string alphaFile;
		if (pos != -1) {
			alphaFile = pt->file.substr(0, pos) + "!a." + pt->file.substr(pos);
		}
		else {
			alphaFile = pt->file + "!a";
		}
		bool haveAlphaTesture = cocos2d::FileUtils::getInstance()->isFileExist(alphaFile);
		if (haveAlphaTesture) {
			std::shared_ptr<cocos2d::Image> alphaImage(new cocos2d::Image);
			if (alphaImage->initWithImageFile(alphaFile)) {
				CCLOG("Find the alpha texture file:%s, but create image failed", alphaFile.c_str());
				return false;
			}
			cocos2d::Texture2D* alphaTex = new cocos2d::Texture2D();
			alphaTex->initWithImage(alphaImage.get());
			pt->texture->setAlphaTexture(alphaTex);
		}
		return true;
	}
	bool UIPackage::loadImage(PackageItem* pt) {
		if (pt->spriteFrame) {
			return true;
		}

		AtlasSprite* atlasSprite = nullptr;
		auto iter = m_sprites.find(pt->id);
		if (iter != m_sprites.end()) {
			atlasSprite = iter->second;
			loadAtlas(atlasSprite->atlas);
		}

		pt->spriteFrame = SpriteFrame::createWithTexture(atlasSprite->atlas->texture, atlasSprite->rect, atlasSprite->rotated, cocos2d::Vec2(0, 0), atlasSprite->rect.size);
		if (pt->scaleByTile) {
			cocos2d::Texture2D::TexParams tp = { GL_LINEAR,GL_LINEAR,GL_REPEAT,GL_REPEAT };
			pt->spriteFrame->getTexture()->setTexParameters(tp);
		}
		pt->spriteFrame->retain();
		return true;
	}

	

	bool UIPackage::loadAnimation(PackageItem* pt) {
		if (pt->animation) {
			return true;
		}

		pt->animation = cocos2d::Animation::create();
		pt->animation->retain();

		ByteBuffer* buffer = pt->rawData;
		buffer->Seek(0, 0);

		float interval = buffer->ReadInt() / 1000.0f;
		pt->swing = buffer->ReadBool();
		pt->repeatDelay = buffer->ReadInt() / 1000.0f;

		buffer->Seek(0, 1);
		int frameCount = buffer->ReadShort();
		cocos2d::Vector<cocos2d::AnimationFrame*> frames(frameCount);
		cocos2d::Size sizeInPixels = cocos2d::Size(pt->width, pt->height);
		cocos2d::Size mcSize = CC_SIZE_PIXELS_TO_POINTS(sizeInPixels);

		AtlasSprite* sprite = NULL;
		cocos2d::SpriteFrame* spriteFrame = NULL;
		for (int i = 0; i < frameCount; i++) {
			int size = buffer->ReadShort();
			int nextPos = buffer->position + size;

			cocos2d::Rect rect;
			rect.origin.x = buffer->ReadInt();
			rect.origin.y = buffer->ReadInt();
			rect.size.width = buffer->ReadInt();
			rect.size.height = buffer->ReadInt();
			float addDelay = buffer->ReadInt() / 1000.0f;
			const std::string& spriteId = buffer->ReadS();
			if (!spriteId.empty() && (sprite = getAtlasSprite(spriteId)) != NULL) {
				spriteFrame = cocos2d::SpriteFrame::createWithTexture(sprite->atlas->texture
					, sprite->rect, sprite->rotated, cocos2d::Vec2(0, 0), sprite->rect.size);
				spriteFrame->setOriginalSizeInPixels(sizeInPixels);
				spriteFrame->setOriginalSize(mcSize);
			}
			else {
				char text[256];
				snprintf(text, sizeof(text), "Can not find the sprite atlas : %s", spriteId.c_str());
				CCASSERT(false, text);
				return false;
			}
			cocos2d::AnimationFrame* frame = cocos2d::AnimationFrame::create(spriteFrame, addDelay / interval + 1, cocos2d::ValueMapNull);
			frames.pushBack(frame);
			buffer->position = nextPos;
		}
		pt->animation->setFrames(frames);
		pt->animation->setDelayPerUnit(interval);
		pt->animation->setLoops(1);
		delete buffer;
		pt->rawData = NULL;
		return true;
	}
	bool UIPackage::loadFont(PackageItem* pt) {
		if (pt->bitmapFont) {
			return true;
		}

		pt->bitmapFont = BitmapFont::create();
		cocos2d::FontAtlas* fontAtlas = new cocos2d::FontAtlas(*pt->bitmapFont);
		pt->bitmapFont->_fontAtlas = fontAtlas;

		ByteBuffer* buffer = pt->rawData;
		buffer->Seek(0, 0);
		bool ttf = buffer->ReadBool();
		pt->bitmapFont->_canTint = buffer->ReadBool();
		pt->bitmapFont->_resizable = buffer->ReadBool();
		buffer->ReadBool();

		int fontSize = buffer->ReadInt();
		int xadvance = buffer->ReadInt();
		int lineHeight = buffer->ReadInt();

		cocos2d::Texture2D* mainTexture = NULL;
		AtlasSprite* mainSprite = NULL;
		if (ttf && (mainSprite = getAtlasSprite(pt->id)) != NULL) {
			loadAtlas(mainSprite->atlas);
			if (mainSprite->atlas->texture == NULL) {
				CCLOG("Find the font atlassprite failed");
				return false;
			}
			mainTexture = mainSprite->atlas->texture;
		}
		cocos2d::FontLetterDefinition def;
		int bx = 0, by = 0, bw = 0, bh = 0;

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
			if (ttf) {
				cocos2d::Rect tmpRect(bx + mainSprite->rect.origin.x, by + mainSprite->rect.origin.y, bw, bh);
				def.U = tmpRect.origin.x;
				def.V = tmpRect.origin.y;
				def.width = tmpRect.size.width;
				def.height = tmpRect.size.height;
				def.validDefinition = true;
			}
			else {
				PackageItem* charItem = getPackageItemById(img);
				if (charItem) {
					loadImage(charItem);
					cocos2d::Rect tmpRect = charItem->spriteFrame->getRectInPixels();
					bw = tmpRect.size.width;
					bh = tmpRect.size.height;
					def.U = tmpRect.origin.x;
					def.V = tmpRect.origin.y;
					def.width = tmpRect.size.width;
					def.height = tmpRect.size.height;
					if (mainTexture == NULL) {
						mainTexture = charItem->spriteFrame->getTexture();
					}
					def.validDefinition = true;
					if (def.xAdvance == 0) {
						if (xadvance == 0) {
							def.xAdvance = def.offsetX + bw;
						}
						else {
							def.xAdvance = xadvance;
						}
					}
					if (fontSize == 0) {
						fontSize = bh;
					}
					lineHeight = std::max(fontSize, lineHeight);
				}
			}
			fontAtlas->addLetterDefinition(ch, def);
			buffer->position = nextPos;
		}
		if (mainTexture) {
			fontAtlas->addTexture(mainTexture, 0);
		}
		fontAtlas->setLineHeight(lineHeight);
		pt->bitmapFont->_originalFontSize = fontSize;

		delete buffer;
		pt->rawData = NULL;
		return true;
	}

	void UIPackage::addPkgItem(PkgItem* item) {
		auto iter = _items.find(item->getId());
		if (iter == _items.end()) {
			_items.insert(std::make_pair(item->getId(), item));
		}
		else {
			CCASSERT(false, StringUtils::format("item %s has added", item->getId().c_str()).c_str());
		}
	}

	PkgItem* UIPackage::getPkgItem(const std::string& id) {
		auto iter = _items.find(id);
		if (iter != _items.end()) {
			return iter->second;
		}
		return NULL;
	}
}