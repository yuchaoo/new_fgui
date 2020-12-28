#include "TestScene.h"
#include "PackageManager.h"
#include "UIPackage.h"
#include "UIConfig.h"
#include "GProgressBar.h"
#include "Package.h"
#include "GLoader.h"
#include "GButton.h"
#include "Controller.h"
#include "TweenManager.h"
#include "GTweener.h"
#include "GList.h"
using namespace fgui;
using namespace cocos2d;

bool TestScene::init() {
	Scene::init();

	UIConfig::registerFont("Dutch801", "res/Dutch801.ttf");
	UIConfig::defaultFont = "Dutch801";

	auto pkgMgr = PackageManager::getInstance();
	const cocos2d::Size& winSize = Director::getInstance()->getWinSize();
	
	
	pkgMgr->createPkg("font", "res/font");
	pkgMgr->loadPackage("font", "res/font");

	UIPackage* uipkg = pkgMgr->loadPackage("main", "res/main");
	Package* package = pkgMgr->createPkg("main", "res/main");
	
	

	/*cocos2d::Node* uiNode = uipkg->createObjectByName("com1");
	uiNode->setAnchorPoint(cocos2d::Vec2(0, 0));
	uiNode->setPosition(cocos2d::Vec2(0, 0));
	addChild(uiNode);*/

	cocos2d::Node* node = package->createNodeByName("com1");
	cocos2d::Vec2 ap = node->getAnchorPoint();
	node->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
	node->setIgnoreAnchorPointForPosition(false);
	node->setPosition(cocos2d::Vec2(winSize.width / 2, winSize.height / 2));
	addChild(node);

	GComponent* comp = dynamic_cast<GComponent*>(node);
	GController* controller = comp->getController("c1");
	
	GComponent* comp1 = dynamic_cast<GComponent*>(node->getChildByName("n24"));
	GProgressBar* bar = dynamic_cast<GProgressBar*>(node->getChildByName("n25"));

	/*GButton* button1 = dynamic_cast<GButton*>(node->getChildByName("n17"));
	button1->setClickListener([button1, comp1, bar]() {
		const cocos2d::Size& size = comp1->getContentSize();
		GTweener* tweener = TweenManager::getInstance()->createTween();
		//tweener->setTarget(comp1, fgui::TweenPropType::Size);
		//tweener->toVec2(cocos2d::Vec2(size.width, size.height), cocos2d::Vec2(size.width + 50, size.height + 50), 0.3f);

		tweener = TweenManager::getInstance()->createTween();
		tweener->setTarget(bar, fgui::TweenPropType::Progress);
		tweener->toValue(0, 100, 0.5f);
	});*/

	GList* list = dynamic_cast<GList*>(node->getChildByName("n37"));
	list->setVirtual();
	list->setVirtualItemCount(100);

	/*Sprite* sprite = cocos2d::Sprite::create("res/header/icon.png");
	sprite->setPosition(300, 300);
	cocos2d::Texture2D::TexParams param{ GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };
	sprite->getTexture()->setTexParameters(param);
	sprite->setTextureRect(cocos2d::Rect(0, 0, 200, 300));
	addChild(sprite);*/

	/*GLoader* loader = dynamic_cast<GLoader*>(node->getChildByName("n15"));
	loader->setFillMethod(FillMethod::Radial90);
	loader->setFillOrigin(FillOrigin::LeftBottom);
	loader->setFillAmount(0.5f);*/

	/*cocos2d::Label* label = cocos2d::Label::createWithTTF("dddddddddddddddd...","res/Dutch801.ttf", 12);
	//cocos2d::Label* label = cocos2d::Label::createWithBMFont("res/Font1.fnt", "1111222222222222");

	label->setPosition(winSize.width / 2, winSize.height / 2 + 100);
	
	label->setHorizontalAlignment(cocos2d::TextHAlignment::LEFT);
	label->setVerticalAlignment(cocos2d::TextVAlignment::CENTER);
	label->setDimensions(50, 100);
	addChild(label);

	const cocos2d::Size& labelSize = label->getContentSize();
	auto layer = cocos2d::LayerColor::create(cocos2d::Color4B(255, 255, 0, 128), labelSize.width, labelSize.height);
	layer->setAnchorPoint(cocos2d::Vec2(0.5f, 0.5f));
	layer->setIgnoreAnchorPointForPosition(false);
	layer->setPosition(winSize.width / 2, winSize.height / 2 + 100);
	addChild(layer);*/

	//cocos2d::Size nodeSize = node->getContentSize();
	//auto layer = cocos2d::LayerColor::create(cocos2d::Color4B(255, 0, 0, 128), nodeSize.width, nodeSize.height);
	//node->addChild(layer);

	//fgui::GProgressBar* expBar = dynamic_cast<fgui::GProgressBar*>( node->getChildByName("n21") );
	//expBar->setValue(50);
	 
	return true;
}