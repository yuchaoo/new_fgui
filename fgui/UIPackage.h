#pragma once
#include "ByteBuffer.h"
#include "FieldTypes.h"
#include "ObjectData.h"
#include "ComponentData.h"
#include <vector>
#include <string>

namespace fgui {
	class UIPackage;
	struct PackageItem;
	class PixelHitTestData;
	class BitmapFont;
	class GObject;
	class GComponent;
	class PkgItem;
	class ImageItem;

	struct AtlasSprite
	{
		PackageItem* atlas;
		cocos2d::Rect rect;
		bool rotated;
	};



	struct PackageItem {
		UIPackage* owner;
		PackageItemType type;
		std::string id;
		std::string name;
		std::string file;
		int width;
		int height;
		cocos2d::Rect* scale9Grid = NULL;
		int tileGridIndice;
		ObjectType objectType;
		bool scaleByTile;
		ByteBuffer* rawData;
		PixelHitTestData* pixelHitTestData;
		cocos2d::Texture2D* texture = NULL;
		cocos2d::SpriteFrame* spriteFrame = NULL;
		cocos2d::Animation* animation = NULL;
		float delayPerUnit;
		float repeatDelay;
		bool swing;
		BitmapFont* bitmapFont = NULL;

		~PackageItem();
	};

	class UIPackage : public cocos2d::Ref {
	public:
		static UIPackage* create();
		UIPackage();
		~UIPackage();
		
		const std::string& getId() const { return m_id; }
		const std::string& getName() const { return m_name; }
		PackageItem* getPackageItemById(const std::string& id);
		PackageItem* getPackageItemByName(const std::string& name);

		cocos2d::Node* createObjectByType(ObjectType type);
		cocos2d::Node* createObjectByName(const std::string& name);
		cocos2d::Node* createObjectById(const std::string& id);
		cocos2d::Node* createObject(PackageItem* pt);

		bool loadPackage(const std::string& filepath);
		bool loadItemAsset(PackageItem* pt);
		bool loadAtlas(PackageItem* pt);
		bool loadImage(PackageItem* pt);
		bool loadAnimation(PackageItem* pt);
		bool loadFont(PackageItem* pt);

		void addPkgItem(PkgItem* item);
		PkgItem* getPkgItem(const std::string& id);
	private:
		bool loadPackage(ByteBuffer* buffer);
		AtlasSprite* getAtlasSprite(const std::string& id);
	private:
		std::string m_id;
		std::string m_name;
		std::string m_assetPath;
		std::vector<std::string> m_stringTable;
		std::vector<PackageItem*> m_items;
		std::unordered_map<std::string, PackageItem*> m_itemById;
		std::unordered_map<std::string, PackageItem*> m_itemByName;
		std::unordered_map<std::string, AtlasSprite*> m_sprites;
		std::unordered_map<std::string, ObjectInfo*> m_objInfos;

		std::unordered_map<std::string, PkgItem*> _items;
	};
}
