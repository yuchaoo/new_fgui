#pragma once
#include "GObject.h"

namespace cocos2d {
	class Animate;
}

namespace fgui {
	class PkgItem;
	class Package;

	class GAnimation
		: public cocos2d::Sprite
		, public GObject {
	public:
		static std::string SCHEDULE_NAME;

		CREATE_FUNC(GAnimation);
		GAnimation();
		~GAnimation();

		int getCurFrame();
		void setCurFrame(int index);

		unsigned int getLoops() const;
		void setLoops(unsigned int loops);
		void setFrames(const std::vector<cocos2d::AnimationFrame*>& frames);
		const std::vector<cocos2d::AnimationFrame*>& getFrames() const;
		void setTimeScale(float scale);
		void setIsSwing(bool bSwing);
		void setIsPlaying(bool bPlaying);
		bool isPlaying() { return _isPlaying; };

		void setPlayTime(float playTime);
		void setIsStopAtLastFrame(bool isStopAtLastFrame);
		void play(int start = 0, int end = -1, int loops = -1);
		void pause();
		void resume();
		void setAutoUpdate(bool bAuotUpdate);
		void update(float dt);

		virtual void setHSVMode(bool isHsv);
		virtual void setHSVValue(float hue, float saturation, float brightness, float contrast);
	protected:
		virtual void constructFromItem(Package* pkg, PkgItem* item);
		virtual void setup(const ObjectInfo* info, cocos2d::Node* parent);
	private:
		void drawFrame();
	private:
		std::vector<cocos2d::AnimationFrame*> _frames;
		int _initFrame;
		int _curFrame;
		int _displayFrame;
		int _bReverse;
		int _playTimes;
		int _totalTimes;
		int _endFrame;
		float _timeScale;
		float _escape;
		bool _swing;
		bool _bEnd;
		bool _bAutoUpdate;
		std::function<void()> _completeCallback;
		bool _isPlaying;
		bool _bStopAtLastFrame;
	};

}

