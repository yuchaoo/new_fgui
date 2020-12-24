#pragma once
#include "cocos2d.h"
#include "Margin.h"
#include "FieldTypes.h"
#include "GTransition.h"
#include "GearAnimation.h"
#include "GearColor.h"
#include "ObjectData.h"
#include "GearLook.h"
#include "TextFormat.h"
#include "ByteBuffer.h"
#include <vector>
#include <string>
#include <unordered_map>
#include "GearData.h"

namespace fgui {
	struct ControllerActionInfo;
	struct PackageItem;
	class Package;

	ControllerActionInfo* createCtrlActionInfo(int type);

	struct ControllerActionInfo {
		int type; 
		std::vector<std::string> fromPages;
		std::vector<std::string> toPages;
	public:
		virtual void setup(ByteBuffer* buffer);
		virtual void operator=(const ControllerActionInfo* other);
	};

	struct CtrlChangePageActionInfo : public ControllerActionInfo {
		std::string objectId;
		std::string controllerName;
		std::string targetPage;
	public:
		virtual void setup(ByteBuffer* buffer);
		virtual void operator=(const ControllerActionInfo* other);
	};

	struct CtrlPlayTransitionActionInfo : public ControllerActionInfo {
		std::string transitionName;
		int playTimes = 0;
		float delay = 0.0f;
		bool stopOnExit = false;
	public:
		virtual void setup(ByteBuffer* buffer);
		virtual void operator=(const ControllerActionInfo* other);
	};

	struct ControlerInfo {
		std::string name;
		bool autoRadioGroupDepth;
		std::vector<std::string> pageIds;
		std::vector<std::string> pageNames;
		std::vector<ControllerActionInfo*> actions;

		~ControlerInfo();
		void setup(ByteBuffer* buffer);
		void operator=(const ControlerInfo* other);
	};

	struct HSVInfo {
		float hue = 0.0f;
		float saturation = 0.0f;
		float brightness = 0.0f;
		float contrast = 0.0f;
	};

	struct RelationItemInfo {
		RelationType type = RelationType::None;
		bool usePercent = false;
	};

	struct RelationTargetInfo {
		int targetIndex = -1;
		std::vector<RelationItemInfo*> items;
		~RelationTargetInfo();
		void operator=(const RelationTargetInfo* other);
	};

	struct RelationInfo {
		std::vector<RelationTargetInfo*> targets;
		~RelationInfo();
		void setup(ByteBuffer* buffer);
		void operator=(const RelationInfo* other);
	};

	struct ObjectInfo {
		ObjectType objectType;
		std::string temId;
		std::string pkgId;
		std::string id;
		std::string name;

		/************setbefore****************/
		cocos2d::Vec2 pos;
		cocos2d::Size* size = NULL;
		cocos2d::Size* minSize = NULL, *maxSize = NULL;
		cocos2d::Vec2* scale = NULL;
		cocos2d::Vec2* skew = NULL;
		cocos2d::Vec2* pivot = NULL;
		bool bPivotAsAchorPoint = false;
		float opacity = 1.0f;
		float rotation = 0.0f;
		bool bVisible = true;
		bool bTouchEnable = false;
		bool bGray = false;
		BlendMode blendMode = BlendMode::NORMAL;
		cocos2d::Vec4* hsv = NULL;
		std::string customData;
		
		RelationInfo* relation = NULL;

		/************setafter******************/
		std::string tooltips;
		int groupId = -1;
		/************GearBase*******************/
		std::vector<GearInfo*> gears;
	public:
		virtual ~ObjectInfo();
		virtual void setup(Package* pkg,PackageItem* pt);
		virtual void setupBefore(ByteBuffer* buffer, int beginPos);
		virtual void setupAfter(ByteBuffer* buffer, int beginPos);
		virtual void setupExtend(ByteBuffer* buffer) {};
		virtual void operator=(const ObjectInfo* other);
	};

	

	
}