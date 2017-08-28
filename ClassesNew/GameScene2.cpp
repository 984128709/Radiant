#include "GameScene2.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
using namespace CocosDenshion;
bool GameScene2::init() {
	if (!Layer::init())
	{
		return false;
	}

}
Scene *  GameScene2::createScene() {
	auto scene = Scene::create();
	auto layer = GameScene2::create();
	scene->addChild(layer);
	return scene;
}