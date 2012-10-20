/*
 * AboutScene.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 		Edit: Long
 */

#ifndef ABOUTSCENE_H_
#define ABOUTSCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class AboutScene : public CCLayer 
{
public:
	AboutScene();
	~AboutScene();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(AboutScene);

	void gotoMenu(CCObject* sender);
};

#endif /* ABOUTSCENE_H_ */


