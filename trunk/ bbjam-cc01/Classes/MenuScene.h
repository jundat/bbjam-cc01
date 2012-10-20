/*
 * MenuScene.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
		Edit: Long
 */

#ifndef MENUSCENE_H_
#define MENUSCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class MenuScene : public CCLayer 
{
private:
	//background
	CCSprite* m_spBackground;
	CCSprite* m_sprLogo;

	//menuitem
	CCMenuItemImage* m_itemPlay;
	//CCMenuItemImage* m_itemOption;
	CCMenuItemImage* m_itemTutorial;
	CCMenuItemImage* m_itemAbout;
	CCMenuItemImage* m_itemExit;
	CCMenuItemToggle* m_itemMusic;

public:
	MenuScene();
	~MenuScene();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(MenuScene);
	
	void gotoPlay(CCObject* sender);
	//void gotoOption(CCObject* sender);
	void gotoAbout(CCObject* sender);
	void gotoTurtorial(CCObject* sender);
	void gotoExit(CCObject* sender);

	//handle event click button music
	void toggleMusic(CCObject* sender);
};

#endif /* MENUSCENE_H_ */
