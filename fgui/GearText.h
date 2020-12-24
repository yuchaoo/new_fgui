#pragma once

#include "cocos2d.h"
#include "GearBase.h"

namespace fgui {
	class GObject;
	class GLabel;
	struct GearInfo;

	class GearText : public GearBase
	{
	public:
		GearText(GObject* owner);
		virtual ~GearText();

		void apply() override;
		void updateState() override;
		virtual void initWithInfo(const GearInfo* inf);
	protected:
		void addStatus(const std::string&  pageId, ByteBuffer* buffer) override;
		void init() override;

	private:
		std::unordered_map<std::string, std::string> _storage;
		std::string _default;
		GLabel* m_label;
	};

}

