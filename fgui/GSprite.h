#pragma once

#include "cocos2d.h"
#include "FieldTypes.h"
#include "GObject.h"

using namespace cocos2d;

namespace fgui {
	
	class GSprite 
		: public cocos2d::Sprite
		, public fgui::GObject
	{
	public:
		GSprite();
		virtual ~GSprite();

		static GSprite* create();
		static GSprite* createWithTexture(Texture2D* texture);
		static GSprite* createWithFileName(const std::string& filename);
		static GSprite* createWithTexture(Texture2D* texture, const Rect& rect, bool rotated = false);
		static GSprite* createWithSpriteFrameName(const std::string& spriteFrameName);
		static GSprite* createWithSpriteFrame(SpriteFrame* spriteFrame);

		virtual void onEnter();
		virtual void onExit();

		void clearContent();
		void setScale9SpriteWithSpace(float l, float r, float b, float t);
		void setScale9Sprite(const cocos2d::Rect* value);
		FillMethod getFillMethod() const { return _fillMethod; }
		void setFillMethod(FillMethod value);

		FillOrigin getFillOrigin() const { return _fillOrigin; }
		void setFillOrigin(FillOrigin value);

		bool isFillClockwise() const { return _fillClockwise; }
		void setFillClockwise(bool value);

		float getFillAmount() const { return _fillAmount; }
		void setFillAmount(float value);

		virtual void setBlendMode(BlendMode blend);
		BlendMode getBlendMode() const { return _blendMode; }

		void setFlipType(FlipType type);
		FlipType getFlipType() const { return _flipType; }

		virtual void setContentSize(const cocos2d::Size& size);
		virtual void setPosition(float x, float y);
	public:
		virtual void setHSVMode(bool isHsv);
		virtual void setHSVValue(float hue, float saturation, float brightness, float contrast);
		virtual void setGrayed(bool value) override;
		
	protected:
		virtual void constructFromItem(Package* pkg, PkgItem* item);
		virtual void setup(const ObjectInfo* info, cocos2d::Node* parent);

	protected:
		virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;
		void onDraw(const cocos2d::Mat4 &transform, uint32_t flags);
		cocos2d::Tex2F textureCoordFromAlphaPoint(cocos2d::Vec2 alpha);
		cocos2d::Vec2 vertexFromAlphaPoint(cocos2d::Vec2 alpha);
		void updateBar(void);
		void updateRadial();
		void getFillVetextAndAOrigin(std::vector<cocos2d::Vec2>& vertex,cocos2d::Vec2& origin, float& angle);
		virtual void updateColor(void) override;
		cocos2d::Vec2 boundaryTexCoord(char index);
		void setupFill();
	private:
		FillMethod _fillMethod;
		FillOrigin _fillOrigin;
		FlipType _flipType;
		float _fillAmount;
		bool _fillClockwise;
		cocos2d::CustomCommand _customCommand;
		int _vertexDataCount;
		cocos2d::V2F_C4B_T2F *_vertexData;
		BlendMode _blendMode;
		int _vertexCapacity;
		bool _bFillDirty;
	};

}
