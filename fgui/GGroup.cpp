#include "GGroup.h"
#include "FguiUtils.h"
#include "ComponentData.h"

namespace fgui {
	GGroup::GGroup() 
	:_layout(GroupLayoutType::NONE)
	,_lineGap(0)
	,_columnGap(0)
	, _isLayouting(false)
	, _layer(NULL){

	}

	GGroup::~GGroup() {

	}

	void GGroup::addNode(Node* child) {
		_children.pushBack(child);
	}

	void GGroup::removeNode(Node* child) {
		for (auto iter = _children.begin(); iter != _children.end(); ++iter) {
			if (*iter == child) {
				_children.erase(iter);
				break;
			}
		}
	}

	void GGroup::setOpacity(GLubyte opacity) {
		for (ssize_t i = 0; i < _children.size(); ++i) {
			cocos2d::Node* node = _children.at(i);
			node->setOpacity(opacity);
		}
	}

	void GGroup::setVisible(bool visible) {
		for (ssize_t i = 0; i < _children.size(); ++i) {
			cocos2d::Node* node = _children.at(i);
			node->setVisible(visible);
		}
	}

	void GGroup::setContentSize(const cocos2d::Size& contentSize) {
		cocos2d::Size oldSize = getContentSize();
		if (_isLayouting) {
			Node::setContentSize(contentSize);
			GObject::onContentSizeChanged(this, oldSize, contentSize);
			if (_layer) {
				_layer->setContentSize(contentSize);
			}
			return;
		}
		
		if (!oldSize.equals(contentSize)) {
			Node::setContentSize(contentSize);
			if (_layer) {
				_layer->setContentSize(contentSize);
			}

			float dw = contentSize.width / oldSize.width;
			float dh = contentSize.height / oldSize.height;
			for (ssize_t i = 0; i < _children.size(); ++i) {
				cocos2d::Node* node = _children.at(i);
				const cocos2d::Size& s = node->getContentSize();
				node->setContentSize(cocos2d::Size(dw * s.width, dh * s.height));
				const cocos2d::Vec2& p = node->getPosition();
				node->setPosition(p.x / oldSize.width * contentSize.width, p.y / oldSize.height * contentSize.height);
			}
			GObject::onContentSizeChanged(this, oldSize, contentSize);
		}
	}

	void GGroup::setPosition(float x, float y) {
		if (_isLayouting) {
			Node::setPosition(x, y);
			return;
		}
		cocos2d::Vec2 oldPos = getPosition();
		Node::setPosition(x, y);

		float dx = x - oldPos.x;
		float dy = y - oldPos.y;
		for (ssize_t i = 0; i < _children.size(); ++i) {
			cocos2d::Node* node = _children.at(i);
			node->setPosition(node->getPositionX() + dx, node->getPositionY() + dy);
		}
		GObject::onPositionChanged(this, oldPos, cocos2d::Vec2(dx, dy));
	}

	void GGroup::setGap(int lineGap, int columnGap) {
		_lineGap = lineGap;
		_columnGap = columnGap;
		updateLayout();
	}

	void GGroup::setBgVisible(bool bVisible) {
		if (_layer) {
			_layer->setVisible(bVisible);
		}
		else if(bVisible) {
			const cocos2d::Size& s = getContentSize();
			_layer = cocos2d::LayerColor::create(cocos2d::Color4B(128, 128, 128, 128), s.width, s.height);
			addChild(_layer);
		}
	}

	void GGroup::updateLayout() {
		if (_children.size() <= 0) {
			return;
		}
		_isLayouting = true;
		std::vector<cocos2d::Node*> tmp(_children.size());

		for (ssize_t i = 0; i < _children.size(); ++i) {
			tmp [i] = _children.at(i);
		}

		std::sort(tmp.begin(), tmp.end(), [](cocos2d::Node* node1, cocos2d::Node* node2) ->bool {
			cocos2d::Vec2 p1 = getPointWithAnchorPoint(node1, 0, 0);
			cocos2d::Vec2 p2 = getPointWithAnchorPoint(node2, 0, 0);
			return p1.x < p2.x;
		});

		float minx = getPointWithAnchorPoint(tmp[0], 0, 0).x;
		float maxx = minx + tmp[0]->getContentSize().width;
		for (size_t i = 1; i < tmp.size(); ++i) {
			const cocos2d::Size& s = tmp[i]->getContentSize();
			const cocos2d::Vec2& ap = tmp[i]->getAnchorPoint();
			tmp[i]->setPositionX(maxx + _columnGap + s.width * ap.x);
			maxx += _columnGap + s.width;
		}

		std::sort(tmp.begin(), tmp.end(), [](cocos2d::Node* node1, cocos2d::Node* node2) ->bool {
			cocos2d::Vec2 p1 = getPointWithAnchorPoint(node1, 0, 0);
			cocos2d::Vec2 p2 = getPointWithAnchorPoint(node2, 0, 0);
			return p1.y > p2.y;
		});

		float maxy = getPointWithAnchorPoint(tmp[0], 0, 1).y;
		float miny = maxy - tmp[0]->getContentSize().height;
		for (size_t i = 1; i < tmp.size(); ++i) {
			const cocos2d::Size& s = tmp[i]->getContentSize();
			const cocos2d::Vec2& ap = tmp[i]->getAnchorPoint();
			tmp[i]->setPositionY(miny - _lineGap - s.width * (1 - ap.y));
			miny -= (_lineGap + s.width);
		}

		setContentSize(cocos2d::Size(maxx - minx,maxy - miny));
		setPosition(minx, maxy);
		_isLayouting = false;
	}

	void GGroup::setup(const ObjectInfo* inf, cocos2d::Node* parent) {
		GObject::setup(inf, parent);
		const GroupInfo* info = dynamic_cast<const GroupInfo*>(inf);
		_layout = info->layoutType;
		_lineGap = info->lineGap;
		_columnGap = info->columnGap;
		setVisible(isVisible());
		updateLayout();
	}
}