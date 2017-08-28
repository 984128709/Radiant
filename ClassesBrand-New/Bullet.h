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
	Animation* f_createAnimate(int count, int fps);//创建子弹运行的动画
	void removeBullet(Node* pNode);//移除超出屏幕可视范围的子弹或者碰撞后的子弹清除
	void ShootBullet(float t);//发射子弹，在其中进行子弹的渲染和子弹的飞行动作

public:
	Vector <Sprite *>vecBullet;//子弹容器
	SpriteBatchNode* bulletBatchNode;//批次渲染节点
};

