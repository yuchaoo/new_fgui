#pragma once

#include "cocos2d.h"
#include "GearBase.h"

namespace fgui {

	class GObject;
	class GTweener;

	class GearSize : public GearBase
	{
	public:
		GearSize(GObject* owner);
		virtual ~GearSize();

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

		std::unordered_map<std::string, cocos2d::Vec4> _storage;
		cocos2d::Vec4 _default;
	};

}


