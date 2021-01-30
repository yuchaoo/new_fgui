#include "GContainer.h"
#include "Relations.h"
#include "FguiUtils.h"
#include "PackageManager.h"
#include "GComponent.h"
#include "PkgItem.h"
using namespace cocos2d;

namespace fgui {
	GContainer::GContainer()
	:_isEdgeDirty(true)
	, _isLayoutDirty(false)
	,_layoutType(ListLayoutType::SINGLE_COLUMN)
	,_hAlign(cocos2d::TextHAlignment::LEFT)
	,_vAlign(cocos2d::TextVAlignment::TOP)
	,_lineCap(0)
	,_columnCap(0)
	,_lineCount(0)
	,_columnCount(0)
	,_isVirtual(false)
	,_virtualItemCount(0)
	,_startIndex(0)
	,_endIndex(0)
	, _pkgItem(NULL){
		
	}

	GContainer::~GContainer() {
		if (_relations) {
			delete _relations;
			_relations = NULL;
		}
		for (auto iter = _urlNodePool.begin(); iter != _urlNodePool.end(); ++iter) {
			(*iter)->release();
		}
		_urlNodePool.clear();
	}

	bool GContainer::init() {
		Node::init();
		this->setAnchorPoint(cocos2d::Vec2(0.0f, 0.0f));
		return true;
	}

	void GContainer::setContentSize(const cocos2d::Size& size) {
		if (_contentSize.equals(size)) {
			return;
		}
		cocos2d::Size oldSize = getContentSize();
		Node::setContentSize(size);
		GObject::onContentSizeChanged(this, oldSize, size);
		_isEdgeDirty = true;
	}

	void GContainer::addChild(Node* child, int localZOrder, const std::string& name) {
		Node::addChild(child, localZOrder, name);
		child->setAnchorPoint(cocos2d::Vec2(0.5f, 0.5f));
		child->setIgnoreAnchorPointForPosition(false);
		if (!_isVirtual) {
			_isEdgeDirty = true;
			_isLayoutDirty = true;
		}
	}

	void GContainer::addChild(Node* child, int localZOrder, int tag) {
		Node::addChild(child, localZOrder, tag);
		child->setAnchorPoint(cocos2d::Vec2(0.5f, 0.5f));
		child->setIgnoreAnchorPointForPosition(false);
		if (!_isVirtual) {
			_isEdgeDirty = true;
			_isLayoutDirty = true;
		}
	}

	void GContainer::addChild(Node* child, int localZOrder) {
		Node::addChild(child, localZOrder);
	}

	void GContainer::addChild(Node* child) {
		Node::addChild(child);
	}

	void GContainer::setLayoutType(ListLayoutType type) {
		_layoutType = type;
		_isLayoutDirty = true;
	}

	void GContainer::setHAlignment(cocos2d::TextHAlignment hAlign) {
		_hAlign = hAlign;
		_isLayoutDirty = true;
	}

	void GContainer::setVAlignment(cocos2d::TextVAlignment vAlign) {
		_vAlign = vAlign;
		_isLayoutDirty = true;
	}

	void GContainer::setLineCount(int count) {
		_lineCount = count;
		_isLayoutDirty = true;
	}

	void GContainer::setColumnCount(int count) {
		_columnCount = count;
		_isLayoutDirty = true;
	}

	void GContainer::setLineGap(int lineCap) {
		_lineCap = lineCap;
		_isLayoutDirty = true;
	}

	void GContainer::setColumnGap(int columnCap) {
		_columnCap = columnCap;
		_isLayoutDirty = true;
	}

	void GContainer::setMargin(const Margin& margin) {
		_margin = margin;
		_isLayoutDirty = true;
	}

