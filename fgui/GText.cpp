#include "fgui/GText.h"
#include "fgui/GLabel.h"
#include "fgui/GTextInput.h"
#include "fgui/GLoader.h"

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

	void GText::setupAfter(ByteBuffer* buffer, int pos) {
		GComponent::setupAfter(buffer, pos);
		_title = dynamic_cast<GLabel*>(getChildByName("title"));
		_icon = dynamic_cast<GLoader*>(getChildByName("icon"));
		_input = dynamic_cast<GTextInput*>(getChildByName("title"));

		if (!buffer->Seek(pos, 6))
			return;

		if ((ObjectType)buffer->ReadByte() != _pkgItem->objectType)
			return;

		const std::string* str;
		if ((str = buffer->ReadSP())) {
			setTitle(*str);
		}
		if ((str = buffer->ReadSP())) {
			setIcon(*str);
		}	
		if (buffer->ReadBool()) {
			setTitleColor(buffer->ReadColor());
		}
		int iv = buffer->ReadInt();
		if (iv != 0) {
			setTitleFontSize(iv);
		}

		if (buffer->ReadBool()){
			if (_input){
				if ((str = buffer->ReadSP())) {
					_input->setPlaceHolder(str->c_str());
				}
				if ((str = buffer->ReadSP())) {
					//_input->setRestrict(*str);
				}	
				iv = buffer->ReadInt();
				if (iv != 0) {
					_input->setMaxLength(iv);
				}	
				iv = buffer->ReadInt();
				if (iv != 0) {
					//_input->setKeyboardType(iv);
				}	
				if (buffer->ReadBool()) {
					_input->setPassword(true);
				}
			}
			else
				buffer->Skip(13);
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