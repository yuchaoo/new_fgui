#pragma once

#include "cocos2d.h"
#include "GearBase.h"

namespace fgui {

	class GObject;
	class GTweener;
	struct GearInfo;

	class GearLookValue
	{
	public:
		float alpha;
		float rotation;
		bool grayed;
		bool touchable;

		GearLookValue();
		GearLookValue(float alpha, float rotation, bool grayed, bool touchable);
	};

	class GearLook : public GearBase
	{
	public:
		GearLook(GObject* owner);
		virtual ~GearLook();

		void apply() override;
		void updateState() override;
		virtual void initWithInfo(const GearInfo* inf);
	protected:
		void addStatus(const std::string&  pageId, ByteBuffer* buffer) override;
		void init() override;

	private:
		void onTweenUpdate(GTweener* tweener);
		void onTweenComplete();

		std::unordered_map<std::string, GearLookValue> _storage;
		GearLookValue _default;
	};

}

