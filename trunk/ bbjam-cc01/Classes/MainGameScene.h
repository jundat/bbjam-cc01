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
class Level;

class MainGameScene : public cocos2d::CCLayer
{
public:
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(MainGameScene);

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
private:
	CCSprite *m_sprBackground;
	CCPoint m_HelperPoint;
	Level *m_Level;
	void InitMap();
	void UpdateGravity();
	void update(float delta);
	void initSubMenu();

	CCMenuItem *m_miMegaBoxz;
	CCMenuItem *m_miSpiderBoxz;
	CCMenuItem *m_miRockBoxz;

	CCMenuItem *m_miPause;
	CCMenuItem *m_miReplay;
	CCMenuItem *m_miResume;
	CCMenuItem *m_miBackMenu;

	CCMenu *m_Menu;

	void onPause(CCObject* sender);
	void onReplay(CCObject* sender);
	void onResume(CCObject* sender);
	void onBackMenu(CCObject* sender);

	void onMegaBoxz(CCObject* sender);
	void onSpiderBoxz(CCObject* sender);
	void onRockboxz(CCObject* sender);

};

#endif /* MAINGAMESCENE_H_ */
