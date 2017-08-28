#include "EnemyLayer.h"
using namespace cocos2d;

EnemyLayer::EnemyLayer() {
}

EnemyLayer::~EnemyLayer() {
}
int EnemyLayer::score = 0;
bool EnemyLayer::init() {
	if (!Layer::init()) 
	{
		return false;
	}
	cocos2d::Vector<SpriteFrame*> vecTemp;
	vecTemp.clear();

	char buff[16];
	Animation* pAnimation1 = Animation::create();
	pAnimation1->setDelayPerUnit(0.1f);
	for (int id = 1; id <= 3; id++) 
	{
		sprintf(buff, "a_%.png", id);
		pAnimation1->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(buff));
	}
	AnimationCache::getInstance()->addAnimation(pAnimation1, "Enemy1Blowup");

	this->schedule(schedule_selector(EnemyLayer::addEnemy1), 1.0f);

	vecTemp.clear();
	for (int id = 1; id <= 3; id++) 
	{
		sprintf(buff, "b_%.png", id);
		vecTemp.pushBack(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(buff));
	}

	Animation *pAnimation2 = Animation::createWithSpriteFrames(vecTemp);
	pAnimation2->setDelayPerUnit(0.1f);
	AnimationCache::getInstance()->addAnimation(pAnimation2, "Enemy2Blowup");

	this->schedule(schedule_selector(EnemyLayer::addEnemy2), 3.0f);

	vecTemp.clear();
	for (int id = 1; id <= 3; id++) 
	{
		sprintf(buff, "c_%.png", id);
		vecTemp.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(buff));
	}
	Animation *pAnimation3 = Animation::createWithSpriteFrames(vecTemp);
	pAnimation3->setDelayPerUnit(0.1f);
	AnimationCache::getInstance()->addAnimation(pAnimation3, "Enemy3Blowup");

	this->schedule(schedule_selector(EnemyLayer::addEnemy3), 7.0f);

	vecTemp.clear();
	for (int id = 1; id <= 3; id++)
	{
		sprintf(buff, "d_%.png", id);
		vecTemp.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(buff));
	}
	Animation *pAnimation4 = Animation::createWithSpriteFrames(vecTemp);
	pAnimation4->setDelayPerUnit(0.1f);
	AnimationCache::getInstance()->addAnimation(pAnimation4, "Enemy4Blowup");

	this->schedule(schedule_selector(EnemyLayer::addEnemy4), 7.0f);

	vecTemp.clear();
	for (int id = 1; id <= 3; id++)
	{
		sprintf(buff, "e_%.png", id);
		vecTemp.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(buff));
	}
	Animation *pAnimation5 = Animation::createWithSpriteFrames(vecTemp);
	pAnimation5->setDelayPerUnit(0.1f);
	AnimationCache::getInstance()->addAnimation(pAnimation5, "Enemy5Blowup");

	this->schedule(schedule_selector(EnemyLayer::addEnemy5), 7.0f);

	vecTemp.clear();
	for (int id = 1; id <= 3; id++)
	{
		sprintf(buff, "f_%.png", id);
		vecTemp.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(buff));
	}
	Animation *pAnimation6 = Animation::createWithSpriteFrames(vecTemp);
	pAnimation6->setDelayPerUnit(0.1f);
	AnimationCache::getInstance()->addAnimation(pAnimation6, "Enemy6Blowup");

	this->schedule(schedule_selector(EnemyLayer::addEnemy6), 7.0f);

	vecTemp.clear();
	for (int id = 1; id <= 3; id++)
	{
		sprintf(buff, "g_%.png", id);
		vecTemp.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(buff));
	}
	Animation *pAnimation7 = Animation::createWithSpriteFrames(vecTemp);
	pAnimation7->setDelayPerUnit(0.1f);
	AnimationCache::getInstance()->addAnimation(pAnimation7, "Enemy7Blowup");

	this->schedule(schedule_selector(EnemyLayer::addEnemy7), 7.0f);

	return true;
}

void EnemyLayer::addEnemy1(float t) {
	Enemy *pEnemy = Enemy::create();
	pEnemy->setEnemyByType(Enemy1);
	pEnemy->setTag(Enemy1);
	this->addChild(pEnemy);
	vecEnemy.pushBack(pEnemy);
	auto actionMove = MoveTo::create(4.0f, Point(pEnemy->getPositionX(), 0 - pEnemy->getSprite()->getContentSize().height / 2));
	auto actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyLayer::removeEnemy, this));
	auto seq1 = Sequence::create(actionMove, actionDone, NULL);
	pEnemy->runAction(seq1);
}

