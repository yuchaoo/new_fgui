#include "fgui/GProgressBar.h"
#include "fgui/GLabel.h"
#include "fgui/GSprite.h"
#include "fgui/GLoader.h"
#include "fgui/GTweener.h"
#include "fgui/TweenManager.h"
#include "fgui/FguiUtils.h"
#include "ComponentData.h"

namespace fgui {
	GProgressBar::GProgressBar()
	:_title(NULL)
	, _value(0)
	, _max(100)
	, _barMaxWidth(1)
	,_barMaxHeight(1){

	}

	GProgressBar::~GProgressBar() {

	}

	void GProgressBar::setTitleType(ProgressTitleType value)
	{
		if (_titleType != value){
			_titleType = value;
			update(_value);
		}
	}

	void GProgressBar::setMax(double value)
	{
		if (_max != value){
			_max = value;
			update(_value);
		}
	}

	void GProgressBar::setIsReverse(bool reverse) {
		_reverse = reverse;
	}

	void GProgressBar::setValue(double value)
	{
		if (_value != value){
			TweenManager::getInstance()->killTweens(this, TweenPropType::Progress, false);
			_value = value;
			update(_value);
		}
	}

	GTweener* GProgressBar::tweenValue(double value, float duration)
	{
		double oldValule;
		GTweener* twener = TweenManager::getInstance()->getTween(this, TweenPropType::Progress);
		if (twener != nullptr){
			oldValule = twener->value.d;
			twener->kill(false);
		}
		else {
			oldValule = _value;
		}
		_value = value;
		twener = TweenManager::getInstance()->createTween();
		return twener->toDouble(oldValule, _value, duration)
			->setEase(EaseType::Linear)
			->setTarget(this, TweenPropType::Progress);
	}

	void GProgressBar::setup(const ObjectInfo* inf, cocos2d::Node* parent) {
		GComponent::setup(inf, parent);
		const ProgressBarInfo* info = dynamic_cast<const ProgressBarInfo*>(inf);

		_title = dynamic_cast<GLabel*>(getChildByName("title"));
		_barH = getChildByName("bar");
		_barV = getChildByName("bar_v");
		if (_barH) {
			_barMaxWidth = _barH->getContentSize().width;
		}
		if (_barV) {
			_barMaxHeight = _barV->getContentSize().height;
		}
		_titleType = info->titleType;
		_reverse = info->bReverse;
		_value = info->value;
		_max = info->maxValue;

		update(_value);
	}

	void GProgressBar::update(double newValue)
	{
		float percent = _max != 0 ? MIN(newValue / _max, 1) : 0;

		if (_title != nullptr){
			std::ostringstream oss;
			switch (_titleType){
			case ProgressTitleType::PERCENT:
				oss << round(percent * 100) << "%";
				break;
			case ProgressTitleType::VALUE_MAX:
				oss << round(newValue) << "/" << round(_max);
				break;
			case ProgressTitleType::VALUE:
				oss << newValue;
				break;
			case ProgressTitleType::MAX:
				oss << _max;
				break;
			}
			_title->setString(oss.str());
		}

		if (!_reverse){
			if (_barH != nullptr){
				GSprite* image = dynamic_cast<GSprite*>(_barH);
				GLoader* loader = dynamic_cast<GLoader*>(_barH);
				if (image && image->getFillMethod() != FillMethod::None)
					image->setFillAmount(percent);
				else if (loader && loader->getFillMethod() != FillMethod::None)
					loader->setFillAmount(percent);
				else {
					const cocos2d::Size size = _barH->getContentSize();
					_barH->setContentSize(cocos2d::Size(round(_barMaxWidth * percent), size.height));
				}
			}
			if (_barV != nullptr){
				GSprite* image = dynamic_cast<GSprite*>(_barV);
				GLoader* loader = dynamic_cast<GLoader*>(_barV);
				if (image && image->getFillMethod() != FillMethod::None)
					image->setFillAmount(percent);
				else if (loader && loader->getFillMethod() != FillMethod::None)
					loader->setFillAmount(percent);
				else {
					const cocos2d::Size size = _barV->getContentSize();
					_barV->setContentSize(cocos2d::Size(size.width, round(_barMaxHeight * percent)));
				}
			}
		}
		else
		{
			percent = 1 - percent;
			if (_barH != nullptr){
				GSprite* image = dynamic_cast<GSprite*>(_barH);
				GLoader* loader = dynamic_cast<GLoader*>(_barH);
				if (image && image->getFillMethod() != FillMethod::None) {
					image->setFillAmount(percent);
				}
				else if (loader && loader->getFillMethod() != FillMethod::None) {
					loader->setFillAmount(percent);
				}
				else{
					cocos2d::Size size = _barH->getContentSize();
					_barH->setContentSize(cocos2d::Size(round(_barMaxWidth * percent), size.height));
				}
			}
			if (_barV != nullptr){
				GSprite* image = dynamic_cast<GSprite*>(_barV);
				GLoader* loader = dynamic_cast<GLoader*>(_barV);
				if (image && image->getFillMethod() != FillMethod::None) {
					image->setFillAmount(1 - percent);
				}
				else if (loader && loader->getFillMethod() != FillMethod::None) {
					loader->setFillAmount(1 - percent);
				}
				else{
					const cocos2d::Size& size = _barV->getContentSize();
					_barV->setContentSize(cocos2d::Size(size.width, round(_barMaxHeight * percent)));
				}
			}
		}
	}
}