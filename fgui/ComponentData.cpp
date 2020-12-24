#include "ComponentData.h"
#include "ByteBuffer.h"
#include "PackageManager.h"
#include "UIPackage.h"
#include "PkgItem.h"
#include "Package.h"

namespace fgui {

	ObjectInfo* createComponentInfo(ObjectType type) {
		switch (type) {
		case ObjectType::BUTTON:
			return new ButtonInfo();
		case ObjectType::COMPONENT:
			return new ComponentInfo();
		case ObjectType::GRAPH:
			return new GraphInfo();
		case ObjectType::GROUP:
			return new GroupInfo();
		case ObjectType::IMAGE:
			return new SpriteInfo();
		case ObjectType::INPUTTEXT:
			return new TextInputInfo();
		case ObjectType::LABEL:
			return new TextInfo();
		case ObjectType::LIST:
			return new ListInfo();
		case ObjectType::LOADER:
			return new LoaderInfo();
		case ObjectType::MOVIECLIP:
			return new AnimationInfo();
		case ObjectType::PROGRESSBAR:
			return new ProgressBarInfo();
		case ObjectType::RICHTEXT:
			return new RichTextInfo();
		case ObjectType::SLIDER:
			return new SliderInfo();
		case ObjectType::TEXT:
			return new LabelInfo();
		}
		return NULL;
	}

	ComponentInfo::~ComponentInfo() {
		for (size_t i = 0; i < controllers.size(); ++i) {
			delete controllers[i];
		}
		for (size_t i = 0; i < children.size(); ++i) {
			delete children[i];
		}
		for (size_t i = 0; i < transitions.size(); ++i) {
			delete transitions[i];
		}
		SAVE_DELETE(margin);
	}

