#include "GearData.h"
#include "ByteBuffer.h"
#include "ComponentData.h"

namespace fgui {
	GearInfo* createGearInfo(int index)
	{
		GearInfo* gear = NULL;
		switch (index)
		{
		case 0:
			gear = new GearDisplayInfo();
			break;
		case 1:
			gear = new GearXYInfo();
			break;
		case 2:
			gear = new GearSizeInfo();
			break;
		case 3:
			gear = new GearLookInfo();
			break;
		case 4:
			gear = new GearColorInfo();
			break;
		case 5:
			gear = new GearAnimationInfo();
			break;
		case 6:
			gear = new GearTextInfo();
			break;
		case 7:
			gear = new GearIconInfo();
			break;
		}
		return gear;
	}

	GearInfo::~GearInfo() {
		if (config) {
			delete config;
		}
	}

	void GearInfo::setup(ByteBuffer* buffer, const std::string& id) {
		ownerId = id;
		controllerIndex = buffer->ReadShort();
		int cnt = buffer->ReadShort();
		for (int i = 0; i < cnt; ++i) {
			addPageValue(buffer);
		}
		addDefaultValue(buffer);
		if (buffer->ReadBool()) {
			config = new GearTweenConfigInfo();
			config->easeType = (EaseType)buffer->ReadByte();
			config->duration = buffer->ReadFloat();
			config->delay = buffer->ReadFloat();
		}
	}

	void GearInfo::addPageValue(ByteBuffer* buffer) {

	}

	void GearInfo::addDefaultValue(ByteBuffer* buffer) {

	}

	void GearInfo::operator=(const GearInfo* other) {
		this->type = other->type;
		this->ownerId = other->ownerId;
		this->controllerIndex = other->controllerIndex;
		this->bTween = other->bTween;
		SAVE_ASSIGN(this->config, other->config, GearTweenConfigInfo);
	}

	/*************************************************************/
	GearAnimationInfo::~GearAnimationInfo() {
		if (defaultValue) {
			delete defaultValue;
		}
		for (auto iter = values.begin(); iter != values.end(); ++iter) {
			delete iter->second;
		}
	}

	void GearAnimationInfo::addPageValue(ByteBuffer* buffer) {
		const std::string& page = buffer->ReadS();
		if (page.empty()) {
			return;
		}
		GearAnimationValue* value = new GearAnimationValue();
		value->playing = buffer->ReadBool();
		value->frame = buffer->ReadInt();
		values[page] = value;
	}

	void GearAnimationInfo::addDefaultValue(ByteBuffer* buffer) {
		if (buffer->ReadBool()) {
			defaultValue = new GearAnimationValue();
			defaultValue->playing = buffer->ReadBool();
			defaultValue->frame = buffer->ReadInt();
		}
	}

	void GearAnimationInfo::operator=(const GearInfo* oth) {
		GearInfo:: operator= (oth);
		const GearAnimationInfo* other = dynamic_cast<const GearAnimationInfo*>(oth);
		SAVE_ASSIGN(this->defaultValue, other->defaultValue, GearAnimationValue);
		for (auto iter = other->values.begin(); iter != other->values.end(); ++iter) {
			GearAnimationValue* v = new GearAnimationValue();
			*v = *iter->second;
			this->values[iter->first] = v;
		}
	}

	/***********************************************************/
	GearColorInfo::~GearColorInfo() {
		if (defaultValue) {
			delete defaultValue;
		}
		for (auto iter = values.begin(); iter != values.end(); ++iter) {
			delete iter->second;
		}
	}

	void GearColorInfo::addPageValue(ByteBuffer* buffer) {
		const std::string& page = buffer->ReadS();
		if (page.empty()) {
			return;
		}
		GearColorValue* value = new GearColorValue();
		value->color = buffer->ReadColor();
		value->outlineColor = buffer->ReadColor();
		values[page] = value;
	}

	void GearColorInfo::addDefaultValue(ByteBuffer* buffer) {
		if (buffer->ReadBool()) {
			defaultValue = new GearColorValue(cocos2d::Color4B::WHITE, cocos2d::Color4B::WHITE);
			defaultValue->color = buffer->ReadColor();
			defaultValue->outlineColor = buffer->ReadColor();
		}
	}

