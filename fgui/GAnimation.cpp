#include "GAnimation.h"
#include "cocosext/ccShaderEx.h"
#include "cocos2d.h"
#include "Package.h"
#include "PkgItem.h"
#include "ObjectData.h"
#include "ComponentData.h"

using namespace cocos2d;

namespace fgui {
	std::string GAnimation::SCHEDULE_NAME = "GAnimation_schedule";

	GAnimation::GAnimation()
	: _isPlaying(false)
	,_curFrame(0)
	,_bReverse(false)
	,_playTimes(0)
	,_totalTimes(-1)
	,_endFrame(-1)
	, _timeScale(1.0f)
	, _escape(0)
	, _swing(false)
	, _bEnd(false)
	, _displayFrame(-1)
	,_bAutoUpdate(true)
	, _bStopAtLastFrame(true)
	, _initFrame(0){
	}

	GAnimation::~GAnimation() {
		for (auto iter = _frames.begin(); iter != _frames.end(); ++iter) {
			(*iter)->release();
		}
	}

	void GAnimation::setHSVMode(bool isHsv) {
		if (_isHsvMode == isHsv) {
			return;
		}
		_isHsvMode = isHsv;
		if (_isHsvMode) {
			GLProgram* program = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, ccPositionTextureColor_noMVP_hsv_frag);
			if (program) {
				CHECK_GL_ERROR_DEBUG();
				GLProgramState* state = GLProgramState::getOrCreateWithGLProgram(program);
				state->setUniformFloat(HSV_HUE, 0.0f);
				state->setUniformFloat(HSV_BRIGHTNESS, 0.0f);
				state->setUniformFloat(HSV_CONTRAST, 0.0f);
				state->setUniformFloat(HSV_SATURATION, 0.0f);
				setGLProgram(program);
				setGLProgramState(state);
			}
		}
		else {
			GLProgram* program = GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP);
			setGLProgram(program);
		}
	}

	void GAnimation::setHSVValue(float hue, float saturation, float brightness, float contrast) {
		GObject::setHSVValue(hue, saturation, brightness, contrast);
		if (_isHsvMode) {
			GLProgramState* state = getGLProgramState();
			state->setUniformFloat(HSV_HUE, hue);
			state->setUniformFloat(HSV_SATURATION, saturation);
			state->setUniformFloat(HSV_BRIGHTNESS, brightness);
			state->setUniformFloat(HSV_CONTRAST, contrast);
		}
	}

	void GAnimation::constructFromItem(Package* pkg, PkgItem* item) {
		GObject::constructFromItem(pkg, item);
		AnimateItem* animateItem = dynamic_cast<AnimateItem*>(item);
		for (auto iter = _frames.begin(); iter != _frames.end(); ++iter) {
			(*iter)->release();
		}
		const std::vector<cocos2d::AnimationFrame*>& frames = animateItem->getAnimateFrames();
		_frames.resize(frames.size());
		for (size_t i = 0; i < _frames.size(); ++i) {
			_frames[i] = frames[i]->clone();
			_frames[i]->retain();
		}
		_swing = animateItem->isSwing();
		setContentSize(item->getSize());
	}

	void GAnimation::setup(const ObjectInfo* inf, cocos2d::Node* parent) {
		GObject::setup(inf, parent);
		const AnimationInfo* info = dynamic_cast<const AnimationInfo*>(inf);
		if (info->color) {
			setColor((cocos2d::Color3B)*info->color);
		}
		if (info->flipType != FlipType::NONE) {
			setFlippedX(info->flipType == FlipType::BOTH || info->flipType == FlipType::HORIZONTAL);
			setFlippedX(info->flipType == FlipType::BOTH || info->flipType == FlipType::VERTICAL);
		}
		_initFrame = info->initFrame;
		_endFrame = _frames.size() - 1;
		setCurFrame(_initFrame);
		setIsPlaying(info->bPlaying);
	}

	int GAnimation::getCurFrame() {
		return _curFrame;
	}

	void GAnimation::setCurFrame(int index) {
		_curFrame = index;
	}

	unsigned int GAnimation::getLoops() const {
		return _totalTimes;
	}

	void GAnimation::setLoops(unsigned int loops) {
		_totalTimes = loops;
	}

	void GAnimation::setFrames(const std::vector<cocos2d::AnimationFrame*>& frames) {
		_frames = frames;
	}

	const std::vector<cocos2d::AnimationFrame*>& GAnimation::getFrames() const {
		return _frames;
	}

	void GAnimation::setTimeScale(float scale) {
		_timeScale = scale;
	}

	void GAnimation::setIsSwing(bool bSwing) {
		_swing = bSwing;
	}

	void GAnimation::setAutoUpdate(bool bAuto) {
		if (_isPlaying || _bAutoUpdate == bAuto) {
			return;
		}
		_bAutoUpdate = bAuto;
	}

	void GAnimation::setPlayTime(float playTime) {
		if (_frames.size() <= 0) {
			return;
		}
		float unitDelay = playTime / _frames.size();
		for (auto iter = _frames.begin(); iter != _frames.end(); ++iter) {
			(*iter)->setDelayUnits(unitDelay);
		}
	}

	void GAnimation::setIsStopAtLastFrame(bool isStopAtLastFrame) {
		_bStopAtLastFrame = isStopAtLastFrame;
	}

	void GAnimation::play(int start, int end , int loops ) {
		_initFrame = MAX(0,start);
		_curFrame = _initFrame;
		_endFrame = end > 0 ? MIN( end, (int)_frames.size() - 1) : (int)_frames.size() - 1;
		_totalTimes = loops;
		_escape = 0;
		_bEnd = false;
		_playTimes = 0;
		_isPlaying = true;
		drawFrame();
	}

	void GAnimation::setIsPlaying(bool bPlaying) {
		if (_isPlaying == bPlaying) {
			return;
		}
		_isPlaying = bPlaying;
		bool ret = _scheduler->isScheduled(SCHEDULE_NAME, this);
		if (bPlaying && _bAutoUpdate) {
			if (!ret) {
				_scheduler->schedule(std::bind(&GAnimation::update, this, std::placeholders::_1), this, 0, false, SCHEDULE_NAME);
			}
			drawFrame();
		}
		else if (!bPlaying && ret) {
			_scheduler->unschedule(SCHEDULE_NAME, this);
		}
	}

	void GAnimation::pause() {
		if (_bEnd) {
			return;
		}
		_isPlaying = false;
	}

	void GAnimation::resume() {
		if (_bEnd) {
			return;
		}
		_isPlaying = true;
	}

	void GAnimation::drawFrame() {
		if (_curFrame == _displayFrame || _frames.size() == 0) {
			return;
		}
		_displayFrame = _curFrame;
		cocos2d::AnimationFrame* frame = _frames[_displayFrame];
		setSpriteFrame(frame->getSpriteFrame());
	}

	void GAnimation::update(float dt) {
		if (!_isPlaying) {
			return;
		}

		int frameCount = _frames.size();
		if (frameCount <= 0) {
			return;
		}
		if (_timeScale != 1) {
			dt *= _timeScale;
		}

		_escape += dt;

		float delayTime = 0.0f;

		while (1) {
			if (!_bReverse) {
				delayTime = _frames[_curFrame]->getDelayUnits();
				while (_escape >= delayTime) {
					_escape -= delayTime;
					++_curFrame;
					if (_curFrame > _endFrame) {
						_playTimes++;
						if (_totalTimes > 0 && _playTimes >= _totalTimes) {
							_curFrame = _bStopAtLastFrame ? _endFrame : _initFrame;
							_bEnd = true;
						}
						break;
					}
					delayTime = _frames[_curFrame]->getDelayUnits();
				}
				if (_bEnd) {
					break;
				}
				if (_curFrame > _endFrame) {
					if (_swing) {
						_curFrame = _endFrame - 1;
						_bReverse = true;
					}
					else {
						_curFrame = _initFrame;
					}
				}
			}
			else {
				delayTime = _frames[_curFrame]->getDelayUnits();
				while (_escape >= delayTime) {
					--_curFrame;
					_escape -= delayTime;
					if (_curFrame < _initFrame ) {
						_playTimes++;
						if (_totalTimes > 0 && _playTimes >= _totalTimes) {
							_curFrame = _bStopAtLastFrame ? _initFrame : _endFrame;
							_bEnd = true;
						}
						break;
					}
					delayTime = _frames[_curFrame]->getDelayUnits();
				}
				if (_bEnd) {
					break;
				}
				if (_curFrame < _initFrame) {
					if (_swing) {
						_curFrame = _initFrame;
						_bReverse = false;
					}
					else {
						_curFrame = _endFrame;
					}
				}
			}
			if (_escape < _frames[_curFrame]->getDelayUnits()) {
				break;
			}
		}
		if (_bEnd) {
			if (_completeCallback) {
				_completeCallback();
			}
			setIsPlaying(false);
		}
		drawFrame();
	}
}