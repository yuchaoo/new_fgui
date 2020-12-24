#include "GTweener.h"
#include "GObject.h"
#include "cocos2d.h"
#include "base/ccRandom.h"
#include "GProgressBar.h"

float random_0_1() {
	return cocos2d::rand_0_1();
}

namespace fgui {
	static const float _PiOver2 = (float)(M_PI * 0.5f);
	static const float _TwoPi = (float)(M_PI * 2);

	class Bounce
	{
	public:
		static float easeIn(float time, float duration) {
			return 1 - easeOut(duration - time, duration);
		}
		static float easeOut(float time, float duration) {
			time /= duration;
			if (time < (1 / 2.75f))
			{
				return (7.5625f * time * time);
			}
			if (time < (2 / 2.75f))
			{
				time -= (1.5f / 2.75f);
				return (7.5625f * time * time + 0.75f);
			}
			if (time < (2.5f / 2.75f))
			{
				time -= (2.25f / 2.75f);
				return (7.5625f * time * time + 0.9375f);
			}
			time -= (2.625f / 2.75f);
			return (7.5625f * time * time + 0.984375f);
		}
		static float easeInOut(float time, float duration) {
			if (time < duration * 0.5f)
			{
				return easeIn(time * 2, duration) * 0.5f;
			}
			return easeOut(time * 2 - duration, duration) * 0.5f + 0.5f;
		}
	};

	GTweener::GTweener() :
		_target(nullptr),
		_refTarget(nullptr),
		_userData(nullptr),
		_onStart(nullptr),
		_onUpdate(nullptr),
		_onComplete(nullptr),
		_onComplete0(nullptr)
	{
	}

	GTweener::~GTweener()
	{

	}

	GTweener * GTweener::setDelay(float value)
	{
		_delay = value;
		return this;
	}

	GTweener * GTweener::setDuration(float value)
	{
		_duration = value;
		return this;
	}

	GTweener * GTweener::setBreakpoint(float value)
	{
		_breakpoint = value;
		return this;
	}

	GTweener * GTweener::setEase(EaseType value)
	{
		_easeType = value;
		return this;
	}

	GTweener * GTweener::setEasePeriod(float value)
	{
		_easePeriod = value;
		return this;
	}

	GTweener * GTweener::setEaseOvershootOrAmplitude(float value)
	{
		_easeOvershootOrAmplitude = value;
		return this;
	}

	GTweener * GTweener::setRepeat(int repeat, bool yoyo)
	{
		_repeat = repeat;
		_yoyo = yoyo;
		return this;
	}

	GTweener * GTweener::setTimeScale(float value)
	{
		_timeScale = value;
		return this;
	}

	GTweener * GTweener::setSnapping(bool value)
	{
		_snapping = value;
		return this;
	}

	GTweener * GTweener::setTargetAny(void * value)
	{
		CC_SAFE_RELEASE(_refTarget);
		_refTarget = nullptr;
		_target = value;
		return this;
	}

	GTweener * GTweener::setTarget(cocos2d::Ref* value)
	{
		return setTarget(value, TweenPropType::None);
	}

	GTweener * GTweener::setTarget(cocos2d::Ref * target, TweenPropType propType)
	{
		CC_SAFE_RELEASE(_refTarget);
		_target = _refTarget = target;
		_propType = propType;
		CC_SAFE_RETAIN(_refTarget);
		return this;
	}

	GTweener * GTweener::setUserData(const cocos2d::Value& value)
	{
		_userData = value;
		return this;
	}

	GTweener * GTweener::onUpdate(GTweenCallback callback)
	{
		_onUpdate = callback;
		return this;
	}

	GTweener * GTweener::onStart(GTweenCallback callback)
	{
		_onStart = callback;
		return this;
	}

	GTweener * GTweener::onComplete(GTweenCallback0 callback)
	{
		_onComplete0 = callback;
		return this;
	}

	GTweener * GTweener::onComplete1(GTweenCallback callback)
	{
		_onComplete = callback;
		return this;
	}

	GTweener * GTweener::setPaused(bool paused)
	{
		_paused = paused;
		return this;
	}

	void GTweener::seek(float time)
	{
		if (_killed)
			return;

		_elapsedTime = time;
		if (_elapsedTime < _delay)
		{
			if (_started)
				_elapsedTime = _delay;
			else
				return;
		}

		update();
	}

	void GTweener::kill(bool complete)
	{
		if (_killed)
			return;

		if (complete)
		{
			if (_ended == 0)
			{
				if (_breakpoint >= 0)
					_elapsedTime = _delay + _breakpoint;
				else if (_repeat >= 0)
					_elapsedTime = _delay + _duration * (_repeat + 1);
				else
					_elapsedTime = _delay + _duration * 2;
				update();
			}

			callCompleteCallback();
		}

		_killed = true;
	}

