#pragma once
#include "GObject.h"
#include "base/ccTypes.h"

namespace cocos2d {
	class Node;
}

namespace fgui {
	class GGraph
		:public cocos2d::DrawNode
		, public GObject {
	public:
		CREATE_FUNC(GGraph);
		GGraph();
		~GGraph();
		int getType() { return _type; }
		void setType(int type);
		void setLineColor(const cocos2d::Color4B& color);
		void setFillColor(const cocos2d::Color4B& color);
		void setLineSize(int size);
		const cocos2d::Color4F& getLineColor() { return _lineColor; }
		const cocos2d::Color4F& getFillColor() { return _fillColor; }
		int getLineSize() { return _lineSize; }
	protected:
		void updateShape();
		virtual void setupBefore(ByteBuffer* buffer, int pos, cocos2d::Node* parent);
		virtual void setup(const ObjectInfo* inf, cocos2d::Node* parent);
		virtual void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags);
	private:
		int _type;
		int _lineSize;
		bool _dirty;
		cocos2d::Color4F _lineColor;
		cocos2d::Color4F _fillColor;
	};
}


