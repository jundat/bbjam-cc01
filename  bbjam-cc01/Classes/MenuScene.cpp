/*
 * MenuScene.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 *		Edit: long
 */

#include "MenuScene.h"
#include "SimpleAudioEngine.h"
#include "MainGameScene.h"
#include "AboutScene.h"
#include "AudioManager.h"
#include "DefileMacro.h"
#include "selectLevelScene.h"

using namespace CocosDenshion;

MenuScene::MenuScene()
{
}

MenuScene::~MenuScene()
{
}

CCScene* MenuScene::scene()
{
	CCScene *scene = CCScene::create();
	MenuScene *layer = MenuScene::create();
	scene->addChild(layer);
	return scene;
}

bool MenuScene::init()
{
	//
	if (!CCLayer::init())
	{
		return false;
	}

	//init here
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	
	//
	//background
	m_spBackground = CCSprite::create("background1.png");
	m_spBackground->setPosition(ccp(s.width/2, s.height/2));
	addChild(m_spBackground);

	

	//menu item
	m_itemPlay = CCMenuItemImage::create("button_up.png", "button_down.png", this, menu_selector(MenuScene::gotoPlay) );
	//m_itemOption = CCMenuItemImage::create("button_up.png", "button_down.png", this, menu_selector(MenuScene::gotoOption) );
	m_itemTutorial = CCMenuItemImage::create("button_up.png", "button_down.png", this, menu_selector(MenuScene::gotoTurtorial) );
	m_itemAbout = CCMenuItemImage::create("button_up.png", "button_down.png", this, menu_selector(MenuScene::gotoAbout) );
	m_itemExit = CCMenuItemImage::create("button_up.png", "button_down.png", this, menu_selector(MenuScene::gotoExit) );
	//
	CCMenuItem* soundOn = CCMenuItemImage::create("music_on.png", NULL, NULL);
	CCMenuItem* soundOff = CCMenuItemImage::create("music_off.png", NULL, NULL);
	m_itemMusic = CCMenuItemToggle::itemWithTarget(this,  menu_selector(MenuScene::toggleMusic), soundOn, soundOff, NULL);
	//
	int sw = 768;
	int sh = 1280;
	int _space  = 150;
	m_itemPlay->setPosition(0,		50 + _space * 1);
	//m_itemOption->setPosition(0,0 +  _space * 1);
	m_itemTutorial->setPosition(0,	50 +  _space * 0);
	m_itemAbout->setPosition(0,		50 +  _space * -1);
	m_itemExit->setPosition(0,		50 + _space * -2);
	//
	m_itemMusic->setPosition(- s.width/2 + 120, - s.height / 2 + 200);
	CCMenu* m_Menu =CCMenu::create(m_itemPlay, /*m_itemOption,*/ m_itemTutorial, m_itemAbout, m_itemExit, m_itemMusic, NULL);
	addChild(m_Menu);

	//text in menu item
	CCLabelBMFont* tPlay = CCLabelBMFont::create("play", "idevice_r_50.fnt");
	CCLabelBMFont* tTurtorial = CCLabelBMFont::create("turtorial", "idevice_r_50.fnt");
	CCLabelBMFont* tAbout = CCLabelBMFont::create("about", "idevice_r_50.fnt");
	CCLabelBMFont* tExit = CCLabelBMFont::create("exit", "idevice_r_50.fnt");
	//
	tPlay->setPosition(s.width/2,		s.height/2 + 60 + _space * 1);
	tTurtorial->setPosition(s.width/2,	s.height/2 + 60 + _space * 0);
	tAbout->setPosition(s.width/2,		s.height/2 + 60 + _space * -1);
	tExit->setPosition(s.width/2,		s.height/2 + 60 + _space * -2);
	//
	addChild(tPlay);
	addChild(tTurtorial);
	addChild(tAbout);
	addChild(tExit);

	//
	return true;
}

void MenuScene::gotoPlay(CCObject* sender)
{
	CCDirector::sharedDirector()->replaceScene(SelectLevelScene::scene());
}

/*
void MenuScene::gotoOption(CCObject* sender)
{

}
*/

void MenuScene::gotoTurtorial(CCObject* sender)
{

}

void MenuScene::gotoAbout(CCObject* sender)
{
	CCDirector::sharedDirector()->replaceScene(AboutScene::scene());
}

void MenuScene::gotoExit(CCObject* sender)
{
	CCDirector::sharedDirector()->end();
}

void MenuScene::toggleMusic(CCObject* sender)
{
	if(AudioManager::sharedAudioManager()->IsEnableBackground())
	{
		AudioManager::sharedAudioManager()->SetEnableBackground(false);
		AudioManager::sharedAudioManager()->SetEnableEffect(false);
	}
	else
	{
		AudioManager::sharedAudioManager()->SetEnableBackground(true);
		AudioManager::sharedAudioManager()->SetEnableEffect(true);

	}
	
}


