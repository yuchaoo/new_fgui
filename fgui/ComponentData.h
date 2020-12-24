#pragma once
#include "ObjectData.h"
#include "FieldTypes.h"
#include "Margin.h"
#include "TransitionData.h"
#include <unordered_map>

#define SAVE_ALLCOTE(ptr, type) if(!ptr) ptr = new type();
#define SAVE_DELETE(ptr) if(ptr) delete (ptr);
#define SAVE_ASSIGN(ptr, vptr, type) \
	if(vptr) { \
		if (!ptr) { \
			ptr = new type(); \
		} \
		* ptr = *vptr;\
	}
	

namespace fgui {
	class ByteBuffer;
	class PkgItem;
	class Package;

	ObjectInfo* createComponentInfo(ObjectType type);

	struct ComponentInfo : public ObjectInfo {
		float width = 0.0f;
		float height = 0.0f;
		Margin* margin = NULL;
		OverflowType overflow = OverflowType::VISIBLE;
		ScrollType scrollType = ScrollType::HORIZONTAL;
		ScrollBarDisplayType scrollBarDisplayType = ScrollBarDisplayType::DEFAULT;
		bool bPageMode = false;
		bool bBouncebackEffect = false;
		bool bInertiaEnabled = false;
		bool bClipEnabled = false;
		std::vector<ControlerInfo*> controllers;
		std::vector<ObjectInfo*> children;
		int maskId = -1;
		bool bInverted = false;
		std::string hitTestId;
		std::vector<TransitionInfo*> transitions;
		std::unordered_map <std::string, std::string> ctrlDefaultPage;
	public:
		virtual ~ComponentInfo();
		virtual void setup(Package* pkg, PkgItem* pt);
		virtual void setupAfter(ByteBuffer* buffer, int beginPos);
		virtual void operator=(const ObjectInfo* other);
	};

	struct ButtonInfo : public ComponentInfo {
		std::string title;
		std::string selectTitle;
		std::string icon;
		std::string selectIcon;
		cocos2d::Color4B* titleColor = NULL;
		int fontSize = 0;
		int controllerIndex = -1;
		std::string relatePageId;
		std::string sound;
		float soundVolumeScale = 0.0f;
		bool bSelected = false;
		ButtonMode mode = ButtonMode::COMMON;
		int downEffectMode = 0;
		float downEffectValue = 0;
	public:
		~ButtonInfo();
		virtual void setupAfter(ByteBuffer* buffer, int beginPos);
		virtual void setupExtend(ByteBuffer* buffer);
		virtual void operator=(const ObjectInfo* other);
	};


	struct AnimationInfo : public ObjectInfo {
		cocos2d::Color4B* color = NULL;
		FlipType flipType = FlipType::NONE;
		int initFrame = 0;
		bool bPlaying = true;
	public:
		~AnimationInfo();
		virtual void setupBefore(ByteBuffer* buffer, int beginPos);
		virtual void operator=(const ObjectInfo* other);
	};

	struct GraphInfo : public ObjectInfo {
		int type = 0; //1,2
		int lineSize = 1;
		cocos2d::Color4B* lineColor = NULL;
		cocos2d::Color4B* fillColor = NULL;
	public:
		~GraphInfo();
		virtual void setupBefore(ByteBuffer* buffer, int beginPos);
		virtual void operator=(const ObjectInfo* other);
	};

	struct GroupInfo : public ObjectInfo {
		GroupLayoutType layoutType = GroupLayoutType::NONE;
		int lineGap = 0;
		int columnGap = 0;
	public:
		virtual void setupBefore(ByteBuffer* buffer, int beginPos);
		virtual void operator=(const ObjectInfo* other);
	};

	struct LabelInfo : public ObjectInfo {
		TextFormat format;
		bool bUbbEnabled = false;
		AutoSizeType autoSize = AutoSizeType::NONE;
		bool bSingleLine = true;
		bool bOutLine = false;
		bool bShadow = false;
		std::string str;
	public:
		virtual void setupBefore(ByteBuffer* buffer, int beginPos);
		virtual void operator=(const ObjectInfo* other);
	};

	struct ListItemInfo {
		std::string url;
		std::string name;
		std::unordered_map<std::string, std::string> controllerInfo;
	};

