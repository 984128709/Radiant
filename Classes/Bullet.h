#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Bullet :public Layer
{
public:
	Bullet();
	~Bullet();
	virtual bool init();
	CREATE_FUNC(Bullet);
	Animation* f_createAnimate(int count, int fps);//�����ӵ����еĶ���
	void removeBullet(Node* pNode);//�Ƴ�������Ļ���ӷ�Χ���ӵ�������ײ����ӵ����
	void ShootBullet(float t);//�����ӵ��������н����ӵ�����Ⱦ���ӵ��ķ��ж���

public:
	Vector <Sprite *>vecBullet;//�ӵ�����
	SpriteBatchNode* bulletBatchNode;//������Ⱦ�ڵ�
};

