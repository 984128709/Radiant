#pragma once
#ifndef GAME_SCENE_1
#define GAME_SCENE_1
#include "cocos2d.h"
using namespace cocos2d;
class GameScene1 :Layer {
public:
	bool init();
	CREATE_FUNC(GameScene1);
	static Scene * createScene();
	void moveBackground(float t);//��������
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
	int px, py;//�ɻ�������
	Vector<Sprite *> allBullet;//�����ӵ�
	void newBullet(float t);
	void moveBullet(float t);
	Vector<Sprite *> allEnemy;//���ел�
	void newEnemy(float t);
	void moveEnemy(float t);
	void update(float t);
	int score;//����
	void newBomb(int x, int  y);//��ըЧ��
	void killMe(Node * pSender);//ɾ���Լ�
	void jumpToMenu();//��ת�����˵�
};
#endif