	void ComponentInfo::setup(Package* pkg, PkgItem* pt) {
		PackageManager* pkgMgr = PackageManager::getInstance();
		CompItem* compItem = dynamic_cast<CompItem*>(pt);
		CCASSERT(compItem, "the item is not compitem");
		ByteBuffer* buffer = compItem->_rawData;

		buffer->Seek(0, 0);
		width = buffer->ReadInt();
		height = buffer->ReadInt();
		if (buffer->ReadBool()) {
			SAVE_ALLCOTE(minSize, cocos2d::Size);
			SAVE_ALLCOTE(maxSize, cocos2d::Size);
			minSize->width = buffer->ReadInt();
			maxSize->width = buffer->ReadInt();
			minSize->height = buffer->ReadInt();
			maxSize->height = buffer->ReadInt();
		}
		if (buffer->ReadBool()) {
			SAVE_ALLCOTE(pivot, cocos2d::Vec2);
			pivot->x = buffer->ReadFloat();
			pivot->y = buffer->ReadFloat();
			bPivotAsAchorPoint = buffer->ReadBool();
		}
		if (buffer->ReadBool()) {
			SAVE_ALLCOTE(margin, Margin);
			margin->top = buffer->ReadInt();
			margin->bottom = buffer->ReadInt();
			margin->left = buffer->ReadInt();
			margin->right = buffer->ReadInt();
		}
		overflow = (OverflowType)buffer->ReadByte();
		if (overflow == OverflowType::SCROLL) {
			scrollType = (ScrollType)buffer->ReadByte();
			scrollBarDisplayType = (ScrollBarDisplayType)buffer->ReadByte();
			int flags = buffer->ReadInt();
			if (buffer->ReadBool()) {
				int top = buffer->ReadInt();
				int bottom = buffer->ReadInt();
				int left = buffer->ReadInt();
				int right = buffer->ReadInt();
			}
			buffer->ReadS();
			buffer->ReadS();
			buffer->ReadS();
			buffer->ReadS();
			bPageMode = (flags & 8) != 0;
			bBouncebackEffect = (flags & 64) != 0;
			bInertiaEnabled = (flags & 256) != 0;
			bClipEnabled = (flags & 512) != 0;
		}
		if (buffer->ReadBool()) {
			buffer->Skip(8);
		}
		buffer->Seek(0, 1);
		int countrolerCount = buffer->ReadShort();
		for (int i = 0; i < countrolerCount; i++) {
			int nextPos = buffer->ReadShort();
			nextPos += buffer->position;

			ControlerInfo* controller = new ControlerInfo();
			controller->setup(buffer);
			controllers.push_back(controller);

			buffer->position = nextPos;
		}

		buffer->Seek(0, 2);
		int childCount = buffer->ReadShort();
		for (int i = 0; i < childCount; ++i) {
			int dataLen = buffer->ReadShort();
			int curPos = buffer->position;
			buffer->Seek(curPos, 0);

			ObjectType type = (ObjectType)buffer->ReadByte();
			const std::string& src = buffer->ReadS();
			const std::string& pkgId = buffer->ReadS();

			Package* pkg = NULL;
			PkgItem* item = NULL;
			pkg = pkgId.empty() ? (pt ? pt->getOwner() : NULL) : pkgMgr->getPkg(pkgId);
			item = src.empty() ? NULL : (pkg ? pkg->getPkgItemById(src) : NULL);

			type = item ? item->getObjType() : type;
			ObjectInfo* child = createComponentInfo(type);
			CompItem* compItem = dynamic_cast<CompItem*>(item);

			if (compItem) {
				const ComponentInfo* compInfo = compItem->getDataInfo();
				child->operator=(compInfo);
			}
			else {
				child->temId = src;
				child->pkgId = pkg ? pkg->getId() : pkgId;
			}
			child->objectType = type;
			child->setupBefore(buffer, curPos);
			children.push_back(child);

			buffer->position = curPos + dataLen;
		}

		buffer->Seek(0, 3);
		SAVE_ALLCOTE(relation, RelationInfo);
		relation->setup(buffer);

		buffer->Seek(0, 2);
		buffer->Skip(2);
		for (int i = 0; i < childCount; ++i) {
			int nextPos = buffer->ReadShort() + buffer->position;
			buffer->Seek(buffer->position, 3);

			ObjectInfo* child = children[i];
			SAVE_ALLCOTE(child->relation, RelationInfo);
			child->relation->setup(buffer);

			buffer->position = nextPos;
		}

		buffer->Seek(0, 2);
		buffer->Skip(2);

		for (int i = 0; i < childCount; ++i) {
			int nextPos = buffer->ReadShort() + buffer->position;
			ObjectInfo* child = children[i];
			child->setupAfter(buffer, buffer->position);
			buffer->position = nextPos;
		}
		
		buffer->Seek(0, 4);
		buffer->Skip(2);

		bVisible = buffer->ReadBool();
		maskId = buffer->ReadShort();
		if (maskId != -1) {
			bInverted = buffer->ReadBool();
		}

		hitTestId = buffer->ReadS();
		
		buffer->Seek(0, 5);
		int transitionCount = buffer->ReadShort();
		if (transitionCount > 0) {
			transitions.resize(transitionCount);
			for (int i = 0; i < transitionCount; ++i) {
				int nextPos = buffer->ReadShort() + buffer->position;
				TransitionInfo* info = new TransitionInfo();
				transitions[i] = info;
				info->setup(buffer);
				buffer->position = nextPos;
			}
		}

		if (objectType != ObjectType::COMPONENT) {
			setupExtend(buffer);
		}
	}

	void ComponentInfo::setupAfter(ByteBuffer* buffer, int beginPos) {
		ObjectInfo::setupAfter(buffer, beginPos);
		buffer->Seek(beginPos, 4);
		buffer->ReadShort();
		int cnt = buffer->ReadShort();
		for (int i = 0; i < cnt; ++i) {
			const std::string& name = buffer->ReadS();
			const std::string& pageId = buffer->ReadS();
			ctrlDefaultPage[name] = pageId;
		}
	}