	void GContainer::setVirtual() {
		if (_isVirtual || !_pkgItem) {
			return;
		}
		_isVirtual = true;
		const cocos2d::Size& viewSize = getParent()->getContentSize();
		const cocos2d::Size& itemSize = _pkgItem->getSize();

		if (_layoutType == ListLayoutType::SINGLE_COLUMN) {
			_columnCount = 1;
		}
		else if (_layoutType == ListLayoutType::SINGLE_ROW) {
			_lineCount = 1;
		}
		else if (_layoutType == ListLayoutType::FLOW_HORIZONTAL) {
			const cocos2d::Size& size = this->getContentSize();
			_columnCount = floor((size.width - _margin.left - _margin.right + _columnCap) / (_columnCap + itemSize.width));
		}
		else if (_layoutType == ListLayoutType::FLOW_VERTICAL) {
			const cocos2d::Size& size = this->getContentSize();
			_lineCount = floor((size.height - _margin.top - _margin.bottom + _lineCap) / (_lineCap + itemSize.height));
		}

		if (_layoutType == ListLayoutType::SINGLE_COLUMN || _layoutType == ListLayoutType::FLOW_HORIZONTAL) {
			_displayRect.setRect(0, -_lineCap - itemSize.height, viewSize.width, viewSize.height + (_lineCap + itemSize.height) * 2);
		}
		else if (_layoutType == ListLayoutType::SINGLE_ROW || _layoutType == ListLayoutType::FLOW_VERTICAL) {
			_displayRect.setRect(-_lineCap - itemSize.width, 0, viewSize.width + (_columnCap + itemSize.width) * 2, viewSize.height);
		}
		clearAllChildren();
		//CCDirector::getInstance()->getScheduler()->scheduleUpdate(this, 0, false);
	}

	bool GContainer::isVirtual() {
		return _isVirtual;
	}

	void GContainer::setVirtualItemCount(int count) {
		_virtualItemCount = count;
		clearAllChildren();
		updateVirtualLayout();
	}

	int GContainer::getVirtualItemCount() {
		return _virtualItemCount;
	}

	void GContainer::pushNodeToList(cocos2d::Node* node, bool isFront, int index) {
		if (_virtualItemList.size() > 0) {
			if (isFront) {
				_virtualItemList.push_front(node);
				if (index != -1) {
					_startIndex = index;
				}
				else {
					--_startIndex;
				}
				if (_updateNodeHandler) {
					_updateNodeHandler(node, _startIndex);
				}
			}
			else {
				_virtualItemList.push_back(node);
				if (index != -1) {
					_endIndex = index;
				}
				else {
					++_endIndex;
				}
				if (_updateNodeHandler) {
					_updateNodeHandler(node,_endIndex);
				}
			}
		}
		else {
			_virtualItemList.push_back(node);
			CCASSERT(index != -1, "the first node index is not -1");
			_startIndex = _endIndex = index;
			if (_updateNodeHandler) {
				_updateNodeHandler(node,_startIndex);
			}
		}
	}

	void GContainer::updateNodeContent() {
		if (!_updateNodeHandler) {
			return;
		}
		int i = _startIndex;
		for (auto iter = _virtualItemList.begin(); iter != _virtualItemList.end(); ++iter) {
			_updateNodeHandler(*iter, i++);
		}
	}

