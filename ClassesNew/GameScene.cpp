#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
#include "GameScene1.h"
#include "GameScene2.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace CocosDenshion;
bool GameScene::init() {
	if (!Layer::init())
	{
		return false;
	}
	auto rootNode = CSLoader::createNode("startScene.csb");

	addChild(rootNode);

	/**auto BossFight = static_cast<ui::Button*>(rootNode->getChildByName("Button_boss1"));
	BossFight->addClickEventListener(CC_CALLBACK_1(GameScene::menuCloseCallback, this));
	auto ClassicFight = static_cast<ui::Button*>(rootNode->getChildByName("Button_game1"));
    ClassicFight->addClickEventListener(CC_CALLBACK_1(GameScene::menuCloseCallback, this));

	BossFight->setTag(10);
	ClassicFight->setTag(11);
	**/
	auto radiant = static_cast<ui::Button*>(rootNode->getChildByName("Button_radiant"));
	radiant->addClickEventListener(CC_CALLBACK_1(GameScene::menuCloseCallback, this));

	radiant->setTag(12);
	return  true;
}

Scene *  GameScene::createScene() {
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

void GameScene::menuCloseCallback(Ref *ptr)
{
	MenuItem * nowItem = (MenuItem *)ptr;
	SimpleAudioEngine::getInstance()->playEffect("");
	switch (nowItem->getTag())
	{
	case 10:
		//Director::getInstance()->replaceScene(GameScene1::createScene());
		break;
	case 11:
		//Director::getInstance()->replaceScene(GameScene2::createScene());
		break;
	case 12:
		Director::getInstance()->replaceScene(HelloWorld::createScene());
		break;
	}
}