#pragma once

#include "cocos2d.h"

namespace fgui {
	cocos2d::Vec2 coordF2C(const cocos2d::Vec2& parentP, cocos2d::Node* node);
	float getLeft(cocos2d::Node* node, float width = 0.0f);
	void setLeft(cocos2d::Node* node, float left);
	float getRight(cocos2d::Node* node, float width = 0.0f);
	void setRight(cocos2d::Node* node, float right);

	float getCenterX(cocos2d::Node* node, float width = 0.0f);
	void setCenterX(cocos2d::Node* node, float center);

	float getTop(cocos2d::Node* node, float width = 0.0f);
	void setTop(cocos2d::Node* node, float top);
	float getBottom(cocos2d::Node* node, float width = 0.0f);
	void setBottom(cocos2d::Node* node, float bottom);

	float getCenterY(cocos2d::Node* node, float height = 0.0f);
	void setCenterY(cocos2d::Node* node, float center);

	cocos2d::Vec2 getPointWithAnchorPoint(cocos2d::Node* node, float ax, float ay);
	void moveAnchorPoint(cocos2d::Node* node, float ax, float ay);

	double getSystemTime();
}