	void ComponentInfo::operator= (const ObjectInfo* oth) {
		ObjectInfo::operator=(oth);
		const ComponentInfo* other = dynamic_cast<const ComponentInfo*>(oth);
		this->width = other->width;
		this->height = other->height;
		SAVE_ASSIGN(this->margin, other->margin, Margin);
		this->overflow = other->overflow;
		this->scrollType = other->scrollType;
		this->scrollBarDisplayType = other->scrollBarDisplayType;
		this->bPageMode = other->bPageMode;
		this->bBouncebackEffect = other->bBouncebackEffect;
		this->bInertiaEnabled = other->bInertiaEnabled;
		this->bClipEnabled = other->bClipEnabled;
		if (other->controllers.size() > 0) {
			this->controllers.resize(other->controllers.size());
			for (size_t i = 0; i < other->controllers.size(); ++i) {
				ControlerInfo* v = new ControlerInfo();
				v->operator=(other->controllers[i]);
				this->controllers[i] = v;
			}
		}
		if (other->children.size() > 0) {
			this->children.resize(other->children.size());
			for (size_t i = 0; i < other->children.size(); ++i) {
				ObjectInfo* v = createComponentInfo(other->children[i]->objectType);
				v->operator=(other->children[i]);
				this->children[i] = v;
			}
		}
		this->bVisible = other->bVisible;
		this->maskId = other->maskId;
		this->bInverted = other->bInverted;
		this->hitTestId = other->hitTestId;
		if (other->transitions.size() > 0) {
			this->transitions.resize(other->transitions.size());
			for (size_t i = 0; i < other->transitions.size(); ++i) {
				TransitionInfo* v = new TransitionInfo();
				v->operator=(other->transitions[i]);
				this->transitions[i] = v;
			}
		}
		if (other->ctrlDefaultPage.size() > 0) {
			this->ctrlDefaultPage = other->ctrlDefaultPage;
		}
	}

	/************************************************************/

	ButtonInfo::~ButtonInfo(){
		SAVE_DELETE(this->titleColor);
	}

	void ButtonInfo::setupAfter(ByteBuffer* buffer, int beginPos) {
		ComponentInfo::setupAfter(buffer, beginPos);
		if (!buffer->Seek(beginPos, 6)) {
			return;
		}
		ObjectType type = (ObjectType)buffer->ReadByte();
		if (type != this->objectType) {
			return;
		}
		const std::string* str = NULL;
		if (str = buffer->ReadSP()) {
			title = *str;
		}
		if (str = buffer->ReadSP()) {
			selectTitle = *str;
		}
		if (str = buffer->ReadSP()) {
			icon = *str;
		}
		if (str = buffer->ReadSP()) {
			selectIcon = *str;
		}
		if (buffer->ReadBool()) {
			SAVE_ALLCOTE(titleColor, cocos2d::Color4B);
			*titleColor = buffer->ReadColor();
		}
		fontSize = buffer->ReadInt();
		controllerIndex = buffer->ReadShort();
		relatePageId = buffer->ReadS();

		std::string sound;
		buffer->ReadS(sound);
		if (buffer->ReadBool()) {
			float soundVolumeScale = buffer->ReadFloat();
		}
		bSelected = buffer->ReadBool();
	}

	void ButtonInfo::setupExtend(ByteBuffer* buffer) {
		if (!buffer->Seek(0, 6)) {
			return;
		}
		mode = (ButtonMode)buffer->ReadByte();
		buffer->ReadS(sound);
		soundVolumeScale = buffer->ReadFloat();
		downEffectMode = buffer->ReadByte();
		downEffectValue = buffer->ReadFloat();
	}

	void ButtonInfo::operator=(const ObjectInfo* oth) {
		ComponentInfo::operator=(oth);
		const ButtonInfo* other = dynamic_cast<const ButtonInfo*>(oth);
		this->title = other->title;
		this->selectTitle = other->selectTitle;
		this->icon = other->icon;
		this->selectIcon = other->selectIcon;
		SAVE_ASSIGN(this->titleColor, other->titleColor, cocos2d::Color4B);
		this->fontSize = other->fontSize;
		this->controllerIndex = other->controllerIndex;
		this->relatePageId = other->relatePageId;
		this->sound = other->sound;
		this->soundVolumeScale = other->soundVolumeScale;
		this->bSelected = other->bSelected;
		this->mode = other->mode;
		this->downEffectMode = other->downEffectMode;
		this->downEffectValue = other->downEffectValue;
	}

	/********************************************************/

	AnimationInfo::~AnimationInfo(){
		SAVE_DELETE(color);
	}