	void GContainer::updateCommonLayout() {
		cocos2d::Node* parent = getParent();
		if (!parent) {
			return;
		}

		cocos2d::Size portSize =  parent->getContentSize();
		cocos2d::Size oldSize = this->getContentSize();

		if (_layoutType == ListLayoutType::SINGLE_COLUMN) {
			float totalHeight = _margin.top + _margin.bottom + (_children.size() - 1) * _lineCap;
			for (ssize_t i = 0; i < _children.size(); ++i) {
				totalHeight += _children.at(i)->getContentSize().height;
			}
			float height = totalHeight > portSize.height ? totalHeight: portSize.height;
			setContentSize(cocos2d::Size(portSize.width, height));
			if (totalHeight > portSize.height) {
				setPositionY(getPositionY() - (totalHeight - portSize.height));
			}

			float offsetY = 0;
			if (totalHeight < portSize.height) {
				if (_vAlign == cocos2d::TextVAlignment::BOTTOM) {
					offsetY = portSize.height - totalHeight;
				}
				else if (_vAlign == cocos2d::TextVAlignment::CENTER) {
					offsetY = (portSize.height - totalHeight) / 2;
				}
			}

			float x =  _margin.left + (portSize.width - _margin.left - _margin.right) / 2;
			float y = height - _margin.top;
			for (ssize_t i = 0; i < _children.size(); ++i) {
				cocos2d::Node* node = _children.at(i);
				const cocos2d::Size& s = node->getContentSize();
				node->setPosition(x, y - s.height/2 - offsetY);
				y -= s.height - _lineCap;
				node->setContentSize(cocos2d::Size(portSize.width - (_margin.left + _margin.right),s.height));
			}
		}
		else if (_layoutType == ListLayoutType::SINGLE_ROW) {
			float totalWidth = _margin.left + _margin.right + (_children.size() - 1) * _columnCap;
			for (ssize_t i = 0; i < _children.size(); ++i) {
				totalWidth += _children.at(i)->getContentSize().width;
			}
			float width = portSize.width < totalWidth ? totalWidth : portSize.width;
			setContentSize(cocos2d::Size(width, portSize.height));

			float offsetX = 0;
			if (totalWidth < portSize.width) {
				if (_hAlign == cocos2d::TextHAlignment::RIGHT) {
					offsetX = portSize.width - totalWidth;
				}
				else if (_hAlign == cocos2d::TextHAlignment::CENTER) {
					offsetX = (portSize.width - totalWidth) / 2;
				}
			}
			float x = _margin.left;
			float y = _margin.bottom + (portSize.height - _margin.top - _margin.bottom) / 2;
			for (ssize_t i = 0; i < _children.size(); ++i) {
				cocos2d::Node* node = _children.at(i);
				const cocos2d::Size& s = node->getContentSize();
				node->setPosition(x + s.width / 2, y);
				x += s.width + _columnCap;
				node->setContentSize(cocos2d::Size(s.width,portSize.height - _margin.top - _margin.bottom));
			}
		}
		else if (_layoutType == ListLayoutType::FLOW_HORIZONTAL) {
			float maxX = 0;
			if (_columnCount == 0) {
				float totalHeight = _margin.top + _margin.bottom;
				cocos2d::Vec2 origin(_margin.left , -_margin.top);
				int rowItemCount = 0;
				float maxItemHeight = 0;

				for (ssize_t i = 0; i < _children.size(); ++i) {
					cocos2d::Node* node = _children.at(i);
					const cocos2d::Size& s = node->getContentSize();
					float nextX = rowItemCount <= 0 ? origin.x + s.width : origin.x + _lineCap + s.width;
					if (rowItemCount <= 0 || nextX <= portSize.width - _margin.right) {
						rowItemCount++;
						node->setPosition(nextX - s.width / 2, origin.y - s.height / 2);
						origin.x = nextX;
						if (maxItemHeight < s.height) {
							maxItemHeight = s.height;
						}
						if (maxX < origin.x) {
							maxX = origin.x;
						}
					}
					else{
						rowItemCount = 1;
						totalHeight += _lineCap + maxItemHeight;
						origin.x = _margin.left + s.width;
						origin.y -= _lineCap + maxItemHeight;
						node->setPosition(origin.x - s.width / 2, origin.y - s.height / 2);
						maxItemHeight = s.height;
						if (maxX < origin.x) {
							maxX = origin.x;
						}
					}
				}
				totalHeight += maxItemHeight;
				float height = portSize.height > totalHeight ? portSize.height : totalHeight;
				setContentSize(cocos2d::Size(portSize.width, height));
				if (totalHeight > portSize.height) {
					setPositionY(getPositionY() - (totalHeight - portSize.height));
				}
				float offsetY = 0;
				if (totalHeight < portSize.height) {
					if (_vAlign == cocos2d::TextVAlignment::BOTTOM) {
						offsetY = portSize.height - totalHeight;
					}
					else if (_vAlign == cocos2d::TextVAlignment::CENTER) {
						offsetY = (portSize.height - totalHeight) / 2;
					}
				}
				for (ssize_t i = 0; i < _children.size(); ++i) {
					cocos2d::Node* node = _children.at(i);
					node->setPositionY(node->getPositionY() + height - offsetY);
				}
			}
			else {
				float maxItemHeight = 0, totalHeight = _margin.top + _margin.bottom;
				cocos2d::Vec2 origin(_margin.left, -_margin.top);
				for (ssize_t i = 0; i < _children.size(); ++i) {
					cocos2d::Node* node = _children.at(i);
					const cocos2d::Size& size = node->getContentSize();

					int xIndex = i % _columnCount;
					if (xIndex == 0) {
						origin.x = _margin.left;
						if (i != 0) {
							totalHeight += maxItemHeight + _lineCap;
							origin.y -= maxItemHeight + _lineCap;
						}
						node->setPosition(origin.x + size.width / 2, origin.y - size.height / 2);
						origin.x += _columnCap + size.width;
						maxItemHeight = size.height;
						if (maxX < origin.x) {
							maxX = origin.x;
						}
					}
					else {
						node->setPosition(origin.x + size.width / 2, origin.y - size.height / 2);
						origin.x += _columnCap + size.width;
						if (maxItemHeight < size.height) {
							maxItemHeight = size.height;
						}
						if (maxX < origin.x) {
							maxX = origin.x;
						}
					}
				}
				totalHeight += maxItemHeight;
				float height = totalHeight > portSize.height ? totalHeight : portSize.height;
				setContentSize(cocos2d::Size(portSize.width, height));
				float offsetY = 0;
				if(totalHeight < portSize.height){
					if (_vAlign == cocos2d::TextVAlignment::BOTTOM) {
						offsetY = (portSize.height - totalHeight);
					}
					else if (_vAlign == cocos2d::TextVAlignment::CENTER) {
						offsetY = (portSize.height - totalHeight) / 2;
					}
				}
				for (ssize_t i = 0; i < _children.size(); ++i) {
					cocos2d::Node* node = _children.at(i);
					node->setPositionY(node->getPositionY() + height - offsetY);
				}
			}
			if (maxX < _margin.right) {
				if (_hAlign == TextHAlignment::RIGHT) {
					float dx = _margin.right - maxX;
					for (ssize_t i = 0; i < _children.size(); ++i) {
						cocos2d::Node* node = _children.at(i);
						node->setPositionX(node->getPositionX() + dx);
					}
				}
				else if (_hAlign == TextHAlignment::CENTER) {
					float dx = (_margin.right - maxX) / 2;
					for (ssize_t i = 0; i < _children.size(); ++i) {
						cocos2d::Node* node = _children.at(i);
						node->setPositionX(node->getPositionX() + dx);
					}
				}
			}
		}
		else if (_layoutType == ListLayoutType::FLOW_VERTICAL) {
			float minY = portSize.height;
			if (_lineCount == 0) {
				float totalWidth = _margin.left + _margin.right;
				cocos2d::Vec2 origin(_margin.left, portSize.height - _margin.top);
				float maxItemWidth = 0;
				int columnItemCount = 0;
				for (ssize_t i = 0; i < _children.size(); ++i) {
					cocos2d::Node* node = _children.at(i);
					const cocos2d::Size& size = node->getContentSize();
					float nextY = (columnItemCount == 0) ? origin.y - size.height : origin.y - size.height - _lineCap;
					if (columnItemCount == 0 || nextY > _margin.bottom) {
						columnItemCount++;
						node->setPosition(origin.x + size.width / 2, nextY + size.height / 2);
						origin.y = nextY;
						if (maxItemWidth < size.width) {
							maxItemWidth = size.width;
						}
						if (minY > origin.y) {
							minY = origin.y;
						}
					}
					else {
						totalWidth += maxItemWidth + _columnCap;
						origin.x += maxItemWidth + _columnCap;
						origin.y = portSize.height - _margin.top - size.height;
						maxItemWidth = size.width;
						columnItemCount = 1;
						node->setPosition(origin.x + size.width / 2, origin.y + size.height / 2);
						if (minY > origin.y) {
							minY = origin.y;
						}
					}
				}
				totalWidth += maxItemWidth;
				float width = totalWidth < portSize.width ? portSize.width : totalWidth;
				setContentSize(cocos2d::Size(width, portSize.height));
				float offsetX = 0;

				if (portSize.width > totalWidth) {
					if (_hAlign == cocos2d::TextHAlignment::CENTER) {
						offsetX = (portSize.width - totalWidth) / 2;
					}
					else if (_hAlign == cocos2d::TextHAlignment::RIGHT) {
						offsetX = portSize.width - totalWidth;
					}
					if (offsetX != 0) {
						for (ssize_t i = 0; i < _children.size(); ++i) {
							cocos2d::Node* node = _children.at(i);
							node->setPositionX(node->getPositionX() + offsetX);
						}
					}
				}
			}
			else {
				float totalWidth = _margin.left + _margin.right;
				float maxItemWidth = 0;
				cocos2d::Vec2 orgin(_margin.left, portSize.height - _margin.top);

				for (ssize_t i = 0; i < _children.size(); ++i) {
					cocos2d::Node* node = _children.at(i);
					const cocos2d::Size& size = node->getContentSize();

					int index = i % _lineCount;
					if (index == 0) {
						if (i != 0) {
							totalWidth += maxItemWidth + _columnCap;
							orgin.x += _columnCap + maxItemWidth;
						}
						orgin.y = portSize.height - _margin.top - size.height;
						maxItemWidth = size.width;
						node->setPosition(orgin.x + size.width / 2, orgin.y + size.height / 2);
						if (minY > orgin.y) {
							minY = orgin.y;
						}
					}
					else {
						orgin.y -= _columnCap + size.height;
						node->setPosition(orgin.x + size.width / 2, orgin.y + size.height / 2);
						if (maxItemWidth < size.width) {
							maxItemWidth = size.width;
						}
						if (minY > orgin.y) {
							minY = orgin.y;
						}
					}
				}
				totalWidth += maxItemWidth;
				float width = portSize.width > totalWidth ? portSize.width : totalWidth;
				setContentSize(cocos2d::Size(width, portSize.height));
				float offsetX = 0;
				if (portSize.width > totalWidth) {
					if (_hAlign == cocos2d::TextHAlignment::RIGHT) {
						offsetX = portSize.width - totalWidth;
					}
					else if (_hAlign == cocos2d::TextHAlignment::CENTER) {
						offsetX = (portSize.width - totalWidth) / 2;
					}
					if (offsetX != 0) {
						for (ssize_t i = 0; i < _children.size(); ++i) {
							cocos2d::Node* node = _children.at(i);
							node->setPositionX(node->getPositionX() + offsetX);
						}
					}
				}
			}
			if (minY > _margin.bottom) {
				if (_vAlign == cocos2d::TextVAlignment::BOTTOM) {
					float dy = minY - _margin.bottom;
					for (ssize_t i = 0; i < _children.size(); ++i) {
						cocos2d::Node* node = _children.at(i);
						node->setPositionY(node->getPositionY() - dy);
					}
				}
				else if (_vAlign == cocos2d::TextVAlignment::CENTER) {
					float dy = (minY - _margin.bottom) / 2;
					for (ssize_t i = 0; i < _children.size(); ++i) {
						cocos2d::Node* node = _children.at(i);
						node->setPositionY(node->getPositionY() - dy);
					}
				}
			}
		}
		_isLayoutDirty = false;
	}

