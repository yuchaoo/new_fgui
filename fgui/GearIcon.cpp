#include "GearIcon.h"
#include "GObject.h"
#include "ByteBuffer.h"
#include "GLoader.h"
#include "Controller.h"
#include "GearData.h"

namespace fgui {

	GearIcon::GearIcon(GObject * owner) 
		:GearBase(owner)
	{
		m_loader = dynamic_cast<GLoader*>(owner);
	}

	GearIcon::~GearIcon()
	{
	}

	void GearIcon::init()
	{
		_default = m_loader->getURL();
		_storage.clear();
	}

	void GearIcon::addStatus(const std::string&  pageId, ByteBuffer* buffer)
	{
		if (pageId.length() == 0)
			_default = buffer->ReadS();
		else
			_storage[pageId] = buffer->ReadS();
	}

	void GearIcon::apply()
	{
		auto it = _storage.find(_controller->getSelectedPageId());
		if (it != _storage.end())
			m_loader->setURL(it->second);
		else
			m_loader->setURL(_default);
	}

	void GearIcon::updateState()
	{
		_storage[_controller->getSelectedPageId()] = m_loader->getURL();
	}

	void GearIcon::initWithInfo(const GearInfo* inf) {
		const GearIconInfo* info = dynamic_cast<const GearIconInfo*>(inf);
		_storage = info->values;
		_default = info->defaultValue;
	}


}