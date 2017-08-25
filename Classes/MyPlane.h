#pragma once
#include "cocos2d.h"

USING_NS_CC;

enum Enum_Plane
{
	AIRPLANE = 1,
};
class MyPlane :public Layer 
{
public:
	static Scene * createScene();
	virtual bool init();//init��ʼ������
	static MyPlane* create();//create��̬���������������õ�����������init����
public:
	static MyPlane* sharedPlane;
	void getPlane();
public:
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
};