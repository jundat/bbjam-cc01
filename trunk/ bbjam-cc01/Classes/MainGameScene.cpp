/*
 * MainGameScene.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "MainGameScene.h"
#include "SimpleAudioEngine.h"
#include "GameConstant.h"
#include "Obj_Stone.h"

USING_NS_CC;
using namespace CocosDenshion;

CCScene* MainGameScene::scene()
{
	CCScene *scene = CCScene::create();
	MainGameScene *layer = MainGameScene::create();
	scene->addChild(layer);
	return scene;
}

bool MainGameScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	m_sprBackground = CCSprite::spriteWithFile("background1.png");
	m_sprBackground->setPosition(ccp(WIDTH >> 1, HEIGHT >> 1));
	this->addChild(m_sprBackground);

	InitMap();
	return true;
}

void MainGameScene::InitMap()
{

}
