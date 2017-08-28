#include "Bullet.h"
#include "GameScene1.h"
#include "GameScene2.h"
#include "MyPlaneLayer.h"

using namespace cocos2d;

Bullet::Bullet() {
}
Bullet::~Bullet() {
}
bool Bullet::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Layer::init());
		Texture2D* texture = TextureCache::sharedTextureCache()->textureForKey("bullet.png");
		//����BatchNode�ڵ�
		bulletBatchNode = SpriteBatchNode::createWithTexture(texture);
		this->addChild(bulletBatchNode);
		//ÿ��0.2S����һ�η����ӵ�����
		this->schedule(schedule_selector(Bullet::ShootBullet), 0.2f);
		bRet = true;
	} while (0);
	return bRet;
}
void Bullet::ShootBullet(float t) {
	Size winSize = Director::getInstance()->getWinSize();
	auto PlanePos = MyPlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getPosition();
	//�ӻ����д����ӵ�
	auto spritebullet = Sprite::createWithSpriteFrameName("bullet0.png");
	//�������õ��ӵ���ӵ�BatchNode�н���������Ⱦ
	bulletBatchNode->addChild(spritebullet);

	//�жϷ�������·�

	//�������õ��ӵ���ӵ�����
	vecBullet.pushBack(spritebullet);
	Point bulletPos = (Point(PlanePos.x,
		PlanePos.y
		+ MyPlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getContentSize().height
		/ 2 )); 
	spritebullet->setPosition(bulletPos);
	spritebullet->setScale(0.4f);


	float flyLen = winSize.height - PlanePos.y;
	float flyVelocity = 320 / 1;//�����ٶȣ������Լ����ƣ�ÿ�����ߵ�����
	float realFlyDuration = flyLen / flyVelocity;//ʵ�ʷ��е�ʱ��


    //�ӵ����еľ����ʱ�䣬�ӷɻ�����ʼ���е���Ļ����
	auto actionMove = MoveTo::create(realFlyDuration,
		Point(bulletPos.x, winSize.height));
	//�ӵ�ִ���궯������к����ص��������Ƴ��ӵ�����
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(Bullet::removeBullet, this));


	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	spritebullet->runAction(sequence);


}
/**
* �Ƴ��ӵ������ӵ����������Ƴ���ͬʱҲ��SpriteBatchNode���Ƴ�
*/
void Bullet::removeBullet(Node* pNode) {
	if (NULL == pNode) {
		return;
	}
	Sprite* bullet = (Sprite*)pNode;
	this->bulletBatchNode->removeChild(bullet, true);
	vecBullet.eraseObject(bullet);
}


/**
* �ӻ����л�ȡ�ӵ�����ͼƬ�󴴽��ӵ����������շ��ش����õĶ���
*/
Animation* Bullet::f_createAnimate(int count, int fps) {
	char buff[16];
	Animation *panimation = Animation::create();
	panimation->setDelayPerUnit(1.0 / fps);
	for (int id = 1; id <= count; id++) {
		sprintf(buff, "bullet%d.png", id);
		panimation->addSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(buff));
	}
	return panimation;
}