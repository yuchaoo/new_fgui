#pragma once
#include <string>
#include <functional>
#include "FieldTypes.h"
#include "math/Vec2.h"
#include "base/ccTypes.h"
#include "base/CCValue.h"

namespace fgui {
	class GObject;
	class GComponent;
	class TransitionItem;
	class GTweener;
	class ByteBuffer;
	class GTransition;
	struct TransitionInfo;

	typedef std::function<void()> PlayCompleteCallback;
	typedef std::function<void()> TransitionHook;

	class TValue
	{
	public:
		float f1;
		float f2;
		float f3;
		float f4;
		bool b1;
		bool b2;

		TValue();
		cocos2d::Vec2 getVec2() const;
		void setVec2(const cocos2d::Vec2& value);
		cocos2d::Vec4 getVec4() const;
		void setVec4(const cocos2d::Vec4& value);
		cocos2d::Color4B getColor() const;
		void setColor(const cocos2d::Color4B& value);
	};

	struct TValue_Visible
	{
	public:
		bool visible;
	};

	struct TValue_Animation
	{
	public:
		int frame;
		bool playing;
		bool flag;
	};

	struct TValue_Sound
	{
	public:
		std::string sound;
		float volume;
	};

	struct TValue_Transition
	{
	public:
		std::string transName;
		int playTimes;
		GTransition* trans;
		float stopTime;
	};

	struct TValue_Shake
	{
	public:
		float amplitude;
		float duration;
		cocos2d::Vec2 lastOffset;
		cocos2d::Vec2 offset;
	};

	struct TValue_Text
	{
	public:
		std::string text;
	};


	class TweenConfig
	{
	public:
		float duration;
		EaseType easeType;
		int repeat;
		bool yoyo;

		TValue* startValue;
		TValue* endValue;

		std::string endLabel;
		TransitionHook endHook;

		TweenConfig();
	};

	class TransitionItem
	{
	public:
		float time;
		std::string targetId;
		TransitionActionType type;
		TweenConfig* tweenConfig;
		std::string label;
		void* value;
		TransitionHook hook;

		//running properties
		GTweener* tweener;
		cocos2d::Node* target;
		uint32_t displayLockToken;

		TransitionItem(TransitionActionType aType);
	};

	class GTransition : public cocos2d::Ref
	{
	public:
		GTransition(GComponent* owner);
		virtual ~GTransition();

		GComponent* getOwner() const { return _owner; }
		bool isPlaying() const { return _playing; }
		const std::string& getName() const { return _name; }

		void play(PlayCompleteCallback callback = nullptr);
		void play(int times, float delay, PlayCompleteCallback callback = nullptr);
		void play(int times, float delay, float startTime, float endTime, PlayCompleteCallback callback = nullptr);
		void playReverse(PlayCompleteCallback callback = nullptr);
		void playReverse(int times, float delay, PlayCompleteCallback callback = nullptr);
		void changePlayTimes(int value);
		void stop();
		void stop(bool setToComplete, bool processCallback);
		void setAutoPlay(bool autoPlay, int times, float delay);
		void setPaused(bool paused);

		void setValue(const std::string& label, const cocos2d::ValueVector& values);
		void setHook(const std::string& label, TransitionHook callback);
		void clearHooks();
		void setTarget(const std::string& label, GObject* newTarget);
		void setDuration(const std::string& label, float value);
		float getLabelTime(const std::string& label) const;
		float getTimeScale() const { return _timeScale; }
		void setTimeScale(float value);

		void updateFromRelations(cocos2d::Node* target, float dx, float dy);
		void onOwnerAddedToStage();
		void onOwnerRemovedFromStage();

		void setup(ByteBuffer* buffer);
		void setup(const TransitionInfo* info);
	private:
		void play(int times, float delay, float startTime, float endTime, PlayCompleteCallback onComplete, bool reverse);
		void stopItem(TransitionItem* item, bool setToComplete);
		void onDelayedPlay();
		void internalPlay();
		void playItem(TransitionItem* item);
		void skipAnimations();
		void onDelayedPlayItem(GTweener* tweener);
		void onTweenStart(GTweener* tweener);
		void onTweenUpdate(GTweener* tweener);
		void onTweenComplete(GTweener* tweener);
		void onPlayTransCompleted(TransitionItem* item);
		void callHook(TransitionItem* item, bool tweenEnd);
		void checkAllComplete();
		void applyValue(TransitionItem* item);
		void decodeValue(TransitionItem* item, ByteBuffer* buffer, void* value);

		GComponent* _owner;
		std::vector<TransitionItem*> _items;
		int _totalTimes;
		int _totalTasks;
		bool _playing;
		bool _paused;
		float _ownerBaseX;
		float _ownerBaseY;
		PlayCompleteCallback _onComplete;
		int _options;
		bool _reversed;
		float _totalDuration;
		bool _autoPlay;
		int _autoPlayTimes;
		float _autoPlayDelay;
		float _timeScale;
		float _startTime;
		float _endTime;
		std::string _name;
	};
}