#pragma once

#include "FieldTypes.h"
#include "2d/CCNode.h"
#include "base/ccTypes.h"

namespace cocos2d {
    class Node;
}

namespace fgui {

    class GObject;
    class EventContext;

    class RelationDef
    {
    public:
        bool percent;
        RelationType type;
        int axis;

        RelationDef() {}

        RelationDef(const RelationDef& source)
        {
            this->percent = source.percent;
            this->type = source.type;
            this->axis = source.axis;
        }
    };

    class RelationItem
    {
    public:
        RelationItem(cocos2d::Node* owner);
        ~RelationItem();

        cocos2d::Node* getTarget() { return _target; }
        void setTarget(cocos2d::Node* value);
        void add(RelationType relationType, bool usePercent);
        void internalAdd(RelationType relationType, bool usePercent);
        void remove(RelationType relationType);
        bool isEmpty() const;
        void copyFrom(const RelationItem& source);
    protected:
        void onTargetSizeChanged(cocos2d::Node* target,const cocos2d::Size& oldSize, const cocos2d::Size& newSize);
        void onTargetXYChanged(cocos2d::Node* target, const cocos2d::Vec2& oldPos, const cocos2d::Vec2& newPos);
        void applySelfSizeChanged(const cocos2d::Size& oldSize, const cocos2d::Size& newSize);
        void applyTargetXYChanged(cocos2d::Node* target, const RelationDef& info, const cocos2d::Vec2& oldPos, const cocos2d::Vec2& newPos);
        void applyTargetSizeChanged(cocos2d::Node* target, const RelationDef& info, const cocos2d::Size& oldSize, const cocos2d::Size& newSize);
    private:
        cocos2d::Node* _owner;
        cocos2d::Node* _target;
        std::vector<RelationDef> _defs;
        friend class Relations;
    };

}

