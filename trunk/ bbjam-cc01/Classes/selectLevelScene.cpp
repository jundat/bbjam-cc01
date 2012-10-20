
#include "selectLevelScene.h"
#include "GameConstant.h"
#include "cocos2d.h"
#include "string.h"
#include <sstream>
#include "actions\CCActionInstant.h"
#include <string>
#include <stdlib.h>
#include "MenuScene.h"
#include "MainGameScene.h"
#include "GameData.h"
#include "SimpleAudioEngine.h"
#include "AudioManager.h"


USING_NS_CC;
using namespace CocosDenshion;

//using namespace CocosDenshion;
#define CCCA(x)   (x->copy()->autorelease())
CCScene* SelectLevelScene::scene()
{
	CCLog("scene");
	CCScene *scene = CCScene::create();
	SelectLevelScene *layer = SelectLevelScene::create();
	scene->addChild(layer);
	return scene;
}

bool SelectLevelScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	m_index =0;
	m_total = MAX_LEVEL/20+1;

	m_pSpritebackground = CCSprite::spriteWithFile("background1.png");
	m_pSpritebackground->setPosition(ccp(WIDTH >> 1, HEIGHT >> 1));
	this->addChild(m_pSpritebackground);

	
	initControll();
	m_pLayerLevel = initLevelLayer(m_index);
	this->addChild(m_pLayerLevel);
	m_pLayerIndex = NULL;
	showIndexLayer();
	
	return true;
}

void SelectLevelScene::onTouchbtnLevel(CCObject* pSender)
{
	//
	AudioManager::sharedAudioManager()->PlayEffect("sndButton.wav", 0);
	AudioManager::sharedAudioManager()->StopBackground();
	
	

	CCMenuItem* pMenuItem = (CCMenuItem*)pSender;
	int level = pMenuItem->getZOrder()-1000+1;
	if(level<28)
	CCLog("Index level : %i",level);
	GameData::sharedGameData()->g_CurrentLevel = level;
	CCDirector::sharedDirector()->replaceScene(MainGameScene::scene());
}

void SelectLevelScene::onTouchbtnNext(CCObject* pSender)
{
	//
	AudioManager::sharedAudioManager()->PlayEffect("sndButton.wav", 0);
	//

	m_index = (++m_index)%(m_total);

	CCActionInterval*  actionTo = CCMoveTo::create(1.0f, CCPointMake(-WIDTH, 0));
	CCFiniteTimeAction* action = CCSequence::create( CCEaseBackInOut::create(actionTo),
		CCCallFuncN::create(this,callfuncN_selector(SelectLevelScene::onChangeLayerComplete)), 
		NULL);
	m_pLayerLevel->runAction(action);

	m_pLayerLevel = initLevelLayer(m_index);
	m_pLayerLevel->setPosition(ccp(WIDTH,0));

	actionTo = CCMoveTo::create(1.0f, CCPointMake(0, 0));	
	m_pLayerLevel->runAction(CCEaseBackInOut::create(actionTo));
	this->addChild(m_pLayerLevel);	

	showIndexLayer();
}

void SelectLevelScene::onTouchbtnPrev(CCObject* pSender)
{
	//
	AudioManager::sharedAudioManager()->PlayEffect("sndButton.wav", 0);
	//

	m_index = (--m_index < 0 ?m_total-1:m_index) ;

	CCActionInterval*  actionTo = CCMoveTo::create(1.0f, CCPointMake(WIDTH, 0));

	CCFiniteTimeAction* action = CCSequence::create( CCEaseBackInOut::create(actionTo),
				CCCallFuncN::create(this,callfuncN_selector(SelectLevelScene::onChangeLayerComplete)), 
				NULL);
	m_pLayerLevel->runAction(action);

	m_pLayerLevel = initLevelLayer(m_index);
	m_pLayerLevel->setPosition(ccp(-WIDTH,0));

	actionTo = CCMoveTo::create(1.0f, CCPointMake(0, 0));
	m_pLayerLevel->runAction(CCEaseBackInOut::create(actionTo));

	this->addChild(m_pLayerLevel);	
	showIndexLayer();
}

void SelectLevelScene::onTouchbtnHome(CCObject* pSender)
{
	//
	AudioManager::sharedAudioManager()->PlayEffect("sndButton.wav", 0);
	//

	CCDirector::sharedDirector()->replaceScene(MenuScene::scene());
}

