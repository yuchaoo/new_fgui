#pragma once

#include "RelationItem.h"

namespace cocos2d {
    class Node;
}

namespace fgui {

    class GObject;
    class ByteBuffer;
    struct RelationInfo;

    class RelationObserver {
    public:
        virtual void onTargetSizeChanged(cocos2d::Node* target, const cocos2d::Size& oldSize, const cocos2d::Size& newSize) {};
        virtual void onTargetPosisitonChanged(cocos2d::Node* target, const cocos2d::Vec2& oldSize, const cocos2d::Vec2& newSize) {};
        virtual void onTargetExit(cocos2d::Node* target) {};
    };

    class Relations : public cocos2d::Ref, public RelationObserver
    {
    public:
        static Relations* create(cocos2d::Node* owner);
        
        void add(cocos2d::Node* target, RelationType relationType);
        void add(cocos2d::Node* target, RelationType relationType, bool usePercent);
        void remove(cocos2d::Node* target, RelationType relationType);
        bool contains(cocos2d::Node* target);
        void clearFor(cocos2d::Node* target);
        void clearAll();
        void copyFrom(const Relations& source);
        
        bool isEmpty() const;
    protected:
        void setup(ByteBuffer* buffer, bool parentToChild);
        void setup(RelationInfo* info, bool parentToChild);

        virtual void onOwnerSizeChanged(const cocos2d::Size& oldSize, const cocos2d::Size& newSize);
        virtual void onTargetSizeChanged(cocos2d::Node* target, const cocos2d::Size& oldSize, const cocos2d::Size& newSize);
        virtual void onTargetPosisitonChanged(cocos2d::Node* target, const cocos2d::Vec2& newPos, const cocos2d::Vec2& oldSize);
        virtual void onTargetExit(cocos2d::Node* target);
    private:
        Relations(cocos2d::Node* owner);
        ~Relations();

        cocos2d::Node* _owner;
        std::vector<RelationItem*> _items;

        friend class GObject;
        friend class GContainer;
        friend class GComponent;
    };

}

