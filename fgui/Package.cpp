#include "Package.h"
#include "PkgItem.h"
#include "platform/CCFileUtils.h"
#include "ByteBuffer.h"
#include "base/ccUTF8.h"
#include "GSprite.h"
#include "GProgressBar.h"
#include "GComponent.h"
#include "GAnimation.h"
#include "GButton.h"
#include "GLoader.h"
#include "GObject.h"
#include "GLabel.h"
#include "GRichText.h"
#include "GTextInput.h"
#include "GText.h"
#include "GGraph.h"
#include "GGroup.h"
#include "GList.h"
#include "GSlider.h"
#include "base/ccUtils.h"

namespace fgui {

	PkgItem* createPkgItem(PackageItemType type) {
		switch (type) {
		case PackageItemType::ATLAS:
			return new AtlasItem();
		case PackageItemType::IMAGE:
			return new ImageItem();
		case PackageItemType::COMPONENT:
			return new CompItem();
		case PackageItemType::FONT:
			return new FontItem();
		case PackageItemType::MOVIECLIP:
			return new AnimateItem();
		case PackageItemType::MISC:
		case PackageItemType::SOUND:
			return new FileItem();
		}
		return NULL;
	}

	Package::Package()
	:_lastReleaseTime(0){

	}
	
	Package::~Package() {
		for (auto iter = _items.begin(); iter != _items.end(); ++iter) {
			iter->second->release();
		}
	}

	void Package::retain() {
		Ref::retain();
	}

	void Package::release() {
		Ref::release();
		_lastReleaseTime = cocos2d::utils::gettime();
	}

	double Package::getLastReleaseTime() {
		return _lastReleaseTime;
	}

	const std::string& Package::getAssetsPath() {
		return _assetPath;
	}

	void Package::addPkgItem(PkgItem* item) {
		auto iter = _items.find(item->getId());
		if (iter == _items.end()) {
			_items.insert(std::make_pair(item->getId(), item));
			_itemsByName.insert(std::make_pair(item->getName(), item));
		}
		else {
			CCASSERT(false, cocos2d::StringUtils::format("item %s has added", item->getId().c_str()).c_str());
		}
	}

	PkgItem* Package::getPkgItemById(const std::string& id) {
		auto iter = _items.find(id);
		if (iter != _items.end()) {
			return iter->second;
		}
		return NULL;
	}

	PkgItem* Package::getPkgItemByName(const std::string& id) {
		auto iter = _itemsByName.find(id);
		if (iter != _itemsByName.end()) {
			return iter->second;
		}
		return NULL;
	}

	bool Package::load(const std::string& filepath) {
		_assetPath = filepath;
		cocos2d::Data data = cocos2d::FileUtils::getInstance()->getDataFromFile(_assetPath + ".fui");
		if (data.isNull()) {
			CCLOG("Get file data failed, %s", filepath.c_str());
			return false;
		}
		ByteBuffer buffer((char*)data.getBytes(), 0, data.getSize(), false);
		return load(&buffer);
	}

	bool Package::load(ByteBuffer* buffer) {
		if (buffer->ReadUint() != 0x46475549){
			CCLOG("FairyGUI: old package format found");
			return false;
		}

		buffer->version = buffer->ReadInt();
		buffer->ReadBool(); //compressed

		_id = buffer->ReadString();
		_name = buffer->ReadString();

		buffer->Skip(20);
		int indexTablePos = buffer->position;
		buffer->Seek(indexTablePos, 4);

		int cnt = buffer->ReadInt();
		_strTable.resize(cnt);
		for (int i = 0; i < cnt; i++) {
			_strTable[i] = buffer->ReadString();
		}
		buffer->stringTable = &_strTable;

		buffer->Seek(indexTablePos, 1);
		cnt = buffer->ReadShort();
		for (int i = 0; i < cnt; i++){
			int nextPos = buffer->ReadInt();
			nextPos += buffer->position;

			PackageItemType type = (PackageItemType)buffer->ReadByte();
			PkgItem* item = createPkgItem(type);
			item->setOwner(this);
			item->setType(type);
			item->setup(buffer);
			this->addPkgItem(item);

			buffer->position = nextPos;
		}

		buffer->Seek(indexTablePos, 2);

		cnt = buffer->ReadShort();
		for (int i = 0; i < cnt; i++){
			int nextPos = buffer->ReadShort();
			nextPos += buffer->position;

			const std::string& itemId = buffer->ReadS();
			const std::string& atlasId = buffer->ReadS();
			ImageItem* item = dynamic_cast<ImageItem*>(getPkgItemById(itemId));
			if (!item) {
				item = new ImageItem();
				item->setId(itemId);
				item->setName(itemId);
				addPkgItem(item);
			}
			AtlasItem* atlas = dynamic_cast<AtlasItem*> (getPkgItemById(atlasId));
			CCASSERT(atlas, cocos2d::StringUtils::format("get atlas failed, id:%s", atlasId.c_str()).c_str());
			item->setAtlasItem(atlas);
			item->setupSpriteFrame(buffer);

			buffer->position = nextPos;
		}

		if (buffer->Seek(indexTablePos, 3)){
			cnt = buffer->ReadShort();
			for (int i = 0; i < cnt; i++){
				int nextPos = buffer->ReadInt();
				nextPos += buffer->position;

				const std::string& itemId = buffer->ReadS();
				ImageItem* item = dynamic_cast<ImageItem*>(getPkgItemById(itemId));
				if (item) {
					item->setupHitTest(buffer);
				}
				buffer->position = nextPos;
			}
		}
		return true;
	}

	cocos2d::Node* Package::createNodeById(const std::string& id) {
		auto iter = _items.find(id);
		if (iter != _items.end()) {
			return createNode(iter->second);
		}
		CCLOG("can not find the item:%s",id.c_str());
		return NULL;
	}

	cocos2d::Node* Package::createNodeByName(const std::string& name) {
		auto iter = _itemsByName.find(name);
		if (iter != _itemsByName.end()) {
			return createNode(iter->second);
		}
		CCLOG("can not find the item:%s",name.c_str());
		return NULL;
	}

	cocos2d::Node* Package::createNode(PkgItem* item) {
		cocos2d::Node* node = createObjectByType(item->getObjType());
		if (!node) {
			CCLOG("create obj failed");
			return NULL;
		}
		item->loadRes();

		GObject* obj = dynamic_cast<GObject*>(node);
		obj->constructFromItem(this, item);
		CompItem* compItem = dynamic_cast<CompItem*>(item);
		if (compItem) {
			obj->setup((const ObjectInfo*)compItem->getDataInfo(), NULL);
		}
		return node;
	}
}