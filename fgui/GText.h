#pragma once
#include "GObject.h"
#include "GComponent.h"

namespace fgui {
	class GLabel;
	class GLoader;
	class GTextInput;

	class GText
		:public GComponent{
	public:
		CREATE_FUNC(GText);
		GText();
		~GText();
		void setTitle(const std::string& title);
		void setTitleColor(const cocos2d::Color4B& color);
		void setTitleFontSize(int size);
		void setIcon(const std::string& icon);
	protected:
		virtual void setupAfter(ByteBuffer* buffer, int pos);
		virtual void setup(const ObjectInfo* info, cocos2d::Node* node);
	private:
		GLabel* _title;
		GLoader* _icon;
		GTextInput* _input;
	};
}