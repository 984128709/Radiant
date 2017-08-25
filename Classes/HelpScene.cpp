#include "HelpScene.h"
#include "HelloWorldScene.h"
bool HelpScene::init() {
	if (!Layer::init())
	{
		return false;
	}
	auto help = Sprite::create("help.png");
	help->setPosition(Point::ZERO);
	help->setAnchorPoint(Point::ZERO);
	this->addChild(help);
	EventListenerTouchOneByOne * touch = EventListenerTouchOneByOne::create();
	touch->onTouchBegan = [](Touch * touch, Event * event) {
		return true;
	};
	touch->onTouchMoved = [](Touch * touch, Event * event) {
		Director::getInstance()->replaceScene(HelloWorld::createScene());
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);
	return true;
}
Scene *  HelpScene::createScene() {
	auto scene = Scene::create();
	auto layer = HelpScene::create();
	scene->addChild(layer);
	return scene;
}