	void AnimationInfo::setupBefore(ByteBuffer* buffer, int beginPos) {
		ObjectInfo::setupBefore(buffer, beginPos);
		buffer->Seek(beginPos, 5);
		if (buffer->ReadBool()) {
			SAVE_ALLCOTE(color, cocos2d::Color4B);
			*color = buffer->ReadColor();
		}
		flipType = (FlipType)buffer->ReadByte();
		initFrame = buffer->ReadInt();
		bPlaying = buffer->ReadBool();
	}

	void AnimationInfo::operator=(const ObjectInfo* oth) {
		ObjectInfo::operator=(oth);
		const AnimationInfo* other = dynamic_cast<const AnimationInfo*>(oth);
		SAVE_ASSIGN(this->color, other->color, cocos2d::Color4B);
		this->flipType = other->flipType;
		this->initFrame = other->initFrame;
		this->bPlaying = other->bPlaying;
	}
	
	/**********************************************************/

	GraphInfo::~GraphInfo() {
		SAVE_DELETE(lineColor);
		SAVE_DELETE(fillColor);
	}

	void GraphInfo::setupBefore(ByteBuffer* buffer, int beginPos) {
		ObjectInfo::setupBefore(buffer, beginPos);
		buffer->Seek(beginPos, 5);
		type = buffer->ReadByte();
		if (type != 0) {
			lineSize = buffer->ReadInt();
			SAVE_ALLCOTE(lineColor, cocos2d::Color4B);
			SAVE_ALLCOTE(fillColor, cocos2d::Color4B);
			*lineColor = buffer->ReadColor();
			*fillColor = buffer->ReadColor();
		}
	}

	void GraphInfo::operator=(const ObjectInfo* oth) {
		ObjectInfo::operator=(oth);
		const GraphInfo* other = dynamic_cast<const GraphInfo*>(oth);
		this->type = other->type;
		this->lineSize = other->lineSize;
		SAVE_ASSIGN(this->lineColor, other->lineColor, cocos2d::Color4B);
		SAVE_ASSIGN(this->fillColor, other->fillColor, cocos2d::Color4B);
	}

	/******************************************************************/
	void GroupInfo::setupBefore(ByteBuffer* buffer, int beginPos) {
		ObjectInfo::setupBefore(buffer, beginPos);
		buffer->Seek(beginPos, 5);
		layoutType = (GroupLayoutType)buffer->ReadByte();
		lineGap = buffer->ReadInt();
		columnGap = buffer->ReadInt();
	}

	void GroupInfo::operator=(const ObjectInfo* oth) {
		ObjectInfo::operator=(oth);
		const GroupInfo* other = dynamic_cast<const GroupInfo*>(oth);
		this->layoutType = other->layoutType;
		this->lineGap = other->lineGap;
		this->columnGap = other->columnGap;
	}

	/**************************************************************/
	void LabelInfo::setupBefore(ByteBuffer* buffer, int beginPos) {
		ObjectInfo::setupBefore(buffer, beginPos);
		buffer->Seek(beginPos, 5);

		format.face = buffer->ReadS();
		format.fontSize = buffer->ReadShort();
		format.color = buffer->ReadColor();
		//int ret = buffer->ReadByte();
		format.align = (cocos2d::TextHAlignment)buffer->ReadByte();
		format.verticalAlign = (cocos2d::TextVAlignment)buffer->ReadByte();
		format.lineSpacing = buffer->ReadShort();
		format.letterSpacing = buffer->ReadShort();
		bUbbEnabled = buffer->ReadBool();
		autoSize = (AutoSizeType)buffer->ReadByte();
		format.underline = buffer->ReadBool();
		format.italics = buffer->ReadBool();
		format.bold = buffer->ReadBool();
		bSingleLine = buffer->ReadBool();
		if (buffer->ReadBool()) {
			format.outlineColor = buffer->ReadColor();
			format.outlineSize = buffer->ReadFloat();
			format.enableEffect(TextFormat::OUTLINE);
		}
		if (buffer->ReadBool()) {
			format.shadowColor = buffer->ReadColor();
			format.shadowOffset = cocos2d::Vec2(buffer->ReadFloat(), buffer->ReadFloat());
			format.enableEffect(TextFormat::SHADOW);
		}
		if (buffer->ReadBool()) {

		}

		buffer->Seek(beginPos, 6);
		str = buffer->ReadS();
	}

