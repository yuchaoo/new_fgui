#pragma once


namespace fgui {

	enum class PackageItemType
	{
		IMAGE,
		MOVIECLIP,
		SOUND,
		COMPONENT,
		ATLAS,
		FONT,
		SWF,
		MISC,
		UNKNOWN
	};

	enum class ObjectType
	{
		IMAGE,
		MOVIECLIP,
		SWF,
		GRAPH,
		LOADER,
		GROUP,
		TEXT,
		RICHTEXT,
		INPUTTEXT,
		COMPONENT,
		LIST,
		LABEL,
		BUTTON,
		COMBOBOX,
		PROGRESSBAR,
		SLIDER,
		SCROLLBAR,
		UNKNOWN
	};

	enum class GearType {
		DISPLAY,
		XY,
		Size,
		LOOK,
		COLOR,
		ANIMATE,
		TEXT,
		ICON,
		NONE
	};

	enum class ButtonMode
	{
		COMMON,
		CHECK,
		RADIO
	};

	enum class ChildrenRenderOrder
	{
		ASCENT,
		DESCENT,
		ARCH,
	};

	enum class OverflowType
	{
		VISIBLE,
		HIDDEN,
		SCROLL
	};

	enum class ScrollType
	{
		HORIZONTAL,
		VERTICAL,
		BOTH
	};

	enum ScrollBarDisplayType
	{
		DEFAULT,
		VISIBLE,
		AUTO,
		HIDDEN
	};

	enum class LoaderFillType
	{
		NONE,
		SCALE,
		SCALE_MATCH_HEIGHT,
		SCALE_MATCH_WIDTH,
		SCALE_FREE,
		SCALE_NO_BORDER
	};

	enum class ProgressTitleType
	{
		PERCENT,
		VALUE_MAX,
		VALUE,
		MAX
	};

	enum class ListLayoutType
	{
		SINGLE_COLUMN,
		SINGLE_ROW,
		FLOW_HORIZONTAL,
		FLOW_VERTICAL,
		PAGINATION
	};

	enum class ListSelectionMode
	{
		SINGLE,
		MULTIPLE,
		MULTIPLE_SINGLECLICK,
		NONE
	};

	enum class GroupLayoutType
	{
		NONE,
		HORIZONTAL,
		VERTICAL
	};

	enum class PopupDirection
	{
		AUTO,
		UP,
		DOWN
	};

	enum class AutoSizeType
	{
		NONE,
		BOTH,
		HEIGHT,
		SHRINK
	};

	enum class FlipType
	{
		NONE,
		HORIZONTAL,
		VERTICAL,
		BOTH
	};

	enum class TransitionActionType
	{
		XY,
		Size,
		Scale,
		Pivot,
		Alpha,
		Rotation,
		Color,
		Animation,
		Visible,
		Sound,
		Transition,
		Shake,
		ColorFilter,
		Skew,
		Text,
		Icon,
		Unknown
	};

	enum class FillMethod
	{
		None,
		Horizontal,
		Vertical,
		Radial90,
		Radial180,
		Radial360,
	};

	enum class FillOrigin
	{
		Top,
		Bottom,
		Left,
		Right,
		LeftTop,
		LeftBottom,
		RightTop,
		RightBottom
	};

	enum class BlendMode
	{
		NORMAL = 0,
		NONE = 1,
		ADD = 2,
		MULTIPLY = 3,
		SCREEN = 4,
	};

	enum class TweenPropType
	{
		None,
		X,
		Y,
		Position,
		Width,
		Height,
		Size,
		ScaleX,
		ScaleY,
		Scale,
		Rotation,
		Alpha,
		Progress
	};

	enum class EaseType
	{
		Linear,
		SineIn,
		SineOut,
		SineInOut,
		QuadIn,
		QuadOut,
		QuadInOut,
		CubicIn,
		CubicOut,
		CubicInOut,
		QuartIn,
		QuartOut,
		QuartInOut,
		QuintIn,
		QuintOut,
		QuintInOut,
		ExpoIn,
		ExpoOut,
		ExpoInOut,
		CircIn,
		CircOut,
		CircInOut,
		ElasticIn,
		ElasticOut,
		ElasticInOut,
		BackIn,
		BackOut,
		BackInOut,
		BounceIn,
		BounceOut,
		BounceInOut,
		Custom
	};

	enum class RelationType
	{
		None = -1,
		Left_Left,
		Left_Center,
		Left_Right,
		Center_Center,
		Right_Left,
		Right_Center,
		Right_Right,

		Top_Top,
		Top_Middle,
		Top_Bottom,
		Middle_Middle,
		Bottom_Top,
		Bottom_Middle,
		Bottom_Bottom,

		Width,
		Height,

		LeftExt_Left,
		LeftExt_Right,
		RightExt_Left,
		RightExt_Right,
		TopExt_Top,
		TopExt_Bottom,
		BottomExt_Top,
		BottomExt_Bottom,

		Size
	};
}