	void GearColorInfo::operator=(const GearInfo* oth) {
		GearInfo:: operator= (oth);
		const GearColorInfo* other = dynamic_cast<const GearColorInfo*>(oth);
		SAVE_ASSIGN(defaultValue, other->defaultValue, GearColorValue);
		for (auto iter = other->values.begin(); iter != other->values.end(); ++iter) {
			GearColorValue* v = new GearColorValue();
			*v = *iter->second;
			this->values[iter->first] = v;
		}
	}

	/*****************************************************************/

	void GearDisplayInfo::addPageValue(ByteBuffer* buffer) {
		pages.push_back(buffer->ReadS());
	}

	void GearDisplayInfo::addDefaultValue(ByteBuffer* buffer) {

	}

	void GearDisplayInfo::operator=(const GearInfo* oth) {
		GearInfo:: operator= (oth);
		const GearDisplayInfo* other = dynamic_cast<const GearDisplayInfo*>(oth);
		if (other->pages.size() <= 0) {
			return;
		}
		this->pages.resize(other->pages.size());
		for (size_t i = 0; i < other->pages.size(); ++i) {
			this->pages[i] = other->pages[i];
		}
	}

	/******************************************************************/

	void GearIconInfo::addPageValue(ByteBuffer* buffer) {
		const std::string& page = buffer->ReadS();
		if (page.empty()) {
			return;
		}
		values[page] = buffer->ReadS();
	}

	void GearIconInfo::addDefaultValue(ByteBuffer* buffer) {
		if (buffer->ReadBool()) {
			defaultValue = buffer->ReadS();
		}
	}
	void GearIconInfo::operator = (const GearInfo* oth) {
		GearInfo::operator= (oth);
		const GearIconInfo* other = dynamic_cast<const GearIconInfo*>(oth);
		this->defaultValue = other->defaultValue;
		this->values = other->values;
	}


	/********************************************************************/
	GearLookInfo::~GearLookInfo() {
		if (defaultValue) {
			delete defaultValue;
		}
		for (auto iter = values.begin(); iter != values.end(); ++iter) {
			delete iter->second;
		}
	}

	void GearLookInfo::addPageValue(ByteBuffer* buffer) {
		const std::string& page = buffer->ReadS();
		if (page.empty()) {
			return;
		}
		if (values.find(page) != values.end()) {
			return;
		}
		GearLookValue* value = new GearLookValue();
		value->alpha = buffer->ReadFloat();
		value->rotation = buffer->ReadFloat();
		value->grayed = buffer->ReadBool();
		value->touchable = buffer->ReadBool();
		values[page] = value;
	}

	void GearLookInfo::addDefaultValue(ByteBuffer* buffer) {
		if (buffer->ReadBool()) {
			defaultValue = new GearLookValue();
			defaultValue->alpha = buffer->ReadFloat();
			defaultValue->rotation = buffer->ReadFloat();
			defaultValue->grayed = buffer->ReadBool();
			defaultValue->touchable = buffer->ReadBool();
		}
	}

	void GearLookInfo::operator=(const GearInfo* oth) {
		GearInfo::operator=(oth);
		const GearLookInfo* other = dynamic_cast<const GearLookInfo*>(oth);
		SAVE_ASSIGN(this->defaultValue, other->defaultValue, GearLookValue);
		for (auto iter = other->values.begin(); iter != other->values.end(); ++iter) {
			GearLookValue* v = new GearLookValue();
			*v = *iter->second;
			this->values[iter->first] = v;
		}
	}

	/******************************************************************/
	GearSizeInfo::~GearSizeInfo() {
		if (defaultValue) {
			delete defaultValue;
		}
		for (auto iter = values.begin(); iter != values.end(); ++iter) {
			delete iter->second;
		}
	}