	bool GContainer::isInViewRect(const cocos2d::Vec2& pos, const cocos2d::Rect& rect) {
		cocos2d::Vec2 p = this->getPosition() + pos;
		return p.x >= rect.origin.x && p.x < rect.origin.x + rect.size.width && p.y >= rect.origin.y && p.y < rect.origin.y + rect.size.height;
	}

	cocos2d::Node* GContainer::getNodeFromPool() {
		if (_urlNodePool.size() > 0) {
			cocos2d::Node* node = _urlNodePool.back();
			_urlNodePool.pop_back();
			return node;
		}

		cocos2d::Node* node = PackageManager::getInstance()->createNodeByUrl(_defaultItemUrl);  //PackageManager::getInstance()->createObjectByURL(_defaultItemUrl);
		if (node) {
			GComponent* comp = dynamic_cast<GComponent*>(node);
			if (comp) {
				comp->setSwallowTouch(false);
			}
			node->retain();
		}
		return node;
	}

	void GContainer::pushNodeToPool(cocos2d::Node* node) {
		_urlNodePool.push_back(node);
	}

	void GContainer::clearAllChildren() {
		removeAllChildren();
		if (_isVirtual) {
			for (auto iter = _virtualItemList.begin(); iter != _virtualItemList.end(); ++iter) {
				pushNodeToPool(*iter);
			}
			setContentSize(getParent()->getContentSize());
			setPosition(0,0);
			_startIndex = _endIndex = 0;
			_virtualItemList.clear();
		}
	}

