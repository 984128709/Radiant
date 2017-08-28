#include "AboutScene1.h"
#include "AboutScene2.h"
#include "SetScene.h"
#include "HelpScene.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace CocosDenshion;

bool AboutScene1::init() {
	if (!Layer::init())
	{
		return false;
	}
	/**auto about = Sprite::create("about.png");
	about->setPosition(Point::ZERO);
	about->setAnchorPoint(Point::ZERO);
	this->addChild(about);
	EventListenerTouchOneByOne * touch = EventListenerTouchOneByOne::create();
	touch->onTouchBegan = [](Touch * touch, Event * event) {
		return true;
	};
	touch->onTouchMoved = [](Touch * touch, Event * event) {
		Director::getInstance()->replaceScene(HelloWorld::createScene());
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);**/
	auto rootNode = CSLoader::createNode("aboutScene1.csb");
	addChild(rootNode);
	
	auto set = static_cast<ui::Button*>(rootNode->getChildByName("Button_set"));
	set->addClickEventListener(CC_CALLBACK_1(AboutScene1::menuCloseCallback, this));
	auto help = static_cast<ui::Button*>(rootNode->getChildByName("Button_help"));
	help->addClickEventListener(CC_CALLBACK_1(AboutScene1::menuCloseCallback, this));
	auto back = static_cast<ui::Button*>(rootNode->getChildByName("Button_back"));
	back->addClickEventListener(CC_CALLBACK_1(AboutScene1::menuCloseCallback, this));
	auto game = static_cast<ui::Button*>(rootNode->getChildByName("Button_game"));
	game->addClickEventListener(CC_CALLBACK_1(AboutScene1::menuCloseCallback, this));

	set->setTag(10);
	help->setTag(11);
	back->setTag(12);
	game->setTag(13);
	
	return true;
}

Scene *  AboutScene1::createScene() {
	auto scene = Scene::create();
	auto layer = AboutScene1::create();
	scene->addChild(layer);
	return scene;
}

void AboutScene1::menuCloseCallback(Ref *ptr) {
	MenuItem * nowItem = (MenuItem *)ptr;
	SimpleAudioEngine::getInstance()->playEffect("");
	switch (nowItem->getTag())
	{
	case 10:
		Director::getInstance()->replaceScene(TransitionCrossFade::create(1, SetScene::createScene()));
		break;
	case 11:
		Director::getInstance()->replaceScene(TransitionCrossFade::create(1, HelpScene::createScene()));
		break;
	case 12:
		Director::getInstance()->replaceScene(TransitionCrossFade::create(1, HelloWorld::createScene()));
		break;
	case 13:
		Director::getInstance()->replaceScene(TransitionCrossFade::create(1, AboutScene2::createScene()));
	}
}