	void GearSizeInfo::addPageValue(ByteBuffer* buffer) {
		const std::string& page = buffer->ReadS();
		if (page.empty()) {
			return;
		}
		if (values.find(page) != values.end()) {
			return;
		}
		cocos2d::Vec4* value = new cocos2d::Vec4();
		value->x = buffer->ReadInt();
		value->y = buffer->ReadInt();
		value->z = buffer->ReadFloat();
		value->w = buffer->ReadFloat();
		values[page] = value;
	}

	void GearSizeInfo::addDefaultValue(ByteBuffer* buffer) {
		if (buffer->ReadBool()) {
			defaultValue = new cocos2d::Vec4();
			defaultValue->x = buffer->ReadInt();
			defaultValue->y = buffer->ReadInt();
			defaultValue->z = buffer->ReadFloat();
			defaultValue->w = buffer->ReadFloat();
		}
	}

	void GearSizeInfo::operator = (const GearInfo* oth) {
		GearInfo::operator=(oth);
		const GearSizeInfo* other = dynamic_cast<const GearSizeInfo*>(oth);
		SAVE_ASSIGN(this->defaultValue, other->defaultValue, cocos2d::Vec4);
		for (auto iter = other->values.begin(); iter != other->values.end(); ++iter) {
			cocos2d::Vec4* v = new cocos2d::Vec4();
			*v = *iter->second;
			this->values[iter->first] = v;
		}
	}

	/************************************************************/
	void GearTextInfo::addPageValue(ByteBuffer* buffer) {
		const std::string& page = buffer->ReadS();
		if (page.empty()) {
			return;
		}
		if (values.find(page) != values.end()) {
			return;
		}
		values[page] = buffer->ReadS();
	}

	void GearTextInfo::addDefaultValue(ByteBuffer* buffer) {
		if (buffer->ReadBool()) {
			defaultValue = buffer->ReadS();
		}
	}

	void GearTextInfo::operator=(const GearInfo* oth) {
		GearInfo::operator=(oth);
		const GearTextInfo* other = dynamic_cast<const GearTextInfo*>(oth);
		this->defaultValue = other->defaultValue;
		this->values = other->values;
	}

	/***********************************************************/
	void GearXYInfo::addPageValue(ByteBuffer* buffer) {
		const std::string& page = buffer->ReadS();
		if (page.empty()) {
			return;
		}
		if (values.find(page) != values.end()) {
			return;
		}
		cocos2d::Vec2* value = new cocos2d::Vec2();
		value->x = buffer->ReadInt();
		value->y = buffer->ReadInt();
		values[page] = value;
	}

	void GearXYInfo::addDefaultValue(ByteBuffer* buffer) {
		if (buffer->ReadBool()) {
			defaultValue = new cocos2d::Vec2();
			defaultValue->x = buffer->ReadInt();
			defaultValue->y = buffer->ReadInt();
		}
	}

	GearXYInfo::~GearXYInfo() {
		if (defaultValue) {
			delete defaultValue;
		}
		for (auto iter = values.begin(); iter != values.end(); ++iter) {
			delete iter->second;
		}
	}

	void GearXYInfo::operator=(const GearInfo* oth) {
		GearInfo::operator=(oth);
		const GearXYInfo* other = dynamic_cast<const GearXYInfo*>(oth);
		SAVE_ASSIGN(this->defaultValue, other->defaultValue, cocos2d::Vec2);
		for (auto iter = other->values.begin(); iter != other->values.end(); ++iter) {
			cocos2d::Vec2* v = new cocos2d::Vec2();
			*v = *iter->second;
			this->values[iter->first] = v;
		}
	}

	/*****************************************************/

	GearTweenConfigInfo::~GearTweenConfigInfo() {
		if (startValue) {
			delete startValue;
		}
		if (endValue) {
			delete endValue;
		}
	}

	void GearTweenConfigInfo::operator=(const GearTweenConfigInfo* other) {
		this->delay = other->delay;
		this->duration = other->duration;
		this->easeType = other->easeType;
		this->endLabel = other->endLabel;
		this->yoyo = other->yoyo;
		this->repeat = other->repeat;
		SAVE_ASSIGN(this->startValue, other->startValue, TValue);
		SAVE_ASSIGN(this->endValue, other->endValue, TValue);
	}
}