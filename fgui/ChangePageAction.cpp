#include "ChangePageAction.h"
#include "Controller.h"
#include "GComponent.h"
#include "ByteBuffer.h"
#include "ObjectData.h"

namespace fgui {

	void ChangePageAction::setup(ByteBuffer * buffer)
	{
		ControllerAction::setup(buffer);
		m_objectId = buffer->ReadS();
		m_controllerName = buffer->ReadS();
		m_targetPage = buffer->ReadS();
	}

	void ChangePageAction::setup(const ControllerActionInfo* info) {
		ControllerAction::setup(info);
		const CtrlChangePageActionInfo* inf = dynamic_cast<const CtrlChangePageActionInfo*>(info);
		m_objectId = inf->objectId;
		m_controllerName = inf->controllerName;
		m_targetPage = inf->targetPage;
	}

	void ChangePageAction::enter(GController * controller)
	{
		if (m_controllerName.empty()) {
			return;
		}
			
		GComponent* gcom = NULL;
		if (!m_objectId.empty()) {
			auto& children = controller->getParent()->getChildren();
			for (ssize_t i = 0; i < children.size(); ++i) {
				GComponent* child = dynamic_cast<GComponent*>(children.at(i));
				if (child && child->getId() == m_objectId) {
					gcom = child;
					break;
				}
			}
		}
		else {
			gcom = controller->getParent();
		}
			
		if (gcom != nullptr){
			GController* cc = gcom->getController(m_controllerName);
			if (cc != nullptr && cc != controller && !cc->m_changing) {
				cc->setSelectedPageId(m_targetPage);
			}
		}
	}

	void ChangePageAction::leave(GController * controller)
	{
	}

}