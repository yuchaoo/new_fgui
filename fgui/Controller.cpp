#include "Controller.h"
#include "GComponent.h"
#include "ToolSet.h"
#include "ByteBuffer.h"
#include "ControllerAction.h"
#include "ObjectData.h"

namespace fgui {
	GController::GController() :
		m_changing(false),
		autoRadioGroupDepth(false),
		m_parent(nullptr),
		m_selectedIndex(-1),
		m_previousIndex(-1)
	{
	}

	GController::~GController()
	{
		for (auto &it : m_actions)
			delete it;
	}

	void GController::setSelectedIndex(int value)
	{
		if (m_selectedIndex != value)
		{
			CCASSERT(value < (int)m_pageIds.size(), "Invalid selected index");

			m_changing = true;

			m_previousIndex = m_selectedIndex;
			m_selectedIndex = value;
			m_parent->applyController(this);

			//dispatchEvent(UIEventType::Changed);

			m_changing = false;
		}
	}

	const std::string& GController::getSelectedPage() const
	{
		if (m_selectedIndex == -1)
			return EMPTY_STRING;
		else
			return m_pageNames[m_selectedIndex];
	}

	void GController::setSelectedPage(const std::string & value)
	{
		int i = ToolSet::findInStringArray(m_pageNames, value);
		if (i == -1) {
			i = 0;
		}
		setSelectedIndex(i);
	}

	const std::string& GController::getSelectedPageId() const
	{
		if (m_selectedIndex == -1)
			return EMPTY_STRING;
		else
			return m_pageIds[m_selectedIndex];
	}

	void GController::setSelectedPageId(const std::string & value)
	{
		int i = ToolSet::findInStringArray(m_pageIds, value);
		if (i != -1)
			setSelectedIndex(i);
	}

	const std::string& GController::getPreviousPage() const
	{
		if (m_previousIndex == -1)
			return EMPTY_STRING;
		else
			return m_pageNames[m_previousIndex];
	}

	const std::string& GController::getPreviousPageId() const
	{
		if (m_previousIndex == -1)
			return EMPTY_STRING;
		else
			return m_pageIds[m_previousIndex];
	}

	int GController::getPageCount() const
	{
		return (int)m_pageIds.size();
	}

	bool GController::hasPage(const std::string & aName) const
	{
		return ToolSet::findInStringArray(m_pageNames, aName) != -1;
	}

	int GController::getPageIndexById(const std::string & value) const
	{
		return ToolSet::findInStringArray(m_pageIds, value);
	}

	const std::string& GController::getPageNameById(const std::string & value) const
	{
		int i = ToolSet::findInStringArray(m_pageIds, value);
		if (i != -1)
			return m_pageNames[i];
		else
			return EMPTY_STRING;
	}

	const std::string& GController::getPageId(int index) const
	{
		return m_pageIds[index];
	}

	void GController::setOppositePageId(const std::string & value)
	{
		int i = ToolSet::findInStringArray(m_pageIds, value);
		if (i > 0)
			setSelectedIndex(0);
		else if (m_pageIds.size() > 1)
			setSelectedIndex(1);
	}

	void GController::runActions()
	{
		if (m_actions.empty())
			return;

		for (auto &it : m_actions) {
			it->run(this, getPreviousPageId(), getSelectedPageId());
		}
	}

	void GController::setup(const ControlerInfo* info) {
		m_name = info->name;
		autoRadioGroupDepth = info->autoRadioGroupDepth;
		m_pageIds = info->pageIds;
		m_pageNames = info->pageNames;
		if (info->actions.size() > 0) {
			m_actions.resize(info->actions.size());
			for (size_t i = 0; i < info->actions.size(); ++i) {
				ControllerActionInfo* actionInfo = info->actions[i];
				ControllerAction* action = ControllerAction::createAction(actionInfo->type);
				action->setup(actionInfo);
				m_actions[i] = action;
			}
		}
		if (m_parent != nullptr && m_pageIds.size() > 0)
			m_selectedIndex = 0;
		else
			m_selectedIndex = -1;
	}

	void GController::setup(ByteBuffer* buffer)
	{
		int beginPos = buffer->position;
		buffer->Seek(beginPos, 0);

		m_name = buffer->ReadS();
		autoRadioGroupDepth = buffer->ReadBool();

		buffer->Seek(beginPos, 1);

		int cnt = buffer->ReadShort();
		m_pageIds.resize(cnt);
		m_pageNames.resize(cnt);
		for (int i = 0; i < cnt; i++)
		{
			m_pageIds[i].assign(buffer->ReadS());
			m_pageNames[i].assign(buffer->ReadS());
		}

		buffer->Seek(beginPos, 2);

		cnt = buffer->ReadShort();
		if (cnt > 0){
			for (int i = 0; i < cnt; i++){
				int nextPos = buffer->ReadShort();
				nextPos += buffer->position;

				ControllerAction* action = ControllerAction::createAction(buffer->ReadByte());
				action->setup(buffer);
				m_actions.push_back(action);

				buffer->position = nextPos;
			}
		}

		if (m_parent != nullptr && m_pageIds.size() > 0)
			m_selectedIndex = 0;
		else
			m_selectedIndex = -1;
	}

}
