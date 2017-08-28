
#include "GameScene1.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"

using namespace CocosDenshion;

Scene *  GameScene1::createScene() {
	auto scene = Scene::create();
	auto layer = GameScene1::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene1::init() {
	if (!Layer::init())
	{
		return false;
	}
	this->setKeyboardEnabled(true);//设置层中可键盘控制
	Size winSize = Director::getInstance()->getWinSize();
	/**planeLayer = MyPlaneLayer::create();
	this->addChild(planeLayer);
	bulletSprite = Bullet::create();
	this->addChild(bulletSprite);
	enemyLayer = EnemyLayer::create();
	this->addChild(enemyLayer);**/
	/**
	* 随即加载背景图片，
	*/
	/**char buff[9];
	int id = getRand(1, 3);//返回1~3之间的随机数
	//std::string buff = StringUtils::format("bg_%d.png", id);
	sprintf(buff, "bg_%d.png", id);
	auto over = Sprite::create(buff);
	over->setPosition(Point(winSize.width / 2, winSize.height / 2));
	this->addChild(over);**/
	auto spbk = Sprite::create("bg_1.png");
	spbk->setAnchorPoint(Point::ZERO);
	spbk->setPosition(Point::ZERO);
	this->addChild(spbk);
	spbk->setTag(10);
	auto spbk02 = Sprite::create("bg_1.png");
	spbk02->setAnchorPoint(Point::ZERO);
	spbk02->setPosition(Point::ZERO);
	spbk02->setPositionY(spbk->getPositionY() + 680);
	this->addChild(spbk02);
	spbk02->setTag(11);
	return true;
}
/**
* 返回从start到end的随机整数
*/

void GameScene1::moveBackground(float t) {
	auto spbk = this->getChildByTag(10);
	auto spbk02 = this->getChildByTag(11);
	spbk->setPositionY(spbk->getPositionY() - 1);
	if (spbk->getPositionY()<-680)
	{
		spbk->setPositionY(0);
	}
	spbk02->setPositionY(spbk->getPositionY() + 680);
}

int GameScene1::getRand(int start, int end) {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	unsigned long int rand_seed = tv.tv_sec * 1000 + tv.tv_usec / 1000;//随机数种子
	srand(rand_seed);
	float i = CCRANDOM_0_1() * (end - start + 1) + start;
	return (int)i;
}

/**
* 在onEnter函数之后调用
* 功能：创建飞机、子弹、敌机并添加到层中
*/
void GameScene1::onEnterTransitionDidFinish() {
	planeLayer = MyPlaneLayer::create();
	this->addChild(planeLayer);
	bulletSprite = Bullet::create();
	this->addChild(bulletSprite);
	enemyLayer = EnemyLayer::create();
	this->addChild(enemyLayer);
	
	this->schedule(schedule_selector(GameScene1::gameUpdate));
	//添加menu，并设置回调函数
	/**Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create("CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(GameScene1::menuCloseCallBack, this));
	closeItem->setPosition(
		Point(
			origin.x + visibleSize.width
			- closeItem->getContentSize().width / 2,
			origin.y + closeItem->getContentSize().height / 2));
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);**/
};

/**void GameScene1::menuCloseCallBack(Ref* ptr) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif
	Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
};**/
/**
* 子弹和敌机碰撞检测函数
*/
bool GameScene1::bulletCollisionEnemy(Sprite* pBullet) {
	//遍历场景中的所有敌机，看子弹是否和敌机的包装矩形有重叠
	for (auto& eEnemy : enemyLayer->vecEnemy)
	{
		Enemy* pEnemySprite = (Enemy*)eEnemy;
		//判断矩形是否有重叠
		if (pBullet->boundingBox().intersectsRect(pEnemySprite->getBoundingBox()))
		{
			if (50 == pEnemySprite->getLife())
			{
				pEnemySprite->loseLife();
				enemyLayer->blowupEnemy(pEnemySprite);
			}
			else
			{
				pEnemySprite->loseLife();
			}
			//有重叠则移除子弹
			bulletSprite->removeBullet(pBullet);
			return true;
		}
	}
	return false;
};
/**
* 在每帧时都进行游戏逻辑检测，
* 检测子弹和敌机是否有碰撞
* 检测主角飞机和敌机是否有碰撞
*/
void GameScene1::gameUpdate(float t) {
	bool bMoveButt = false;
	for (auto& eBullet : bulletSprite->vecBullet)
	{
		Sprite* pBullet = (Sprite*) eBullet;
		bMoveButt = bulletCollisionEnemy(pBullet);
		if (bMoveButt)
		{
			return;
		}
	}
	enemyCollisionPlane();
}
/**
* 敌机和主角飞机是否有碰撞
* 遍历所有敌机进行检测
*/
bool GameScene1::enemyCollisionPlane() {
	Sprite* pPlane = (Sprite*)planeLayer->getChildByTag(AIRPLANE);
	for (auto& eEnemy : enemyLayer->vecEnemy)
	{
		Enemy* pEnemySprite = (Enemy*)eEnemy;
		if (pPlane->boundingBox().intersectsRect(pEnemySprite->getBoundingBox()) 
			&& pEnemySprite->getLife() > 0)
		{
			return true;
		}
	}
	return false;
}
