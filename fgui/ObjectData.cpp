#include "ObjectData.h"
#include "GearData.h"
#include "UIPackage.h"
#include "ComponentData.h"

namespace fgui {

	ControllerActionInfo* createCtrlActionInfo(int type) {
		switch (type)
		{
		case 0:
			return new CtrlPlayTransitionActionInfo();

		case 1:
			return new ControllerActionInfo();
		}
		return nullptr;
	}

	void ControllerActionInfo::setup(ByteBuffer* buffer) {
		type = buffer->ReadByte();
		int cnt = buffer->ReadShort();
		fromPages.resize(cnt);

		for (int i = 0; i < cnt; ++i) {
			fromPages[i].assign(buffer->ReadS());
		}

		cnt = buffer->ReadShort();
		toPages.resize(cnt);
		for (int i = 0; i < cnt; ++i) {
			toPages[i].assign(buffer->ReadS());
		}
	}

	void ControllerActionInfo::operator=(const ControllerActionInfo* other) {
		this->type = other->type;
		this->fromPages.resize(other->fromPages.size());
		std::copy(other->fromPages.begin(), other->fromPages.end(), this->fromPages.begin());
		this->toPages.resize(other->toPages.size());
		std::copy(other->toPages.begin(), other->toPages.end(), this->toPages.begin());
	}

	/******************************************************************/
	void CtrlChangePageActionInfo::setup(ByteBuffer* buffer) {
		ControllerActionInfo::setup(buffer);
		objectId = buffer->ReadS();
		controllerName = buffer->ReadS();
		targetPage = buffer->ReadS();
	}

	void CtrlChangePageActionInfo::operator=(const ControllerActionInfo* oth) {
		ControllerActionInfo::operator=(oth);
		const CtrlChangePageActionInfo* other = dynamic_cast<const CtrlChangePageActionInfo*>(oth);
		this->objectId = other->objectId;
		this->controllerName = other->controllerName;
		this->targetPage = other->targetPage;
	}

	/****************************************************************/
	void CtrlPlayTransitionActionInfo::setup(ByteBuffer* buffer) {
		transitionName = buffer->ReadS();
		playTimes = buffer->ReadInt();
		delay = buffer->ReadFloat();
		stopOnExit = buffer->ReadBool();
	}

	void CtrlPlayTransitionActionInfo::operator=(const ControllerActionInfo* oth) {
		ControllerActionInfo::operator=(oth);
		const CtrlPlayTransitionActionInfo* other = dynamic_cast<const CtrlPlayTransitionActionInfo*>(oth);
		this->transitionName = other->transitionName;
		this->playTimes = other->playTimes;
		this->delay = other->delay;
		this->stopOnExit = other->stopOnExit;
	}

	/****************************************************************/
	RelationTargetInfo::~RelationTargetInfo() {
		for (size_t i = 0; i < items.size(); ++i) {
			delete items[i];
		}
	}

	void RelationTargetInfo::operator=(const RelationTargetInfo* other) {
		this->targetIndex = other->targetIndex;
		if (other->items.size() <= 0) {
			return;
		}
		this->items.resize(other->items.size());
		for (size_t i = 0; i < this->items.size(); ++i) {
			RelationItemInfo* v = new RelationItemInfo();
			*v = *other->items[i];
			this->items[i] = v;
		}
	}

	RelationInfo::~RelationInfo() {
		for (size_t i = 0; i < targets.size(); ++i) {
			delete targets[i];
		}
	}

	void RelationInfo::setup(ByteBuffer* buffer) {
		int cnt = buffer->ReadByte();
		if (cnt <= 0) {
			return;
		}

		targets.resize(cnt);
		for (int i = 0; i < cnt; ++i) {
			RelationTargetInfo* target = new RelationTargetInfo();
			target->targetIndex = buffer->ReadShort();
			int cnt2 = buffer->ReadByte();
			target->items.resize(cnt2);

			for (int j = 0; j < cnt2; ++j) {
				RelationItemInfo* item = new RelationItemInfo();
				item->type = (RelationType)buffer->ReadByte();
				item->usePercent = buffer->ReadBool();
				target->items[j] = item;
			}
			targets[i] = target;
		}
	}

