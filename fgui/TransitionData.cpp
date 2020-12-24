#include "TransitionData.h"
#include "ByteBuffer.h"
#include "ComponentData.h"

namespace fgui {

	TransitionItemInfo::~TransitionItemInfo() {
		switch (type) {
		case TransitionActionType::XY:
		case TransitionActionType::Pivot:
		case TransitionActionType::Size:
		case TransitionActionType::Skew:
		case TransitionActionType::Alpha:
		case TransitionActionType::Rotation:
		case TransitionActionType::Scale :
		case TransitionActionType::ColorFilter:
		case TransitionActionType::Color: {
			if (value) {
				delete (TValue*)(value);
			}
			break;
		}
			
		case TransitionActionType::Animation: {
			if (value) {
				delete (TValue_Animation*)value;
			}
			break;
		}
		case TransitionActionType::Visible: {
			if (value) {
				delete (TValue_Visible*)value;
			}
			break;
		}
		case TransitionActionType::Sound: {
			if (value) {
				delete (TValue_Sound*)value;
			}
			break;
		}
		case TransitionActionType::Transition: {
			if (value) {
				delete (TValue_Transition*)value;
			}
			break;
		}
		case TransitionActionType::Shake: {
			if (value) {
				delete (TValue_Shake*)value;
			}
			break;
		}
		case TransitionActionType::Text:
		case TransitionActionType::Icon: {
			if (value) {
				delete (TValue_Text*)value;
			}
			break;
		}
		}
		if (tweenConfig) {
			delete tweenConfig;
		}
	}

	void TransitionItemInfo::operator=(const TransitionItemInfo* other) {
		this->type = other->type;
		this->time = other->time;
		this->targetId = other->targetId;
		this->label = other->label;
		this->endLabel = other->endLabel;
		SAVE_ASSIGN(this->tweenConfig, other->tweenConfig, GearTweenConfigInfo);

		switch (type) {
		case TransitionActionType::XY:
		case TransitionActionType::Pivot:
		case TransitionActionType::Size:
		case TransitionActionType::Skew:
		case TransitionActionType::Alpha:
		case TransitionActionType::Rotation:
		case TransitionActionType::Scale:
		case TransitionActionType::ColorFilter:
		case TransitionActionType::Color: {
			TValue* v = new TValue();
			SAVE_ASSIGN(v, ((TValue*)other->value), TValue);
			this->value = v;
			break;
		}

		case TransitionActionType::Animation: {
			TValue_Animation* v = new TValue_Animation();
			SAVE_ASSIGN(v, (TValue_Animation*)other->value, TValue_Animation);
			this->value = v;
			break;
		}
		case TransitionActionType::Visible: {
			TValue_Visible* v = new TValue_Visible();
			SAVE_ASSIGN(v, (TValue_Visible*)other->value, TValue_Visible);
			this->value = v;
			break;
		}
		case TransitionActionType::Sound: {
			TValue_Sound* v = new TValue_Sound();
			SAVE_ASSIGN(v, (TValue_Sound*)other->value, TValue_Sound);
			this->value = v;
			break;
		}
		case TransitionActionType::Transition: {
			TValue_Transition* v = new TValue_Transition();
			SAVE_ASSIGN(v, (TValue_Transition*)other->value, TValue_Transition);
			this->value = v;
			break;
		}
		case TransitionActionType::Shake: {
			TValue_Shake* v = new TValue_Shake();
			SAVE_ASSIGN(v, (TValue_Shake*)other->value, TValue_Shake);
			this->value = v;
			break;
		}
		case TransitionActionType::Text:
		case TransitionActionType::Icon: {
			TValue_Text* v = new TValue_Text();
			SAVE_ASSIGN(v, (TValue_Text*)other->value, TValue_Text);
			this->value = v;
			break;
		}
		}
	}