	GTweener * GTweener::toValue(float start, float end, float duration)
	{
		_valueSize = 1;
		startValue.x = start;
		endValue.x = end;
		value.x = start;
		_duration = duration;
		return this;
	}

	GTweener * GTweener::toVec2(const cocos2d::Vec2 & start, const cocos2d::Vec2 & end, float duration)
	{
		_valueSize = 2;
		startValue.setVec2(start);
		endValue.setVec2(end);
		value.setVec2(start);
		_duration = duration;
		return this;
	}

	GTweener * GTweener::toVec3(const cocos2d::Vec3 & start, const cocos2d::Vec3 & end, float duration)
	{
		_valueSize = 3;
		startValue.setVec3(start);
		endValue.setVec3(end);
		value.setVec3(start);
		_duration = duration;
		return this;
	}

	GTweener * GTweener::toVec4(const cocos2d::Vec4 & start, const cocos2d::Vec4 & end, float duration)
	{
		_valueSize = 4;
		startValue.setVec4(start);
		endValue.setVec4(end);
		value.setVec4(start);
		_duration = duration;
		return this;
	}

	GTweener * GTweener::toColor(const cocos2d::Color4B & start, const cocos2d::Color4B & end, float duration)
	{
		_valueSize = 4;
		startValue.setColor(start);
		endValue.setColor(end);
		value.setColor(start);
		_duration = duration;
		return this;
	}

	GTweener * GTweener::toDouble(double start, double end, float duration)
	{
		_valueSize = 5;
		startValue.d = start;
		endValue.d = end;
		value.d = start;
		_duration = duration;
		return this;
	}

	GTweener * GTweener::shake(const cocos2d::Vec2 & start, float amplitude, float duration)
	{
		_valueSize = 6;
		startValue.setVec2(start);
		startValue.w = amplitude;
		_duration = duration;
		_easeType = EaseType::Linear;
		return this;
	}

	void GTweener::init()
	{
		_delay = 0;
		_duration = 0;
		_breakpoint = -1;
		_easeType = EaseType::QuadOut;
		_timeScale = 1;
		_easePeriod = 0;
		_easeOvershootOrAmplitude = 1.70158f;
		_snapping = false;
		_repeat = 0;
		_yoyo = false;
		_valueSize = 0;
		_started = false;
		_paused = false;
		_killed = false;
		_elapsedTime = 0;
		_normalizedTime = 0;
		_ended = 0;
		startValue.setZero();
		endValue.setZero();
		value.setZero();
		deltaValue.setZero();
	}

	void GTweener::reset()
	{
		CC_SAFE_RELEASE(_refTarget);
		_target = nullptr;
		_refTarget = nullptr;
		_userData = nullptr;
		_onStart = _onUpdate = _onComplete = nullptr;
		_onComplete0 = nullptr;
	}

	void GTweener::update(float dt)
	{
		if (_ended != 0){ //Maybe completed by seek
			callCompleteCallback();
			_killed = true;
			return;
		}

		if (_timeScale != 1) {
			dt *= _timeScale;
		}
			
		if (dt == 0) {
			return;
		}
			
		_elapsedTime += dt;
		update();

		if (_ended != 0){
			if (!_killed){
				callCompleteCallback();
				_killed = true;
			}
		}
	}

