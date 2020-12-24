#pragma once

#include "ControllerAction.h"
#include "Controller.h"

namespace fgui {
	struct ControllerActionInfo;

	class ChangePageAction : public ControllerAction
	{
	public:
		virtual void setup(ByteBuffer * buffer) override;
		virtual void setup(const ControllerActionInfo* info);
	protected:
		virtual void enter(GController* controller) override;
		virtual void leave(GController* controller) override;
	protected:
		std::string m_objectId;
		std::string m_controllerName;
		std::string m_targetPage;
	};

}

