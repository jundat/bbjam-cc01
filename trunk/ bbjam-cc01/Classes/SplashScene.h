/*
 * SplashScene.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#ifndef SPLASHSCENE_H_
#define SPLASHSCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class SplashScene : public cocos2d::CCLayer
{
public:
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(SplashScene);

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
//	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
//	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
//	virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
};

#endif /* SPLASHSCENE_H_ */
