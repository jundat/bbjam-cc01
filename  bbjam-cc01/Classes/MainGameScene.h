/*
 * MainGameScene.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#ifndef MAINGAMESCENE_H_
#define MAINGAMESCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class MainGameScene : public cocos2d::CCLayer
{
public:
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(MainGameScene);

private:
	CCSprite *m_sprBackground;
	void InitMap();
};

#endif /* MAINGAMESCENE_H_ */
