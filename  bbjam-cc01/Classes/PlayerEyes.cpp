#include "PlayerEyes.h"
#include "GameConstant.h"


PlayerEyes::PlayerEyes()
{
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Emotion.plist");
	m_pSprite = NULL;
	setState(0);
}

PlayerEyes::~PlayerEyes()
{

}
void PlayerEyes::setState(int state)
{
	if(m_pSprite!= NULL)
	{
		m_pSprite->removeFromParentAndCleanup(true);
	}
	switch (state)
	{
	
	case ID_MB_DEFAULT : 
	case ID_SB_DEFAULT  :
	case ID_RB_DEFAULT  :
		m_pSprite = getAnimation_Looking();
		break;
	case ID_SMOKING     :
		m_pSprite = getAnimation_Smoking();
		break;
	case ID_LOOKING     :
		m_pSprite = getAnimation_Looking();
		break;
	case ID_SCARING     :
		m_pSprite = getAnimation_Scaring();
		break;
	case ID_DEAD :
		m_pSprite = getAnimation_Dead();
		break;
	}
	

	if (m_pSprite!= NULL)
	{
		this->addChild(m_pSprite);
	}
}
CCSprite* PlayerEyes::getAnimation_Default ()
{
	CCSprite* pSprite =  CCSprite::createWithSpriteFrameName("Looking1.png");;
	CCAnimation * anim = CCAnimation::animation();
	anim->setDelayPerUnit(1.0f); 
	// There are other several ways of storing + adding frames, 
	// this is the most basic using one image per frame.
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Looking1.png"));
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Looking2.png"));
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Looking3.png"));
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Looking4.png"));

	 

	CCAnimate *theAnim = CCAnimate::actionWithAnimation(anim); 
	CCFiniteTimeAction*  action = CCSequence::create(CCDelayTime::create(10), theAnim, NULL);

	pSprite->runAction(action);   
	pSprite->setPosition(CCPointZero);
	return pSprite;
}
CCSprite* PlayerEyes::getAnimation_Dead ()
{
	CCSprite* pSprite =  CCSprite::createWithSpriteFrameName("Dead1.png");;
	CCAnimation * anim = CCAnimation::animation();
	anim->setDelayPerUnit(1.0f); 
	// There are other several ways of storing + adding frames, 
	// this is the most basic using one image per frame.
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Dead1.png"));
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Dead2.png"));
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Dead3.png"));
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Dead4.png"));

	CCAnimate *theAnim = CCAnimate::actionWithAnimation(anim); 

	pSprite->runAction(CCRepeatForever::actionWithAction(theAnim));   
	pSprite->setPosition(CCPointZero);
	return pSprite;
}
CCSprite* PlayerEyes::getAnimation_Looking ()
{
	CCSprite* pSprite =  CCSprite::createWithSpriteFrameName("Looking1.png");;
	CCAnimation * anim = CCAnimation::animation();
	anim->setDelayPerUnit(1.0f); 
	// There are other several ways of storing + adding frames, 
	// this is the most basic using one image per frame.
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Looking1.png"));
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Looking2.png"));
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Looking3.png"));
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Looking4.png"));

	CCAnimate *theAnim = CCAnimate::actionWithAnimation(anim); 

	pSprite->runAction(CCRepeatForever::actionWithAction(theAnim));   
	pSprite->setPosition(CCPointZero);
	return pSprite;
}
CCSprite* PlayerEyes::getAnimation_Scaring ()
{
	CCSprite* pSprite =  CCSprite::createWithSpriteFrameName("Scaring1.png");;
	CCAnimation * anim = CCAnimation::animation();
	anim->setDelayPerUnit(1.0f); 
	// There are other several ways of storing + adding frames, 
	// this is the most basic using one image per frame.
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scaring1.png"));
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scaring2.png"));
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scaring3.png"));
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Scaring4.png"));

	CCAnimate *theAnim = CCAnimate::actionWithAnimation(anim); 

	pSprite->runAction(CCRepeatForever::actionWithAction(theAnim));   
	pSprite->setPosition(CCPointZero);
	return pSprite;
}
CCSprite* PlayerEyes::getAnimation_Smoking ()
{
	CCSprite* pSprite =  CCSprite::createWithSpriteFrameName("Smoking1.png");;
	CCAnimation * anim = CCAnimation::animation();
	anim->setDelayPerUnit(1.0f); 
	// There are other several ways of storing + adding frames, 
	// this is the most basic using one image per frame.
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Smoking1.png"));
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Smoking2.png"));
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Smoking3.png"));
	anim->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Smoking4.png"));

	CCAnimate *theAnim = CCAnimate::actionWithAnimation(anim); 

	pSprite->runAction(CCRepeatForever::actionWithAction(theAnim));   
	pSprite->setPosition(CCPointZero);
	return pSprite;
}