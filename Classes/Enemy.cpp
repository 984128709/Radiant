#include "Enemy.h"
#include "GameScene1.h"
#include "GameScene2.h"
 
using namespace cocos2d;

Enemy::Enemy() {}
Enemy::~Enemy() {}
/**
* ���ݵл�������������ͬ�ĵл�
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
	//���õл�������ֵ�λ��
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
* ȡ�ô����ĵл�����
*/
Sprite* Enemy::getSprite() {
	return pEnemy;
}
/**
* ȡ������ֵ
*/
int Enemy::getLife() {
	return nLife;
}
/**
* ����ֵ���٣�ÿ�α����м���50
*/
void Enemy::loseLife() {
	nLife = nLife - 50;
}
/**
* ȡ�����ڵ�λ��
*/
Point Enemy::getcurPoint() {
	return this->getPosition();
}
/**
* ��ȡ���װ����
*/
Rect Enemy::getBoundingBox() {
	Rect rect = pEnemy->boundingBox();
	Point pos = this->convertToWorldSpace(rect.origin);
	Rect enemyRect(pos.x, pos.y, rect.size.width, rect.size.height);
	return enemyRect;
}