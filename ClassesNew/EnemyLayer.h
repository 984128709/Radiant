#pragma once
#include "cocos2d.h"
#include "EnemyInfo.h"
#include "Enemy.h"

USING_NS_CC;

class EnemyLayer : public Layer 
{
public:
	EnemyLayer();
	~EnemyLayer();
	virtual bool init();
	CREATE_FUNC(EnemyLayer);

public:
	void addEnemy1(float t);
	void addEnemy2(float t);
	void addEnemy3(float t);
	void addEnemy4(float t);
	void addEnemy5(float t);
	void addEnemy6(float t);
	void addEnemy7(float t);


	void blowupEnemy(Enemy* pEnemySprite);
	void removeEnemy(Node *pNode);

	void setScore(int nScore);
	int  getScore();
	void updateScore(int score);

public:
	Vector<Enemy*> vecEnemy;
	static int score;
	LabelBMFont* scoreItem;

	void removeAnimation(Node *pNode);

};
