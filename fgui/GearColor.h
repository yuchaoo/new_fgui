#pragma once

#include "cocos2d.h"
#include "GearBase.h"

namespace fgui {

	class GObject;
	class GTweener;
	class GLabel;
	struct GearInfo;

	class IColorGear
	{
	public:
		virtual cocos2d::Color3B getColor() const = 0;
		virtual void setColor(const cocos2d::Color3B& value) = 0;
	};

	class GearColorValue
	{
	public:
		cocos2d::Color4B color;
		cocos2d::Color4B outlineColor;

		GearColorValue();
		GearColorValue(const cocos2d::Color4B& color, const cocos2d::Color4B& outlineColor);
	};

	class GearColor : public GearBase
	{
	public:
		GearColor(GObject* owner);
		virtual ~GearColor();

		void apply() override;
		void updateState() override;
		virtual void initWithInfo(const GearInfo* inf);
	protected:
		void addStatus(const std::string&  pageId, ByteBuffer* buffer) override;
		void init() override;

	private:
		void onTweenUpdate(GTweener* tweener);
		void onTweenComplete();

		std::unordered_map<std::string, GearColorValue> _storage;
		GearColorValue _default;
		GLabel* _label;
	};

}