	struct ListInfo : public ComponentInfo {
		ListLayoutType layoutType = ListLayoutType::FLOW_VERTICAL;
		ListSelectionMode selectMode = ListSelectionMode::NONE;
		cocos2d::TextHAlignment hAlign = cocos2d::TextHAlignment::CENTER;
		cocos2d::TextVAlignment vAlign = cocos2d::TextVAlignment::CENTER;
		int lineGap = 0;
		int columnGap = 0;
		int lineCount = 0;
		int columnCount = 0;
		bool bAutoResizeItem = false;
		ChildrenRenderOrder renderOrder = ChildrenRenderOrder::ARCH;
		int apexIndex;

		std::string defaultItem;
		std::vector <ListItemInfo*> items;
	public:
		~ListInfo();
		virtual void setupBefore(ByteBuffer* buffer, int beginPos);
		virtual void operator=(const ObjectInfo* other);
	};

	struct LoaderInfo : public ObjectInfo {
		std::string url;
		cocos2d::TextHAlignment hAlign = cocos2d::TextHAlignment::CENTER;
		cocos2d::TextVAlignment vAlign = cocos2d::TextVAlignment::CENTER;
		LoaderFillType fillType = LoaderFillType::NONE;
		bool bShrinkOnly = false;
		bool bAutoSize = false;
		bool bPlaying = false;
		int frame = 0;
		cocos2d::Color4B* color = NULL;
		FillMethod fillMethod = FillMethod::None;
		FillOrigin fillOrign = FillOrigin::Left;
		bool bFillClockwise = false;
		float fillAmount = 0.0f;
	public:
		~LoaderInfo();
		virtual void setupBefore(ByteBuffer* buffer, int beginPos);
		virtual void operator=(const ObjectInfo* other);
	};

	struct ProgressBarInfo : public ComponentInfo {
		bool bDefault = true;
		float maxValue = 100.0f;
		float value = 0.0f;
		ProgressTitleType titleType = ProgressTitleType::PERCENT;
		bool bReverse = false;
	public:
		virtual void setupAfter(ByteBuffer* buffer, int beginPos);
		virtual void setupExtend(ByteBuffer* buffer);
		virtual void operator=(const ObjectInfo* other);
	};

	struct RichTextInfo : public ObjectInfo {
		TextFormat format;
		bool bUbbEnabled = false;
		bool bSingleLine = false;
		AutoSizeType autoSizeType = AutoSizeType::NONE;
		bool bOutline = false;
		bool bShadow = false;
		bool bPassword = false;
		std::string str;
		std::string placeHolder;
		int maxLength = 0;
	public:
		virtual void setupBefore(ByteBuffer* buffer, int beginPos);
		virtual void operator=(const ObjectInfo* other);
	};

	struct SliderInfo : public ComponentInfo {
		bool bDefault = false;
		float maxValue = 100.0f;
		float value = 0.0f;
		ProgressTitleType titleType = ProgressTitleType::PERCENT;
		bool bReverse = false;
	public:
		virtual void setupAfter(ByteBuffer* buffer, int beginPos);
		virtual void setupExtend(ByteBuffer* buffer);
		virtual void operator=(const ObjectInfo* other);
	};

	struct SpriteInfo : public ObjectInfo {
		cocos2d::Color4B* color = NULL;
		FlipType flipType = FlipType::NONE;
		FillMethod fillMethod = FillMethod::None;
		FillOrigin fillOrigin = FillOrigin::Left;
		bool bClockwise = false;
		float fillAmount = 0.0f;
	public:
		~SpriteInfo();
		virtual void setupBefore(ByteBuffer* buffer, int beginPos);
		virtual void operator=(const ObjectInfo* other);
	};

	struct TextInfo : public ComponentInfo {
		std::string title;
		std::string icon;
		cocos2d::Color4B* titleColor = NULL;
		int titleFontSize = 0;
		bool bInput = false;
		std::string placeHolder;
		std::string restrict;
		int maxLength = 0;
		int keyboardType = 0;
		bool bPassword = false;
	public:
		~TextInfo();
		virtual void setupAfter(ByteBuffer* buffer, int beginPos);
		virtual void operator=(const ObjectInfo* other);
	};

	struct TextInputInfo : ObjectInfo {
		TextFormat format;
		bool bUbbEnabled = false;
		AutoSizeType autoSizeType = AutoSizeType::NONE;
		bool bSingleLine = false;
		bool bOutline = false;
		bool bShadow = false;
		std::string placeHolder;
		int maxLength = 0;
		bool bPassword = false;
	public:
		virtual void setupBefore(ByteBuffer* buffer, int beginPos);
		virtual void operator=(const ObjectInfo* other);
	};
}