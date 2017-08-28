#ifndef ABOUT_SCENE_1
#define ABOUT_SCENE_1
#include "cocos2d.h"
using namespace cocos2d;
class AboutScene1 :Layer {
public:
	bool init();
	CREATE_FUNC(AboutScene1);
	static Scene * createScene();
	void menuCloseCallback(Ref *ptr);
};
#endif