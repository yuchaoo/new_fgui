#pragma once

#include "cocos2d.h"

namespace fgui {

	class GComponent;
	class ControllerAction;
	class ByteBuffer;
	struct ControlerInfo;

	static std::string EMPTY_STRING("");
	class GController : cocos2d::Ref
	{
	public:
		GController();
		virtual ~GController();

		const std::string& getName() const { return m_name; }

		GComponent* getParent() const { return m_parent; }
		void setParent(GComponent* value) { m_parent = value; }

		int getSelectedIndex() const { return m_selectedIndex; }
		void setSelectedIndex(int value);

		const std::string& getSelectedPage() const;
		void setSelectedPage(const std::string& value);

		const std::string& getSelectedPageId() const;
		void setSelectedPageId(const std::string& value);

		int getPrevisousIndex() const { return m_previousIndex; }
		const std::string& getPreviousPage() const;
		const std::string& getPreviousPageId() const;

		int getPageCount() const;
		bool hasPage(const std::string& aName) const;
		int getPageIndexById(const std::string& value) const;

		const std::string& getPageNameById(const std::string& value) const;
		const std::string& getPageId(int index) const;

		void setOppositePageId(const std::string& value);
		void runActions();

		void setup(ByteBuffer* buffer);
		void setup(const ControlerInfo* info);
		

	private:
		GComponent* m_parent;
		int m_selectedIndex;
		int m_previousIndex;

		std::string m_name;
		bool m_changing;
		bool autoRadioGroupDepth;

		std::vector<std::string> m_pageIds;
		std::vector<std::string> m_pageNames;
		std::vector<ControllerAction*> m_actions;
		friend class PlayTransitionAction;
		friend class ChangePageAction;
	};

}

