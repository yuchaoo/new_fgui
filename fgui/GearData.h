#pragma once

#include "GTransition.h"
#include "GearAnimation.h"
#include "GearColor.h"
#include "GearLook.h"
#include "FieldTypes.h"

namespace fgui {
	struct GearInfo;
	struct GearTweenConfigInfo;
	struct GearInfo;

	GearInfo* createGearInfo(int index);

	struct GearInfo {
		GearType type = GearType::NONE;
		std::string ownerId;
		int controllerIndex = -1;
		bool bTween = false;
		GearTweenConfigInfo* config = NULL;
	public:
		virtual ~GearInfo();
		virtual void setup(ByteBuffer* buffer, const std::string& id);
		virtual void addPageValue(ByteBuffer* buffer);
		virtual void addDefaultValue(ByteBuffer* buffer);
		virtual void operator=(const GearInfo* other);
	};

	struct GearAnimationInfo : public GearInfo {
		GearAnimationValue* defaultValue = NULL;
		std::unordered_map<std::string, GearAnimationValue*> values;
	public:
		~GearAnimationInfo();
		virtual void addPageValue(ByteBuffer* buffer);
		virtual void addDefaultValue(ByteBuffer* buffer);
		virtual void operator=(const GearInfo* other);
	};

	struct GearColorInfo : public GearInfo {
		GearColorValue* defaultValue = NULL;
		std::unordered_map<std::string, GearColorValue*> values;
	public:
		~GearColorInfo();
		virtual void addPageValue(ByteBuffer* buffer);
		virtual void addDefaultValue(ByteBuffer* buffer);
		virtual void operator=(const GearInfo* other);
	};

	struct GearDisplayInfo : public GearInfo {
		std::vector<std::string> pages;
	public:
		virtual void addPageValue(ByteBuffer* buffer);
		virtual void addDefaultValue(ByteBuffer* buffer);
		virtual void operator=(const GearInfo* other);
	};

	struct GearIconInfo : public GearInfo {
		std::string defaultValue;
		std::unordered_map<std::string, std::string> values;
	public:
		virtual void addPageValue(ByteBuffer* buffer);
		virtual void addDefaultValue(ByteBuffer* buffer);
		virtual void operator = (const GearInfo* other);
	};

	struct GearLookInfo : public GearInfo {
		GearLookValue* defaultValue = NULL;
		std::unordered_map<std::string, GearLookValue*> values;
	public:
		~GearLookInfo();
		virtual void addPageValue(ByteBuffer* buffer);
		virtual void addDefaultValue(ByteBuffer* buffer);
		virtual void operator=(const GearInfo* other);
	};

	struct GearSizeInfo : public GearInfo {
		cocos2d::Vec4* defaultValue = NULL;
		std::unordered_map<std::string, cocos2d::Vec4*> values;
	public:
		~GearSizeInfo();
		virtual void addPageValue(ByteBuffer* buffer);
		virtual void addDefaultValue(ByteBuffer* buffer);
		virtual void operator = (const GearInfo* other);
	};

	struct GearTextInfo : public GearInfo {
		std::string defaultValue;
		std::unordered_map<std::string, std::string> values;
	public:
		virtual void addPageValue(ByteBuffer* buffer);
		virtual void addDefaultValue(ByteBuffer* buffer);
		virtual void operator=(const GearInfo* other);
	};

	struct GearXYInfo : public GearInfo {
		cocos2d::Vec2* defaultValue = NULL;
		std::unordered_map<std::string, cocos2d::Vec2*> values;
	public:
		~GearXYInfo();
		virtual void addPageValue(ByteBuffer* buffer);
		virtual void addDefaultValue(ByteBuffer* buffer);
		virtual void operator=(const GearInfo* other);
	};

	struct GearTweenConfigInfo {
		EaseType easeType = EaseType::Linear;
		float duration = 0.0f;
		float delay = 0.0f;
		bool yoyo = false;
		std::string endLabel;
		int repeat = 0;
		TValue* startValue = NULL;
		TValue* endValue = NULL;
		~GearTweenConfigInfo();
		void operator=(const GearTweenConfigInfo* other);
	};

}