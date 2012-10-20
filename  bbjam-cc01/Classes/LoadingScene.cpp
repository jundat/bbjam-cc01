/*
 * LoadingScene.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "LoadingScene.h"
#include "SimpleAudioEngine.h"
#include "GameConstant.h"

USING_NS_CC;
using namespace CocosDenshion;

CCScene* LoadingScene::scene()
{
	CCLog("scene");
	CCScene *scene = CCScene::create();
	LoadingScene *layer = LoadingScene::create();
	scene->addChild(layer);
	return scene;
}

bool LoadingScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	m_sprLoading = CCSprite::spriteWithFile("loading.png");
	m_sprLoading->setPosition(ccp(WIDTH >> 1, HEIGHT >> 1));
	this->addChild(m_sprLoading);

	CCRepeatForever *actionForever = new CCRepeatForever();
	actionForever->initWithAction(CCRotateBy::create(2, 360));
	m_sprLoading->runAction(actionForever);

	return true;
}