	void LabelInfo::operator=(const ObjectInfo* oth) {
		ObjectInfo::operator=(oth);
		const LabelInfo* other = dynamic_cast<const LabelInfo*>(oth);
		this->format = other->format;
		this->bUbbEnabled = other->bUbbEnabled;
		this->autoSize = other->autoSize;
		this->bSingleLine = other->bSingleLine;
		this->bOutLine = other->bOutLine;
		this->bShadow = other->bShadow;
		this->str = other->str;
	}

	/**************************************************************/
	void ListInfo::setupBefore(ByteBuffer* buffer, int beginPos) {
		ComponentInfo::setupBefore(buffer, beginPos);
		buffer->Seek(beginPos, 5);
		layoutType = (ListLayoutType)buffer->ReadByte();
		selectMode = (ListSelectionMode)buffer->ReadByte();
		hAlign = (cocos2d::TextHAlignment)buffer->ReadByte();
		vAlign = (cocos2d::TextVAlignment)buffer->ReadByte();
		lineGap = buffer->ReadShort();
		columnGap = buffer->ReadShort();
		lineCount = buffer->ReadShort();
		columnCount = buffer->ReadShort();

		bAutoResizeItem = buffer->ReadBool();
		renderOrder = (ChildrenRenderOrder)buffer->ReadByte();
		apexIndex = buffer->ReadShort();

		if (buffer->ReadBool()) {
			SAVE_ALLCOTE(margin, Margin);
			margin->top = buffer->ReadInt();
			margin->bottom = buffer->ReadInt();
			margin->left = buffer->ReadInt();
			margin->right = buffer->ReadInt();
		}

		overflow = (OverflowType)buffer->ReadByte();
		if (overflow == OverflowType::SCROLL) {
			int savePos = buffer->position;
			buffer->Seek(beginPos, 7);
			
			ScrollBarDisplayType barDisplayType = (ScrollBarDisplayType)buffer->ReadByte();
			int flags = buffer->ReadInt();
			if (buffer->ReadBool()) {
				int top = buffer->ReadInt();
				int bottom = buffer->ReadInt();
				int left = buffer->ReadInt();
				int right = buffer->ReadInt();
			}
			buffer->ReadS();
			buffer->ReadS();
			buffer->ReadS();
			buffer->ReadS();

			bPageMode = (flags & 8);
			bBouncebackEffect = (flags & 64);
			bInertiaEnabled = (flags & 256);
			bClipEnabled = (flags & 512);

			buffer->position = savePos;
		}

		if (buffer->ReadBool()) {
			buffer->Skip(8);
		}
		buffer->Seek(beginPos, 8);

		defaultItem = buffer->ReadS();
		int itemCount = buffer->ReadShort();
		items.resize(itemCount);

		for (int i = 0; i < itemCount; ++i) {
			int nextPos = buffer->ReadShort() + buffer->position;

			ListItemInfo* info = new ListItemInfo();
			const std::string* str = buffer->ReadSP();
			if (!str || str->empty()) {
				info->url = *str;
				if (info->url.empty()) {
					buffer->position = nextPos;
					continue;
				}
			}

			str = buffer->ReadSP();
			str = buffer->ReadSP();
			str = buffer->ReadSP();
			str = buffer->ReadSP();
			str = buffer->ReadSP();
			if (str) {
				info->name = *str;
			}
			
			int cnt = buffer->ReadShort();
			for (int i = 0; i < cnt; ++i) {
				const std::string& name = buffer->ReadS();
				const std::string& page = buffer->ReadS();
				info->controllerInfo[name] = page;
			}

			items[i] = info;
			buffer->position = nextPos;
		}
	}

	ListInfo::~ListInfo() {
		for (size_t i = 0; i < items.size(); ++i) {
			delete items[i];
		}
	}

