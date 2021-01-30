#pragma once
#include "cocos2d.h"
#include "ui/UIEditBox/UIEditBox.h"
#include "GObject.h"
using namespace cocos2d::ui;


namespace fgui {
	class TextFormat;
	struct ObjectInfo;

	class GTextInput
		: public EditBox
		, public GObject
		, public EditBoxDelegate
	{
	public:
		CREATE_FUNC(GTextInput);
		GTextInput();
		~GTextInput();
		bool init();
		std::string getString() const;
		void setString(const std::string& value);
		void applyTextFormat();
		bool isSingleLine() const;
		void setSingleLine(bool value);
		void setPassword(bool value);
	protected:
		virtual void setup(const ObjectInfo* inf, cocos2d::Node* parent);
		virtual void editBoxReturn(EditBox* editBox) override;
		virtual void editBoxTextChanged(EditBox* editBox, const std::string& text) override;
	private:
		bool _ubbEnabled;
		bool _password;
		TextFormat* _textFormat;
		std::string _text;
		bool _isSingleLine;
	};
}
