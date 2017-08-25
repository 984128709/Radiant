#include "HelloWorldScene.h"
#include "GameScene.h"
#include "GameScene1.h"
#include "GameScene2.h"
#include "HelpScene.h"
#include "AboutScene.h"
#include "SetScene.h"
#include "SimpleAudioEngine.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace CocosDenshion;
using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
// on "init" you need to initialize your instance
bool HelloWorld::init()
{   /**
    // you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));
	closeItem->setTag(10);

	auto gameItem = MenuItemFont::create("Start", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	//auto gameItem2 = MenuItemFont::create("StartGame2", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	auto helpItem = MenuItemFont::create("Help", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	auto aboutItem = MenuItemFont::create("About", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	gameItem->setPosition(Point(origin.x + visibleSize.width / 2 - closeItem->getContentSize().width / 2, ));
	//gameItem2->setPosition(Point(origin.x + visibleSize.width / 2 - closeItem->getContentSize().width / 2, ));
	helpItem->setPosition(Point(origin.x + visibleSize.width / 2 - closeItem->getContentSize().width / 2, ));
	aboutItem->setPosition(Point(origin.x + visibleSize.width / 2 - closeItem->getContentSize().width / 2, ));
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
	gameItem->setTag(11);
	//gameItem2->setTag(12);
	helpItem->setTag(12);
	aboutItem->setTag(13);
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("menu.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);  
    **/
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene1.csb");

    addChild(rootNode);
	auto start = static_cast<ui::Button*>(rootNode->getChildByName("Button_start"));
	start->addClickEventListener(CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	auto set = static_cast<ui::Button*>(rootNode->getChildByName("Button_set"));
	set->addCCSEventListener(CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	auto help = static_cast<ui::Button*>(rootNode->getChildByName("Button_help"));
	help->addClickEventListener(CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	auto about = static_cast<ui::Button*>(rootNode->getChildByName("Button_about"));
	about->addClickEventListener(CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	start->setTag(10);
	set->setTag(11);
	help->setTag(12);
	about->setTag(13);
	return true;
}
void HelloWorld::menuCloseCallback(Ref *ptr)
{
	MenuItem * nowItem = (MenuItem *)ptr;
	SimpleAudioEngine ::getInstance()->playEffect("");
	switch (nowItem->getTag())
	{
	case 10:
		Director::getInstance()->replaceScene(GameScene::createScene());
		break;
	case 11:
		Director::getInstance()->replaceScene(TransitionFlipY::create(1, SetScene::createScene()));
		break;
	case 12:
		Director::getInstance()->replaceScene(TransitionFlipY::create(1, HelpScene::createScene()));
		break;
	case 13:
		Director::getInstance()->replaceScene(TransitionFlipY::create(1, AboutScene::createScene()));
		break;
	default:
		break;
	}
}