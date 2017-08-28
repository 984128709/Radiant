#pragma once
#ifndef GAME_SCENE_1
#define GAME_SCENE_1
#include "cocos2d.h"
#include "Bullet.h"
#include "MyPlaneLayer.h"
#include "EnemyLayer.h"	

USING_NS_CC;

enum EnBackground
{
	e_BackgroundA = 1,
	e_BackgroundB = 2,
};
using namespace cocos2d;
class GameScene1 :Layer {
public:
	virtual bool init();
	//��onEnterִ�����֮����ô˺���
	virtual void onEnterTransitionDidFinish();
	CREATE_FUNC(GameScene1);
	static Scene * createScene();
public:
	//����ÿ֡��������Ϸ
	void gameUpdate(float t);
	//�ӵ���ײ���
	bool bulletCollisionEnemy(Sprite* pBullet);
	//�ɻ���ײ���
	bool enemyCollisionPlane();
	//void menuCloseCallBack(Ref* ptr);
public:
	MyPlaneLayer *planeLayer;
	Bullet *bulletSprite;
	EnemyLayer *enemyLayer;

	int getRand(int start, int end);//��ȡ��start��end�������
};
#endif