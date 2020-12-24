#include "fgui/GSlider.h"
#include "fgui/GLabel.h"
#include "fgui/GSprite.h"
#include "fgui/GLoader.h"
#include "fgui/FguiUtils.h"
#include <algorithm>

namespace fgui {
	GSlider::GSlider()
		:_title(0)
		, _titleType(ProgressTitleType::VALUE)
		, _barH(NULL)
		, _barV(NULL)
		, _barMaxWidth(0)
		, _barMaxHeight(0)
		, _value(0)
		,_max(100){

	}

	GSlider::~GSlider() {

	}

	void GSlider::setValue(float value) {
		if (_value != value) {
			_value = value;
			update();
		}
	}

	void GSlider::setMax(float max) {
		if (_max != max) {
			_max = max;
			update();
		}
	}

	void GSlider::setPercent(float percent) {
		_value = percent * _max;
		update();
	}

	void GSlider::setupAfter(ByteBuffer* buffer, int pos) {
		GComponent::setupAfter(buffer, pos);
		if (!buffer->Seek(pos, 6)) {
			update();
			return;
		}

		if ((ObjectType)buffer->ReadByte() != _pkgItem->objectType) {
			update();
			return;
		}

		_value = buffer->ReadInt();
		_max = buffer->ReadInt();

		update();
	}

	void GSlider::setupExtend(ByteBuffer* buffer) {
		_titleType = (ProgressTitleType)buffer->ReadByte();
		_reverse = buffer->ReadBool();

		_title = dynamic_cast<GLabel*>(getChildByName("title"));
		_barH = getChildByName("bar");
		_barV = getChildByName("bar_v");
		_grip = getChildByName("grip");

		if (_barH != nullptr) {
			_barMaxWidth = _barH->getContentSize().width;
		}
		if (_barV != nullptr) {
			_barMaxHeight = _barV->getContentSize().height;
		}
		GObject* obj = dynamic_cast<GObject*>(_grip);
		if (obj) {
			obj->setTouchable(true);
			obj->setTouchMovedCallback(std::bind(&GSlider::onTouchMoved, this, std::placeholders::_1, std::placeholders::_2));
		}
	}

	void GSlider::setup(const ObjectInfo* inf, cocos2d::Node* parent) {
		GComponent::setup(inf, parent);
		const SliderInfo* info = dynamic_cast<const SliderInfo*>(inf);

		_value = info->value;
		_max = info->maxValue;
		_titleType = info->titleType;
		_reverse = info->bReverse;

		_title = dynamic_cast<GLabel*>(getChildByName("title"));
		_barH = getChildByName("bar");
		_barV = getChildByName("bar_v");
		_grip = getChildByName("grip");

		if (_barH != nullptr) {
			_barMaxWidth = _barH->getContentSize().width;
		}
		if (_barV != nullptr) {
			_barMaxHeight = _barV->getContentSize().height;
		}
		GObject* obj = dynamic_cast<GObject*>(_grip);
		if (obj) {
			obj->setTouchable(true);
			obj->setTouchMovedCallback(std::bind(&GSlider::onTouchMoved, this, std::placeholders::_1, std::placeholders::_2));
		}
		update();
	}

	void GSlider::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) {
		cocos2d::Vec2 v = touch->getLocation() - touch->getPreviousLocation();
		if (_barH) {
			float percent = (_barH->getContentSize().width + v.x) / _barMaxWidth;
			_value = std::max(0.0f,std::min(1.0f, percent)) * _max;
			update();
		}
		if (_barV) {
			float percent = (_barV->getContentSize().height + v.y) / _barMaxHeight;
			_value = std::max(0.0f, std::min(1.0f, percent)) * _max;
			update();
		}
	}

	void GSlider::setSlidingCallback(std::function<void(float)> handler) {
		_slidingHandler = handler;
	}

	void GSlider::update() {
		float percent = std::min(1.0f, std::max(0.0f, (_value / _max)));;
		if (_title != nullptr){
			std::ostringstream oss;
			switch (_titleType){
			case ProgressTitleType::PERCENT:
				oss << round(percent * 100) << "%";
				break;

			case ProgressTitleType::VALUE_MAX:
				oss << round(_value) << "/" << round(_max);
				break;

			case ProgressTitleType::VALUE:
				oss << _value;
				break;

			case ProgressTitleType::MAX:
				oss << _max;
				break;
			}
			_title->setString(oss.str());
		}

		if (_barH) {
			GSprite* image = dynamic_cast<GSprite*>(_barH);
			GLoader* loader = dynamic_cast<GLoader*>(_barH);
			if (image && image->getFillMethod() != FillMethod::None) {
				image->setFillAmount(percent);
			}
			else if (loader && loader->getFillMethod() != FillMethod::None) {
				loader->setFillAmount(percent);
			}
			else {
				cocos2d::Size size = _barH->getContentSize();
				_barH->setContentSize(cocos2d::Size(round(_barMaxWidth * percent), size.height));
			}
			/*if (_grip) {
				cocos2d::Vec2 lc = getPointWithAnchorPoint(_barH, 0, 0.5f);
				_grip->setPositionX(lc.x + _barMaxWidth * percent);
			}*/
		}
		if (_barV) {
			GSprite* image = dynamic_cast<GSprite*>(_barV);
			GLoader* loader = dynamic_cast<GLoader*>(_barV);
			if (image && image->getFillMethod() != FillMethod::None) {
				image->setFillAmount(percent);
			}
			else if (loader && loader->getFillMethod() != FillMethod::None) {
				loader->setFillAmount(percent);
			}
			else {
				const cocos2d::Size& size = _barV->getContentSize();
				_barV->setContentSize(cocos2d::Size(size.width, round(_barMaxHeight * percent)));
			}
			/*if (_grip) {
				cocos2d::Vec2 bc = getPointWithAnchorPoint(_barV, 0.5f, 0);
				_grip->setPositionY(bc.y + _barMaxHeight * percent);
			}*/
		}
		if (_slidingHandler) {
			_slidingHandler(percent);
		}
	}
}