/*
 * LoadingScene.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#ifndef LOADINGSCENE_H_
#define LOADINGSCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class LoadingScene : public CCLayer
{
public:
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(LoadingScene);

private:
	CCSprite *m_sprLoading;
};

#endif /* LOADINGSCENE_H_ */
