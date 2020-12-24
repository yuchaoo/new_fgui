#include "GearText.h"
#include "GObject.h"
#include "ByteBuffer.h"
#include "GLabel.h"
#include "Controller.h"

namespace fgui {

	GearText::GearText(GObject * owner) 
		:GearBase(owner)
		, m_label(NULL)
	{
		m_label = dynamic_cast<GLabel*>(owner);
	}

	GearText::~GearText()
	{
	}

	void GearText::init()
	{
		if (m_label) {
			_default = m_label->getString();
		}
		_storage.clear();
	}

	void GearText::addStatus(const std::string&  pageId, ByteBuffer* buffer)
	{
		if (pageId.length() == 0)
			_default = buffer->ReadS();
		else
			_storage[pageId] = buffer->ReadS();
	}

	void GearText::apply()
	{
		auto it = _storage.find(_controller->getSelectedPageId());
		if (it != _storage.end()) {
			if (m_label) {
				m_label->setString(it->second);
			}
		}
		else {
			if (m_label) {
				m_label->setString(_default);
			}
		}
	}

	void GearText::updateState()
	{
		if (m_label) {
			_storage[_controller->getSelectedPageId()] = m_label->getString();
		}
	}

	void GearText::initWithInfo(const GearInfo* inf) {
		const GearTextInfo* info = dynamic_cast<const GearTextInfo*>(inf);
		_storage = info->values;
		_default = info->defaultValue;
	}

}