	void RelationInfo::operator=(const RelationInfo* other) {
		if (other->targets.size() <= 0) {
			return;
		}
		this->targets.resize(other->targets.size());
		for (size_t i = 0; i < this->targets.size(); ++i) {
			RelationTargetInfo* v = new RelationTargetInfo();
			*v = *other->targets[i];
			this->targets[i] = v;
		}
	}

	/**************************************************************/

	ControlerInfo::~ControlerInfo() {
		for (size_t i = 0; i < actions.size(); ++i) {
			delete actions[i];
		}
	}

	void ControlerInfo::setup(ByteBuffer* buffer) {
		int beginPos = buffer->position;

		buffer->Seek(beginPos, 0);

		name = buffer->ReadS();
		autoRadioGroupDepth = buffer->ReadBool();
		buffer->Seek(beginPos, 1);
		int cnt = buffer->ReadShort();
		pageIds.resize(cnt);
		pageNames.resize(cnt);
		for (int i = 0; i < cnt; ++i) {
			pageIds[i].assign(buffer->ReadS());
			pageNames[i].assign(buffer->ReadS());
		}
		
		buffer->Seek(beginPos, 2);

		cnt = buffer->ReadShort();
		for (int i = 0; i < cnt; ++i) {
			int nextPos = buffer->ReadShort();
			nextPos += buffer->position;

			int type = buffer->ReadByte();
			ControllerActionInfo* action = createCtrlActionInfo(type);
			action->setup(buffer);
			buffer->position = nextPos;
		}
	}

	void ControlerInfo::operator=(const ControlerInfo* other) {
		this->name = other->name;
		this->autoRadioGroupDepth = other->autoRadioGroupDepth;
		if (other->pageIds.size() > 0) {
			this->pageIds.resize(other->pageIds.size());
			std::copy(other->pageIds.begin(), other->pageIds.end(), this->pageIds.begin());
		}
		if (other->pageNames.size() > 0) {
			this->pageNames.resize(other->pageNames.size());
			std::copy(other->pageNames.begin(), other->pageNames.end(), this->pageNames.begin());
		}
		if (other->actions.size() > 0) {
			this->actions.resize(other->actions.size());
			for (size_t i = 0; i < other->actions.size(); ++i) {
				ControllerActionInfo* v = createCtrlActionInfo(other->actions[i]->type);
				v->operator=(other->actions[i]);
				this->actions[i] = v;
			}
		}
	}

	/*************************************************************/

	ObjectInfo::~ObjectInfo() {
		SAVE_DELETE(this->size);
		SAVE_DELETE(this->minSize);
		SAVE_DELETE(this->maxSize);
		SAVE_DELETE(this->scale);
		SAVE_DELETE(this->skew);
		SAVE_DELETE(this->pivot);
		SAVE_DELETE(this->hsv);
		SAVE_DELETE(this->relation);
		for (size_t i = 0; i < gears.size(); ++i) {
			delete gears[i];
		}
	}

	void ObjectInfo::setup(Package* pkg, PackageItem* pt) {
	}

