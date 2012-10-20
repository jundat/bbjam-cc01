/*
 * SplashScene.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 *		Edit: Long
 */

#ifndef SPLASHSCENE_H_
#define SPLASHSCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class SplashScene : public CCLayer
{
private:
	CCSprite* m_SprBox[3];
	CCSprite* m_SprLogo;
	CCSprite* m_SprBg;

	void fallBlock(CCNode* sender);

public:
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(SplashScene);

	SplashScene();
	virtual ~SplashScene();

	void gotoMenu(CCNode* sender);

	void update(float delta);
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
};

#endif /* SPLASHSCENE_H_ */
