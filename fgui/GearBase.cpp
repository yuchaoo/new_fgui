#include "GearBase.h"
#include "GearDisplay.h"
#include "GComponent.h"
#include "ToolSet.h"
#include "ByteBuffer.h"
#include "GTweener.h"
#include "ComponentData.h"

namespace fgui {

	GearTweenConfig::GearTweenConfig() :
		tween(true),
		easeType(EaseType::QuadOut),
		duration(0.3f),
		delay(0),
		_tweener(nullptr),
		_displayLockToken(0)
	{
	}

	GearBase::GearBase(GObject * owner) 
		:_owner(owner)
		, _tweenConfig(nullptr)
		, _node(NULL)
	{
		_node = dynamic_cast<cocos2d::Node*>(owner);
	}

	GearBase::~GearBase()
	{
		if (_tweenConfig && _tweenConfig->_tweener) {
			_tweenConfig->_tweener->kill();
		}
		CC_SAFE_DELETE(_tweenConfig);
	}

	void GearBase::setController(GController * value)
	{
		if (value != _controller){
			_controller = value;
			if (_controller != nullptr) {
				init();
			}	
		}
	}

	GearTweenConfig * GearBase::getTweenConfig()
	{
		if (!_tweenConfig)
			_tweenConfig = new GearTweenConfig();

		return _tweenConfig;
	}

	void GearBase::init()
	{
	}

	void GearBase::initWithInfo(const GearInfo* info) {

	}

	void GearBase::addStatus(const std::string&  pageId, ByteBuffer* buffer)
	{
	}

	void GearBase::apply()
	{
	}

	void GearBase::updateState()
	{
	}

	void GearBase::updateFromRelations(float dx, float dy)
	{
	}

	void GearBase::setup(ByteBuffer* buffer,GComponent* parent)
	{
		_controller = parent->getControllerAt(buffer->ReadShort());

		init();

		GearDisplay* gear = dynamic_cast<GearDisplay*>(this);
		if (gear){
			int cnt = buffer->ReadShort();
			for (int i = 0; i < cnt; i++) {
				gear->pages.push_back(buffer->ReadS());
			}
		}
		else{
			int cnt = buffer->ReadShort();
			for (int i = 0; i < cnt; i++){
				const std::string& page = buffer->ReadS();
				if (page.empty()) {
					continue;
				}	
				addStatus(page, buffer);
			}

			if (buffer->ReadBool()) {
				addStatus("", buffer);
			}
		}

		if (buffer->ReadBool()){
			_tweenConfig = new GearTweenConfig();
			_tweenConfig->easeType = (EaseType)buffer->ReadByte();
			_tweenConfig->duration = buffer->ReadFloat();
			_tweenConfig->delay = buffer->ReadFloat();
		}
	}

	void GearBase::setup(const GearInfo* info, GComponent* parent) {
		_controller = parent->getControllerAt(info->controllerIndex);
		init();
		initWithInfo(info);
		if (info->config) {
			_tweenConfig = new GearTweenConfig();
			_tweenConfig->easeType = info->config->easeType;
			_tweenConfig->duration = info->config->duration;
			_tweenConfig->delay = info->config->delay;
		}
	}

}