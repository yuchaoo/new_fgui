#pragma once

#include "cocos2d.h"
#include "GearBase.h"

namespace fgui {

	class GObject;
	class GLoader;

	class GearIcon : public GearBase
	{
	public:
		GearIcon(GObject* owner);
		virtual ~GearIcon();

		void apply() override;
		void updateState() override;

		virtual void initWithInfo(const GearInfo* inf);
	protected:
		void addStatus(const std::string&  pageId, ByteBuffer* buffer) override;
		void init() override;

	private:
		std::unordered_map<std::string, std::string> _storage;
		std::string _default;
		GLoader* m_loader;
	};

}

