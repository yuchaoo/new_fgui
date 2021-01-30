#include "GButton.h"
#include "GLabel.h"
#include "GLoader.h"
#include "Controller.h"
#include "ComponentData.h"

namespace fgui {
	const std::string GButton::UP = "up";
	const std::string GButton::DOWN = "down";
	const std::string GButton::OVER = "over";
	const std::string GButton::SELECTED_OVER = "selectedOver";
	const std::string GButton::DISABLED = "disabled";
	const std::string GButton::SELECTED_DISABLED = "selectedDisabled";

	GButton::GButton()
	:m_titleTxt(NULL)
	,m_iconLoader(NULL)
	,m_initScaleX(1.0f)
	,m_initScaleY(1.0f)
	, m_relatedController(NULL)
	, m_buttonController(NULL)
	, m_isSelected(false)
	, m_state(UP){

	}
	GButton::~GButton() {

	}

	void GButton::setTitle(const std::string& title) {
		m_title = title;
		if (m_titleTxt && m_state == UP) {
			m_titleTxt->setString(title);
		}
	}

	void GButton::setSelectedTitle(const std::string& title) {
		m_selectedTxtTitle = title;
		if (m_titleTxt && m_state == DOWN) {
			m_titleTxt->setString(title);
		}
	}

	void GButton::setIcon(const std::string& icon) {
		m_iconURL = icon;
		if (m_iconLoader && m_state == UP) {
			m_iconLoader->setURL(icon);
		}
	}

	void GButton::setSelectedIcon(const std::string& icon) {
		m_selectIconURL = icon;
		if (m_iconLoader && m_state == DOWN) {
			m_iconLoader->setURL(icon);
		}
	}

	void GButton::setTitleColor(const cocos2d::Color4B& color) {
		if (m_titleTxt) {
			m_titleTxt->setFontColor(color);
		}
	}

	void GButton::setTitleFontSize(int fontSize) {
		if (m_titleTxt) {
			m_titleTxt->setFontSize(fontSize);
		}
	}

	void GButton::setup(const ObjectInfo* inf, cocos2d::Node* parent) {
		GComponent::setup(inf, parent);
		const ButtonInfo* info = dynamic_cast<const ButtonInfo*>(inf);

		m_buttonController = getController("button");
		m_titleTxt = (fgui::GLabel*)getChildByName("title");
		m_iconLoader = (fgui::GLoader*)getChildByName("icon");

		if (!info->title.empty()) {
			setTitle(info->title);
		}
		if (!info->selectTitle.empty()) {
			setSelectedTitle(info->selectTitle);
		}
		if (!info->icon.empty()) {
			setIcon(info->icon);
		}
		if (!info->selectIcon.empty()) {
			setSelectedIcon(info->selectIcon);
		}
		if (info->titleColor) {
			setTitleColor(*(info->titleColor));
		}
		if (info->fontSize > 0) {
			setTitleFontSize(info->fontSize);
		}
		if (info->controllerIndex >= 0) {
			GComponent* parent = dynamic_cast<GComponent*>(_parent);
			m_relatedController = parent->getControllerAt(info->controllerIndex);
		}
		if (!info->relatePageId.empty()) {
			m_relatePageId = info->relatePageId;
		}
		m_mode = info->mode;
		m_downEffect = info->downEffectMode;
		m_downEffectValue = info->downEffectValue;

		m_initScaleX = getScaleX();
		m_initScaleY = getScaleY();

		setSelected(info->bSelected);
		setTouchable(true);
	}

	void GButton::setState(const std::string& value)
	{
		if (m_state == value) {
			return;
		}
		m_state = value;
		if (m_downEffect == 1) {
			auto& children = getChildren();
			if (value == DOWN || value == SELECTED_OVER || value == SELECTED_DISABLED) {
				cocos2d::Color3B color(m_downEffectValue * 255, m_downEffectValue * 255, m_downEffectValue * 255);
				for (int i = 0; i < children.size(); i++) {
					cocos2d::Node* child = children.at(i);
					child->setColor(color);
				}
			}
			else {
				for (int i = 0; i < children.size(); i++) {
					cocos2d::Node* child = children.at(i);
					child->setColor(cocos2d::Color3B::WHITE);
				}
			}
		}
		else if (m_downEffect == 2) {
			if (value == DOWN || value == SELECTED_OVER || value == SELECTED_DISABLED) {
				setScale(m_initScaleX * m_downEffectValue, m_initScaleY * m_downEffectValue);
			}
			else {
				setScale(m_initScaleX, m_initScaleY);
			}
		}
		if (m_buttonController && m_buttonController->hasPage(value)) {
			m_buttonController->setSelectedPage(value);
		}
	}

	void GButton::setSelected(bool isSelected) {
		if (m_mode == ButtonMode::COMMON || m_isSelected == isSelected) {
			return;
		}
		m_isSelected = isSelected;
		if (isSelected) {
			setState(DOWN);
			if (m_iconLoader) {
				m_iconLoader->setURL(m_selectIconURL);
			}
			
		}
		else {
			setState(UP);
			if (m_iconLoader) {
				m_iconLoader->setURL(m_iconURL);
			}
		}
	}

	bool GButton::onTouchBegin(cocos2d::Touch* touch, cocos2d::Event* event) {
		bool ret = GComponent::onTouchBegin(touch, event);
		if (ret) {
			if (m_buttonController
				&& (m_buttonController->getSelectedPage() == DISABLED
					|| m_buttonController->getSelectedPage() == SELECTED_DISABLED)) {
				return false;
			}
			if (m_mode == ButtonMode::COMMON || !m_isSelected) {
				setState(DOWN);
			}
			else if (m_isSelected && m_mode == ButtonMode::RADIO) {
				return false;
			}
			return true;
		}
		return false;
	}

	void GButton::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) {
		if (m_mode == ButtonMode::COMMON) {
			setState(UP);
			if (m_relatedController) {
				m_relatedController->setSelectedPageId(m_relatePageId);
			}
		}
		else if (!m_isSelected) {
			setSelected(true);
			if (m_relatedController) {
				m_relatedController->setSelectedPageId(m_relatePageId);
			}
		}
		else if (m_mode == ButtonMode::CHECK && m_isSelected) {
			setSelected(false);
			if (m_relatedController) {
				const std::string& pageId = m_relatedController->getPreviousPage();;
				m_relatedController->setSelectedPageId(pageId);
			}
		}
		GObject::onTouchEnded(touch, event);
		if (_clickHandler) {
			_clickHandler();
		}
	}

	void GButton::onControllerChanged(GController* controller) {
		GObject::onControllerChanged(controller);
		if (controller == m_relatedController) {
			if (m_mode == ButtonMode::CHECK || m_mode == ButtonMode::RADIO) {
				const std::string& id = m_relatedController->getSelectedPageId();
				setSelected(m_relatePageId == id);
			}
		}
	}

	void GButton::setClickListener(std::function<void()> handler) {
		_clickHandler = handler;
	}
}