/*
 * MainGameScene.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "MainGameScene.h"
#include "SimpleAudioEngine.h"
#include "AudioManager.h"
#include "GameConstant.h"
#include "Obj_Stone.h"
#include "Obj_Player.h"
#include "LevelManager.h"
#include "MenuScene.h"
#include "math.h"
#include "Level.h"
#include "GameData.h"

using namespace CocosDenshion;

CCScene* MainGameScene::scene()
{
	CCLog("scene");
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

	//
	AudioManager::sharedAudioManager()->PlayBackground("sndGame.wav", true);
	//

	m_sprBackground = CCSprite::spriteWithFile("background2.png");
	m_sprBackground->setPosition(ccp(WIDTH >> 1, HEIGHT >> 1));
	this->addChild(m_sprBackground);

	InitMap();
	initSubMenu();

	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	this->setTouchEnabled(true);
	
	return true;
}

bool MainGameScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	//
	AudioManager::sharedAudioManager()->PlayEffect("sndButton.wav", 0);
	//

	m_HelperPoint = pTouch->getLocation();
	return true;
}

void MainGameScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	if (m_Level->isDroping())
		return;

	CCPoint pt = pTouch->getLocation();

	int deltaX = pt.x - m_HelperPoint.x;
	int deltaY = pt.y - m_HelperPoint.y;

	if (abs(deltaX) < 150 && abs(deltaY) < 150)
		return;

	if (abs(deltaX) > abs(deltaY))
	{
		if (deltaX < 0)
		{
			GameData::sharedGameData()->g_Gravity = GRAVITY_LEFT;//left
			CCLog("GRAVITY_LEFT");
		}
		else
		{
			GameData::sharedGameData()->g_Gravity = GRAVITY_RIGHT;//right
			CCLog("GRAVITY_RIGHT");
		}
	}
	else
	{
		if (deltaY < 0)
		{
			GameData::sharedGameData()->g_Gravity = GRAVITY_DOWN;//down
			CCLog("GRAVITY_DOWN");
		}
		else
		{
			GameData::sharedGameData()->g_Gravity = GRAVITY_UP;//top
			CCLog("GRAVITY_UP");
		}
	}
	UpdateGravity();
}

void MainGameScene::InitMap()
{
	m_Level = LevelManager::sharedLevelManager()->getLevel(GameData::sharedGameData()->g_CurrentLevel);
	this->addChild(m_Level);
	m_Level->setPosition(48, 230);
	m_Level->m_refMain = this;
}

void MainGameScene::UpdateGravity()
{
	m_Level->updateGravity();
//	m_Level->getPlayer()->updateAngle();
}

void MainGameScene::initSubMenu()
{
	m_miPause = CCMenuItemImage::create("btn_pause.png", "btn_pause.png", this, menu_selector(MainGameScene::onPause));
	m_miReplay = CCMenuItemImage::create("btn_replay.png", "btn_replay.png", this, menu_selector(MainGameScene::onReplay));
	m_miResume = CCMenuItemImage::create("btn_resume.png", "btn_resume.png", this, menu_selector(MainGameScene::onResume));
	m_miBackMenu = CCMenuItemImage::create("btn_menu.png", "btn_menu.png", this, menu_selector(MainGameScene::onBackMenu));
	m_miMegaBoxz = CCMenuItemImage::create("megaboxz.png", "megaboxz.png", this, menu_selector(MainGameScene::onMegaBoxz));
	m_miSpiderBoxz = CCMenuItemImage::create("spiderboxz.png", "spiderboxz.png", this, menu_selector(MainGameScene::onSpiderBoxz));
	m_miRockBoxz = CCMenuItemImage::create("rockboxz.png", "rockboxz.png", this, menu_selector(MainGameScene::onRockboxz));

	if (!ALLOW_TYPE_PLAYER[GameData::sharedGameData()->g_CurrentLevel][0]) m_miMegaBoxz->setVisible(false);
	if (!ALLOW_TYPE_PLAYER[GameData::sharedGameData()->g_CurrentLevel][1]) m_miSpiderBoxz->setVisible(false);
	if (!ALLOW_TYPE_PLAYER[GameData::sharedGameData()->g_CurrentLevel][2]) m_miRockBoxz->setVisible(false);

	m_miMegaBoxz->setPosition(100, 100);
	m_miSpiderBoxz->setPosition(100, 100);
	m_miRockBoxz->setPosition(100, 100);

	m_miPause->setPosition(698, 1210);
	m_miReplay->setPosition(200, 1210);
	m_miResume->setPosition(400, 1210);
	m_miBackMenu->setPosition(600, 1210);

	m_miReplay->setScale(0);
	m_miResume->setScale(0);
	m_miBackMenu->setScale(0);
	m_miMegaBoxz->setScale(0);

	m_Menu = CCMenu::create(m_miPause, m_miReplay, m_miResume, m_miBackMenu, m_miMegaBoxz, m_miSpiderBoxz, m_miRockBoxz, NULL);
	m_Menu->setPosition(0, 0);
	this->addChild(m_Menu);
}

void MainGameScene::onPause(CCObject* sender)
{
	//
	AudioManager::sharedAudioManager()->PlayEffect("sndPause.wav", 0);
	//

	CCScaleTo *scale1 = CCScaleTo::create(0.2, 1.0);
	CCScaleTo *scale2 = CCScaleTo::create(0.2, 1.0);
	CCScaleTo *scale3 = CCScaleTo::create(0.2, 1.0);
	CCScaleTo *scale4 = CCScaleTo::create(0.2, 0);

	m_miPause->runAction(scale4);
	m_miReplay->runAction(scale1);
	m_miResume->runAction(scale2);
	m_miBackMenu->runAction(scale3);
}

void MainGameScene::onReplay(CCObject* sender)
{

}
void MainGameScene::onRetry(CCObject* sender)
{
	CCDirector::sharedDirector()->replaceScene(MainGameScene::scene());
}
void MainGameScene::onNext(CCObject* sender)
{
	//
	AudioManager::sharedAudioManager()->PlayEffect("sndButton.wav", 0);
	//

	if(GameData::sharedGameData()->g_CurrentLevel == GameData::sharedGameData()->g_UnlockLevel && GameData::sharedGameData()->g_UnlockLevel< MAX_LEVEL)
	{
		GameData::sharedGameData()->g_CurrentLevel++;
		GameData::sharedGameData()->g_UnlockLevel++;
		CCDirector::sharedDirector()->replaceScene(MainGameScene::scene());
	}else if (GameData::sharedGameData()->g_CurrentLevel < GameData::sharedGameData()->g_UnlockLevel)
	{
		GameData::sharedGameData()->g_CurrentLevel++;
		CCDirector::sharedDirector()->replaceScene(MainGameScene::scene());
	}
}
void MainGameScene::onResume(CCObject* sender)
{
	//
	AudioManager::sharedAudioManager()->PlayEffect("sndPause.wav", 0);
	//

	CCScaleTo *scale1 = CCScaleTo::create(0.2, 0);
	CCScaleTo *scale2 = CCScaleTo::create(0.2, 0);
	CCScaleTo *scale3 = CCScaleTo::create(0.2, 0);
	CCScaleTo *scale4 = CCScaleTo::create(0.2, 1);

	m_miPause->runAction(scale4);
	m_miReplay->runAction(scale1);
	m_miResume->runAction(scale2);
	m_miBackMenu->runAction(scale3);
}
void MainGameScene::onBackMenu(CCObject* sender)
{
	//
	AudioManager::sharedAudioManager()->StopBackground();
	//

	CCDirector::sharedDirector()->replaceScene(MenuScene::scene());
}

void MainGameScene::onMegaBoxz(CCObject* sender)
{
	CCScaleTo *scale1 = CCScaleTo::create(0.2, 0);
	CCScaleTo *scale2 = CCScaleTo::create(0.2, 1.0);
	CCScaleTo *scale3 = CCScaleTo::create(0.2, 1.0);

	m_miMegaBoxz->runAction(scale1);
	m_miSpiderBoxz->runAction(scale2);
	m_miRockBoxz->runAction(scale3);

	m_Level->getPlayer()->changePlayerType(PLAYER_MEGABOXZ);
}

void MainGameScene::onSpiderBoxz(CCObject* sender)
{
	CCScaleTo *scale1 = CCScaleTo::create(0.2, 1.0);
	CCScaleTo *scale2 = CCScaleTo::create(0.2, 0);
	CCScaleTo *scale3 = CCScaleTo::create(0.2, 1.0);

	m_miMegaBoxz->runAction(scale1);
	m_miSpiderBoxz->runAction(scale2);
	m_miRockBoxz->runAction(scale3);

	m_Level->getPlayer()->changePlayerType(PLAYER_SPIDERBOXZ);
}

void MainGameScene::onRockboxz(CCObject* sender)
{
	CCScaleTo *scale1 = CCScaleTo::create(0.2, 1.0);
	CCScaleTo *scale2 = CCScaleTo::create(0.2, 1.0);
	CCScaleTo *scale3 = CCScaleTo::create(0.2, 0);

	m_miMegaBoxz->runAction(scale1);
	m_miSpiderBoxz->runAction(scale2);
	m_miRockBoxz->runAction(scale3);

	m_Level->getPlayer()->changePlayerType(PLAYER_ROCKBOXZ);
}
void MainGameScene::onLost ()
{
	//
	AudioManager::sharedAudioManager()->PlayEffect("sndDead.wav", 0);
	//

	CCLayer* pDialog = CCLayer::create();
	CCSprite* pBoard = CCSprite::spriteWithFile("board.png");
	CCMenuItemImage* miReplay = CCMenuItemImage::create("btn_replay.png", "btn_replay.png", this, menu_selector(MainGameScene::onRetry));
	CCMenuItemImage* miBackMenu = CCMenuItemImage::create("btn_menu.png", "btn_menu.png", this, menu_selector(MainGameScene::onBackMenu));
	CCMenu* pMenu = CCMenu::create(miReplay,miBackMenu,NULL);;

	pDialog->setPosition(WIDTH>>1,HEIGHT>>1);
	pBoard->setPosition(CCPointZero);
	miReplay->setPosition(50,50);
	miBackMenu->setPosition(450,50);	
	pMenu->setPosition(CCPointZero);

	pDialog->addChild(pBoard);
	pBoard->addChild(pMenu);
	this->addChild(pDialog);
}
void MainGameScene::onWin ()
{
	//
	AudioManager::sharedAudioManager()->PlayEffect("sndWin.wav",  0);
	//

	CCLayer* pDialog = CCLayer::create();
	CCSprite* pBoard = CCSprite::spriteWithFile("board.png");
	CCMenuItemImage* miReplay = CCMenuItemImage::create("btn_replay.png", "btn_replay.png", this, menu_selector(MainGameScene::onRetry));
	CCMenuItemImage* miBackMenu = CCMenuItemImage::create("btn_menu.png", "btn_menu.png", this, menu_selector(MainGameScene::onBackMenu));
	CCMenuItemImage* miNext = CCMenuItemImage::create("btn_resume.png", "btn_resume.png", this, menu_selector(MainGameScene::onNext));

	CCMenu* pMenu = CCMenu::create(miReplay,miBackMenu,miNext,NULL);;

	pDialog->setPosition(WIDTH>>1,HEIGHT>>1);
	pBoard->setPosition(CCPointZero);
	miReplay->setPosition(50,50);
	miBackMenu->setPosition(250,50);	
	miNext->setPosition(450,50);	
	pMenu->setPosition(CCPointZero);

	pDialog->addChild(pBoard);
	pBoard->addChild(pMenu);
	this->addChild(pDialog);
}