	void GContainer::setNodeUrl(const std::string& url) {
		if (_defaultItemUrl != url) {
			_defaultItemUrl = url;
			_pkgItem = PackageManager::getInstance()->getItemByUrl(url);
			
			_startIndex = _endIndex = 0;
			_virtualItemList.clear();
			for (auto iter = _urlNodePool.begin(); iter != _urlNodePool.end(); ++iter) {
				(*iter)->release();
			}
			_urlNodePool.clear();
		}
	}

	void GContainer::setUpdateNodeCallback(std::function<void(cocos2d::Node*, int)> handler) {
		_updateNodeHandler = handler;
	}

	int GContainer::getFirstNodeIndex() {
		cocos2d::Size size = getContentSize();
		const cocos2d::Size& parentSize = getParent()->getContentSize();
		const cocos2d::Size& itemSize = _pkgItem->getSize();
		if (_layoutType == ListLayoutType::SINGLE_COLUMN || _layoutType == ListLayoutType::FLOW_HORIZONTAL) {
			float h = size.height + getPositionY() - parentSize.height;
			if (h > _margin.top) {
				int index = floor((h - _margin.top - itemSize.height) / (itemSize.height + _lineCap) + 1);
				return index * _columnCount;
			}
			return 0;
		}
		else if (_layoutType == ListLayoutType::SINGLE_ROW || _layoutType == ListLayoutType::FLOW_VERTICAL) {
			float w = -getPositionX();
			if (w > _margin.left) {
				int index = floor((w - _margin.left - itemSize.width) / (itemSize.width + _columnCap) + 1);
				return index * _lineCount;
			}
			return 0;
		}
		CCASSERT(false, "layout type is not support");
		return 0;
	}