void SelectLevelScene::initControll()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	m_pLayerControll = CCLayer::create();
	m_pLayerControll->setPosition(CCPointZero);

	CCMenuItemImage* pMenuItembtnNext = CCMenuItemImage::create("btn_arrow.png","btn_arrow_select.png",this,menu_selector(SelectLevelScene::onTouchbtnNext));
	pMenuItembtnNext->setScaleX(-1);
	pMenuItembtnNext->setPosition(ccp(size.width - (20+pMenuItembtnNext->getContentSize().width/2),20+pMenuItembtnNext->getContentSize().height/2));

	CCMenuItemImage* pMenuItembtnPrev = CCMenuItemImage::create("btn_arrow.png","btn_arrow_select.png",this,menu_selector(SelectLevelScene::onTouchbtnPrev));
	pMenuItembtnPrev->setPosition(ccp((20+pMenuItembtnPrev->getContentSize().width/2),20+pMenuItembtnPrev->getContentSize().height/2));

	CCMenuItemImage* pMenuItembtnHome = CCMenuItemImage::create("btn_home.png","btn_home.png",this,menu_selector(SelectLevelScene::onTouchbtnHome));
	pMenuItembtnHome->setPosition(ccp(WIDTH>>1,pMenuItembtnHome->getContentSize().height/2));

	CCMenu* pMenucontroll = CCMenu::create(pMenuItembtnNext,pMenuItembtnPrev,pMenuItembtnHome,NULL);
	pMenucontroll->setPosition(CCPointZero);
	m_pLayerControll->addChild(pMenucontroll);

	this->addChild(m_pLayerControll);
}
CCLayer* SelectLevelScene::initLevelLayer(int index)
{
	int CUR_UNLOCK_LEVEL = GameData::sharedGameData()->g_UnlockLevel;
	int Start = 0;
	CCLayer* layerLevel= CCLayer::create();
	CCMenu* pMenuLevel = CCMenu::create();

	
	layerLevel->setPosition(CCPointZero);
	pMenuLevel->setPosition(CCPointZero);
	layerLevel->addChild(pMenuLevel);
	
	for(int i = 0; i<20 && (i+index*20)<MAX_LEVEL ;i++)
	{
		CCMenuItemImage* pMenuImage;
		int x = 120 + (i%4)*176;
		int y = HEIGHT-( 350 + (i/4)*150);	

		if ((i+index*20)< CUR_UNLOCK_LEVEL)
		{
			pMenuImage = CCMenuItemImage::create(
				"level_unlock.png","level_unlock_select.png",this,menu_selector(SelectLevelScene::onTouchbtnLevel));

			char buff[100];
			sprintf(buff, "%i", i+index*20+1);
			CCLabelTTF* pLbNum = CCLabelTTF::create( buff,"Arial", 50);

			pLbNum->setPosition(ccp(x,y));
			layerLevel->addChild(pLbNum);

			for (int j = 0 ; j < Start; j++)
			{
				CCSprite* pSStart = CCSprite::create("start.png");
				pSStart->setPosition(ccp(x+(j-1)*pSStart->getContentSize().width/2,y-(pMenuImage->getContentSize().height/2)));
				layerLevel->addChild(pSStart);
			}
		} 
		else		
		{
			pMenuImage = CCMenuItemImage::create(
			"level_lock.png","level_lock_select.png",this,menu_selector(SelectLevelScene::onTouchbtnLevel));
		}
		pMenuImage->setPosition(ccp(x,y));
		pMenuLevel->addChild(pMenuImage,1000+index*20+i);		
	}
	return layerLevel;
}
void SelectLevelScene::showIndexLayer ()
{
	if (m_pLayerIndex != NULL)
	{
		m_pLayerIndex->removeFromParentAndCleanup(true);
	}
	m_pLayerIndex = CCLayer::create();
	

	for(int i = 0; i < (m_total);i++)
	{
		int x = (i - (m_total>>1))*100 + (m_total%2?0:50)+WIDTH>>1;
		CCSprite* pSIndex = CCSprite::create((i==m_index?"c_w.png":"c_b.png"));
		pSIndex->setPosition(ccp(x, 240));
		m_pLayerIndex->addChild(pSIndex);
	}

	m_pLayerIndex->setPosition(CCPointZero);
	this->addChild(m_pLayerIndex);

	
}

void SelectLevelScene::onChangeLayerComplete(CCNode* psender)
{
	CCLayer* layerLevel = (CCLayer*)psender;
	if(layerLevel != NULL)
	{
		layerLevel->removeFromParentAndCleanup(true);
	}
}



