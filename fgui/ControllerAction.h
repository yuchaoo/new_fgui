#pragma once
#include <string>
#include <vector>

namespace fgui {

	class GController;
	class ByteBuffer;
	struct ControllerActionInfo;

	class ControllerAction
	{
	public:
		static ControllerAction* createAction(int types);
		ControllerAction();
		virtual ~ControllerAction();
		virtual void run(GController* controller, const std::string& prevPage, const std::string& curPage);
		virtual void setup(ByteBuffer * buffer);
		virtual void setup(const ControllerActionInfo* info);
	protected:
		virtual void enter(GController* controller) = 0;
		virtual void leave(GController* controller) = 0;
	protected:
		std::vector<std::string> fromPage;
		std::vector<std::string> toPage;
	};

}

