#pragma once
#include "UIPackage.h"

namespace fgui {
	class Package;

	class PackageManager : cocos2d::Ref {
	public:
		static PackageManager* getInstance();
		void init();
		UIPackage* getPackageById(const std::string& id);
		UIPackage* getPackageByName(const std::string& name);
		UIPackage* loadPackage(const std::string& name,const std::string& filepath);
		UIPackage* createPackage(const std::string& filepath);
		void removePackage(const std::string& name);
		bool parseURL(const std::string& url, std::string& pkgName, std::string& itemName, bool& isById);
		cocos2d::Node* createObject(const std::string& pkgName, const std::string& itemName);
		cocos2d::Node* createObjectByURL(const std::string& url);
		PackageItem* getPackageItemByURL(const std::string& url);

		Package* getPkg(const std::string& id);
		Package* getPkgByName(const std::string& name);
		Package* createPkg(const std::string& name, const std::string& filepath);
		PkgItem* getItemByUrl(const std::string& url);
		cocos2d::Node* createNodeByUrl(const std::string& url);
		cocos2d::Node* createNodeByName(const std::string& pkgName, const std::string& itemName);
		cocos2d::Node* createNodeById(const std::string& pkgId, const std::string& itemId);
	private:
		
	private:
		std::vector<UIPackage*> m_packages;
		std::unordered_map<std::string, UIPackage*> m_pkgById;
		std::unordered_map<std::string, UIPackage*> m_pkgByName;
		std::unordered_map<std::string, Package*> _pkgs;
		std::unordered_map<std::string, Package*> _pkgsByName;
	};
}