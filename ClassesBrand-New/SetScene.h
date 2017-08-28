#pragma once
#ifndef SET_SCENE
#define SET_SCENE
#include "cocos2d.h"
using namespace cocos2d;
class SetScene :Layer {
public:
	bool init();
	CREATE_FUNC(SetScene);
	static Scene * createScene();
	void menuCloseCallback(Ref *ptr);
};


#endif