	void ObjectInfo::setupBefore(ByteBuffer* buffer, int beginPos) {
		buffer->Seek(beginPos, 0);
		buffer->Skip(5);
		id = buffer->ReadS();
		name = buffer->ReadS();
		
		pos.x = buffer->ReadInt();
		pos.y = buffer->ReadInt();

		if (buffer->ReadBool()) {
			SAVE_ALLCOTE(size, cocos2d::Size);
			size->width = buffer->ReadInt();
			size->height = buffer->ReadInt();
		}
		if (buffer->ReadBool()) {
			SAVE_ALLCOTE(minSize,cocos2d::Size);
			SAVE_ALLCOTE(maxSize,cocos2d::Size);
			minSize->width = buffer->ReadInt();
			maxSize->width = buffer->ReadInt();
			minSize->height = buffer->ReadInt();
			maxSize->height = buffer->ReadInt();
		}

		if (buffer->ReadBool()) {
			SAVE_ALLCOTE(scale,cocos2d::Vec2);
			scale->x = buffer->ReadFloat();
			scale->y = buffer->ReadFloat();
		}

		if (buffer->ReadBool()) {
			SAVE_ALLCOTE(skew,cocos2d::Vec2);
			skew->x = buffer->ReadFloat();
			skew->y = buffer->ReadFloat();
		}

		if (buffer->ReadBool()) {
			SAVE_ALLCOTE(pivot,cocos2d::Vec2);
			pivot->x = buffer->ReadFloat();
			pivot->y = buffer->ReadFloat();
			bPivotAsAchorPoint = buffer->ReadBool();
		}

		opacity = buffer->ReadFloat();
		rotation = buffer->ReadFloat();
		bVisible = buffer->ReadBool();
		buffer->ReadBool();
		bGray = buffer->ReadBool();
		blendMode = (BlendMode) buffer->ReadByte();

		if (buffer->ReadBool()) {
			SAVE_ALLCOTE(hsv,cocos2d::Vec4);
			hsv->x = buffer->ReadFloat();
			hsv->y = buffer->ReadFloat();
			hsv->w = buffer->ReadFloat();
			hsv->z = buffer->ReadFloat();
		}
		customData = buffer->ReadS();
	}

	void ObjectInfo::setupAfter(ByteBuffer* buffer, int beginPos) {
		buffer->Seek(beginPos, 1);

		tooltips = buffer->ReadS();
		groupId = buffer->ReadShort();

		buffer->Seek(beginPos, 2);
		int cnt = buffer->ReadShort();
		gears.resize(cnt);
		for (int i = 0; i < cnt; ++i) {
			int nextPos = buffer->ReadShort();
			nextPos += buffer->position;

			int type = buffer->ReadByte();
			GearInfo* gearInfo = createGearInfo(type);
			gearInfo->type = (GearType)type;
			gearInfo->setup(buffer, id);
			gears[i] = gearInfo;
		}
	}

	void ObjectInfo::operator=(const ObjectInfo* other) {
		this->objectType = other->objectType;
		this->temId = other->temId;
		this->pkgId = other->pkgId;
		this->id = other->id;
		this->name = other->name;
		this->pos = other->pos;
		SAVE_ASSIGN(this->size, other->size, cocos2d::Size);
		SAVE_ASSIGN(this->minSize, other->minSize, cocos2d::Size);
		SAVE_ASSIGN(this->maxSize, other->maxSize, cocos2d::Size);
		SAVE_ASSIGN(this->scale, other->scale, cocos2d::Vec2);
		SAVE_ASSIGN(this->skew, other->skew, cocos2d::Vec2);
		SAVE_ASSIGN(this->pivot, other->pivot, cocos2d::Vec2);
		this->bPivotAsAchorPoint = other->bPivotAsAchorPoint;
		this->opacity = other->opacity;
		this->rotation = other->rotation;
		this->bVisible = other->bVisible;
		this->bTouchEnable = other->bTouchEnable;
		this->bGray = other->bGray;
		this->blendMode = other->blendMode;
		SAVE_ASSIGN(this->hsv, other->hsv, cocos2d::Vec4);
		this->customData = other->customData;
		SAVE_ASSIGN(this->relation, other->relation, RelationInfo);
		this->tooltips = other->tooltips;
		this->groupId = other->groupId;

		if (other->gears.size() > 0) {
			this->gears.resize(other->gears.size());
			for (size_t i = 0; i < other->gears.size(); ++i) {
				GearInfo* v = createGearInfo((int)other->gears[i]->type);
				*v = other->gears[i];
				this->gears[i] = v;
			}
		}
	}
}