	cocos2d::Vec2 GContainer::getNodePositionByIndex(int index) {
		cocos2d::Size size = getContentSize();
		const cocos2d::Size& itemSize = _pkgItem->getSize();
		if (_layoutType == ListLayoutType::SINGLE_COLUMN || _layoutType == ListLayoutType::FLOW_HORIZONTAL) {
			float offsetX = (size.width - _margin.left - _margin.right - _columnCount * itemSize.width - (_columnCount - 1) * _columnCap) / 2;
			int row = index / _columnCount + 1;
			int column = index % _columnCount + 1;
			float x = _margin.left + (column - 1) * (itemSize.width + _columnCap) + itemSize.width * 0.5f;
			float y = _margin.top + (row - 1) * (itemSize.height + _lineCap) + itemSize.height * 0.5f;
			return cocos2d::Vec2(x + offsetX, size.height - y);
		}
		else if (_layoutType == ListLayoutType::FLOW_VERTICAL || _layoutType == ListLayoutType::SINGLE_ROW) {
			float offsetY = (size.height - _margin.top - _margin.bottom - (_lineCount * itemSize.height) - (_lineCount - 1) * _lineCap) / 2;
			int column = index / _lineCount + 1;
			int row = index % _lineCount + 1;
			float x = _margin.left + (column - 1) * (itemSize.width + _columnCap) + itemSize.width * 0.5f;
			float y = _margin.top + (row - 1) * (itemSize.height + _lineCap) + itemSize.height * 0.5f;
			return cocos2d::Vec2(x, size.height - y - offsetY);
		}
		else {
			CCASSERT(false, "page mode is not suport in virtual list");
		}
		return cocos2d::Vec2::ZERO;
	}

	void GContainer::setNodePosition(cocos2d::Node* node, const cocos2d::Vec2& pos) {
		const cocos2d::Size& size = getContentSize();
		const cocos2d::Size& itemSize = _pkgItem->getSize();
		if (_layoutType == ListLayoutType::SINGLE_COLUMN || _layoutType == ListLayoutType::FLOW_HORIZONTAL) {
			if (pos.y - itemSize.height / 2 < _margin.bottom) {
				float dh = _margin.bottom - pos.y + itemSize.height / 2;
				setContentSize(cocos2d::Size(size.width, size.height + dh));
				setPositionY(getPositionY() - dh);
				for (auto iter = _virtualItemList.begin(); iter != _virtualItemList.end(); ++iter) {
					(*iter)->setPositionY((*iter)->getPositionY() + dh);
				}
				node->setPosition(pos.x, pos.y + dh);
			}
			else if (pos.y + itemSize.height / 2 > size.height - _margin.top) {
				float dh = pos.y + itemSize.height / 2 - size.height + _margin.top;
				setContentSize(cocos2d::Size(size.width, size.height + dh));
				node->setPosition(pos.x, pos.y);
			}
			else {
				node->setPosition(pos.x,pos.y);
			}
		}
		else if (_layoutType == ListLayoutType::SINGLE_ROW || _layoutType == ListLayoutType::FLOW_VERTICAL) {
			if (pos.x - itemSize.width / 2 < _margin.left) {
				float dw = _margin.left - pos.x + itemSize.width / 2;
				setContentSize(cocos2d::Size(size.width + dw, size.height));
				setPositionX(getPositionX() - dw);
				for (auto iter = _virtualItemList.begin(); iter != _virtualItemList.end(); ++iter) {
					(*iter)->setPositionX((*iter)->getPositionX() + dw);
				}
				node->setPosition(pos.x + dw, pos.y);
			}
			else if (pos.x + itemSize.width / 2 > size.width - _margin.right) {
				float dw = pos.x + itemSize.width / 2 - size.width - _margin.right;
				setContentSize(cocos2d::Size(size.width + dw, size.height));
				node->setPosition(pos.x, pos.y);
			}
			else {
				node->setPosition(pos.x, pos.y);
			}
		}
	}

