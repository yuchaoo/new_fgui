#pragma once
#include "FieldTypes.h"
#include "GTransition.h"
#include "GearData.h"

namespace fgui {
	struct TransitionItemInfo {
		TransitionActionType type;
		float time = 0.0f;
		int targetId = -1;
		std::string label;
		std::string endLabel;
		GearTweenConfigInfo* tweenConfig = NULL;
		void* value = NULL;
	public:
		~TransitionItemInfo();
		void operator=(const TransitionItemInfo* other);
	};

	struct TransitionInfo {
		std::string name;
		int options = -1;
		bool autoPlay = false;
		int autoPlayTimes = 0;
		float autoPlayDelay = 0;
		std::vector<TransitionItemInfo*> items;
	public:
		void* decodeValue(TransitionItemInfo* item, ByteBuffer* buffer);
		virtual void setup(ByteBuffer* buffer);
		void operator=(const TransitionInfo* other);
	};
}