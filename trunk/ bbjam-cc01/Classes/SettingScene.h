/*
 * SettingScene.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 *		Edit: Long
 */

#ifndef SETTINGSCENE_H_
#define SETTINGSCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class SettingScene : public CCLayer
{
public:
	SettingScene();
	~SettingScene();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(SettingScene);

	void gotoMenu(CCObject* sender);

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	//virtual bool ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
};

#endif /* SETTINGSCENE_H_ */
