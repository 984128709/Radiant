#pragma once
#ifndef GAME_SCENE_2
#define GAME_SCENE_2
#include "cocos2d.h"
using namespace cocos2d;
class GameScene2 :Layer{
public:
	bool init();
	CREATE_FUNC(GameScene2);
	static Scene * createScene();
	void moveBackground(float t);//¹ö¶¯±³¾°
};
#endif