	void GContainer::updateVirtualLayout() {
		if (!_pkgItem) {
			return;
		}

		cocos2d::Node* node = _virtualItemList.size() > 0 ? _virtualItemList.front() : NULL;
		while (node && !isInViewRect(node->getPosition(), _displayRect)) {
			removeChild(node);
			pushNodeToPool(node);
			_virtualItemList.pop_front();
			++_startIndex;
			node = _virtualItemList.size() > 0 ? _virtualItemList.front() : NULL;
		}

		node = _virtualItemList.size() > 0 ? _virtualItemList.back() : NULL;
		while (node && !isInViewRect(node->getPosition(),_displayRect)) {
			removeChild(node);
			pushNodeToPool(node);
			_virtualItemList.pop_back();
			--_endIndex;
			node = _virtualItemList.size() > 0 ? _virtualItemList.back() : NULL;
		}

		cocos2d::Vec2 pos;
		if (_virtualItemList.size() <= 0) {
			cocos2d::Node* node = getNodeFromPool();
			addChild(node);

			int index = getFirstNodeIndex();
			pos = getNodePositionByIndex(index);
			setNodePosition(node, pos);
			pushNodeToList(node, true, index);
		}
		
		while (_startIndex > 0 ) {
			pos = getNodePositionByIndex(_startIndex - 1);
			if (!isInViewRect(pos, _displayRect)) {
				break;
			}
			cocos2d::Node* node = getNodeFromPool();
			addChild(node);
			setNodePosition(node, pos);
			pushNodeToList(node, true);
		}

		int count2 = 0;
		while (_endIndex < _virtualItemCount - 1) {
			pos = getNodePositionByIndex(_endIndex + 1);
			if (!isInViewRect(pos, _displayRect)) {
				break;
			}
			cocos2d::Node* node = getNodeFromPool();
			addChild(node);
			setNodePosition(node, pos);
			pushNodeToList(node, false);
			count2++;
		}
		CCLOG("startIndex = %d, endIndex = %d, count2 = %d", _startIndex, _endIndex, count2);
	}

	void GContainer::visit(Renderer* renderer, const Mat4& parentTransform, uint32_t parentFlags) {
		if (!_isVirtual && _isLayoutDirty) {
			updateCommonLayout();
		}
		Node::visit(renderer, parentTransform, parentFlags);
	}

	const cocos2d::Rect& GContainer::getEdgeRectangle() {
		if (_isEdgeDirty) {
			const cocos2d::Size& size = getContentSize();
			float l = 0, r = size.width, t = size.height, b = 0;
			for (ssize_t i = 0; i < _children.size(); ++i) {
				cocos2d::Node* node = _children.at(i);
				cocos2d::Vec2 lb = getPointWithAnchorPoint(node, 0.0f, 0.0f);
				cocos2d::Vec2 rt = getPointWithAnchorPoint(node, 1.0f, 1.0f);
				if (l > lb.x) l = lb.x;
				if (b > lb.y) b = lb.y;
				if (t < rt.y) t = rt.y;
				if (r < rt.x) r = rt.x;
			}
			_edgeRect = cocos2d::Rect(cocos2d::Vec2(l, b), cocos2d::Size(r - l, t - b));
			_isEdgeDirty = false;
		}
		return _edgeRect;
	}
}