#include "FguiUtils.h"
#include "GObject.h"

namespace fgui {
	cocos2d::Vec2 coordF2C(const cocos2d::Vec2& p, cocos2d::Node* node) {
		if (!node) {
			return p;
		}
		GObject* obj = dynamic_cast<GObject*>(node);
		CCASSERT(obj, "the node is not object");
		
		const ObjectInfo* info = obj->getObjectInfo();
		CCASSERT(info, "the obj data info is null");

		cocos2d::Node* parent = node->getParent();
		const cocos2d::Size& parentSize = parent->getContentSize();
		if (info->bPivotAsAchorPoint) {
			return cocos2d::Vec2(p.x, parentSize.height - p.y);
		}
		else {
			const cocos2d::Size& size = node->getContentSize();
			const cocos2d::Vec2& ap = node->getAnchorPoint();
			return cocos2d::Vec2(p.x + ap.x * size.width, parentSize.height - p.y + (ap.y - 1.0f) * size.height);
		}
	}

	float getLeft(cocos2d::Node* node, float width) {
		if (node->isIgnoreAnchorPointForPosition()) {
			return node->getPositionX();
		}
		if (width == 0) {
			width = node->getContentSize().width;
		}
		return node->getPositionX() - node->getAnchorPoint().x * width;
	}

	void setLeft(cocos2d::Node* node, float left) {
		if (node->isIgnoreAnchorPointForPosition()) {
			node->setPositionX(left);
		}
		else {
			node->setPositionX(left + node->getAnchorPoint().x * node->getContentSize().width);
		}
	}

	float getRight(cocos2d::Node* node, float width) {
		if (width == 0) {
			width = node->getContentSize().width;
		}
		if (node->isIgnoreAnchorPointForPosition()) {
			return node->getPositionX() + width;
		}
		return node->getPositionX() + (1 - node->getAnchorPoint().x) * width;
	}

	void setRight(cocos2d::Node* node, float right) {
		if (node->isIgnoreAnchorPointForPosition()) {
			node->setPositionX(right - node->getContentSize().width);
		}
		else {
			node->setPositionX(right - node->getContentSize().width * (1 - node->getAnchorPoint().x));
		}
	}

	float getCenterX(cocos2d::Node* node, float width) {
		if (width == 0) {
			width = node->getContentSize().width;
		}
		if (node->isIgnoreAnchorPointForPosition()) {
			return node->getPositionX() + width * 0.5f;
		}
		else {
			return node->getPositionX() + (0.5f - node->getAnchorPoint().x) * width;
		}
	}

	void setCenterX(cocos2d::Node* node, float center) {
		if (node->isIgnoreAnchorPointForPosition()) {
			node->setPositionX(center - node->getContentSize().width * 0.5f);
		}
		else {
			node->setPositionX(center - node->getContentSize().width * (0.5f - node->getAnchorPoint().x));
		}
	}

	float getTop(cocos2d::Node* node, float height) {
		if (node->isIgnoreAnchorPointForPosition()) {
			return node->getPositionY() + node->getContentSize().height;
		}
		if (height == 0) {
			height = node->getContentSize().height;
		}
		return node->getPositionY() + (1 - node->getAnchorPoint().y) * height;
	}

	void setTop(cocos2d::Node* node, float top) {
		if (node->isIgnoreAnchorPointForPosition()) {
			node->setPositionY(top - node->getContentSize().height);
		}
		else {
			node->setPositionY(top - node->getContentSize().height * (1 - node->getAnchorPoint().y));
		}
	}

	float getBottom(cocos2d::Node* node, float height) {
		if (node->isIgnoreAnchorPointForPosition()) {
			return node->getPositionY();
		}
		if (height == 0) {
			height = node->getContentSize().height;
		}
		return node->getPositionY() - node->getAnchorPoint().y * height;
	}

	void setBottom(cocos2d::Node* node, float bottom) {
		if (node->isIgnoreAnchorPointForPosition()) {
			node->setPositionY(bottom);
		}
		else {
			node->setPositionY(bottom + node->getAnchorPoint().y * node->getContentSize().height);
		}
	}

	float getCenterY(cocos2d::Node* node, float height) {
		if (height == 0) {
			height = node->getContentSize().height;
		}
		if (node->isIgnoreAnchorPointForPosition()) {
			return node->getPositionY() + 0.5f * height;
		}
		else {
			return node->getPositionY() + (0.5f - node->getAnchorPoint().y) * height;
		}
	}

	void setCenterY(cocos2d::Node* node, float center) {
		if (node->isIgnoreAnchorPointForPosition()) {
			node->setPositionY(center - 0.5f * node->getContentSize().height);
		}
		else {
			node->setPositionY(center - (0.5f - node->getAnchorPoint().y) * node->getContentSize().height);
		}
	}

	cocos2d::Vec2 getPointWithAnchorPoint(cocos2d::Node* node, float ax, float ay) {
		const cocos2d::Vec2& ap = node->getAnchorPoint();
		const cocos2d::Size& size = node->getContentSize();
		const cocos2d::Vec2& pos = node->getPosition();
		return cocos2d::Vec2(pos.x + (ax - ap.x) * size.width, pos.y + (ay - ap.y) * size.height);
	}

	void moveAnchorPoint(cocos2d::Node* node, float ax, float ay) {
		cocos2d::Vec2 ap(0.0f, 0.0f);
		if (!node->isIgnoreAnchorPointForPosition()) {
			ap = node->getAnchorPoint();
		}
		const cocos2d::Vec2& pos = node->getPosition();
		const cocos2d::Size size = node->getContentSize();
		node->setPosition(cocos2d::Vec2(pos.x + (ax - ap.x) * size.width, pos.y + (ay - ap.y) * size.height));
		node->setAnchorPoint(cocos2d::Vec2(ax, ay));
		node->setIgnoreAnchorPointForPosition(false);
	}

	double getSystemTime() {
		struct timeval val;
		cocos2d::gettimeofday(&val, NULL);
		double sec = val.tv_sec;
		double usec = val.tv_usec;
		return sec + usec / 10e6;
	}
}