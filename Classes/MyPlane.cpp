#include "MyPlane.h"
#include "Bullet.h"
#include "base/CCEventKeyboard.h"

using namespace cocos2d;

USING_NS_CC;
/**
* ��̬����������ʼ��
*/
MyPlane *MyPlane::sharedPlane = NULL;
/**
* ���������������MyPlane��
*/
Scene* MyPlane::createScene() {
	auto scene = Scene::create();
	auto layer = MyPlane::create();
	scene->addChild(layer);
	return scene;
}
/**
* �����㣬���������Ĳ㸳ֵ����������
*/
MyPlane* MyPlane ::create() {
	MyPlane *pRet = new MyPlane();
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
bool MyPlane::init() {
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

	//���ô������麯��
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