#pragma once
#ifndef ABOUT_SCENE_2
#define ABOUT_SCENE_2
#include "cocos2d.h"
using namespace cocos2d;
class AboutScene2 :Layer {
public:
	bool init();
	CREATE_FUNC(AboutScene2);
	static Scene * createScene();
	void menuCloseCallback(Ref *ptr);
};
#endif