	void ListInfo::operator = (const ObjectInfo* oth){
		ComponentInfo::operator=(oth);
		const ListInfo* other = dynamic_cast<const ListInfo*>(oth);
		this->layoutType = other->layoutType;
		this->selectMode = other->selectMode;
		this->hAlign = other->hAlign;
		this->vAlign = other->vAlign;
		this->lineGap = other->lineGap;
		this->columnGap = other->columnGap;
		this->lineCount = other->lineCount;
		this->columnCount = other->columnCount;
		this->bAutoResizeItem = other->bAutoResizeItem;
		this->renderOrder = other->renderOrder;
		this->apexIndex = other->apexIndex;
		this->defaultItem = other->defaultItem;
		if (other->items.size() > 0) {
			this->items.resize(other->items.size());
			for (size_t i = 0; i < other->items.size(); ++i) {
				ListItemInfo* v = new ListItemInfo();
				v->url = other->items[i]->url;
				v->controllerInfo = other->items[i]->controllerInfo;
				v->name = other->items[i]->name;
				this->items[i] = v;
			}
		}
	}

	/*****************************************************************/
	LoaderInfo::~LoaderInfo() {
		SAVE_DELETE(color);
	}

	void LoaderInfo::setupBefore(ByteBuffer* buffer, int beginPos) {
		ObjectInfo::setupBefore(buffer, beginPos);
		buffer->Seek(beginPos,5);
		url = buffer->ReadS();
		hAlign = (cocos2d::TextHAlignment) buffer->ReadByte();
		vAlign = (cocos2d::TextVAlignment) buffer->ReadByte();
		fillType = (LoaderFillType)buffer->ReadByte();
		bShrinkOnly = buffer->ReadBool();
		bAutoSize = buffer->ReadBool();
		bPlaying = buffer->ReadBool();
		frame = buffer->ReadBool();

		if (buffer->ReadBool()) {
			SAVE_ALLCOTE(color, cocos2d::Color4B);
			*color = buffer->ReadColor();
		}
		fillMethod = (FillMethod)buffer->ReadByte();
		fillOrign = (FillOrigin)buffer->ReadByte();
		bFillClockwise = buffer->ReadBool();
		fillAmount = buffer->ReadFloat();
	}

	void LoaderInfo::operator=(const ObjectInfo* oth) {
		ObjectInfo::operator=(oth);
		const LoaderInfo* other = dynamic_cast<const LoaderInfo*>(oth);
		this->url = other->url;
		this->hAlign = other->hAlign;
		this->vAlign = other->vAlign;
		this->fillType = other->fillType;
		this->bShrinkOnly = other->bShrinkOnly;
		this->bAutoSize = other->bAutoSize;
		this->bPlaying = other->bPlaying;
		this->frame = other->frame;
		SAVE_ASSIGN(this->color, other->color, cocos2d::Color4B);
		this->fillMethod = other->fillMethod;
		this->fillOrign = other->fillOrign;
		this->bFillClockwise = other->bFillClockwise;
		this->fillAmount = other->fillAmount;
	}

	/*****************************************************************/
	void ProgressBarInfo::setupAfter(ByteBuffer* buffer, int beginPos) {
		ComponentInfo::setupAfter(buffer, beginPos);
		if (!buffer->Seek(beginPos, 6)) {
			return;
		}
		ObjectType type = (ObjectType)buffer->ReadByte();
		if (type != objectType) {
			return;
		}
		value = buffer->ReadInt();
		maxValue = buffer->ReadInt();
	}

	void ProgressBarInfo::setupExtend(ByteBuffer* buffer) {
		buffer->Seek(0, 6);
		titleType = (ProgressTitleType)buffer->ReadByte();
		bReverse = buffer->ReadBool();
	}

	void ProgressBarInfo::operator=(const ObjectInfo* oth) {
		ComponentInfo::operator=(oth);
		const ProgressBarInfo* other = dynamic_cast<const ProgressBarInfo*>(oth);
		this->bDefault = other->bDefault;
		this->maxValue = other->maxValue;
		this->value = other->value;
		this->titleType = other->titleType;
		this->bReverse = other->bReverse;
	}

