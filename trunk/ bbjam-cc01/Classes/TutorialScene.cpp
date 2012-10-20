/*
 * TutorialScene.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 *		Edit: Long
 */

#include "GameConstant.h"
#include "TutorialScene.h"
#include "MenuScene.h"
#include "AudioManager.h"

USING_NS_CC;
using namespace CocosDenshion;

CCScene* TutorialScene::scene()
{
	CCLog("scene");
	CCScene *scene = CCScene::create();
	TutorialScene *layer = TutorialScene::create();
	scene->addChild(layer);
	return scene;
}

bool TutorialScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	//background
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	m_pSpritebackground = CCSprite::spriteWithFile("background1.png");
	m_pSpritebackground->setPosition(ccp(WIDTH >> 1, HEIGHT >> 1));
	this->addChild(m_pSpritebackground, 0);

	//layerLevel
	m_index = 0;
	m_total = 4;
	initControll();
	m_pLayerContent = initLayerContent(m_index);
	this->addChild(m_pLayerContent, 5);
	//
	return true;
}

void TutorialScene::onTouchbtnNext(CCObject* pSender)
{
	//
	AudioManager::sharedAudioManager()->PlayEffect("sndButton.wav", 0);
	//

	//do not slide around
	m_index++;
	m_index = (m_index % m_total);

	CCActionInterval*  actionTo = CCMoveTo::create(1.0f, CCPointMake(- WIDTH, 0));
	CCFiniteTimeAction* action = CCSequence::create(
		CCEaseBackInOut::create(actionTo),
		CCCallFuncN::create(this, callfuncN_selector(TutorialScene::onChangeLayerComplete)), 
		NULL);
	m_pLayerContent->runAction(action);

	m_pLayerContent = initLayerContent(m_index);
	m_pLayerContent->setPosition(ccp(WIDTH, 0));

	actionTo = CCMoveTo::create(1.0f, CCPointMake(0, 0));	
	m_pLayerContent->runAction(CCEaseBackInOut::create(actionTo));

	this->addChild(m_pLayerContent, 5);
}

void TutorialScene::onTouchbtnPrev(CCObject* pSender)
{
	//
	AudioManager::sharedAudioManager()->PlayEffect("sndButton.wav", 0);
	//

	//index
	m_index--;
	if(m_index < 0)
		m_index = m_total - 1;

	CCActionInterval*  actionTo = CCMoveTo::create(1.0f, CCPointMake(WIDTH, 0));
	CCFiniteTimeAction* action = CCSequence::create( CCEaseBackInOut::create(actionTo),
		CCCallFuncN::create(this, callfuncN_selector(TutorialScene::onChangeLayerComplete)), 
		NULL);
	m_pLayerContent->runAction(action);

	m_pLayerContent = initLayerContent(m_index);
	m_pLayerContent->setPosition(ccp(- WIDTH,0));

	actionTo = CCMoveTo::create(1.0f, CCPointMake(0, 0));
	m_pLayerContent->runAction(CCEaseBackInOut::create(actionTo));

	this->addChild(m_pLayerContent, 5);
}

void TutorialScene::onTouchbtnHome(CCObject* pSender)
{
	//
	AudioManager::sharedAudioManager()->PlayEffect("sndButton.wav", 0);
	//

	CCDirector::sharedDirector()->replaceScene(MenuScene::scene());
}

void TutorialScene::initControll()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	m_pLayerControll = CCLayer::create();
	m_pLayerControll->setPosition(CCPointZero);
	CCMenuItemImage* pMenuItembtnNext = CCMenuItemImage::create("btn_arrow.png","btn_arrow_select.png",this, menu_selector(TutorialScene::onTouchbtnNext));
	pMenuItembtnNext->setScaleX(-1);
	pMenuItembtnNext->setPosition(ccp(size.width - (20+pMenuItembtnNext->getContentSize().width/2),20+pMenuItembtnNext->getContentSize().height/2));

	CCMenuItemImage* pMenuItembtnPrev = CCMenuItemImage::create("btn_arrow.png","btn_arrow_select.png",this, menu_selector(TutorialScene::onTouchbtnPrev));
	pMenuItembtnPrev->setPosition(ccp((20+pMenuItembtnPrev->getContentSize().width/2),20+pMenuItembtnPrev->getContentSize().height/2));

	CCMenuItemImage* pMenuItembtnHome = CCMenuItemImage::create("btn_home.png","btn_home.png",this, menu_selector(TutorialScene::onTouchbtnHome));
	pMenuItembtnHome->setPosition(ccp(WIDTH>>1,pMenuItembtnHome->getContentSize().height/2));

	CCMenu* pMenucontroll = CCMenu::create(pMenuItembtnNext,pMenuItembtnPrev,pMenuItembtnHome,NULL);
	pMenucontroll->setPosition(CCPointZero);
	m_pLayerControll->addChild(pMenucontroll);

	this->addChild(m_pLayerControll, 10);
}

void TutorialScene::onChangeLayerComplete(CCNode* psender)
{
	CCLayer* layerLevel = (CCLayer*)psender;
	if(layerLevel != NULL)
	{
		layerLevel->removeFromParentAndCleanup(true);
	}
}

CCLayer* TutorialScene::initLayerContent(int pageIndex)
{
	CCLayer* layerLevel= CCLayer::create();
	layerLevel->setPosition(CCPointZero);

	CCSprite* background = CCSprite::create("tutBg.png");
	background->setPosition(ccp(WIDTH/2, HEIGHT/2));
	layerLevel->addChild(background);

	//
	return layerLevel;
}




