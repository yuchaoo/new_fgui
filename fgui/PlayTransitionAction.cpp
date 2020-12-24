#include "PlayTransitionAction.h"
#include "Controller.h"
#include "GComponent.h"
#include "ByteBuffer.h"
#include "GTransition.h"
#include "ObjectData.h"
namespace fgui {

	PlayTransitionAction::PlayTransitionAction() :
		playTimes(1), 
		delay(0), 
		stopOnExit(false),
		_currentTransition(nullptr)
	{
	}

	void PlayTransitionAction::setup(ByteBuffer * buffer)
	{
		ControllerAction::setup(buffer);

		transitionName = buffer->ReadS();
		playTimes = buffer->ReadInt();
		delay = buffer->ReadFloat();
		stopOnExit = buffer->ReadBool();
	}

	void PlayTransitionAction::setup(const ControllerActionInfo* info) {
		ControllerAction::setup(info);
		const CtrlPlayTransitionActionInfo* inf = dynamic_cast<const CtrlPlayTransitionActionInfo*>(info);
		transitionName = inf->transitionName;
		playTimes = inf->playTimes;
		delay = inf->delay;
		stopOnExit = inf->stopOnExit;
	}

	void PlayTransitionAction::enter(GController * controller)
	{
		GTransition* trans = controller->getParent()->getTransition(transitionName);
		if (trans != nullptr){
			if (_currentTransition != nullptr && _currentTransition->isPlaying())
				trans->changePlayTimes(playTimes);
			else
				trans->play(playTimes, delay, nullptr);
			_currentTransition = trans;
		}
	}

	void PlayTransitionAction::leave(GController * controller)
	{
		if (stopOnExit && _currentTransition != nullptr)
		{
			_currentTransition->stop();
			_currentTransition = nullptr;
		}
	}

}