	/************************************************************************/
	void RichTextInfo::setupBefore(ByteBuffer* buffer, int beginPos) {
		ObjectInfo::setupBefore(buffer, beginPos);
		buffer->Seek(beginPos, 5);

		format.face = buffer->ReadS();
		format.fontSize = buffer->ReadShort();
		format.color = buffer->ReadColor();
		format.align = (cocos2d::TextHAlignment)buffer->ReadByte();
		format.verticalAlign = (cocos2d::TextVAlignment)buffer->ReadByte();
		format.lineSpacing = buffer->ReadShort();
		format.letterSpacing = buffer->ReadShort();
		bUbbEnabled = buffer->ReadBool();
		autoSizeType = (AutoSizeType)buffer->ReadByte();
		format.underline = buffer->ReadBool();
		format.italics = buffer->ReadBool();
		format.bold = buffer->ReadBool();
		bSingleLine = buffer->ReadBool();
		if (buffer->ReadBool()) {
			format.outlineColor = buffer->ReadColor();
			format.outlineSize = buffer->ReadFloat();
			format.enableEffect(TextFormat::OUTLINE);
		}
		if (buffer->ReadBool()) {
			format.shadowColor = buffer->ReadColor();
			format.shadowOffset = cocos2d::Vec2(buffer->ReadFloat(), buffer->ReadFloat());
			format.enableEffect(TextFormat::SHADOW);
		}
		if (buffer->ReadBool()) {

		}

		buffer->Seek(beginPos, 4);
		const std::string* str = NULL;
		if (str = buffer->ReadSP()) {
			placeHolder = *str;
		}
		if (str = buffer->ReadSP()) {

		}
		maxLength = buffer->ReadInt();

		buffer->ReadInt();
		bPassword = buffer->ReadBool();
	}

	void RichTextInfo::operator=(const ObjectInfo* oth) {
		ObjectInfo::operator=(oth);
		const RichTextInfo* other = dynamic_cast<const RichTextInfo*>(oth);
		this->format = other->format;
		this->bUbbEnabled = other->bUbbEnabled;
		this->bSingleLine = other->bSingleLine;
		this->autoSizeType = other->autoSizeType;
		this->bOutline = other->bOutline;
		this->bShadow = other->bShadow;
		this->bPassword = other->bPassword;
		this->str = other->str;
		this->placeHolder = other->placeHolder;
		this->maxLength = other->maxLength;
	}

	/****************************************************************/
	void SliderInfo::setupAfter(ByteBuffer* buffer, int beginPos) {
		ComponentInfo::setupAfter(buffer, beginPos);
		if (!buffer->Seek(beginPos, 6)) {
			return;
		}
		ObjectType type = (ObjectType)buffer->ReadByte();
		if (type != objectType) {
			return;
		}
		value = buffer->ReadInt();
		maxValue = buffer->ReadInt();
	}

	void SliderInfo::setupExtend(ByteBuffer* buffer) {
		titleType = (ProgressTitleType)buffer->ReadByte();
		bReverse = buffer->ReadBool();
	}

	void SliderInfo::operator=(const ObjectInfo* oth) {
		ComponentInfo::operator=(oth);
		const SliderInfo* other = dynamic_cast<const SliderInfo*>(oth);
		this->bDefault = other->bDefault;
		this->maxValue = other->maxValue;
		this->value = other->value;
		this->titleType = other->titleType;
		this->bReverse = other->bReverse;
	}

	/********************************************************************/
	SpriteInfo::~SpriteInfo() {
		SAVE_DELETE(color);
	}

	void SpriteInfo::setupBefore(ByteBuffer* buffer, int beginPos) {
		ObjectInfo::setupBefore(buffer, beginPos);
		buffer->Seek(beginPos, 5);
		if (buffer->ReadBool()) {
			SAVE_ALLCOTE(color, cocos2d::Color4B);
			*color = buffer->ReadColor();
		}
		flipType = (FlipType)buffer->ReadByte();
		fillMethod = (FillMethod)buffer->ReadByte();
		if (fillMethod != FillMethod::None) {
			fillOrigin = (FillOrigin)buffer->ReadByte();
			bClockwise = buffer->ReadBool();
			fillAmount = buffer->ReadFloat();
		}
	}

	void SpriteInfo::operator=(const ObjectInfo* oth) {
		ObjectInfo::operator=(oth);
		const SpriteInfo* other = dynamic_cast<const SpriteInfo*>(oth);
		SAVE_ASSIGN(this->color, other->color, cocos2d::Color4B);
		this->flipType = other->flipType;
		this->fillMethod = other->fillMethod;
		this->fillOrigin = other->fillOrigin;
		this->bClockwise = other->bClockwise;
		this->fillAmount = other->fillAmount;
	}

