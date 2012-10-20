/*
 * SettingScene.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 *		Edit: Long
 */

#include "SettingScene.h"

#include "MenuScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

SettingScene::SettingScene()
{

}

SettingScene::~SettingScene()
{

}

CCScene* SettingScene::scene()
{
	CCScene *scene = CCScene::create();
	SettingScene *layer = SettingScene::create();
	scene->addChild(layer);
	return scene;
}



bool SettingScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	//init here
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	this->setTouchEnabled(true);

	CCSize s = CCDirector::sharedDirector()->getWinSize();

	//background
	CCSprite* sprBackground;
	sprBackground = CCSprite::create("background1.png");
	sprBackground->setPosition(ccp(s.width/2, s.height/2));
	addChild(sprBackground, 0);

	//
	return true;
}


void SettingScene::gotoMenu(CCObject* sender)
{
	CCDirector::sharedDirector()->replaceScene(MenuScene::scene());
}

bool SettingScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}

/*
bool SettingScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{}
*/