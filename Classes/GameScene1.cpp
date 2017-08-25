#include "GameScene1.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
using namespace CocosDenshion;
bool GameScene1::init() {
	if (!Layer::init())
	{
		return false;
	}
	//��ӱ�����
	auto spbk = Sprite::create("background4.png");
	spbk->setAnchorPoint(Point::ZERO);
	spbk->setPosition(Point::ZERO);
	this->addChild(spbk);
	spbk->setTag(10);
	auto spbk02 = Sprite::create("background4.png");
	spbk02->setAnchorPoint(Point::ZERO);
	spbk02->setPosition(Point::ZERO);
	spbk02->setPositionY(spbk->getPositionY() + 680);
	this->addChild(spbk02);
	spbk02->setTag(11);
	//��ӷ�����ʾ
	score = 0;
	auto labScore = Label::create("score:0", "Marker Felt", 20);
	labScore->setPosition();
	labScore->setColor();
	this->addChild(labScore);
	labScore->setTag(120);




	EventListenerTouchOneByOne * event = EventListenerTouchOneByOne::create();
	event->setSwallowTouches(true);
	event->onTouchBegan = CC_CALLBACK_2(GameScene1::onTouchBegan, this);
	event->onTouchMoved = CC_CALLBACK_2(GameScene1::onTouchMoved, this);
	event->onTouchEnded = CC_CALLBACK_2(GameScene1::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(event, this);

	//�ƻ�����
	//��������
	this->schedule(schedule_selector(GameScene1::moveBackground), 0.01);
	//�����ӵ�����
	this->schedule(schedule_selector(GameScene1::newBullet), 0.5);
	this->schedule(schedule_selector(GameScene1::moveBullet), 0.01);
	//����л��ķ���
	this->schedule(schedule_selector(GameScene1::newEnemy), 0.5);
	this->schedule(schedule_selector(GameScene1::moveEnemy), 0.01);
	//������ײ������Ϸ�߼�
	this->scheduleUpdate();
	//���ű�������
	SimpleAudioEngine::getInstance()->playBackgroundMusic("game.mp3", true);
	return true;
}
Scene *  GameScene1::createScene() {
	auto scene = Scene::create();
	auto layer = GameScene1::create();
	scene->addChild(layer);
	return scene;
}
void  GameScene1::moveBackground(float t)//��������
{
	auto spbk = this->getChildByTag(10);
	auto spbk02 = this->getChildByTag(11);
	spbk->setPositionY(spbk->getPositionY() - 1);
	if (spbk->getPositionY()<-680)
	{
		spbk->setPositionY(0);
	}
	spbk02->setPositionY(spbk->getPositionY() + 680);
}
bool GameScene1::onTouchBegan(Touch *touch, Event *unused_event) {
	px = touch->getLocation().x;
	py = touch->getLocation().y;
	return true;
}
void GameScene1::onTouchMoved(Touch *touch, Event *unused_event) {
	int mx = (touch->getLocation().x - px);
	int my = (touch->getLocation().y - py);
	auto spPlane = this->getChildByTag(110);
	spPlane->runAction(MoveBy::create(0, Point(mx, my)));
	px = touch->getLocation().x;
	py = touch->getLocation().y;
}
void GameScene1::onTouchEnded(Touch *touch, Event *unused_event) {

}
void  GameScene1::newBullet(float t) {
	auto spPlane = this->getChildByTag(110);
	Sprite * bullet = Sprite::create("bullet3.png");
	bullet->setPosition(spPlane->getPosition());
	this->addChild(bullet);
	this->allBullet.pushBack(bullet);
}
void  GameScene1::moveBullet(float t) {

	//for (auto nowbullet:allBullet)
	for (int i = 0; i<allBullet.size(); i++)
	{
		auto nowbullet = allBullet.at(i);
		nowbullet->setPositionY(nowbullet->getPositionY() + 3);
		if (nowbullet->getPositionY()>Director::getInstance()->getWinSize().height)
		{
			nowbullet->removeFromParent();
			allBullet.eraseObject(nowbullet);
			i--;
		}
	}
}
void  GameScene1::newEnemy(float t) {

	Sprite * enemy = nullptr;
	int num = rand() % 10;
	if (num >= 3)
	{
		enemy = Sprite::create("aaa.png");
		enemy->setTag(1000);
	}
	else
	{
		enemy = Sprite::create("ccc.png");
		enemy->setTag(2000);
	}
	enemy->setPosition(Point(rand() % 300 + 10, 500));
	this->addChild(enemy);
	this->allEnemy.pushBack(enemy);
}
void  GameScene1::moveEnemy(float t) {

	for (int i = 0; i<allEnemy.size(); i++)
	{
		auto nowenemy = allEnemy.at(i);
		nowenemy->setPositionY(nowenemy->getPositionY() - 3);
		if (nowenemy->getPositionY()<0)
		{
			nowenemy->removeFromParent();
			allEnemy.eraseObject(nowenemy);
			i--;
		}
	}
}
void GameScene1::update(float t) {

	//��ײ���
	auto spPlane = this->getChildByTag(110);
	Rect rp(spPlane->getPositionX(), spPlane->getPositionY(), 47, 56);
	for (int i = 0; i<allEnemy.size(); i++)
	{
		auto nowenemy = allEnemy.at(i);
		Rect er(nowenemy->getPositionX(), nowenemy->getPositionY(), 40, 50);
		//�ͷɻ���ײ���
		if (rp.intersectsRect(er))
		{
			// //��ըЧ�� 
			newBomb(spPlane->getPositionX(), spPlane->getPositionY());
			//�л���ʧ
			nowenemy->removeFromParent();
			allEnemy.eraseObject(nowenemy);
			i--;
			//��������
			SimpleAudioEngine::getInstance()->playEffect("explo.wav");
			//��ת��GAMEOVER
			//Director::getInstance()->getActionManager()->pauseAllRunningActions();
			this->pauseSchedulerAndActions();
			auto spover = Sprite::create("end.png");
			spover->setPosition(Point::ZERO);
			spover->setAnchorPoint(Point::ZERO);
			this->addChild(spover);
			auto act = Sequence::create(
				DelayTime::create(2),
				CallFunc::create(this, callfunc_selector(GameScene1::jumpToMenu)),
				NULL
			);
			this->runAction(act);
		}
		//���ӵ���ײ���
		for (int j = 0; j<allBullet.size(); j++)
		{
			auto nowbullet = allBullet.at(j);
			Rect br(nowbullet->getPositionX(), nowbullet->getPositionY(), 20, 20);
			if (er.intersectsRect(br))
			{//�ӵ������˵л�
				Label * labScore = (Label*)this->getChildByTag(120);
				score += nowenemy->getTag();
				//��ըЧ�� 
				newBomb(nowbullet->getPositionX(), nowbullet->getPositionY());
				//����ϵͳ
				auto ps = ParticleSystemQuad::create("bomb.plist");
				ps->setPosition(Point(nowbullet->getPositionX(), nowbullet->getPositionY()));
				this->addChild(ps);
				//�ӷ�
				labScore->setString(String::createWithFormat("score:%d", score)->_string);
				//�ӵ���ʧ
				nowbullet->removeFromParent();
				allBullet.eraseObject(nowbullet);
				//�л���ʧ
				nowenemy->removeFromParent();
				allEnemy.eraseObject(nowenemy);
				i--;
				//��������
				SimpleAudioEngine::getInstance()->playEffect("explo.wav");

				break;

			}

		}
	}
}
void GameScene1::newBomb(int x, int  y)//��ըЧ��
{
	Vector<SpriteFrame*> allframe;
	for (int i = 0; i<7; i++)
	{
		SpriteFrame * sf = SpriteFrame::create("boom.png", Rect(i * 44, 0, 44, 47));
		allframe.pushBack(sf);
	}
	Animation * ani = Animation::createWithSpriteFrames(allframe, 0.03);
	auto sprite = Sprite::create();
	Action * act = Sequence::create(
		Animate::create(ani),  //����
		CCCallFuncN::create(sprite, callfuncN_selector(GameScene1::killMe)), //ɾ���Լ�
		NULL);
	this->addChild(sprite);
	sprite->setPosition(Point(x, y));
	sprite->runAction(act);

}
void GameScene1::killMe(Node * pSender)//ɾ���Լ�
{
	pSender->removeFromParentAndCleanup(true);
}
void GameScene1::jumpToMenu()//��ת�����˵�
{

	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	Director::getInstance()->replaceScene(HelloWorld::createScene());
}