#include "GText.h"
#include "GLabel.h"
#include "GTextInput.h"
#include "GLoader.h"
#include "TextFormat.h"
#include "ComponentData.h"

namespace fgui {
	GText::GText()
	:_title(NULL)
	,_icon(NULL)
	,_input(NULL){

	}

	GText::~GText() {

	}

	void GText::setTitle(const std::string& title) {
		if (_title) {
			_title->setString(title);
		}
		else if (_input) {
			_input->setString(title);
		}
	}

	void GText::setTitleColor(const cocos2d::Color4B& color) {
		if (_title) {
			_title->getTextFormat()->color = color;
			_title->applyTextFormat();
		}
		else if (_input) {
			_input->setFontColor((cocos2d::Color3B)color);
		}
	}

	void GText::setTitleFontSize(int size) {
		if (_title) {
			_title->getTextFormat()->fontSize = size;
			_title->applyTextFormat();
		}
		else if (_input) {
			_input->setFontSize(size);
		}
	}

	void GText::setIcon(const std::string& icon) {
		if (_icon) {
			_icon->setURL(icon);
		}
	}

	void GText::setup(const ObjectInfo* inf, cocos2d::Node* node) {
		GComponent::setup(inf, node);
		_title = dynamic_cast<GLabel*>(getChildByName("title"));
		_icon = dynamic_cast<GLoader*>(getChildByName("icon"));
		_input = dynamic_cast<GTextInput*>(getChildByName("title"));
		const TextInfo* info = dynamic_cast<const TextInfo*>(inf);

		if (!info->title.empty()) {
			setTitle(info->title);
		}
		if (!info->icon.empty()) {
			setIcon(info->icon);
		}
		if (info->titleColor) {
			setTitleColor(*info->titleColor);
		}
		if (info->titleFontSize > 0) {
			setTitleFontSize(info->titleFontSize);
		}
		if (info->bInput) {
			if (_input) {
				if (!info->placeHolder.empty()) {
					_input->setPlaceHolder(info->placeHolder.c_str());
				}
				if (info->maxLength > 0) {
					_input->setMaxLength(info->maxLength);
				}
				if (info->bPassword) {
					_input->setPassword(info->bPassword);
				}
			}
		}
	}
}