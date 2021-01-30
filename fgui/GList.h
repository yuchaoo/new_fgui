#pragma once
#include "GComponent.h"
#include <unordered_map>

namespace fgui {
	struct ListLayoutInfo {
		ListLayoutType layoutType = ListLayoutType::SINGLE_COLUMN;
		float lineGap = 0;
		float columnGap = 0;
		int lineCount = 0;
		int columnCount = 1;
		float left = 0;
		float right = 0;
		float top = 0;
		float bottom = 0;
	};

	class GContainer;

	class GList : public GComponent{
	public:
		CREATE_FUNC(GList);
		GList();
		~GList();
	public:
		virtual bool init();
		void setLayoutInfo(const ListLayoutInfo& info);
		virtual void addChild(Node* child, int localZOrder, const std::string& name);
		virtual void addChild(Node* child, int localZOrder, int tag);
		virtual void addChild(Node* child, int localZOrder);
		virtual void addChild(Node* child);
		void setUpdateNodeCallback(std::function<void(cocos2d::Node*, int)> handler);
		void setNodeUrl(const std::string& url);
		void setVirtual();
		bool isVirtual();
		void setVirtualItemCount(int count);
		int getVirtualItemCount();

	protected:
		virtual void setupOverflow(OverflowType overflow);
		virtual void setup(const ObjectInfo* inf, cocos2d::Node* parent);
		virtual bool onTouchBegin(cocos2d::Touch* touch, cocos2d::Event* event);
		virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
		virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	private:
		double _touchBeginTime;
		GContainer* _container;
	};
}