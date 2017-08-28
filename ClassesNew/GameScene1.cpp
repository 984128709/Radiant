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
	this->setKeyboardEnabled(true);//���ò��пɼ��̿���
	Size winSize = Director::getInstance()->getWinSize();
	/**
	* �漴���ر���ͼƬ��
	*/
	char buff[9];
	int id = getRand(1, 3);//����1~3֮��������
	sprintf(buff, "bg_%d.png", id);
	auto over = Sprite::create(buff);
	over->setPosition(Point(winSize.width / 2, winSize.height / 2));
	this->addChild(over);
	return true;
}
/**
* ���ش�start��end���������
*/
int GameScene1::getRand(int start, int end) {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	unsigned long int rand_seed = tv.tv_sec * 1000 + tv.tv_usec / 1000;//���������
	srand(rand_seed);
	float i = CCRANDOM_0_1() * (end - start + 1) + start;
	return (int)i;
}
/**
* ��onEnter����֮�����
* ���ܣ������ɻ����ӵ����л�����ӵ�����
*/
void GameScene1::onEnterTransitionDidFinish() {
	planeLayer = MyPlaneLayer::create();
	this->addChild(planeLayer);
	bulletSprite = Bullet::create();
	this->addChild(bulletSprite);
	enemyLayer = EnemyLayer::create();
	this->addChild(enemyLayer);
	//����ÿ֡ʱ������gameUpdate����
	this->schedule(schedule_selector(GameScene1::gameUpdate));
};
/**
* �ӵ��͵л���ײ��⺯��
*/
bool GameScene1::bulletCollisionEnemy(Sprite* pBullet) {
	//���������е����ел������ӵ��Ƿ�͵л��İ�װ�������ص�
	for (auto& eEnemy : enemyLayer->vecEnemy)
	{
		Enemy* pEnemySprite = (Enemy*)eEnemy;
		//�жϾ����Ƿ����ص�
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
			//���ص����Ƴ��ӵ�
			bulletSprite->removeBullet(pBullet);
			return true;
		}
	}
	return false;
};
/**
* ��ÿ֡ʱ��������Ϸ�߼���⣬
* ����ӵ��͵л��Ƿ�����ײ
* ������Ƿɻ��͵л��Ƿ�����ײ
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
* �л������Ƿɻ��Ƿ�����ײ
* �������ел����м��
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
Scene *  GameScene1::createScene() {
	auto scene = Scene::create();
	auto layer = GameScene1::create();
	scene->addChild(layer);
	return scene;
}