#include "GearAnimation.h"
#include "GObject.h"
#include "ByteBuffer.h"
#include "UIPackage.h"
#include "Controller.h"

namespace fgui {

	GearAnimationValue::GearAnimationValue() 
		:frame(0)
		, playing(false)
	{

	}

	GearAnimationValue::GearAnimationValue(bool playing, int frame)
	{
		this->playing = playing;
		this->frame = frame;
	}

	GearAnimation::GearAnimation(GObject * owner) 
		:GearBase(owner)
	{

	}

	GearAnimation::~GearAnimation()
	{
	}

	void GearAnimation::init()
	{
		IAnimationGear *ag = dynamic_cast<IAnimationGear*>(_owner);

		_default = GearAnimationValue(ag->isPlaying(), ag->getFrame());
		_storage.clear();
	}

	void GearAnimation::initWithInfo(const GearInfo* inf) {
		const GearAnimationInfo* info = dynamic_cast<const GearAnimationInfo*>(inf);
		_storage.clear();
		for (auto iter = info->values.begin(); iter != info->values.end(); ++iter) {
			_storage.insert(std::make_pair(iter->first, *iter->second));
		}
		if (info->defaultValue) {
			_default = *info->defaultValue;
		}
	}

	void GearAnimation::addStatus(const std::string&  pageId, ByteBuffer* buffer)
	{
		GearAnimationValue gv;
		gv.playing = buffer->ReadBool();
		gv.frame = buffer->ReadInt();
		if (pageId.size() == 0)
			_default = gv;
		else
			_storage[pageId] = gv;
	}

	void GearAnimation::apply()
	{
		GearAnimationValue gv;
		auto it = _storage.find(_controller->getSelectedPageId());
		if (it != _storage.end())
			gv = it->second;
		else
			gv = _default;

		IAnimationGear *ag = dynamic_cast<IAnimationGear*>(_owner);

		ag->setPlaying(gv.playing);
		ag->setFrame(gv.frame);
	}

	void GearAnimation::updateState()
	{
		IAnimationGear *ag = dynamic_cast<IAnimationGear*>(_owner);
		_storage[_controller->getSelectedPageId()] = GearAnimationValue(ag->isPlaying(), ag->getFrame());
	}

}