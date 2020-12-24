#pragma once
#include "GObject.h"

namespace cocos2d {
	class Node;
}

namespace fgui {
	class GComponent;
	class GSprite;
	class GAnimation;
	struct ObjectInfo;

	class GLoader : public cocos2d::Node, public GObject
	{
	public:
		GLoader();
		virtual ~GLoader();

		CREATE_FUNC(GLoader);
		virtual void onEnter();
		virtual void onExit();

		const std::string& getURL() const { return _url; }
		void setURL(const std::string& value);
		void setColor(const cocos2d::Color3B & value);

		FillMethod getFillMethod() const;
		void setFillMethod(FillMethod value);

		FillOrigin getFillOrigin() const;
		void setFillOrigin(FillOrigin value);

		bool isFillClockwise() const;
		void setFillClockwise(bool value);

		float getFillAmount() const;
		void setFillAmount(float value);

		void setAlign(cocos2d::TextHAlignment hAlign, cocos2d::TextVAlignment vAlign);
		void setLoadFillType(LoaderFillType type);
		void setLayout(LoaderFillType type, cocos2d::TextHAlignment hAlign, cocos2d::TextVAlignment vAlign);

		const cocos2d::Size& getOriginContentSize();
		cocos2d::TextHAlignment getHAlign() const { return _align; }
		cocos2d::TextVAlignment getVAlign() const { return _verticalAlign; }
		cocos2d::Node* getContent();
	public:
		virtual void setContentSize(const cocos2d::Size& size) override;
		virtual void setPosition(float x, float y);

		virtual void setBlendMode(BlendMode blendMode);
		virtual void setGrayed(bool value) override;
		virtual void setHSVMode(bool isHsv);
		virtual void setHSVValue(float hue, float saturation, float brightness, float contrast);

		cocos2d::Node* hitTest(const cocos2d::Vec2 &worldPoint, const cocos2d::Camera* camera);
	protected:
		void loadContent();
		void loadFromPackage();
		void loadExternal();
		void updateLayout();
		void clearLayout();

		virtual void setupBefore(ByteBuffer* buffer, int pos, cocos2d::Node* parent);
		virtual void setupAfter(ByteBuffer* buffer, int pos);
		virtual void setup(const ObjectInfo* info, cocos2d::Node* parent);
	private:
		std::string _url;
		cocos2d::TextHAlignment _align;
		cocos2d::TextVAlignment _verticalAlign;
		LoaderFillType _fill;
		bool _shrinkOnly;
		bool _autoSize;
		bool _playing;
		int _frame;
		cocos2d::Size _contentSourceSize;
		GSprite* _sprite;
		GAnimation* _animation;
		FillMethod _fillMethod;
		FillOrigin _fillOrigin;
		bool _isFillClockwise;
		float _fillAmount;
		GComponent* _component;
		PackageItem* _urlItem;
		bool _bLayoutDirty;
	};

}