void EnemyLayer::addEnemy2(float t) {
	Enemy *pEnemy = Enemy::create();
	pEnemy->setEnemyByType(Enemy2);
	pEnemy->setTag(Enemy2);
	this->addChild(pEnemy);
	vecEnemy.pushBack(pEnemy);

	auto actionMove = MoveTo::create(5.5f, Point(pEnemy->getPositionX(), 0 - pEnemy->getSprite()->getContentSize().height / 2));
	auto actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyLayer::removeEnemy, this));
	auto seq2 = Sequence::create(actionMove, actionDone, NULL);
	pEnemy->runAction(seq2);
}

void EnemyLayer::addEnemy3(float t) {
	Enemy *pEnemy = Enemy::create();
	pEnemy->setEnemyByType(Enemy3);
	pEnemy->setTag(Enemy3);
	this->addChild(pEnemy);
	vecEnemy.pushBack(pEnemy);

	auto actionMove = MoveTo::create(7.0f,
		Point(pEnemy->getPositionX(), 0 - pEnemy->getSprite()->getContentSize().height / 2));
	auto actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyLayer::removeEnemy, this));
	auto seq3 = Sequence::create(actionMove, actionDone, NULL);
	pEnemy->runAction(seq3);
}

void EnemyLayer::addEnemy4(float t) {

}

void EnemyLayer::addEnemy5(float t) {

}

void EnemyLayer::addEnemy6(float t) {

}

void EnemyLayer::addEnemy7(float t) {

}

void EnemyLayer::removeEnemy(Node *pNode) {
	Enemy* enemy = (Enemy*)pNode;
	if (enemy != NULL) {
		this->removeChild(enemy, true);
		vecEnemy.eraseObject(enemy);
	}
}

void EnemyLayer::blowupEnemy(Enemy* pEnemy) {
	Animation *pAnimation = NULL;
	Sprite *pmsprite = NULL;
	char *buff = NULL;
	if (Enemy1 == pEnemy->getTag()) {
		buff = "a_1.png";
		pAnimation = AnimationCache::getInstance()->getAnimation("Enemy1Blowup"); 
		setScore(ENEMY1_SCORE);
	}
	else if (Enemy2 == pEnemy->getTag()) {
		buff = "b_1.png";
		pAnimation = AnimationCache::getInstance()->getAnimation("Enemy2Blowup");
		setScore(ENEMY2_SCORE);
	}
	else if (Enemy3 == pEnemy->getTag()) {
		buff = "c_1.png";
		pAnimation = AnimationCache::getInstance()->getAnimation("Enemy3Blowup");
		setScore(ENEMY3_SCORE);
	}
	else if (Enemy4 == pEnemy->getTag())
	{
		buff = "d_1.png";
		pAnimation = AnimationCache::getInstance()->getAnimation("Enemy4Blowup");
		setScore(ENEMY4_SCORE);
	}
	else if (Enemy5 == pEnemy->getTag())
	{
		buff = "e_1.png";
		pAnimation = AnimationCache::getInstance()->getAnimation("Enemy5Blowup");
	}
	else if (Enemy6 == pEnemy->getTag())
	{
		buff = "f_1.png";
		pAnimation = AnimationCache::getInstance()->getAnimation("Enemy6Blowup");
	}
	else if (Enemy7 == pEnemy->getTag())
	{
		buff = "g_1.png";
		pAnimation = AnimationCache::getInstance()->getAnimation("Enemy7Blowup");
	}
	else {
		return;
	}
	pmsprite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(buff));

	Point newPos = pEnemy->getcurPoint();
	Animate *pAnimate = Animate::create(pAnimation);
	pmsprite->setPosition(newPos);
	this->addChild(pmsprite);

	CallFuncN* mactiondone = CallFuncN::create(CC_CALLBACK_0(EnemyLayer::removeAnimation, this, pmsprite));
	auto seq = Sequence::create(pAnimate, mactiondone, NULL);
	pmsprite->runAction(seq);
	removeEnemy(pEnemy);
	updateScore(score);
}

void EnemyLayer::removeAnimation(Node *pNode) {
	Sprite *sp = (Sprite *)pNode;
	this->removeChild(sp);
}
void EnemyLayer::setScore(int nScore) {
	score += nScore;
}
int EnemyLayer::getScore() {
	return score;
}
void EnemyLayer::updateScore(int score) {
}


