#include "PackageManager.h"
#include "GObject.h"
#include "cocosext/ccExtend.h"
#include "cocosext/ccShaderEx.h"
#include "Package.h"

namespace fgui {
	PackageManager* PackageManager::getInstance() {
		static PackageManager* mgr = NULL;
		if (mgr == NULL) {
			mgr = new PackageManager();
			mgr->init();
		}
		return mgr;
	}

	PackageManager::PackageManager() {

	}

	PackageManager::~PackageManager() {
		for (auto iter = _pkgs.begin(); iter != _pkgs.end(); ++iter) {
			delete iter->second;
		}
	}

	void PackageManager::init() {
		
	}

	bool PackageManager::parseURL(const std::string& url, std::string& pkgName, std::string& itemName, bool& isById) {
		if (url.compare(0, 5, "ui://")) {
			CCLOG("Parse the url failed, url:%s",url.c_str());
			return false;
		}
		size_t pos = url.find('/', 5);
		if (pos == -1) {
			if (url.size() <= 13) {
				return false;
			}
			pkgName = url.substr(5, 8);
			itemName = url.substr(13);
			isById = true;
		}
		else {
			pkgName = url.substr(5, pos - 5);
			itemName = url.substr(pos + 1);
			isById = false;
		}
		return true;
	}

	Package* PackageManager::getPkg(const std::string& id) {
		auto iter = _pkgs.find(id);
		if (iter != _pkgs.end()) {
			return iter->second;
		}
		return NULL;
	}

	Package* PackageManager::getPkgByName(const std::string& name) {
		auto iter = _pkgsByName.find(name);
		if (iter != _pkgsByName.end()) {
			return iter->second;
		}
		return NULL;
	}

	Package* PackageManager::createPkg(const std::string& name, const std::string& filepath) {
		auto iter = _pkgsByName.find(name);
		if (iter != _pkgsByName.end()) {
			return iter->second;
		}
		Package* pkg = new Package();
		if (pkg->load(filepath)) {
			_pkgsByName[name] = pkg;
			_pkgs[pkg->getId()] = pkg;
			return pkg;
		}
		CCLOG("load pkg failed, file:%s",filepath.c_str());
		delete pkg;
		return NULL;
	}

	PkgItem* PackageManager::getItemByUrl(const std::string& url) {
		std::string pkgName, itemName;
		bool isById = false;
		if (!parseURL(url, pkgName, itemName, isById)) {
			CCLOG("parse url failed,%s", url.c_str());
			return NULL;
		}
		if (isById) {
			Package* pkg = getPkg(pkgName);
			if (pkg) {
				return pkg->getPkgItemById(itemName);
			}
		}
		else {
			Package* pkg = getPkgByName(pkgName);
			if (pkg) {
				return pkg->getPkgItemByName(itemName);
			}
		}
		CCLOG("can not find the item:%s",url.c_str());
		return NULL;
	}

	cocos2d::Node* PackageManager::createNodeByUrl(const std::string& url) {
		std::string pkgName, itemName;
		bool isById = false;
		if (!parseURL(url, pkgName, itemName, isById)) {
			CCLOG("parse url failed,%s",url.c_str());
			return NULL;
		}
		if (isById) {
			return createNodeById(pkgName, itemName);
		}
		else {
			return createNodeByName(pkgName, itemName);
		}
	}

	cocos2d::Node* PackageManager::createNodeByName(const std::string& pkgName, const std::string& itemName) {
		auto iter = _pkgsByName.find(pkgName);
		if (iter != _pkgsByName.end()) {
			return iter->second->createNodeByName(itemName);
		}
		CCLOG("can not find the pkg:%s",pkgName.c_str());
		return NULL;
	}

	cocos2d::Node* PackageManager::createNodeById(const std::string& pkgId, const std::string& itemId) {
		auto iter = _pkgs.find(pkgId);
		if (iter != _pkgs.end()) {
			return iter->second->createNodeById(itemId);
		}
		CCLOG("can not find the pkg:%s",pkgId.c_str());
		return NULL;
	}
}