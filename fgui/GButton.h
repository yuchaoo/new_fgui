#pragma once

#include "cocos2d.h"
#include "GObject.h"
#include "FieldTypes.h"
#include "GComponent.h"

namespace fgui {
	class GLabel;
	class GLoader;
	class GController;

	class GButton : public fgui::GComponent{
	public:
		static const std::string UP;
		static const std::string DOWN;
		static const std::string OVER;
		static const std::string SELECTED_OVER;
		static const std::string DISABLED;
		static const std::string SELECTED_DISABLED;

		CREATE_FUNC(GButton);
		void setTitle(const std::string& title);
		void setSelectedTitle(const std::string& title);
		void setIcon(const std::string& icon);
		void setSelectedIcon(const std::string& icon);
		void setTitleColor(const cocos2d::Color4B& color);
		void setTitleFontSize(int fontSize);
		void setSelected(bool isSelected);
		void setClickListener(std::function<void()> handler);
	protected:
		void setState(const std::string& value);
		virtual void setup(const ObjectInfo* info, cocos2d::Node* parent);
		virtual bool onTouchBegin(cocos2d::Touch* touch, cocos2d::Event* event);
		virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
		virtual void onControllerChanged(GController* controller);
	private:
		GButton();
		~GButton();
	private:
		ButtonMode m_mode;
		std::string m_sound;
		
		float m_soundVolumeScale;
		int m_downEffect;
		bool m_isDownScaled;
		float m_downEffectValue;
		float m_initScaleX, m_initScaleY;

		std::string m_title;
		std::string m_selectedTxtTitle;
		std::string m_iconURL;
		std::string m_selectIconURL;
		std::string m_state;
		bool m_isSelected;

		GController* m_relatedController;
		std::string m_relatePageId;
		GController* m_buttonController;

		fgui::GLabel* m_titleTxt;
		fgui::GLoader* m_iconLoader;
		std::function<void()> _clickHandler;
	};
}