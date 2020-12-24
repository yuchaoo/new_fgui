#include "PackageManager.h"
#include "GObject.h"
#include "ccExtend.h"
#include "ccShaderEx.h"
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

	void PackageManager::init() {
		loadShaderEx();
	}

	UIPackage* PackageManager::getPackageById(const std::string& id) {
		auto iter = m_pkgById.find(id);
		return iter == m_pkgById.end() ? NULL : iter->second;
	}

	UIPackage* PackageManager::getPackageByName(const std::string& name) {
		auto iter = m_pkgByName.find(name);
		return iter == m_pkgByName.end() ? NULL : iter->second;
	}

	UIPackage* PackageManager::loadPackage(const std::string& name, const std::string& filepath) {
		auto iter = m_pkgByName.find(name);
		if (iter != m_pkgByName.end()) {
			return iter->second;
		}
		UIPackage* pkg = createPackage(filepath);
		if (pkg) {
			if (pkg->getName() != name) {
				CCLOG("The name(%s) is not same as package name(%s)",name.c_str(),pkg->getName().c_str());
			}
			auto it = m_pkgByName.find(pkg->getName());
			if (it == m_pkgByName.end()) {
				m_packages.push_back(pkg);
				m_pkgById[pkg->getId()] = pkg;
				m_pkgByName[pkg->getName()] = pkg;
				pkg->retain();
			}
		}
		return pkg;
	}

	UIPackage* PackageManager::createPackage(const std::string& filepath) {
		UIPackage* pkg = UIPackage::create();
		if (pkg->loadPackage(filepath)) {
			return pkg;
		}
		return NULL;
	}

	void PackageManager::removePackage(const std::string& name) {
		auto iter = m_pkgByName.find(name);
		if (iter != m_pkgByName.end()) {
			auto it = m_pkgById.find(iter->second->getId());
			if (it != m_pkgById.end()) {
				m_pkgById.erase(it);
			}

			for (auto it = m_packages.begin(); it != m_packages.end(); ++it) {
				if (*it == iter->second) {
					m_packages.erase(it);
					break;
				}
			}
			iter->second->release();
			m_pkgByName.erase(iter);
		}
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

	cocos2d::Node* PackageManager::createObject(const std::string& pkgName, const std::string& itemName) {
		UIPackage* pkg = getPackageByName(pkgName);
		if (!pkg) {
			CCLOG("Cannot find the package:%s", pkgName.c_str());
			return NULL;
		}
		return (cocos2d::Node*)pkg->createObjectByName(itemName);
	}

	cocos2d::Node* PackageManager::createObjectByURL(const std::string& url) {
		std::string pkgStr, itemStr;
		bool isById = false;
		if (parseURL(url, pkgStr, itemStr, isById)) {
			if (isById) {
				UIPackage* pkg = getPackageById(pkgStr);
				if (pkg) {
					cocos2d::Node* obj = pkg->createObjectById(itemStr);
					return obj;
				}
			}
			else {
				UIPackage* pkg = getPackageByName(pkgStr);
				if (pkg) {
					cocos2d::Node* obj = pkg->createObjectByName(itemStr);
					return obj;
				}
			}
		}
		return NULL;
	}

	PackageItem* PackageManager::getPackageItemByURL(const std::string& url) {
		std::string pkgStr, itemStr;
		bool isById = false;
		if (parseURL(url, pkgStr, itemStr, isById)) {
			if (isById) {
				UIPackage* pkg = getPackageById(pkgStr);
				if (pkg) {
					PackageItem* pt = pkg->getPackageItemById(itemStr);
					if (pt) {
						pkg->loadItemAsset(pt);
					}
					else {
						cocos2d::log("can not fint the url:%s",url.c_str());
					}
					return pt;
				}
			}
			else {
				UIPackage* pkg = getPackageByName(pkgStr);
				if (pkg) {
					PackageItem* pt = pkg->getPackageItemByName(itemStr);
					if (pt) {
						pkg->loadItemAsset(pt);
					}else{
						cocos2d::log("can not fint the url:%s", url.c_str());
					}
					return pt;
				}
			}
		}
		return NULL;
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
			Package* pkg = getPkg(pkgName);
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