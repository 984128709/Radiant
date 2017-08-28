#include "Enemy.h"
#include "GameScene1.h"
#include "GameScene2.h"
 
using namespace cocos2d;

Enemy::Enemy() {}
Enemy::~Enemy() {}
/**
* 根据敌机类型来创建不同的敌机
*/
void Enemy::setEnemyByType(EnemyType enType) {
	switch (enType) {
	case Enemy1:
		pEnemy = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Enemy1.png"));
		nLife = ENEMY1_MAXLIFE;
		break;
	case Enemy2:
		pEnemy = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Enemy2.png"));
		nLife = ENEMY2_MAXLIFE;
		break;
	case Enemy3:
		pEnemy = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Enemy3.png"));
		nLife = ENEMY3_MAXLIFE;
		break;
	case Enemy4:
		pEnemy = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Enemy4.png"));
		nLife = ENEMY4_MAXLIFE;
		break;
	case Enemy5:
		pEnemy = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Enemy5.png"));
		nLife = ENEMY5_MAXLIFE;
		break;
	case Enemy6:
		pEnemy = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Enemy6.png"));
		nLife = ENEMY6_MAXLIFE;
		break;
	case Enemy7:
		pEnemy = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Enemy7.png"));
		nLife = ENEMY7_MAXLIFE;
		break;
	default:
		return;
		break;
	}
	this->addChild(pEnemy);
	pEnemy->setScale(0.6f);
	Size winSize = Director::getInstance()->getWinSize();
	Size enemySize = pEnemy->getContentSize();
	//设置敌机随机出现的位置
	int minX = enemySize.width / 2;
	int maxX = winSize.width - enemySize.width / 2;
	int rangeX = maxX - minX;
	int actualX = (rand() % rangeX) + minX;
	this->setPosition(Point(actualX, winSize.height + enemySize.height / 2));
}
bool Enemy::init() {
	bool pRet = true;
	if (!Node::init()) {
		pRet = false;
	}
	return pRet;
}
/**
* 取得创建的敌机精灵
*/
Sprite* Enemy::getSprite() {
	return pEnemy;
}
/**
* 取得生命值
*/
int Enemy::getLife() {
	return nLife;
}
/**
* 生命值减少，每次被击中减少50
*/
void Enemy::loseLife() {
	nLife = nLife - 50;
}
/**
* 取得现在的位置
*/
Point Enemy::getcurPoint() {
	return this->getPosition();
}
/**
* 获取外包装矩形
*/
Rect Enemy::getBoundingBox() {
	Rect rect = pEnemy->boundingBox();
	Point pos = this->convertToWorldSpace(rect.origin);
	Rect enemyRect(pos.x, pos.y, rect.size.width, rect.size.height);
	return enemyRect;
}