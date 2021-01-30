#include "GGraph.h"
#include "FguiUtils.h"
#include "ComponentData.h"

namespace fgui {
	GGraph::GGraph()
		:_type(0),
		_lineSize(1),
		_lineColor(cocos2d::Color4F::BLACK),
		_fillColor(cocos2d::Color4F::WHITE) {

	}
	GGraph::~GGraph() {

	}

	void GGraph::updateShape() {
		clear();
		const cocos2d::Size& size = getContentSize();
		if (_type == 1){
			if (_lineSize > 0) {
				setLineWidth(_lineWidth);
				cocos2d::Vec2 lb(0, 0);
				cocos2d::Vec2 rb(size.width, 0);
				cocos2d::Vec2 rt(size.width, size.height);
				cocos2d::Vec2 lt(0, size.height);
				this->drawSolidRect(lb, rt, _fillColor);
				this->drawRect(lb, rb, rt, lt, _lineColor);		
			}
			else {
				cocos2d::Vec2 lb(0,0);
				cocos2d::Vec2 rt(size.width,size.height);
				this->drawSolidRect(lb, rt, _fillColor);
			}
		}
		else if (_type == 2){
			if (_lineSize > 0){
				this->setLineWidth(_lineSize);
				cocos2d::Vec2 ct(size.width / 2, size.height / 2);
				this->drawSolidCircle(ct, size.width / 2, 0, 360, 1, size.height / size.width, _fillColor);
				this->drawCircle(ct, size.width / 2, 0, 360, false, 1, size.height / size.width, _lineColor);		
			}
			else {
				cocos2d::Vec2 ct(size.width / 2, size.height / 2);
				this->drawSolidCircle(ct, size.width / 2, 0, 360, 1, size.height / size.width, _fillColor);
			}
		}
	}

	void GGraph::setType(int type) {
		if (_type != type) {
			_type = type;
			_dirty = true;
		}
	}

	void GGraph::setLineColor(const cocos2d::Color4B& color) {
		if (_lineColor != color) {
			_lineColor = (cocos2d::Color4F)color;
			_dirty = true;
		}
	}

	void GGraph::setFillColor(const cocos2d::Color4B& color) {
		if (_fillColor != color) {
			_fillColor = (cocos2d::Color4F)color;
			_dirty = true;
		}
	}

	void GGraph::setLineSize(int size) {
		if (_lineSize != size) {
			_lineSize = size;
			_dirty = true;
		}
	}

	void GGraph::draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags) {
		if (_dirty) {
			updateShape();
			_dirty = false;
		}
		cocos2d::DrawNode::draw(renderer, transform, flags);
	}

	void GGraph::setup(const ObjectInfo* inf, cocos2d::Node* parent) {
		GObject::setup(inf, parent);
		const GraphInfo* info = dynamic_cast<const GraphInfo*>(parent);
		_type = info->type;
		if (_type != 0) {
			_lineSize = info->lineSize;
			if (info->lineColor) {
				_lineColor = (cocos2d::Color4F)*info->lineColor;
			}
			if (info->fillColor) {
				_fillColor = (cocos2d::Color4F) * info->fillColor;
			}
			updateShape();
		}
	}
}