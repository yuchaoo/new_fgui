#include "RelationItem.h"
#include "GComponent.h"
#include "FguiUtils.h"

namespace fgui {

    RelationItem::RelationItem(cocos2d::Node* owner) :
        _target(nullptr)
    {
        _owner = owner;
    }

    RelationItem::~RelationItem()
    {
        
    }

    void RelationItem::setTarget(cocos2d::Node* value){
        if (_target != value) {
            _target = value;
        }
    }

    void RelationItem::add(RelationType relationType, bool usePercent){
        for (auto& it : _defs){
            if (it.type == relationType)
                return;
        }
        internalAdd(relationType, usePercent);
    }

    void RelationItem::internalAdd(RelationType relationType, bool usePercent){
        RelationDef info;
        info.percent = usePercent;
        info.type = relationType;
        info.axis = (relationType <= RelationType::Right_Right || relationType == RelationType::Width || (relationType >= RelationType::LeftExt_Left && relationType <= RelationType::RightExt_Right)) ? 0 : 1;
        _defs.push_back(info);
    }

    void RelationItem::remove(RelationType relationType){
        for (auto it = _defs.begin(); it != _defs.end(); ++it){
            if (it->type == relationType){
                _defs.erase(it);
                break;
            }
        }
    }

    bool RelationItem::isEmpty() const
    {
        return _defs.size() == 0;
    }

	void RelationItem::copyFrom(const RelationItem& source){
		setTarget(source._target);
		_defs.clear();
		for (auto& it : source._defs)
			_defs.push_back(it);
	}

    void RelationItem::applySelfSizeChanged(const cocos2d::Size& oldSize, const cocos2d::Size& newSize)
    {
        if (_target == nullptr || _defs.size() == 0)
            return;
        cocos2d::Vec2 ownerAp;
        float dw = newSize.width - oldSize.width;
        float dh = newSize.height - oldSize.height;
        if (!_owner->isIgnoreAnchorPointForPosition()) {
            ownerAp = _owner->getAnchorPoint();
        }

        for (auto& it : _defs)
        {
            switch (it.type)
            {
            case RelationType::Left_Left:
            case RelationType::Left_Right:
            case RelationType::Left_Center: {
				_owner->setPositionX(_owner->getPositionX() + ownerAp.x * dw);
				break;
            }
            case RelationType::Center_Center: {
				_owner->setPositionX(_owner->getPositionX() - (0.5f - ownerAp.x) * dw);
				break;
            }
            case RelationType::Right_Center:
            case RelationType::Right_Left:
            case RelationType::Right_Right: {
                _owner->setPositionX(_owner->getPositionX() - (1.0f - ownerAp.x) * dw);
                break;
            }
            case RelationType::Middle_Middle:{
                _owner->setPositionY(_owner->getPositionY() - (0.5f - ownerAp.y) * dh);
                break;
            }
            case RelationType::Top_Top:
            case RelationType::Top_Middle:
            case RelationType::Top_Bottom: {
                _owner->setPositionY(_owner->getPositionY() - (1.0f - ownerAp.y) * dh);
                break;
            }
            case RelationType::Bottom_Middle:
            case RelationType::Bottom_Top:
            case RelationType::Bottom_Bottom: {
                _owner->setPositionY(_owner->getPositionY() + ownerAp.y * dh);
                break;
            }
            default:
                break;
            }
        }
    }
    void RelationItem::onTargetXYChanged(cocos2d::Node* target, const cocos2d::Vec2& oldPos, const cocos2d::Vec2& newPos) {
        for (auto iter = _defs.begin(); iter != _defs.end(); ++iter) {
            applyTargetXYChanged(target, *iter, oldPos, newPos);
        }
    }

