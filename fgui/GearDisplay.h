#pragma once

#include "cocos2d.h"
#include "GearBase.h"

namespace fgui {

	class GObject;

	class GearDisplay : public GearBase
	{
	public:
		GearDisplay(GObject* owner);
		virtual ~GearDisplay();

		void apply() override;
		void updateState() override;

		uint32_t addLock();
		void releaseLock(uint32_t token);
		bool isConnected();

		std::vector<std::string> pages;
		virtual void initWithInfo(const GearInfo* info);
	protected:
		void addStatus(const std::string&  pageId, ByteBuffer* buffer) override;
		void init() override;

	private:
		int _visible;
		uint32_t _displayLockToken;
	};

}

