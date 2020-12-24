#pragma once


#include "cocos2d.h"
#include "GearBase.h"

namespace fgui {

	class GObject;
	struct GearInfo;

	class GearXY : public GearBase
	{
	public:
		GearXY(GObject* owner);
		virtual ~GearXY();

		void apply() override;
		void updateState() override;
		void updateFromRelations(float dx, float dy) override;
		virtual void initWithInfo(const GearInfo* inf);
	protected:
		void addStatus(const std::string&  pageId, ByteBuffer* buffer) override;
		void init() override;

	private:
		void onTweenUpdate(GTweener* tweener);
		void onTweenComplete();

		std::unordered_map<std::string, cocos2d::Vec2> m_storage;
		cocos2d::Vec2 m_default;
	};
}

