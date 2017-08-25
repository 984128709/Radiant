#include "AboutScene.h"
#include "HelloWorldScene.h"
bool AboutScene::init() {
	if (!Layer::init())
	{
		return false;
	}
	auto about = Sprite::create("about.png");
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
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);
	return true;
}
Scene *  AboutScene::createScene() {
	auto scene = Scene::create();
	auto layer = AboutScene::create();
	scene->addChild(layer);
	return scene;
}