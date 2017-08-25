#include "MyPlane.h"
#include "Bullet.h"
#include "base/CCEventKeyboard.h"

using namespace cocos2d;

USING_NS_CC;
/**
* 静态单例变量初始化
*/
MyPlane *MyPlane::sharedPlane = NULL;
/**
* 创建场景，并添加MyPlane层
*/
Scene* MyPlane::createScene() {
	auto scene = Scene::create();
	auto layer = MyPlane::create();
	scene->addChild(layer);
	return scene;
}
/**
* 创建层，并将创建的层赋值给单例变量
*/
MyPlane* MyPlane ::create() {
	MyPlane *pRet = new MyPlane();
	if (pRet && pRet->init()) {
		pRet->autorelease();
		sharedPlane = pRet;//赋值给单例变量
		return pRet;
	}
	else {
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}
bool MyPlane::init() {
	if (!Layer::init()) {
		return false;
	}
	/**
	* 加载缓存类图片，图片用TexturePacker进行打包处理，
	* 加载生成的plist文件，也即xml文件
	* SpriteFrameCache缓存类会根据plist中的键值对应的图片进行加载并缓存到系统中
	* 方便从缓存中获取相应图片
	*/
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("bullet.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("plane.plist");

	//调用创建精灵函数
	getPlane();
	return true;
}

void MyPlane::getPlane()
{
	Size winSize = Director::getInstance()->getWinSize();
	auto plane = Sprite::create("plane0.png");
	plane->setTag(AIRPLANE);
	plane->setScale(0.7f);
	plane->setPosition(Point(winSize.width / 2 - plane->getContentSize().width / 2, winSize.height / 7));
	this->addChild(plane);
	auto keyListener = EventListenerKeyboard::create();
	keyListener->setEnabled(true);
	keyListener->onKeyPressed = CC_CALLBACK_2(MyPlane::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(MyPlane::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
};

void  MyPlane::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());

};

void MyPlane::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{

};