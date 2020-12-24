#include "GearColor.h"
#include "GObject.h"
#include "UIPackage.h"
#include "ByteBuffer.h"
#include "GLabel.h"
#include "TweenManager.h"
#include "GTweener.h"
#include "Controller.h"
#include "GComponent.h"

namespace fgui {

	GearColorValue::GearColorValue()
	{

	}

	GearColorValue::GearColorValue(const cocos2d::Color4B& color, const cocos2d::Color4B& strokeColor)
	{
		this->color = color;
		this->outlineColor = strokeColor;
	}

	GearColor::GearColor(GObject * owner) 
		:GearBase(owner)
	{
		_label = dynamic_cast<GLabel*>(owner);
	}

	GearColor::~GearColor()
	{
	}

	void GearColor::init()
	{
		_default.color = cocos2d::Color4B::WHITE;
		_default.outlineColor = cocos2d::Color4B::WHITE;
		if (_label) {
			const TextFormat* format = _label->getTextFormat();
			_default = GearColorValue(format->color, format->outlineColor);
		}
		_storage.clear();
	}

	void GearColor::addStatus(const std::string&  pageId, ByteBuffer* buffer)
	{
		GearColorValue gv;
		gv.color = buffer->ReadColor();
		gv.outlineColor = buffer->ReadColor();
		if (pageId.size() == 0)
			_default = gv;
		else
			_storage[pageId] = gv;
	}

	void GearColor::apply()
	{
		GearColorValue gv;
		auto it = _storage.find(_controller->getSelectedPageId());
		if (it != _storage.end()) {
			gv = it->second;
		}
		else {
			gv = _default;
		}

		GComponent* comp = _controller->getParent();
		if (_tweenConfig && !comp->isConstructing()) {
			if (_tweenConfig->_tweener != nullptr){
				if (_tweenConfig->_tweener->endValue.getColor() != gv.color){
					_tweenConfig->_tweener->kill(true);
					_tweenConfig->_tweener = nullptr;
				}
				else {
					return;
				}	
			}
			
			if (_label) {
				TextFormat* format = _label->getTextFormat();
				if (gv.outlineColor != format->outlineColor) {
					format->outlineColor = gv.outlineColor;
				}
				if (gv.color != format->color) {
					GTweener* tweener = TweenManager::getInstance()->createTween();
					tweener->toColor(format->color, gv.color, _tweenConfig->duration);
					tweener->setDelay(_tweenConfig->delay);
					tweener->setEase(_tweenConfig->easeType);
					tweener->setTargetAny(this);
					tweener->onUpdate(CC_CALLBACK_1(GearColor::onTweenUpdate, this));
					tweener->onComplete(CC_CALLBACK_0(GearColor::onTweenComplete, this));
				}
			}
			else {
				const cocos2d::Color3B& color = _node->getColor();
				if (gv.color != color) {
					GTweener* tweener = TweenManager::getInstance()->createTween();
					tweener->toColor((cocos2d::Color4B)color, gv.color, _tweenConfig->duration);
					tweener->setDelay(_tweenConfig->delay);
					tweener->setEase(_tweenConfig->easeType);
					tweener->setTargetAny(this);
					tweener->onUpdate(CC_CALLBACK_1(GearColor::onTweenUpdate, this));
					tweener->onComplete(CC_CALLBACK_0(GearColor::onTweenComplete, this));
				}
			}
		}
		else
		{
			if (_label) {
				bool isDirty = false;
				TextFormat* format = _label->getTextFormat();
				if (gv.outlineColor != format->outlineColor) {
					format->outlineColor = gv.outlineColor;
					isDirty = true;
				}
				if (gv.color != format->color) {
					format->color = gv.color;
					isDirty = true;
				}
				if (isDirty) {
					_label->applyTextFormat();
				}
			}
		}
	}

	void GearColor::onTweenUpdate(GTweener* tweener)
	{
		if (_label) {
			_label->setFontColor(tweener->value.getColor());
		}
		else {
			_node->setColor((cocos2d::Color3B)tweener->value.getColor());
		}
	}

	void GearColor::onTweenComplete()
	{
		_tweenConfig->_tweener = nullptr;
	}

	void GearColor::updateState()
	{
		if (_label) {
			TextFormat* format = _label->getTextFormat();
			_storage[_controller->getSelectedPageId()] = GearColorValue(format->color, format->outlineColor);
		}
	}

	void GearColor::initWithInfo(const GearInfo* inf) {
		const GearColorInfo* info = dynamic_cast<const GearColorInfo*>(inf);
		_storage.clear();
		for (auto iter = info->values.begin(); iter != info->values.end(); ++iter) {
			_storage.insert(std::make_pair(iter->first, *iter->second));
		}
		if (info->defaultValue) {
			_default = *info->defaultValue;
		}
	}



}