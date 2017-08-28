#pragma once
#include "cocos2d.h"
#include "EnemyInfo.h"

USING_NS_CC;

class Enemy : public Node
{
public:
	Enemy();//���캯��
	~Enemy();//��������
	virtual bool init();//��ʼ������
	CREATE_FUNC(Enemy);//create�����궨�壬ϵͳ�Ѿ�ʵ��
public:
	void setEnemyByType(EnemyType enType);//���õ��˵�����
	Sprite* getSprite();//ȡ���Ѿ������ĵ���
	int getLife();//��ȡ����ֵ
	void loseLife();//���ӵ����к�����ֵ����
	Rect getBoundingBox();//ȡ�õ��˵����װ����
	Point getcurPoint();//ȡ�õ��˵�λ��
private:
	Sprite *pEnemy;
	int nLife;
};