	void GTweener::update()
	{
		_ended = 0;

		if (_valueSize == 0){ //DelayedCall
			if (_elapsedTime >= _delay + _duration)
				_ended = 1;
			return;
		}

		if (!_started){
			if (_elapsedTime < _delay) {
				return;
			}
			_started = true;
			callStartCallback();
			if (_killed) {
				return;
			}
		}

		bool reversed = false;
		float tt = _elapsedTime - _delay;
		if (_breakpoint >= 0 && tt >= _breakpoint){
			tt = _breakpoint;
			_ended = 2;
		}

		if (_repeat != 0){
			int round = (int)floor(tt / _duration);
			tt -= _duration * round;
			if (_yoyo) {
				reversed = round % 2 == 1;
			}
			
			if (_repeat > 0 && _repeat - round < 0){
				if (_yoyo) {
					reversed = _repeat % 2 == 1;
				}
				tt = _duration;
				_ended = 1;
			}
		}
		else if (tt >= _duration){
			tt = _duration;
			_ended = 1;
		}

		_normalizedTime = evaluate(_easeType, reversed ? (_duration - tt) : tt, _duration, _easeOvershootOrAmplitude, _easePeriod);

		value.setZero();
		deltaValue.setZero();

		if (_valueSize == 5){
			double d = startValue.d + (endValue.d - startValue.d) * _normalizedTime;
			if (_snapping)
				d = round(d);
			deltaValue.d = d - value.d;
			value.d = d;
		}
		else if (_valueSize == 6){ //shake
			if (_ended == 0){
				float r = startValue.w * (1 - _normalizedTime);
				float rx = (random_0_1() * 2 - 1)*r;
				float ry = (random_0_1() * 2 - 1)*r;
				rx = rx > 0 ? ceil(rx) : floor(rx);
				ry = ry > 0 ? ceil(ry) : floor(ry);

				deltaValue.x = rx;
				deltaValue.y = ry;
				value.x = startValue.x + rx;
				value.y = startValue.y + ry;
			}
			else
				value.setVec3(startValue.getVec3());
		}
		else{
			for (int i = 0; i < _valueSize; i++){
				float n1 = startValue[i];
				float n2 = endValue[i];
				float f = n1 + (n2 - n1) * _normalizedTime;
				if (_snapping)
					f = round(f);
				deltaValue[i] = f - value[i];
				value[i] = f;
			}
		}

		if (_refTarget != nullptr && _propType != TweenPropType::None){
			cocos2d::Node* node = dynamic_cast<cocos2d::Node*>(_refTarget);
			if (node != nullptr) {
				setProps(node, _propType, value);
			}
		}

		callUpdateCallback();
	}

	float GTweener::evaluate(EaseType easeType, float time, float duration, float overshootOrAmplitude, float period) {
		switch (easeType)
		{
		case EaseType::Linear:
			return time / duration;
		case EaseType::SineIn:
			return -(float)cos(time / duration * _PiOver2) + 1;
		case EaseType::SineOut:
			return (float)sin(time / duration * _PiOver2);
		case EaseType::SineInOut:
			return -0.5f * ((float)cos(M_PI * time / duration) - 1);
		case EaseType::QuadIn:
			time /= duration;
			return time * time;
		case EaseType::QuadOut:
			time /= duration;
			return -time * (time - 2);
		case EaseType::QuadInOut:
			time /= duration * 0.5f;
			if (time < 1) return 0.5f * time * time;
			--time;
			return -0.5f * (time * (time - 2) - 1);
		case EaseType::CubicIn:
			time /= duration;
			return time * time * time;
		case EaseType::CubicOut:
			time = time / duration - 1;
			return time * time * time + 1;
		case EaseType::CubicInOut:
			time /= duration * 0.5f;
			if (time < 1) return 0.5f * time * time * time;
			time -= 2;
			return 0.5f * (time * time * time + 2);
		case EaseType::QuartIn:
			time /= duration;
			return time * time * time * time;
		case EaseType::QuartOut:
			time = time / duration - 1;
			return -(time * time * time * time - 1);
		case EaseType::QuartInOut:
			time /= duration * 0.5f;
			if (time < 1) return 0.5f * time * time * time * time;
			time -= 2;
			return -0.5f * (time * time * time * time - 2);
		case EaseType::QuintIn:
			time /= duration;
			return time * time * time * time * time;
		case EaseType::QuintOut:
			time = time / duration - 1;
			return (time * time * time * time * time + 1);
		case EaseType::QuintInOut:
			time /= duration * 0.5f;
			if (time < 1) return 0.5f * time * time * time * time * time;
			time -= 2;
			return 0.5f * (time * time * time * time * time + 2);
		case EaseType::ExpoIn:
			return (time == 0) ? 0 : (float)pow(2, 10 * (time / duration - 1));
		case EaseType::ExpoOut:
			if (time == duration) return 1;
			return (-(float)pow(2, -10 * time / duration) + 1);
		case EaseType::ExpoInOut:
			if (time == 0) return 0;
			if (time == duration) return 1;
			if ((time /= duration * 0.5f) < 1) return 0.5f * (float)pow(2, 10 * (time - 1));
			return 0.5f * (-(float)pow(2, -10 * --time) + 2);
		case EaseType::CircIn:
			time /= duration;
			return -((float)sqrt(1 - time * time) - 1);
		case EaseType::CircOut:
			time = time / duration - 1;
			return (float)sqrt(1 - time * time);
		case EaseType::CircInOut:
			time /= duration * 0.5f;
			if (time < 1) return -0.5f * ((float)sqrt(1 - time * time) - 1);
			time -= 2;
			return 0.5f * ((float)sqrt(1 - time * time) + 1);
		case EaseType::ElasticIn:
			float s0;
			if (time == 0) return 0;
			if ((time /= duration) == 1) return 1;
			if (period == 0) period = duration * 0.3f;
			if (overshootOrAmplitude < 1)
			{
				overshootOrAmplitude = 1;
				s0 = period / 4;
			}
			else s0 = period / _TwoPi * (float)asin(1 / overshootOrAmplitude);
			time -= 1;
			return -(overshootOrAmplitude * (float)pow(2, 10 * time) * (float)sin((time * duration - s0) * _TwoPi / period));
		case EaseType::ElasticOut:
			float s1;
			if (time == 0) return 0;
			if ((time /= duration) == 1) return 1;
			if (period == 0) period = duration * 0.3f;
			if (overshootOrAmplitude < 1)
			{
				overshootOrAmplitude = 1;
				s1 = period / 4;
			}
			else s1 = period / _TwoPi * (float)asin(1 / overshootOrAmplitude);
			return (overshootOrAmplitude * (float)pow(2, -10 * time) * (float)sin((time * duration - s1) * _TwoPi / period) + 1);
		case EaseType::ElasticInOut:
			float s;
			if (time == 0) return 0;
			if ((time /= duration * 0.5f) == 2) return 1;
			if (period == 0) period = duration * (0.3f * 1.5f);
			if (overshootOrAmplitude < 1)
			{
				overshootOrAmplitude = 1;
				s = period / 4;
			}
			else s = period / _TwoPi * (float)asin(1 / overshootOrAmplitude);
			if (time < 1)
			{
				time -= 1;
				return -0.5f * (overshootOrAmplitude * (float)pow(2, 10 * time) * (float)sin((time * duration - s) * _TwoPi / period));
			}

			time -= 1;
			return overshootOrAmplitude * (float)pow(2, -10 * time) * (float)sin((time * duration - s) * _TwoPi / period) * 0.5f + 1;
		case EaseType::BackIn:
			time /= duration;
			return time * time * ((overshootOrAmplitude + 1) * time - overshootOrAmplitude);
		case EaseType::BackOut:
			time = time / duration - 1;
			return (time * time * ((overshootOrAmplitude + 1) * time + overshootOrAmplitude) + 1);
		case EaseType::BackInOut:
			time /= duration * 0.5f;
			overshootOrAmplitude *= (1.525f);
			if (time < 1) return 0.5f * (time * time * ((overshootOrAmplitude + 1) * time - overshootOrAmplitude));
			time -= 2;
			return 0.5f * (time * time * ((overshootOrAmplitude + 1) * time + overshootOrAmplitude) + 2);
		case EaseType::BounceIn:
			return Bounce::easeIn(time, duration);
		case EaseType::BounceOut:
			return Bounce::easeOut(time, duration);
		case EaseType::BounceInOut:
			return Bounce::easeInOut(time, duration);

		default:
			time /= duration;
			return -time * (time - 2);
		}
	}

