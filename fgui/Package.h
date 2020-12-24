#pragma once
#include "base/CCRef.h"
#include <unordered_map>
#include "FieldTypes.h"
#include <vector>

namespace cocos2d {
	class Node;
}

namespace fgui {
	class PkgItem;
	class ByteBuffer;
	class GObject;

	PkgItem* createPkgItem(PackageItemType type);

	class Package : public cocos2d::Ref {
	public:
		Package();
		~Package();
		virtual void retain();
		virtual void release();
		const std::string& getId() const { return _id; }
		const std::string& getName() const { return _name; }
		double getLastReleaseTime();
		const std::string& getAssetsPath();
		void addPkgItem(PkgItem* item);
		PkgItem* getPkgItemById(const std::string& id);
		PkgItem* getPkgItemByName(const std::string& id);
		cocos2d::Node* createNodeById(const std::string& id);
		cocos2d::Node* createNodeByName(const std::string& name);
		bool load(const std::string& file);
	private:
		bool load(ByteBuffer* buffer);
		cocos2d::Node* createNode(PkgItem* item);
	private:
		std::unordered_map<std::string, PkgItem*> _items;
		std::unordered_map<std::string, PkgItem*> _itemsByName;
		std::string _assetPath;
		std::string _id;
		std::string _name;
		std::vector<std::string> _strTable;
		double _lastReleaseTime;
	};

}