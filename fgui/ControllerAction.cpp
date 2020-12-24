#include "ControllerAction.h"
#include "Controller.h"
#include "ChangePageAction.h"
#include "PlayTransitionAction.h"
#include "ByteBuffer.h"
#include "ObjectData.h"

namespace fgui {

	ControllerAction * ControllerAction::createAction(int type)
	{
		switch (type)
		{
		case 0:
			return new PlayTransitionAction();

		case 1:
			return new ChangePageAction();
		}
		return nullptr;
	}

	ControllerAction::ControllerAction()
	{
	}

	ControllerAction::~ControllerAction()
	{
	}

	void ControllerAction::run(GController * controller, const std::string & prevPage, const std::string & curPage)
	{
		if ((fromPage.empty() || std::find(fromPage.cbegin(), fromPage.cend(), prevPage) != fromPage.cend())
			&& (toPage.empty() || std::find(toPage.cbegin(), toPage.cend(), curPage) != toPage.cend()))
			enter(controller);
		else
			leave(controller);
	}

	void ControllerAction::setup(ByteBuffer * buffer)
	{
		int cnt = buffer->ReadShort();
		fromPage.resize(cnt);
		for (int i = 0; i < cnt; i++) {
			fromPage[i].assign(buffer->ReadS());
		}

		cnt = buffer->ReadShort();
		toPage.resize(cnt);
		for (int i = 0; i < cnt; i++) {
			toPage[i].assign(buffer->ReadS());
		}
	}

	void ControllerAction::setup(const ControllerActionInfo* info) {
		fromPage = info->fromPages;
		toPage = info->toPages;
	}
}
