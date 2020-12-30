#pragma once
#include "GObject.h"
#include "base/CCVector.h"

namespace cocos2d {
	class LayerColor;
	class Node;
}

namespace fgui {
	class GGroup
		: public cocos2d::Node
		, public GObject
	{
	public:
		CREATE_FUNC(GGroup);
		GGroup();
		~GGroup();
		virtual void addNode(Node* child);
		virtual void removeNode(Node* child);
		virtual void setOpacity(GLubyte opacity);
		virtual void setVisible(bool visible);
		virtual void setContentSize(const cocos2d::Size& contentSize);
		virtual void setPosition(float x, float y);
		void updateLayout();
		void setGap(int lineGap, int columnGap);
		void setBgVisible(bool bVisible);
	protected:
		virtual void setupBefore(ByteBuffer* buffer, int pos, cocos2d::Node* parent);
		virtual void setupAfter(ByteBuffer* buffer, int pos);
		virtual void setup(const ObjectInfo* inf, cocos2d::Node* parent);
	private:
		GroupLayoutType _layout;
		int _lineGap;
		int _columnGap;
		bool _isLayouting;
		cocos2d::Vector<cocos2d::Node*> _children;
		cocos2d::LayerColor* _layer;
	};
}