    void RelationItem::applyTargetXYChanged(cocos2d::Node* target, const RelationDef& info, const cocos2d::Vec2& oldPos, const cocos2d::Vec2& newPos)
    {
        cocos2d::Vec2 ownerAp, targetAp;
        if (_target == _owner->getParent() || _owner == _target->getParent()) {
            return;
        }

		float dx = newPos.x - oldPos.x;
		float dy = newPos.y - oldPos.y;
        if (!_target->isIgnoreAnchorPointForPosition()) {
            targetAp = _target->getAnchorPoint();
        }
        const cocos2d::Size& ownerSize = _owner->getContentSize();
        if (!_owner->isIgnoreAnchorPointForPosition()) {
            ownerAp  = _owner->getAnchorPoint();
        }

        switch (info.type)
        {
        case RelationType::Left_Left:
        case RelationType::Left_Center:
        case RelationType::Left_Right:
        case RelationType::Center_Center:
        case RelationType::Right_Left:
        case RelationType::Right_Center:
        case RelationType::Right_Right:{
             _owner->setPositionX(_owner->getPositionX() + dx);
        }
        break;
        case RelationType::Top_Top:
        case RelationType::Top_Middle:
        case RelationType::Top_Bottom:
        case RelationType::Middle_Middle:
        case RelationType::Bottom_Top:
        case RelationType::Bottom_Middle:
        case RelationType::Bottom_Bottom:{
             _owner->setPositionY(_owner->getPositionY() + dy);
        }
        break;
        case RelationType::Width:
        case RelationType::Height:
            break;
        case RelationType::LeftExt_Left:
        case RelationType::LeftExt_Right: {
			_owner->setContentSize(cocos2d::Size(ownerSize.width - dx, ownerSize.height));
			_owner->setPositionX(_owner->getPositionX() + (1.0f - ownerAp.x) * dx);
        }
        break;
        case RelationType::RightExt_Left:
        case RelationType::RightExt_Right: {
			_owner->setContentSize(cocos2d::Size(ownerSize.width + dx, ownerSize.height));
			_owner->setPositionX(_owner->getPositionX() + dx * ownerAp.x);
        }
        break;
        case RelationType::TopExt_Top:
        case RelationType::TopExt_Bottom: {
			_owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + dy));
			_owner->setPositionY(_owner->getPositionY() + ownerAp.y * dy);
        }
        break;
        case RelationType::BottomExt_Top:
        case RelationType::BottomExt_Bottom: {
			_owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height - dy));
			_owner->setPositionY(_owner->getPositionY() + (1.0f - ownerAp.y) * dy);
        }
        break;
        default:
            break;
        }
    }
    void RelationItem::onTargetSizeChanged(cocos2d::Node* target,const cocos2d::Size& oldSize, const cocos2d::Size& newSize){
        for (auto iter = _defs.begin(); iter != _defs.end(); ++iter) {
            applyTargetSizeChanged(target, *iter, oldSize, newSize);
        }
    }
    void RelationItem::applyTargetSizeChanged(cocos2d::Node* target, const RelationDef& info, const cocos2d::Size& oldSize, const cocos2d::Size& newSize)
    {
        cocos2d::Vec2 targetAp, ownerAp;
        if (!_target->isIgnoreAnchorPointForPosition()) {
            targetAp = _target->getAnchorPoint();
        }
        if (!_owner->isIgnoreAnchorPointForPosition()) {
            ownerAp = _owner->getAnchorPoint();
        }
        const cocos2d::Size& ownerSize = _owner->getContentSize();
        float fw = newSize.width / oldSize.width;
        float fh = newSize.height / oldSize.height;

        switch (info.type)
        {
        case RelationType::Left_Left:{
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float left = (_owner->getPositionX() - ownerAp.x * ownerSize.width) * fw;
                    _owner->setPositionX(left + ownerAp.x * ownerSize.width);
                }
            }
            else if(_target->getParent() != _owner) {
                if (info.percent) {
                    float ol = _owner->getPositionX() - (ownerAp.x * ownerSize.width);
                    float tl = _target->getPositionX() - (targetAp.x * oldSize.width);
                    float left = (ol - tl) * fw + _target->getPositionX() - (targetAp.x * newSize.width);
                    _owner->setPositionX(left + ownerAp.x * ownerSize.width);
                }
                else {
                    _owner->setPositionX(_owner->getPositionX() - targetAp.x * (newSize.width - oldSize.width));
                }
            }
        }
        break;
        case RelationType::Left_Center:{
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float tc = oldSize.width / 2;
                    float ol = _owner->getPositionX() - (ownerAp.x * ownerSize.width);
                    float left = (ol - tc) * fw + newSize.width / 2;
                    _owner->setPositionX(left + ownerAp.x * ownerSize.width);
                }
                else {
                    _owner->setPositionX(_owner->getPositionX() + (newSize.width - oldSize.width) / 2);
                }
            }
            else if(_target->getParent() != _owner){
                if (info.percent) {
                    float tc = _target->getPositionX() + (0.5f - targetAp.x) * oldSize.width;
                    float ol = _owner->getPositionX() - ownerAp.x * ownerSize.width;
                    float left = (ol - tc) * fw + _target->getPositionX() + (0.5f - targetAp.x) * newSize.width;
                    _owner->setPositionX(left + ownerAp.x * ownerSize.width);
                }
                else {
                    _owner->setPositionX(_owner->getPositionX() + (0.5f - targetAp.x) * (newSize.width - oldSize.width));
                }
            }
        }
        break;
        case RelationType::Left_Right:{
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float ol = _owner->getPositionX() - ownerAp.x * ownerSize.width;
                    float tr = oldSize.width;
                    float left = (ol - tr) * fw + newSize.width;
                    _owner->setPositionX(left + ownerAp.x * ownerSize.width);
                }
                else {
                    _owner->setPositionX(_owner->getPositionX() + (newSize.width - oldSize.width));
                }
            }
            else if(_target->getParent() != _owner){
                if (info.percent) {
                    float ol = _owner->getPositionX() - ownerAp.x * ownerSize.width;
                    float tr = _target->getPositionX() + (1.0f - targetAp.x) * oldSize.width;
                    float left = (ol - tr) * fw + _target->getPositionX() + (1.0f - targetAp.x) * newSize.width ;
                    _owner->setPositionX(left + ownerAp.x * ownerSize.width);
                }
                else {
                    _owner->setPositionX(_owner->getPositionX() + (1.0f - targetAp.x) * (newSize.width - oldSize.width));
                }
            }
        }
        break;
        case RelationType::Center_Center:{
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float oc = _owner->getPositionX() + (0.5f - ownerAp.x) * ownerSize.width;
                    float tc = oldSize.width / 2;
                    float center = (oc - tc) * fw + newSize.width / 2;
                    _owner->setPositionX(center + (ownerAp.x - 0.5f) * ownerSize.width);
                }
                else {
                    _owner->setPositionX(_owner->getPositionX() + 0.5f * (newSize.width - oldSize.width));
                }
            }
            else if(_target->getParent() != _owner){
                if (info.percent) {
                    float oc = _owner->getPositionX() + (0.5f - ownerAp.x) * ownerSize.width;
                    float tc = _target->getPositionX() + (0.5f - ownerAp.x) * oldSize.width;
                    float center = (oc - tc) * fw + _target->getPositionX() + (0.5f - ownerAp.x) * newSize.width;
                    _owner->setPositionX(center + (ownerAp.x - 0.5f) * ownerSize.width);
                }
                else {
                    _owner->setPositionX(_owner->getPositionX() + (0.5f - targetAp.x) * (newSize.width - oldSize.width));
                }
            }
        }
        break;
        case RelationType::Right_Left:{
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float oR = _owner->getPositionX() + (1.0f - ownerAp.x) * ownerSize.width;
                    float tl = 0;
                    float right = (oR - tl ) * fw ;
                    _owner->setPositionX(right + (ownerAp.x - 1.0f) * ownerSize.width);
                }
            }
            else if(_owner != _target->getParent()){
				if (info.percent) {
					float oR = _owner->getPositionX() + (1.0f - ownerAp.x) * ownerSize.width;
					float tl = _target->getPositionX() - targetAp.x * oldSize.width;
					float right = (oR - tl) * fw + _target->getPositionX() - targetAp.x * newSize.width;
					_owner->setPositionX(right + (ownerAp.x - 1.0f) * ownerSize.width);
				}
				else {
					_owner->setPositionX(_owner->getPositionX() - targetAp.x * (newSize.width - oldSize.width));
				}
            }
        }
        break;
        case RelationType::Right_Center:{
            if (_target == _owner->getParent()) {
				if (info.percent) {
					float oR = _owner->getPositionX() + (1.0f - ownerAp.x) * ownerSize.width;
                    float tc = oldSize.width / 2;
                    float right = (oR -tc) * fw + newSize.width / 2;
                    _owner->setPositionX(right + (ownerAp.x - 1.0f) * ownerSize.width);
				}
				else {
                    _owner->setPositionX(_owner->getPositionX() + 0.5f * (newSize.width - oldSize.width));
				}
            }
            else if (_target->getParent() != _owner) {
                if (info.percent) {
                    float oR = _owner->getPositionX() + (1.0f - ownerAp.x) * ownerSize.width;
                    float tc = _target->getPositionX() + (0.5f - targetAp.x) * oldSize.width;
                    float right = (oR -tc) * fw + _target->getPositionX() + (0.5f - targetAp.x) * newSize.width;
                    _owner->setPositionX(right + (ownerAp.x - 1.0f) * ownerSize.width);
                }
                else {
                    _owner->setPositionX(_owner->getPositionX() + (0.5f - targetAp.x) * (newSize.width - oldSize.width));
                }
            }
        }
        break;
        case RelationType::Right_Right:{
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float oR = _owner->getPositionX() + (1.0f - ownerAp.x) * ownerSize.width;
                    float tr = oldSize.width;
                    float right = (oR - tr) * fw + newSize.width;
                    _owner->setPositionX(right + (ownerAp.x - 1.0f) * ownerSize.width);
                }
                else {
                    _owner->setPositionX(_owner->getPositionX() + (newSize.width - oldSize.width));
                }
            }
            else if(_target->getParent() != _owner){
                if (info.percent) {
                    float oR = _owner->getPositionX() + (1.0f - ownerAp.x) * ownerSize.width;
                    float tr = _target->getPositionX() + (1.0f - targetAp.x) * oldSize.width;
                    float right = (oR - tr) * fw + _target->getPositionX() + (1.0f - targetAp.x) * newSize.width;
                    _owner->setPositionX(right + (ownerAp.x - 1.0f) * ownerSize.width);
                }
                else {
                    _owner->setPositionX(_owner->getPositionX() + (1.0f - targetAp.x) * (newSize.width - oldSize.width));
                }
            }
        }
        break;
        case RelationType::Top_Top:{
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float ot = _owner->getPositionY() + (1.0f - ownerAp.y) * ownerSize.height;
                    float tt = oldSize.height;
                    float top = (ot - tt) * fh + newSize.height;
                    _owner->setPositionY(top + (ownerAp.y - 1.0f) * ownerSize.height);
                }
                else {
                    _owner->setPositionY(_owner->getPositionY() + (newSize.height - oldSize.height));
                }
            }
            else if (_owner != _target->getParent()) {
                if (info.percent) {
                    float ot = _owner->getPositionY() + (1.0f - ownerAp.y) * ownerSize.height;
                    float tt = _target->getPositionY() + (1.0f - targetAp.y) * oldSize.height;
                    float top = (ot - tt) * fh + _target->getPositionY() + (1.0f - targetAp.y) * newSize.height;
                    _owner->setPositionY(top + (ownerAp.y - 1.0f) * ownerSize.height);
                }
                else {
                    _owner->setPositionY(_owner->getPositionY() + (1.0f - targetAp.y) * (newSize.height - oldSize.height));
                }
            }
        }
        break;
        case RelationType::Top_Middle:
        {
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float ot = _owner->getPositionY() + (1.0f - ownerAp.y) * ownerSize.height;
                    float tm = oldSize.height / 2;
                    float top = (ot - tm) * fh + newSize.height / 2;
                    _owner->setPositionY(top + (ownerAp.y - 1.0f) * ownerSize.height);
                }
                else {
                    _owner->setPositionY(_owner->getPositionY() + 0.5f * (newSize.height - oldSize.height));
                }
            }
            else if (_owner != _target->getParent()) {
                if (info.percent) {
                    float ot = _owner->getPositionY() + (1.0f - ownerAp.y) * ownerSize.height;
                    float tm = _target->getPositionY() + (0.5f - targetAp.y) * oldSize.height;
                    float top = (ot - tm) * fh + _target->getPositionY() + (0.5f - targetAp.y) * newSize.height;
                    _owner->setPositionY(top + (ownerAp.y - 1.0f) * ownerSize.height);
                }
                else {
                    _owner->setPositionY(_owner->getPositionY() + (0.5f - targetAp.y) * (newSize.height - oldSize.height));
                }
            }
        }
        break;
        case RelationType::Top_Bottom:
        {
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float ot = _owner->getPositionY() + (1.0f - ownerAp.y) * ownerSize.height;
                    float bm = 0;
                    float top = (ot - bm) * fh + bm;
                    _owner->setPositionY(top + (ownerAp.y - 1.0f) * ownerSize.height);
                }
            }
            else if(_owner != _target->getParent()){
                if (info.percent) {
                    float ot = _owner->getPositionY() + (1.0f - ownerAp.y) * ownerSize.height;
                    float bm = _target->getPositionY() + (0 - targetAp.y) * oldSize.height;
                    float top = (ot - bm) * fh + _target->getPositionY() - targetAp.y * newSize.height;
                    _owner->setPositionY(top + (ownerAp.y - 1.0f) * ownerSize.height);
                }
                else {
                    _owner->setPositionY(_owner->getPositionY() + (0.0 - targetAp.y) * (newSize.height - oldSize.height));
                }
            }
        }
        break;
        case RelationType::Middle_Middle:
        {
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float om = _owner->getPositionY() + (0.5f - ownerAp.y) * ownerSize.height;
                    float tm = oldSize.height / 2;
                    float middle = (om - tm) * fh + newSize.height/2;
                    _owner->setPositionY(middle + (ownerAp.y - 0.5f) * ownerSize.height);
                }
                else {
                    _owner->setPositionY(_owner->getPositionY() + 0.5f * (newSize.height - oldSize.height));
                }
            }
            else if (_owner != _target->getParent()) {
                if (info.percent) {
					float om = _owner->getPositionY() + (0.5f - ownerAp.y) * ownerSize.height;
					float tm = _target->getPositionY() + (0.5f - targetAp.y) * oldSize.height;
					float middle = (om - tm) * fh + _target->getPositionY() + (0.5f - targetAp.y) * newSize.height;
					_owner->setPositionY(middle + (ownerAp.y - 0.5f) * ownerSize.height);
                }
                else {
                    _owner->setPositionY(_owner->getPositionY() + (0.5f - targetAp.y) * (newSize.height - oldSize.height));
                }
            }
        }
        break;
        case RelationType::Bottom_Top:
        {
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float ob = _owner->getPositionY() + (0 - ownerAp.y) * ownerSize.height;
                    float tt = oldSize.height;
                    float bottom = (ob - tt) * fh + newSize.height;
                    _owner->setPositionY(bottom + (ownerAp.y) * ownerSize.height);
                }
                else {
                    _owner->setPositionY(_owner->getPositionY() + (newSize.height - oldSize.height));
                }
            }
            else if (_owner != _target->getParent()) {
                if (info.percent) {
                    float ob = _owner->getPositionY() + (0 - ownerAp.y) * ownerSize.height;
                    float tt = _target->getPositionY() + (1.0f - targetAp.y) * oldSize.height;
                    float bottom = (ob - tt) * fh + _target->getPositionY() + (1.0f - targetAp.y) * newSize.height;
                    _owner->setPositionY(bottom + (targetAp.y) * ownerSize.height);
                }
                else {
                    _owner->setPositionY(_owner->getPositionY() + (1.0f - targetAp.y) * (newSize.height - oldSize.height));
                }
            }
        }
        break;
        case RelationType::Bottom_Middle:
        {
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float ob = _owner->getPositionY() + (0 - ownerAp.y) * ownerSize.height;
                    float tm = oldSize.height / 2;
                    float bottom = (ob - tm) * fh + newSize.height / 2;
                    _owner->setPositionY(bottom + (ownerAp.y) * ownerSize.height);
                }
                else {
                    _owner->setPositionY(_owner->getPositionY() + 0.5f * (newSize.height - oldSize.height));
                }
            }
            else if (_owner != _target->getParent()) {
                if (info.percent) {
                    float ob = _owner->getPositionY() + (0 - ownerAp.y) * ownerSize.height;
                    float tm = _target->getPositionY() + (0.5f - targetAp.y) * oldSize.height;
                    float bottom = (ob - tm) * fh + _target->getPositionY() + (0.5f - targetAp.y) * newSize.height;
                    _owner->setPositionY(bottom + (ownerAp.y) * ownerSize.height);
                }
                else {
                    _owner->setPositionY(_owner->getPositionY() + (0.5f - targetAp.y) * (newSize.height - oldSize.height));
                }
            }
        }
        break;
        case RelationType::Bottom_Bottom:
        {
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float ob = _owner->getPositionY() + (0 - ownerAp.y) * ownerSize.height;
                    float tb = 0;
                    float bottom = (ob - 0) * fh + 0;
                    _owner->setPositionY(bottom + (ownerAp.y) * ownerSize.height );
                }
            }
            else if(_owner != _target->getParent()){
                if (info.percent) {
                    float ob = _owner->getPositionY() + (0 - ownerAp.y) * ownerSize.height;
                    float tb = _target->getPositionY() + (0 - targetAp.y) * oldSize.height;
                    float bottom = (ob - tb) * fh + _target->getPositionY() - targetAp.y * newSize.height;
                    _owner->setPositionY(bottom + (ownerAp.y) * ownerSize.height);
                }
                else {
                    _owner->setPositionY(_owner->getPositionY() + (0 - targetAp.y) * (newSize.height - oldSize.height));
                }
            }
        }
        break;
        case RelationType::Width:  
        {
            if (_target == _owner->getParent()) {
				_owner->setContentSize(cocos2d::Size(ownerSize.width + newSize.width - oldSize.width, ownerSize.height));
				_owner->setPositionX(_owner->getPositionX() + ownerAp.x * (newSize.width - oldSize.width));
            }
            else {
                _owner->setContentSize(cocos2d::Size(ownerSize.width + newSize.width - oldSize.width, ownerSize.height));
            }
        }
        break;
        case RelationType::Height:
        {
            if (_target == _owner->getParent()) {
				_owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + newSize.height - oldSize.height));
				_owner->setPositionY(_owner->getPositionY() + ownerAp.y * (newSize.height - oldSize.height));
            }
            else {
                _owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + newSize.height - oldSize.height));
            }
        }
        break;
        case RelationType::Size:
        {
			if (_target == _owner->getParent()) {
				_owner->setContentSize(cocos2d::Size(ownerSize.width + newSize.width - oldSize.width, ownerSize.height + newSize.height - oldSize.height));
                float x = _owner->getPositionX() + ownerAp.x * (newSize.width - oldSize.width);
                float y = _owner->getPositionY() + ownerAp.y * (newSize.height - oldSize.height);
				_owner->setPosition(x,y);
            }
			else {
				_owner->setContentSize(cocos2d::Size(ownerSize.width + newSize.width - oldSize.width, ownerSize.height + newSize.height - oldSize.height));
			}
        }
        break;
        case RelationType::LeftExt_Left: 
        {
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float dw = ownerSize.width * (fw - 1.0f);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width + dw, ownerSize.height));
                    _owner->setPositionX(_owner->getPositionX() - (1.0f - ownerAp.x) * dw);
                }
            }
            else if (_owner != _target->getParent()) {
                if (info.percent) {
                    float dw = ownerSize.width * (fw - 1.0f);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width + dw, ownerSize.height));
                    _owner->setPositionX(_owner->getPositionX() - (1.0f - ownerAp.x) * dw);
                }
                else {
                    float width = ownerSize.width + newSize.width - oldSize.width;
                    _owner->setContentSize(cocos2d::Size(width, ownerSize.height));
                    _owner->setPositionX(_owner->getPositionX() - (1.0f - ownerAp.x) * (newSize.width - oldSize.width));
                }
            }
        }
        break;
        case RelationType::LeftExt_Right: 
        {
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float dw = -ownerSize.width * (fw - 1.0f);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width + dw, ownerSize.height));
                    _owner->setPositionX(_owner->getPositionX() - dw * (1.0f - ownerAp.x));
                }
                else {
                    float dw = -(newSize.width - oldSize.width);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width + dw, ownerSize.height));
                    _owner->setPositionX(_owner->getPositionX() - dw * (1.0f - ownerAp.x));
                }
            }
            else if (_owner != _target->getParent()) {
                if (info.percent) {
                    float dw = -ownerSize.width * (fw - 1.0f);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width + dw, ownerSize.height));
                    _owner->setPositionX(_owner->getPositionX() - dw * (1.0f - ownerAp.x));
                }
                else {
                    float dw = -(newSize.width - oldSize.width) * (1.0f - targetAp.x);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width + dw , ownerSize.height));
                    _owner->setPositionX(_owner->getPositionX() - dw * (1.0f - ownerAp.x));
                }
            }
        }
        break;
        case RelationType::RightExt_Left: 
        {
            if (_target == _owner->getParent()) {
				if (info.percent) {
					float dw = ownerSize.width * (fw - 1.0f);
					_owner->setContentSize(cocos2d::Size(ownerSize.width + dw, ownerSize.height));
					_owner->setPositionX(_owner->getPositionX() + ownerAp.x * dw);
				}
            }
            else if (_owner != _target->getParent()) {
                if (info.percent) {
                    float dw = -ownerSize.width * (fw - 1.0f);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width + dw, ownerSize.height));
                    _owner->setPositionX(_owner->getPositionX() + ownerAp.x * dw);
                }
                else {
                    float dw = -(targetAp.x) * (newSize.width - oldSize.width);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width + dw, ownerSize.height));
                    _owner->setPositionX(_owner->getPositionX() + ownerAp.x * dw);
                }
            }
        }
        break;
        case RelationType::RightExt_Right: 
        {
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float dw = ownerSize.width * (fw - 1.0f);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width + dw, ownerSize.height));
                    _owner->setPositionX(_owner->getPositionX() + (ownerAp.x) * dw);
                }
                else {
                    float dw = newSize.width - oldSize.width;
                    _owner->setContentSize(cocos2d::Size(ownerSize.width + dw, ownerSize.height));
                    _owner->setPositionX(_owner->getPositionX() + ownerAp.x * dw);
                }
            }
            else if (_owner != _target->getParent()) {
                if (info.percent) {
                    float dw = ownerSize.width * (fw - 1.0f);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width + dw, ownerSize.height));
                    _owner->setPositionX(_owner->getPositionX() + ownerAp.x * dw);
                }
                else {
                    float dw = (newSize.width - oldSize.width) * (1.0f - targetAp.x);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width + dw, ownerSize.height));
                    _owner->setPositionX(_owner->getPositionX() + ownerAp.x * dw);
                }
            }
            else if (_owner == _target->getParent()) {
                float dw = (newSize.width - oldSize.width) * (1.0f - targetAp.x);
                _owner->setContentSize(cocos2d::Size(ownerSize.width + dw, ownerSize.height));
            }
        }
        break;
        case RelationType::TopExt_Top: 
        {
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float dh = ownerSize.height * (fh - 1.0f);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + dh));
                    _owner->setPositionY(_owner->getPositionY() + ownerAp.y * dh);
                }
                else {
                    float dh = newSize.height - oldSize.height;
                    _owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + dh));
                    _owner->setPositionY(_owner->getPositionY() + ownerAp.y * dh);
                }
            }
            else if (_owner != _target->getParent()) {
                if (info.percent) {
                    float dh = ownerSize.height * (fh - 1.0f);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + dh));
                    _owner->setPositionY(_owner->getPositionY() + ownerAp.y * dh);
                }
                else {
                    float dh = (newSize.height - oldSize.height) * (1.0f - targetAp.y);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + dh));
                    _owner->setPositionY(_owner->getPositionY() + ownerAp.y * dh);
                }
            }
        }
        break;
        case RelationType::TopExt_Bottom:
        {
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float dh = ownerSize.height * (fh - 1.0f);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + dh));
                    _owner->setPositionY(_owner->getPositionY() - (1.0f - ownerAp.y) * dh);
                }
            }
            else if (_owner != _target->getParent()) {
                if (info.percent) {
                    float dh = -ownerSize.height * (fh - 1.0f);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + dh));
                    _owner->setPositionY(_owner->getPositionY() + ownerAp.y * dh);
                }
                else {
                    float dh = -(targetAp.y) * (newSize.height - oldSize.height);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + dh));
                    _owner->setPositionY(_owner->getPositionY() + ownerAp.y * dh);
                }
            }
        }
        break;
        case RelationType::BottomExt_Top: 
        {
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float dh = -ownerSize.width * (fh - 1.0f);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + dh));
                    _owner->setPositionY(_owner->getPositionY() - (1.0f - ownerAp.y) * dh);
                }
                else {
                    float dh = -(newSize.height - oldSize.height);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + dh));
                    _owner->setPositionY(_owner->getPositionY() - dh + ownerAp.y * dh);
                }
            }
            else if (_owner != _target->getParent()) {
                if (info.percent) {
                    float dh = -ownerSize.height * (fh - 1.0f);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + dh));
                    _owner->setPositionY(_owner->getPositionY() - dh + ownerAp.y * dh);
                }
                else {
                    float dh = -(newSize.height - oldSize.height) * (1.0f - targetAp.y);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + dh));
                    _owner->setPositionY(_owner->getPositionY() - dh + ownerAp.y * dh);
                }
            }
        }
        break;
        case RelationType::BottomExt_Bottom:  
        {
            if (_target == _owner->getParent()) {
                if (info.percent) {
                    float dh = ownerSize.height * (fh - 1.0f);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + dh));
                    _owner->setPositionY(_owner->getPositionY() + ownerAp.y * dh);
                }
            }
            else if (_owner != _target->getParent()) {
                if (info.percent) {
                    float dh = ownerSize.height * (fh - 1.0f);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + dh));
                    _owner->setPositionY(_owner->getPositionY() + ownerAp.y * dh);
                }
                else {
                    float dh = targetAp.y * (newSize.height - oldSize.height);
                    _owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + dh));
                    _owner->setPositionY(_owner->getPositionY() - (1.0f - ownerAp.y) * dh);
                }
            }
            else if (_owner == _target->getParent()) {
                float dh = targetAp.y * (newSize.height - oldSize.height);
                _owner->setContentSize(cocos2d::Size(ownerSize.width, ownerSize.height + dh));
                _target->setPositionY(_target->getPositionY() + dh);
            }
        }
        break;
        default:
            break;
        }
    }

}