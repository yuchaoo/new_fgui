#pragma once
#include "cocos2d.h"
#include "GObject.h"

using namespace cocos2d;

namespace fgui {
	class GContainer 
		: public cocos2d::Node
		, public GObject {
	public:
		CREATE_FUNC(GContainer);
		GContainer();
		~GContainer();
		virtual bool init();
		virtual void setContentSize(const cocos2d::Size& size);
		virtual void addChild(Node* child, int localZOrder, const std::string& name);
		virtual void addChild(Node* child, int localZOrder, int tag);
		virtual void addChild(Node* child, int localZOrder);
		virtual void addChild(Node* child);

		void setLayoutType(ListLayoutType type);
		ListLayoutType getLayoutType() const { return _layoutType; }
		void setHAlignment(cocos2d::TextHAlignment hAlign);
		cocos2d::TextHAlignment getHAlignment() const { return _hAlign; }
		void setVAlignment(cocos2d::TextVAlignment vAlign);
		cocos2d::TextVAlignment getVAlignment() const { return _vAlign; }
		void setLineCount(int count);
		int getLineCount() const { return _lineCount; }
		void setColumnCount(int count);
		int getColumnCount() const { return _columnCount; }
		void setLineGap(int lineCap);
		int getLineGap() const { return _lineCap; }
		void setColumnGap(int columnCap);
		int getColumnGap() const { return _columnCap; }
		void setMargin(const Margin& margin);
		void setVirtual();
		bool isVirtual();
		void setVirtualItemCount(int count);
		int getVirtualItemCount();
		
		virtual void visit(Renderer* renderer, const Mat4& parentTransform, uint32_t parentFlags);
		const cocos2d::Rect& getEdgeRectangle();
		void updateCommonLayout();
		void updateVirtualLayout();
		void clearAllChildren();
		void setNodeUrl(const std::string& url);
		void setUpdateNodeCallback(std::function<void(cocos2d::Node*, int)> handler);
	protected:
		bool isInViewRect(const cocos2d::Vec2& p, const cocos2d::Rect& rect);
		cocos2d::Node* getNodeFromPool();
		void pushNodeToPool(cocos2d::Node* node);
		cocos2d::Vec2 getNodePositionByIndex(int index);
		void setNodePosition(cocos2d::Node* node, const cocos2d::Vec2& pos);
		int getFirstNodeIndex();
		void pushNodeToList(cocos2d::Node* node, bool isFront, int index = -1);
		void updateNodeContent();
	private:
		bool _isEdgeDirty;
		cocos2d::Rect _edgeRect;
		bool _isLayoutDirty;
		ListLayoutType _layoutType;
		cocos2d::TextHAlignment _hAlign;
		cocos2d::TextVAlignment _vAlign;
		int _lineCount;
		int _columnCount;
		int _lineCap;
		int _columnCap;
		bool _isVirtual;
		int _virtualItemCount;
		std::string _defaultItemUrl;
		PkgItem* _pkgItem;
		Margin _margin;
		cocos2d::Rect _displayRect;
		std::list<cocos2d::Node*> _virtualItemList;
		std::vector<cocos2d::Node*> _urlNodePool;
		int _startIndex, _endIndex;
		std::function<void(cocos2d::Node* node, int index)> _updateNodeHandler;
	};
}


