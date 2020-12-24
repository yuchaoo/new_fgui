#pragma once

#include "ControllerAction.h"
#include "Controller.h"

namespace fgui {
	class GTransition;
	class GController;

	class PlayTransitionAction : public ControllerAction
	{
	public:
		PlayTransitionAction();
		virtual void setup(ByteBuffer * buffer) override;
		virtual void setup(const ControllerActionInfo* info);

		std::string transitionName;
		int playTimes;
		float delay;
		bool stopOnExit;

	protected:
		virtual void enter(GController* controller) override;
		virtual void leave(GController* controller) override;

		GTransition* _currentTransition;
	};

}

