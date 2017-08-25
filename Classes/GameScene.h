#pragma once
#ifndef GAME_SCENE
#define GAME_SCENE
#include "Enemy.h"
#include "MyPlane.h"
#include "Bullet.h"
#include "cocos2d.h"

using namespace cocos2d;
class GameScene :Layer {
public:
	bool init();
	CREATE_FUNC(GameScene);
	static Scene * createScene();
	//void menuCloseCallback(Ref *ptr);
public:
	int score;
};

#endif