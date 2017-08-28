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
	//在onEnter执行完成之后调用此函数
	virtual void onEnterTransitionDidFinish();
	CREATE_FUNC(GameScene1);
	static Scene * createScene();
public:
	//根据每帧来更新游戏
	void gameUpdate(float t);
	//子弹碰撞检测
	bool bulletCollisionEnemy(Sprite* pBullet);
	//飞机碰撞检测
	bool enemyCollisionPlane();
	//void menuCloseCallBack(Ref* ptr);
public:
	MyPlaneLayer *planeLayer;
	Bullet *bulletSprite;
	EnemyLayer *enemyLayer;

	int getRand(int start, int end);//获取从start到end的随机数
};
#endif