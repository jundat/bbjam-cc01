/*
 * AboutScene.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
		Edit: long
 */

#include "AboutScene.h"
#include "MenuScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

AboutScene::AboutScene()
{

}

AboutScene::~AboutScene()
{

}

CCScene* AboutScene::scene()
{
	CCScene *scene = CCScene::create();
	AboutScene *layer = AboutScene::create();
	scene->addChild(layer);
	return scene;
}


bool AboutScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	//init here
	CCSize s = CCDirector::sharedDirector()->getWinSize();

	//background
	CCSprite* sprBackground;
	sprBackground = CCSprite::create("background1.png");
	sprBackground->setPosition(ccp(s.width/2, s.height/2));
	addChild(sprBackground, 0);

	//logo
	CCSprite* sprLogo = CCSprite::create("imgLogo.png");
	sprLogo->setPosition(ccp(s.width/2, 860));
	addChild(sprLogo, 1);

	//text
	CCLabelBMFont* gameName = CCLabelBMFont::create("Mind Boxz", "idevice_r_50.fnt");
	CCLabelBMFont* teamName = CCLabelBMFont::create("GameUit team", "idevice_r_50.fnt");
	CCLabelBMFont* version = CCLabelBMFont::create("Version 1.0.0", "idevice_r_50.fnt");

	gameName->setPosition(ccp(s.width/2, s.height/2));
	teamName->setPosition(ccp(s.width/2, s.height/2 - 50));
	version->setPosition(ccp(s.width/2, s.height/2 - 100));

	addChild(gameName, 2);
	addChild(teamName, 2);
	addChild(version, 2);

	//menu
	CCMenuItemImage* itemBack = CCMenuItemImage::create("button_up.png", "button_down.png", this, menu_selector(AboutScene::gotoMenu) );
	itemBack->setPosition(0, - s.height/2 + 70);
	CCMenu* menu = CCMenu::create(itemBack, NULL);
	addChild(menu, 2);

	//
	return true;
}

void AboutScene::gotoMenu(CCObject* sender)
{
	CCDirector::sharedDirector()->replaceScene(MenuScene::scene());
}

