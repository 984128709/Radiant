#pragma once
#include "cocos2d.h"
#include "EnemyInfo.h"

USING_NS_CC;

class Enemy : public Node
{
public:
	Enemy();//构造函数
	~Enemy();//析构函数
	virtual bool init();//初始化函数
	CREATE_FUNC(Enemy);//create函数宏定义，系统已经实现
public:
	void setEnemyByType(EnemyType enType);//设置敌人的种类
	Sprite* getSprite();//取得已经创建的敌人
	int getLife();//获取生命值
	void loseLife();//被子弹击中后生命值减少
	Rect getBoundingBox();//取得敌人的外包装矩形
	Point getcurPoint();//取得敌人的位置
private:
	Sprite *pEnemy;
	int nLife;
};