	void* TransitionInfo::decodeValue(TransitionItemInfo* item, ByteBuffer* buffer)
	{
		switch (item->type)
		{
		case TransitionActionType::XY:{
			TValue* tvalue = new TValue;
			tvalue->b1 = buffer->ReadBool();
			tvalue->b2 = buffer->ReadBool();

			tvalue->f1 = buffer->ReadFloat();
			tvalue->f2 = buffer->ReadFloat();
			return tvalue;
		}
		case TransitionActionType::Pivot:{
			TValue* tvalue = new TValue;
			tvalue->b1 = buffer->ReadBool();
			tvalue->b2 = buffer->ReadBool();
			tvalue->f1 = buffer->ReadFloat();
			tvalue->f2 = buffer->ReadFloat();
			return tvalue;
		}
		case TransitionActionType::Size:
		case TransitionActionType::Skew:{
			TValue* tvalue = new TValue;
			tvalue->b1 = buffer->ReadBool();
			tvalue->b2 = buffer->ReadBool();
			tvalue->f1 = buffer->ReadFloat();
			tvalue->f2 = buffer->ReadFloat();
			return tvalue;
		}

		case TransitionActionType::Alpha:
		case TransitionActionType::Rotation: {
			TValue* tvalue = new TValue;
			tvalue->f1 = buffer->ReadFloat();
			return tvalue;
		}
		case TransitionActionType::Scale:{
			TValue* tvalue = new TValue;
			tvalue->f1 = buffer->ReadFloat();
			tvalue->f2 = buffer->ReadFloat();
			return tvalue;
		}

		case TransitionActionType::Color: {
			TValue* tvalue = new TValue;
			tvalue->setColor(buffer->ReadColor());
			return tvalue;
		}
		case TransitionActionType::Animation:{
			TValue_Animation* value = new TValue_Animation;
			value->playing = buffer->ReadBool();
			value->frame = buffer->ReadInt();
			return value;
		}

		case TransitionActionType::Visible: {
			TValue_Visible* value = new TValue_Visible;
			value->visible = buffer->ReadBool();
			return value;
		}
		case TransitionActionType::Sound:{
			TValue_Sound* value = new TValue_Sound;
			value->sound = buffer->ReadS();
			value->volume = buffer->ReadFloat();
			return value;
		}

		case TransitionActionType::Transition:{
			TValue_Transition* value = new TValue_Transition;
			value->transName = buffer->ReadS();
			value->playTimes = buffer->ReadInt();
			return value;
		}

		case TransitionActionType::Shake:{
			TValue_Shake* value = new TValue_Shake;
			value->amplitude = buffer->ReadFloat();
			value->duration = buffer->ReadFloat();
			return value;
		}

		case TransitionActionType::ColorFilter:{
			TValue* tvalue = new TValue;
			tvalue->f1 = buffer->ReadFloat();
			tvalue->f2 = buffer->ReadFloat();
			tvalue->f3 = buffer->ReadFloat();
			tvalue->f4 = buffer->ReadFloat();
			return tvalue;
		}

		case TransitionActionType::Text:
		case TransitionActionType::Icon: {
			TValue_Text* value = new TValue_Text;
			value->text = buffer->ReadS();
			return value;
		}

		default:
			break;
		}
		return NULL;
	}

	void TransitionInfo::setup(ByteBuffer* buffer) {
		name = buffer->ReadS();
		options = buffer->ReadInt();
		autoPlay = buffer->ReadBool();
		autoPlayTimes = buffer->ReadInt();
		autoPlayDelay = buffer->ReadFloat();
		
		int cnt = buffer->ReadShort();
		for (int i = 0; i < cnt; ++i) {
			int dataLen = buffer->ReadShort();
			int curPos = buffer->position;
			buffer->Seek(buffer->position, 0);

			TransitionItemInfo* item = new TransitionItemInfo();
			item->type = (TransitionActionType)buffer->ReadByte();
			item->time = buffer->ReadFloat();
			item->targetId = buffer->ReadShort();
			item->label = buffer->ReadS();

			if (buffer->ReadBool()) {
				buffer->Seek(curPos, 1);
				GearTweenConfigInfo* config = new GearTweenConfigInfo();
				config->duration = buffer->ReadFloat();
				config->easeType = (EaseType)buffer->ReadByte();
				config->repeat = buffer->ReadInt();
				config->yoyo = buffer->ReadBool();
				config->endLabel = buffer->ReadS();

				item->tweenConfig = config;
				buffer->Seek(curPos, 2);
				item->tweenConfig->startValue = (TValue*)decodeValue(item, buffer);

				buffer->Seek(curPos, 3);
				item->tweenConfig->endValue = (TValue*)decodeValue(item, buffer);
			}
			else {
				buffer->Seek(curPos, 2);
				item->value = decodeValue(item, buffer);
			}

			buffer->position = curPos + dataLen;
		}
	}

	void TransitionInfo::operator=(const TransitionInfo* other) {
		this->name = other->name;
		this->options = other->options;
		this->autoPlay = other->autoPlay;
		this->autoPlayDelay = other->autoPlayDelay;
		this->autoPlayTimes = other->autoPlayTimes;
		if (other->items.size() > 0) {
			this->items.resize(other->items.size());
			for (size_t i = 0; i < other->items.size(); ++i) {
				TransitionItemInfo* v = new TransitionItemInfo();
				v->operator=(other->items[i]);
			}
		}
	}
}

