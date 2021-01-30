#pragma once
#include "base/CCRef.h"
#include <string>
#include <unordered_map>
namespace fgui {
	class Package;
	class PkgItem;

	class PackageManager : cocos2d::Ref {
	public:
		static PackageManager* getInstance();
		void init();
		bool parseURL(const std::string& url, std::string& pkgName, std::string& itemName, bool& isById);
		Package* getPkg(const std::string& id);
		Package* getPkgByName(const std::string& name);
		Package* createPkg(const std::string& name, const std::string& filepath);
		PkgItem* getItemByUrl(const std::string& url);
		cocos2d::Node* createNodeByUrl(const std::string& url);
		cocos2d::Node* createNodeByName(const std::string& pkgName, const std::string& itemName);
		cocos2d::Node* createNodeById(const std::string& pkgId, const std::string& itemId);
	private:
		std::unordered_map<std::string, Package*> _pkgs;
		std::unordered_map<std::string, Package*> _pkgsByName;
	};
}