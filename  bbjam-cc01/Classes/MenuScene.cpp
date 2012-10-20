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

USING_NS_CC;

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

	m_itemPlay = CCMenuItemImage::create("button_up.png", "button_down.png", this, menu_selector(MenuScene::gotoPlay) );
	m_itemOption = CCMenuItemImage::create("button_up.png", "button_down.png", this, menu_selector(MenuScene::gotoOption) );
	m_itemTutorial = CCMenuItemImage::create("button_up.png", "button_down.png", this, menu_selector(MenuScene::gotoTurtorial) );
	m_itemAbout = CCMenuItemImage::create("button_up.png", "button_down.png", this, menu_selector(MenuScene::gotoAbout) );
	m_itemExit = CCMenuItemImage::create("button_up.png", "button_down.png", this, menu_selector(MenuScene::gotoExit) );
	//
	int sw = 768;
	int sh = 1280;
	int _space  = 150;
	
	m_itemPlay->setPosition(0,0 + _space * 2);
	m_itemOption->setPosition(0,0 +  _space * 1);
	m_itemTutorial->setPosition(0,0 +  _space * 0);
	m_itemAbout->setPosition(0,0 +  _space * -1);
	m_itemExit->setPosition(0,0 + _space * -2);

	CCMenu* m_Menu =CCMenu::create(m_itemPlay, m_itemOption, m_itemTutorial, m_itemAbout, m_itemExit, NULL);

	addChild(m_Menu);
	//
	return true;
}

void MenuScene::gotoPlay(CCObject* sender)
{
	CCDirector::sharedDirector()->replaceScene(MainGameScene::scene());
}

void MenuScene::gotoOption(CCObject* sender)
{

}

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



