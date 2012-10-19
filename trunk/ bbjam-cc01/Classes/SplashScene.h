/*
 * SplashScene.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#ifndef SPLASHSCENE_H_
#define SPLASHSCENE_H_

#include "cocos2d.h"

class SplashScene : public cocos2d::CCLayer
{
public:
	virtual bool init();
	static cocos2d::CCScene* scene();
	CREATE_FUNC(SplashScene);
};

#endif /* SPLASHSCENE_H_ */