	/******************************************************************/
	TextInfo::~TextInfo() {
		SAVE_DELETE(titleColor);
	}

	void TextInfo::setupAfter(ByteBuffer* buffer, int beginPos) {
		ComponentInfo::setupAfter(buffer, beginPos);
		if (!buffer->Seek(beginPos, 6)) {
			return;
		}
		ObjectType type = (ObjectType)buffer->ReadByte();
		if (type != objectType) {
			return;
		}
		const std::string* str = NULL;
		if (str = buffer->ReadSP()) {
			title = *str;
		}
		if (str = buffer->ReadSP()) {
			icon = *str;
		}
		if (buffer->ReadBool()) {
			SAVE_ALLCOTE(titleColor, cocos2d::Color4B);
			*titleColor = buffer->ReadColor();
		}
		titleFontSize = buffer->ReadInt();
		if (buffer->ReadBool()) {
			if (str = buffer->ReadSP()) {
				placeHolder = *str;
			}
			if (str = buffer->ReadSP()) {
				restrict = *str;
			}
			maxLength = buffer->ReadInt();
			keyboardType = buffer->ReadInt();
			bPassword = buffer->ReadBool();
		}
	}

	void TextInfo::operator=(const ObjectInfo* oth) {
		ComponentInfo::operator=(oth);
		const TextInfo* other = dynamic_cast<const TextInfo*>(oth);
		this->title = other->title;
		this->icon = other->icon;
		SAVE_ASSIGN(this->titleColor, other->titleColor, cocos2d::Color4B);
		this->titleFontSize = other->titleFontSize;
		this->bInput = other->bInput;
		this->placeHolder = other->placeHolder;
		this->restrict = other->restrict;
		this->maxLength = other->maxLength;
		this->keyboardType = other->keyboardType;
		this->bPassword = other->bPassword;
	}

	/*************************************************************************/
	void TextInputInfo::setupBefore(ByteBuffer* buffer, int beginPos) {
		ObjectInfo::setupBefore(buffer, beginPos);
		buffer->Seek(beginPos, 5);

		format.face = buffer->ReadS();
		format.fontSize = buffer->ReadShort();
		format.color = buffer->ReadColor();
		format.align = (cocos2d::TextHAlignment)buffer->ReadByte();
		format.verticalAlign = (cocos2d::TextVAlignment)buffer->ReadByte();
		format.lineSpacing = buffer->ReadShort();
		format.letterSpacing = buffer->ReadShort();
		bUbbEnabled = buffer->ReadBool();
		autoSizeType = (AutoSizeType)buffer->ReadByte();
		format.underline = buffer->ReadBool();
		format.italics = buffer->ReadBool();
		format.bold = buffer->ReadBool();
		bSingleLine = buffer->ReadBool();
		if (buffer->ReadBool()) {
			format.outlineColor = buffer->ReadColor();
			format.outlineSize = buffer->ReadFloat();
			format.enableEffect(TextFormat::OUTLINE);
		}
		if (buffer->ReadBool()) {
			format.shadowColor = buffer->ReadColor();
			format.shadowOffset = cocos2d::Vec2(buffer->ReadFloat(), buffer->ReadFloat());
			format.enableEffect(TextFormat::SHADOW);
		}
		if (buffer->ReadBool()) {

		}

		buffer->Seek(beginPos, 4);
		const std::string* str = NULL;
		if (str = buffer->ReadSP()) {
			placeHolder = *str;
		}
		if (str = buffer->ReadSP()) {

		}
		maxLength = buffer->ReadInt();
		int keyboardType = buffer->ReadInt();
		bPassword = buffer->ReadBool();
	}

	void TextInputInfo::operator=(const ObjectInfo* oth) {
		ObjectInfo::operator=(oth);
		const TextInputInfo* other = dynamic_cast<const TextInputInfo*>(oth);
		this->format = other->format;
		this->bUbbEnabled = other->bUbbEnabled;
		this->autoSizeType = other->autoSizeType;
		this->bSingleLine = other->bSingleLine;
		this->bOutline = other->bOutline;
		this->bShadow = other->bShadow;
		this->placeHolder = other->placeHolder;
		this->maxLength = other->maxLength;
		this->bPassword = other->bPassword;
	}
}