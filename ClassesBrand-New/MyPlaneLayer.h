#pragma once
#include "cocos2d.h"

USING_NS_CC;

enum Enum_Plane
{
	AIRPLANE = 1,
};
class MyPlaneLayer :public Layer 
{
public:
	static Scene * createScene();
	virtual bool init();//init初始化函数
	static MyPlaneLayer* create();//create静态函数，在其中设置单例，并调用init方法
public:
	static MyPlaneLayer* sharedPlane;
	void getPlaneSprite();
public:
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
};