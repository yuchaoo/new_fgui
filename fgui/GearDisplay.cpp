#include "GearDisplay.h"
#include "Controller.h"
#include "ByteBuffer.h"
#include "GObject.h"

namespace fgui {

	GearDisplay::GearDisplay(GObject * owner) 
		:GearBase(owner)
		, _displayLockToken(1)
	{
	}

	GearDisplay::~GearDisplay()
	{
	}

	void GearDisplay::apply()
	{
		_displayLockToken++;
		if (_displayLockToken == 0)
			_displayLockToken = 1;

		if (pages.size() == 0)
			_visible = 1;
		else{
			auto iter = std::find(pages.begin(), pages.end(), _controller->getSelectedPageId());
			if (iter != pages.end())
				_visible = 1;
			else
				_visible = 0;
		}
		auto node = dynamic_cast<cocos2d::Node*>(_owner);
		if (node) {
			node->setVisible(_visible);
		}
	}

	void GearDisplay::initWithInfo(const GearInfo* inf) {
		const GearDisplayInfo* info = dynamic_cast<const GearDisplayInfo*>(inf);
		pages = info->pages;
	}

	void GearDisplay::updateState()
	{
	}

	void GearDisplay::addStatus(const std::string&  pageId, ByteBuffer* buffer)
	{
	}

	void GearDisplay::init()
	{
		pages.clear();
	}

	uint32_t GearDisplay::addLock()
	{
		_visible++;
		return _displayLockToken;
	}

	void GearDisplay::releaseLock(uint32_t token)
	{
		if (token == _displayLockToken)
			_visible--;
	}

	bool GearDisplay::isConnected()
	{
		return _controller == nullptr || _visible > 0;
	}

}