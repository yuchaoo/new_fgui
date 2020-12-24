#pragma once

#include "cocos2d.h"
#include "FieldTypes.h"

namespace fgui {
	class GObject;
	class GController;
	class GTweener;
	class ByteBuffer;
	class GComponent;
	struct GearInfo;
	struct ObjectInfo;

	struct GearTweenConfig
	{
	public:
		GearTweenConfig();

		bool tween;
		EaseType easeType;
		float duration;
		float delay;

		uint32_t _displayLockToken;
		GTweener* _tweener;
	};

	class GearBase : public cocos2d::Ref
	{
	public:
		GearBase(GObject* owner);
		virtual ~GearBase();

		GController* getController() const { return _controller; }
		void setController(GController* value);

		GearTweenConfig* getTweenConfig();

		virtual void updateFromRelations(float dx, float dy);
		virtual void apply();
		virtual void updateState();

		void setup(ByteBuffer* buffer, GComponent* parent);
		void setup(const GearInfo* info, GComponent* parent);
		virtual void initWithInfo(const GearInfo* info);
	protected:
		virtual void addStatus(const std::string&  pageId, ByteBuffer* buffer);
		virtual void init();

		GObject* _owner;
		GController* _controller;
		GearTweenConfig* _tweenConfig;
		cocos2d::Node* _node;

	};

}

