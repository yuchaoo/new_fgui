#pragma once

#include "cocos2d.h"
#include "GearBase.h"

namespace fgui {
	struct GearInfo;

	class IAnimationGear
	{
	public:
		virtual bool isPlaying() const = 0;
		virtual void setPlaying(bool value) = 0;

		virtual int getFrame() const = 0;
		virtual void setFrame(int value) = 0;

		virtual float getTimeScale() const = 0;
		virtual void setTimeScale(float value) = 0;

		virtual void advance(float time) = 0;
	};

	class GearAnimationValue
	{
	public:
		bool playing;
		int frame;

		GearAnimationValue();
		GearAnimationValue(bool playing, int frame);
	};

	class GObject;

	class GearAnimation : public GearBase
	{
	public:
		GearAnimation(GObject* owner);
		virtual ~GearAnimation();

		void apply() override;
		void updateState() override;
		virtual void initWithInfo(const GearInfo* inf);
	protected:
		void addStatus(const std::string&  pageId, ByteBuffer* buffer) override;
		void init() override;

	private:
		std::unordered_map<std::string, GearAnimationValue> _storage;
		GearAnimationValue _default;
	};

}