	void GTweener::setProps(cocos2d::Node* g, TweenPropType propType, const TweenValue& value) {
		if (g == nullptr)
			return;

		switch (propType){
		case TweenPropType::X: {
			g->setPositionX(value.x);
		}
		break;

		case TweenPropType::Y: {
			g->setPositionY(value.x);
		}
		break;

		case TweenPropType::Position: {
			g->setPosition(value.x, value.y);
		}
		break;

		case TweenPropType::Width: {
			const cocos2d::Size& size = g->getContentSize();
			g->setContentSize(cocos2d::Size(value.x, size.height));
		}
		break;

		case TweenPropType::Height: {
			const cocos2d::Size& size = g->getContentSize();
			g->setContentSize(cocos2d::Size(size.width, value.x));
		}
		break;
		
		case TweenPropType::Size: {
			g->setContentSize(cocos2d::Size(value.x, value.y));
		}
		break;

		case TweenPropType::ScaleX: {
			g->setScaleX(value.x);
		}
		break;

		case TweenPropType::ScaleY: {
			g->setScaleY(value.x);
		}
		break;

		case TweenPropType::Scale: {
			g->setScale(value.x, value.y);
		}
		break;

		case TweenPropType::Rotation: {
			g->setRotation(value.x);
		}
		break;

		case TweenPropType::Alpha: {
			g->setOpacity(value.x);
		}
		break;

		case TweenPropType::Progress: {
			GProgressBar* bar = dynamic_cast<GProgressBar*>(g);
			if (bar) {
				bar->update(value.x);
			}
		}
		break;
		default:
		break;
		}
	}


	void GTweener::callStartCallback()
	{
		if (_onStart != nullptr)
			_onStart(this);
	}

	void GTweener::callUpdateCallback()
	{
		if (_onUpdate != nullptr)
			_onUpdate(this);
	}

	void GTweener::callCompleteCallback()
	{
		if (_onComplete != nullptr)
			_onComplete(this);
		if (_onComplete0 != nullptr)
			_onComplete0();
	}

}