#pragma once
#include "cocos2d.h"
#include "UIPackage.h"
#include "Margin.h"
#include "FieldTypes.h"
#include <vector>

namespace fgui {
	class IHitTest;
	class UIPackage;
	struct PackageItem;
	class GController;
	class GearBase;
	class Relations;
	class RelationObserver;
	class Package;
	class PkgItem;

	typedef std::function<void(cocos2d::Node*)> NodeEECallback;
	typedef std::function<void(cocos2d::Node*, const cocos2d::Size& newSize, const cocos2d::Size& oldSize)> NodeSizeCallback;

	cocos2d::Node* createObjectByType(ObjectType type);

	class GObject {
	public:
		UIPackage* getPackage() { return _uiPackage; }
		PackageItem* getPackageItem() { return _pkgItem; }
		const std::string& getId() const { return _id; }
		ObjectType getObjType() const { return _objType; }

		void onEnter();
		void onExit();

		const ObjectInfo* getObjectInfo() { return _dataInfo; }

		void addRelationObserver(RelationObserver* observer);
		void removeRelationObserver(RelationObserver* observer);
		virtual void setRelationIsValid(bool isRelationValid);

		virtual bool isGrayed() { return _isGray; };
		virtual void setGrayed(bool value);
		virtual void setHSVMode(bool isHsv);
		virtual bool isHSVMode();
		virtual void setHSVValue(float hue, float saturation, float brightness, float contrast);
		virtual const cocos2d::Vec4& getHSVValue();

		virtual bool isTouchable() { return _isTouchEnabled; }
		virtual void setTouchable(bool enabled);
		virtual void setSwallowTouch(bool bSwallow);
		virtual bool isSwallowTouch() const;
		virtual void setBlendMode(BlendMode blend);
		virtual BlendMode getBlendMode() { return m_blendMode; }

		void setTouchBeginCallback(std::function<bool(cocos2d::Touch*, cocos2d::Event*)> handler);
		void setTouchMovedCallback(std::function<void(cocos2d::Touch*, cocos2d::Event*)> handler);
		void setTouchEndedCallback(std::function<void(cocos2d::Touch*, cocos2d::Event*)> handler);
		void setTouchCancelCallback(std::function<void(cocos2d::Touch*, cocos2d::Event*)> handler);

		virtual void setupOverflow(OverflowType overflow);
	protected:
		GObject();
		~GObject();
		virtual void constructFromResource(UIPackage* pkg, PackageItem* pt);
		virtual void constructFromItem(Package* pkg, PkgItem* item);
		virtual void setup(const ObjectInfo* info, cocos2d::Node* parent);

		virtual void setupBefore(ByteBuffer* buffer, int pos, cocos2d::Node* parent);
		virtual void setupAfter(ByteBuffer* buffer, int pos);
		virtual void setupExtend(ByteBuffer* buffer);
		virtual void setupScroll(ByteBuffer* buffer);
		
		GearBase* getGear(int index);
		void updateGear(int index);
		void updateGearFromRelations(int index, float dx, float dy);

		virtual void onControllerChanged(GController* controller);
		virtual bool onTouchBegin(cocos2d::Touch* touch, cocos2d::Event* event);
		virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
		virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

		virtual void onContentSizeChanged(cocos2d::Node* target, const cocos2d::Size& oldSize, const cocos2d::Size& newSize);
		virtual void onPositionChanged(cocos2d::Node* target, const cocos2d::Vec2& oldPos, const cocos2d::Vec2& newPos);
		void clearAllRelationObserver();
	protected:
		UIPackage* _uiPackage;
		PackageItem* _pkgItem;
		cocos2d::Node* m_nodeSelf;

		std::string _id;
		cocos2d::Size _minSize;
		cocos2d::Size _maxSize;
		int _groupId;
		bool _isGray;
		bool _isTouchEnabled;

		BlendMode m_blendMode;
		bool _isRelationValid;
		bool _isPivotAsAchorPoint;
		bool _isHsvMode;
		cocos2d::Vec4 _hsvValue;
		std::vector<RelationObserver*> m_relationObservers;
		GearBase* m_gears[8];
		Relations* _relations;

		cocos2d::Value m_customData;
		cocos2d::EventListenerTouchOneByOne* m_listener;
		std::function<bool(cocos2d::Touch*, cocos2d::Event*)> m_touchBeganHandler;
		std::function<void(cocos2d::Touch*, cocos2d::Event*)> m_touchMoveHandler;
		std::function<void(cocos2d::Touch*, cocos2d::Event*)> m_touchEndedHandler;
		std::function<void(cocos2d::Touch*, cocos2d::Event*)> m_touchCancelHandler;
		
		Package* _pkg;
		PkgItem* _item;
		ObjectType _objType;
		const ObjectInfo* _dataInfo;
	private:
		friend class UIPackage;
		friend class GComponent;
		friend class Package;
	};
}