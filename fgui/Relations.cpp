#include "Relations.h"
#include "GComponent.h"
#include "ByteBuffer.h"
#include "ObjectData.h"

namespace fgui {

	Relations* Relations::create(cocos2d::Node* owner) {
		Relations* rel = new Relations(owner);
		rel->autorelease();
		return rel;
	}

	Relations::Relations(cocos2d::Node* owner) 
	{
		_owner = owner;
	}

	Relations::~Relations(){
		clearAll();
	}

	void Relations::add(cocos2d::Node* target, RelationType relationType) {
		add(target, relationType, false);
	}

	void Relations::add(cocos2d::Node* target, RelationType relationType, bool usePercent) {
		CCASSERT(target, "target is null");
		for (auto it = _items.begin(); it != _items.end(); ++it) {
			if ((*it)->getTarget() == target) {
				(*it)->add(relationType, usePercent);
				return;
			}
		}
		RelationItem* newItem = new RelationItem(_owner);
		newItem->setTarget(target);
		newItem->add(relationType, usePercent);
		_items.push_back(newItem);

		GObject* obj = dynamic_cast<GObject*>(target);
		CC_ASSERT(obj);
		obj->addRelationObserver(this);
	}

	void Relations::remove(cocos2d::Node* target, RelationType relationType) {
		for (auto it = _items.begin(); it != _items.end(); ++it) {
			if ((*it)->getTarget() == target) {
				(*it)->remove(relationType);
				if ((*it)->isEmpty()) {
					delete (*it);
					_items.erase(it);
					GObject* obj = dynamic_cast<GObject*>(target);
					CC_ASSERT(obj);
					obj->removeRelationObserver(this);
				}	
				break;
			}
		}
	}

	bool Relations::contains(cocos2d::Node* target) {
		for (auto it = _items.begin(); it != _items.end(); ++it) {
			if ((*it)->getTarget() == target) {
				return true;
			}
		}
		return false;
	}

	void Relations::clearFor(cocos2d::Node* target){
		for (auto it = _items.begin(); it != _items.end(); ++it){
			if ((*it)->getTarget() == target){
				delete (*it);
				_items.erase(it);
				break;
			}
		}
		GObject* obj = dynamic_cast<GObject*>(target);
		CC_ASSERT(obj);
		obj->removeRelationObserver(this);
	}

	void Relations::clearAll(){
		for (auto it = _items.begin(); it != _items.end(); ++it){
			GObject* obj = dynamic_cast<GObject*>((*it)->getTarget());
			obj->removeRelationObserver(this);
		}
		_items.clear();
	}

	void Relations::copyFrom(const Relations& source){
		clearAll();
		for (auto it = source._items.begin(); it != source._items.end(); ++it){
			RelationItem* item = new RelationItem(_owner);
			item->copyFrom(**it);
			_items.push_back(item);
			GObject* obj = dynamic_cast<GObject*>(item->getTarget()); 
			obj->addRelationObserver(this);
		}
	}

	void Relations::onOwnerSizeChanged(const cocos2d::Size& oldSize, const cocos2d::Size& newSize) {
		cocos2d::Vec2 p1 = _owner->getPosition();
		for (auto it = _items.begin(); it != _items.end(); ++it) {
			(*it)->applySelfSizeChanged(oldSize, newSize);
		}
		const cocos2d::Vec2& p2 = _owner->getPosition();
		if (!p1.equals(p2)) {
			GComponent* comp = dynamic_cast<GComponent*>(_owner->getParent());
			if (comp) {
				comp->onTransionPositionChanged(_owner, p2.x - p1.x, p2.y - p1.y);
			}
		}
	}

	void Relations::onTargetSizeChanged(cocos2d::Node* target, const cocos2d::Size& oldSize, const cocos2d::Size& newSize) {
		cocos2d::Vec2 p1 = _owner->getPosition();
		for (auto it = _items.begin(); it != _items.end(); ++it) {
			if ((*it)->getTarget() == target) {
				(*it)->onTargetSizeChanged(target, oldSize, newSize);
			}
		}
		const cocos2d::Vec2& p2 = _owner->getPosition();
		if (!p1.equals(p2)) {
			GComponent* comp = dynamic_cast<GComponent*>(_owner->getParent());
			if (comp) {
				comp->onTransionPositionChanged(_owner, p2.x - p1.x, p2.y - p1.y);
			}
		}
	}

	void Relations::onTargetPosisitonChanged(cocos2d::Node* target, const cocos2d::Vec2& oldPos, const cocos2d::Vec2& newPos) {
		cocos2d::Vec2 p1 = _owner->getPosition();
		for (auto it = _items.begin(); it != _items.end(); ++it) {
			if ((*it)->getTarget() == target) {
				(*it)->onTargetXYChanged(target, oldPos, newPos);
			}
		}
		const cocos2d::Vec2& p2 = _owner->getPosition();
		if (!p1.equals(p2)) {
			GComponent* comp = dynamic_cast<GComponent*>(_owner->getParent());
			if (comp) {
				comp->onTransionPositionChanged(_owner, p2.x - p1.x, p2.y - p1.y);
			}
		}
	}

	void Relations::onTargetExit(cocos2d::Node* target) {
		clearFor(target);
	}

	bool Relations::isEmpty() const{
		return _items.size() == 0;
	}

	void Relations::setup(ByteBuffer* buffer, bool parentToChild)
	{
		int cnt = buffer->ReadByte();
		cocos2d::Node* target;
		for (int i = 0; i < cnt; i++) {
			int targetIndex = buffer->ReadShort();
			if (targetIndex == -1) {
				target = _owner->getParent();
			}
			else if (parentToChild) {
				target = _owner->getChildren().at(targetIndex);
			}
			else {
				target = _owner->getParent()->getChildren().at(targetIndex);
			}

			int cnt2 = buffer->ReadByte();
			for (int j = 0; j < cnt2; j++) {
				RelationType rt = (RelationType)buffer->ReadByte();
				bool usePercent = buffer->ReadBool();
				add(target, rt, usePercent);
			}
		}
	}

	void Relations::setup(RelationInfo* info, bool parentToChild) {
		cocos2d::Node* target;
		for (size_t i = 0; i < info->targets.size(); ++i) {
			int targetIndex = info->targets[i]->targetIndex;
			if (targetIndex == -1) {
				target = _owner->getParent();
			}
			else if (parentToChild) {
				target = _owner->getChildren().at(targetIndex);
			}
			else {
				target = _owner->getParent()->getChildren().at(targetIndex);
			}
			auto& items = info->targets[i]->items;
			for (size_t j = 0; j < items.size(); j++) {
				RelationType rt = items[j]->type;
				bool usePercent = items[j]->usePercent;
				add(target, rt, usePercent);
			}
		}
	}

}