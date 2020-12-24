#pragma once
#include "base/CCRef.h"
#include "FieldTypes.h"
#include <string>
#include <math/CCGeometry.h>

namespace cocos2d {
	class SpriteFrame;
	class AnimationFrame;
	class Texture2D;
	class FontAtlas;
}

namespace fgui {
	class Package;
	class ByteBuffer;
	struct ComponentInfo;
	class PixelHitTestData;
	class ImageItem;
	class BitmapFont;
	struct SpriteInfo;

	class PkgItem : public cocos2d::Ref {
	public:
		PkgItem();
		~PkgItem();
		Package* getOwner();
		void setOwner(Package* pkg);
		PackageItemType getType() const;
		void setType(PackageItemType type);
		const std::string& getId() const;
		void setId(const std::string& id) { _id = id; }
		const std::string& getName() const;
		void setName(const std::string& name) { _name = name; }
		const std::string& getFileName() const;
		const cocos2d::Size& getSize() const;
		ObjectType getObjType() const;
		virtual void setup(ByteBuffer* buffer);
		virtual void loadRes() {};
	protected:
		Package* _owner;
		PackageItemType _type;
		std::string _id;
		std::string _name;
		std::string _file;
		cocos2d::Size _size;
		std::string _filepath;
		ObjectType _objectType;
	};

	class AtlasItem : public PkgItem {
	public:
		AtlasItem();
		~AtlasItem();
		cocos2d::Texture2D* getTexture();
		const std::string& getFilePath();
		virtual void setup(ByteBuffer* buffer);
		virtual void loadRes();
	protected:
		cocos2d::Texture2D* _texture;
		std::string _fullpath;
	};

	class ImageItem : public PkgItem {
	public:
		ImageItem();
		~ImageItem();
		cocos2d::SpriteFrame* getSpriteFrame();
		const cocos2d::Rect* getScale9Rect();
		bool isScaleByTile() const;
		cocos2d::Texture2D* getTexture();
		const cocos2d::Rect& getTextureRect() const;
		bool isRotated() const;
		PixelHitTestData* getHitTestData();

		AtlasItem* getAtlasItem();
		void setAtlasItem(AtlasItem* item);

		void setupSpriteFrame(ByteBuffer* buffer);
		void setupHitTest(ByteBuffer* buffer);

		virtual void setup(ByteBuffer* buffer);
		virtual void loadRes();
	protected:
		cocos2d::SpriteFrame* _spriteFrame;
		AtlasItem* _atlasItem;
		cocos2d::Rect* _scale9Rect;
		bool _scaleByTile;
		int _tileGridIndice;
		cocos2d::Rect _textureRect;
		bool _bRotated;
		PixelHitTestData* _hitTest;
	};

	class AnimateItem : public PkgItem {
	public:
		AnimateItem();
		~AnimateItem();
		const std::vector<cocos2d::AnimationFrame*>& getAnimateFrames();
		bool isSwing() const { return _swing; }
		float getInterval() const { return _interval; }
		float getRepeatDelay() const { return _repeatDealy; }
		virtual void setup(ByteBuffer* buffer);
		virtual void loadRes();
	public:
		ByteBuffer* rawData;
		std::vector<cocos2d::AnimationFrame*> _frames;
		bool _swing;
		float _interval;
		float _repeatDealy;
	};

	class FontItem : public PkgItem {
	public:
		FontItem();
		~FontItem();
		BitmapFont* getBitmapFont();
		virtual void setup(ByteBuffer* buffer);
		virtual void loadRes();
	private:
		ByteBuffer* rawData;
		BitmapFont* _bitmapFont;
		cocos2d::FontAtlas* _fontAtlas;
	};

	class CompItem : public PkgItem {
	public:
		CompItem();
		~CompItem();
		virtual void setup(ByteBuffer* buffer);
		virtual void loadRes();
		const ComponentInfo* getDataInfo();
	public:
		ByteBuffer* _rawData;
		ComponentInfo* _infoData;
	};

	class FileItem : public PkgItem {
	public:
		FileItem();
		~FileItem();
		const std::string& getFilePath();
		virtual void setup(ByteBuffer* buffer);
	private:
		std::string _fullpath;
	};
	

}