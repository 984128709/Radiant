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
	virtual bool init();//init��ʼ������
	static MyPlaneLayer* create();//create��̬���������������õ�����������init����
public:
	static MyPlaneLayer* sharedPlane;
	void getPlaneSprite();
public:
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
};