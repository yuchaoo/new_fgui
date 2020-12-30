#pragma once
#include <string>
#include <unordered_map>
#include "base/ccTypes.h"
#include "FGui.h"

namespace fgui {

	class UIConfig
	{
	public:
		static std::string defaultFont;
		static std::string buttonSound;
		static float buttonSoundVolumeScale;
		static int defaultScrollStep;
		static float defaultScrollDecelerationRate;
		static bool defaultScrollTouchEffect;
		static bool defaultScrollBounceEffect;
		static std::string verticalScrollBar;
		static std::string horizontalScrollBar;
		static int touchDragSensitivity;
		static int clickDragSensitivity;
		static int touchScrollSensitivity;
		static int defaultComboBoxVisibleItemCount;
		static std::string globalModalWaiting;
		static cocos2d::Color4F modalLayerColor;
		static std::string tooltipsWin;
		static bool bringWindowToFrontOnClick;
		static std::string windowModalWaiting;
		static std::string popupMenu;
		static std::string popupMenu_seperator;

		static void registerFont(const std::string& aliasName, const std::string& realName);
		static const std::string& getRealFontName(const std::string& aliasName, bool* isTTF = nullptr);

	private:
		struct FontNameItem
		{
			std::string name;
			bool ttf;
		};
		static std::unordered_map<std::string, FontNameItem> _fontNames;
	};

}

