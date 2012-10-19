/*
 * SplashScene.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "SplashScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

CCScene* SplashScene::scene()
{
	CCScene *scene = CCScene::create();
	SplashScene *layer = SplashScene::create();
	scene->addChild(layer);
	return scene;
}

bool SplashScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	return true;
}
