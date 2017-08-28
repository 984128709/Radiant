#include "MyPlaneLayer.h"
#include "Bullet.h"
#include "base/CCEventKeyboard.h"

using namespace cocos2d;

USING_NS_CC;
/**
* ��̬����������ʼ��
*/
MyPlaneLayer *MyPlaneLayer::sharedPlane = NULL;
/**
* ���������������MyPlane��
*/
Scene* MyPlaneLayer::createScene() {
	auto scene = Scene::create();
	auto layer = MyPlaneLayer::create();
	scene->addChild(layer);
	return scene;
}
/**
* �����㣬���������Ĳ㸳ֵ����������
*/
MyPlaneLayer* MyPlaneLayer ::create() {
	MyPlaneLayer *pRet = new MyPlaneLayer();
	if (pRet && pRet->init()) {
		pRet->autorelease();
		sharedPlane = pRet;//��ֵ����������
		return pRet;
	}
	else {
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}
bool MyPlaneLayer::init() {
	if (!Layer::init()) {
		return false;
	}
	/**
	* ���ػ�����ͼƬ��ͼƬ��TexturePacker���д������
	* �������ɵ�plist�ļ���Ҳ��xml�ļ�
	* SpriteFrameCache����������plist�еļ�ֵ��Ӧ��ͼƬ���м��ز����浽ϵͳ��
	* ����ӻ����л�ȡ��ӦͼƬ
	*/
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("bullet.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("plane.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boom.plist");
	

	//���ô������麯��
	getPlaneSprite();
	return true;
}

void MyPlaneLayer::getPlaneSprite()
{
	Size winSize = Director::getInstance()->getWinSize();
	auto plane = Sprite::create("plane0.png");
	plane->setTag(AIRPLANE);
	plane->setScale(0.7f);
	plane->setPosition(Point(winSize.width / 2 - plane->getContentSize().width / 2, winSize.height / 7));
	this->addChild(plane);
	auto keyListener = EventListenerKeyboard::create();
	keyListener->setEnabled(true);
	keyListener->onKeyPressed = CC_CALLBACK_2(MyPlaneLayer::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(MyPlaneLayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
};

void  MyPlaneLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());

};

void MyPlaneLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{

};