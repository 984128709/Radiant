#include "HelpScene.h"
#include "AboutScene.h"
#include "SetScene.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace CocosDenshion;

bool HelpScene::init() {
	if (!Layer::init())
	{
		return false;
	}
	auto rootNode = CSLoader::createNode("HelpScene.csb");
	addChild(rootNode);

	auto set = static_cast<ui::Button*>(rootNode->getChildByName("Button_set"));
	set->addClickEventListener(CC_CALLBACK_1(HelpScene::menuCloseCallback, this));
	auto about = static_cast<ui::Button*>(rootNode->getChildByName("Button_about"));
	about->addClickEventListener(CC_CALLBACK_1(HelpScene::menuCloseCallback, this));
	auto back = static_cast<ui::Button*>(rootNode->getChildByName("Button_back"));
	back->addClickEventListener(CC_CALLBACK_1(HelpScene::menuCloseCallback, this));

	set->setTag(10);
	about->setTag(11);
	back->setTag(12);

	/**auto help = Sprite::create("help.png");
	help->setPosition(Point::ZERO);
	help->setAnchorPoint(Point::ZERO);
	this->addChild(help);
	/**EventListenerTouchOneByOne * touch = EventListenerTouchOneByOne::create();
	touch->onTouchBegan = [](Touch * touch, Event * event) {
		return true;
	};
	touch->onTouchMoved = [](Touch * touch, Event * event) {
		Director::getInstance()->replaceScene(HelloWorld::createScene());
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);**/
	return true;
}

Scene *  HelpScene::createScene() {
	auto scene = Scene::create();
	auto layer = HelpScene::create();
	scene->addChild(layer);
	return scene;
}

void HelpScene::menuCloseCallback(Ref *ptr) {
	MenuItem * nowItem = (MenuItem *)ptr;
	SimpleAudioEngine::getInstance()->playEffect("");
	switch (nowItem->getTag())
	{
	case 10:
		Director::getInstance()->replaceScene(TransitionFlipY::create(1, SetScene::createScene()));
		break;
	case 11:
		Director::getInstance()->replaceScene(TransitionFlipY::create(1, AboutScene::createScene()));
		break;
	case 12:
		Director::getInstance()->replaceScene(TransitionFlipY::create(1, HelloWorld::createScene()));
		break;
	}
}