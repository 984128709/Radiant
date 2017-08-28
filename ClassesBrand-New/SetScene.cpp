#include "HelpScene.h"
#include "AboutScene1.h"
#include "SetScene.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace CocosDenshion;

bool SetScene::init() {
	if (!Layer::init())
	{
		return false;
	}
	auto rootNode = CSLoader::createNode("setScene.csb");
	addChild(rootNode);

	auto help = static_cast<ui::Button*>(rootNode->getChildByName("Button_help"));
	help->addClickEventListener(CC_CALLBACK_1(SetScene::menuCloseCallback, this));
	auto about = static_cast<ui::Button*>(rootNode->getChildByName("Button_about"));
	about->addClickEventListener(CC_CALLBACK_1(SetScene::menuCloseCallback, this));
	auto back = static_cast<ui::Button*>(rootNode->getChildByName("Button_back"));
	back->addClickEventListener(CC_CALLBACK_1(SetScene::menuCloseCallback, this));

	help->setTag(10);
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

Scene *  SetScene::createScene() {
	auto scene = Scene::create();
	auto layer = SetScene::create();
	scene->addChild(layer);
	return scene;
}

void SetScene::menuCloseCallback(Ref *ptr) {
	MenuItem * nowItem = (MenuItem *)ptr;
	SimpleAudioEngine::getInstance()->playEffect("");
	switch (nowItem->getTag())
	{
	case 10:
		Director::getInstance()->replaceScene(TransitionCrossFade::create(1, HelpScene::createScene()));
		break;
	case 11:
		Director::getInstance()->replaceScene(TransitionCrossFade::create(1, AboutScene1::createScene()));
		break;
	case 12:
		Director::getInstance()->replaceScene(TransitionCrossFade::create(1, HelloWorld::createScene()));
		break;
	}
}