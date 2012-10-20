/*
 * Obj_Player.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "Obj_Player.h"
#include "GameConstant.h"
#include "PlayerEyes.h"
#include "GameData.h"
#include "math.h"

Obj_Player::Obj_Player(float x, float y):GameObject(x, y)
{
//	m_Sprite = CreateSprite();
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("character.plist");
	m_Sprite = CCSprite::createWithSpriteFrameName("megaboxz.png");
	//CCLog("Size player w: %i-- h: %i",m_Sprite->getContentSize().width,m_Sprite->getContentSize().height);
	if (m_Sprite != 0)
		this->addChild(m_Sprite);

	m_PlayerType = PLAYER_MEGABOXZ;
	m_Eyes = new PlayerEyes();
	m_Eyes->setPosition(CCPointZero);
	this->addChild(m_Eyes);
	m_iW = GRID_SIZE * 2;
	m_iH = GRID_SIZE * 2;
}

int Obj_Player::GetID()
{
	return MAP_PLAYER;
}

CCSprite* Obj_Player::CreateSprite()
{
	return CCSprite::spriteWithFile("character.png");
}

void Obj_Player::changePlayerType(int playerID)
{
	CCLog("change player type = %i", playerID);
	if (m_PlayerType == playerID)
		return;
	m_PlayerType = playerID;
	if (m_PlayerType == PLAYER_MEGABOXZ)
	{
		CCSprite *sprite = CCSprite::createWithSpriteFrameName("megaboxz.png");
		m_Sprite->setTexture(sprite->getTexture());
		m_Sprite->setTextureRect(sprite->getTextureRect());
	}
	else if (m_PlayerType == PLAYER_ROCKBOXZ)
	{
		CCSprite *sprite = CCSprite::createWithSpriteFrameName("rockboxz.png");
		m_Sprite->setTexture(sprite->getTexture());
		m_Sprite->setTextureRect(sprite->getTextureRect());
	}
	else if (m_PlayerType == PLAYER_SPIDERBOXZ)
	{
		CCSprite *sprite = CCSprite::createWithSpriteFrameName("spiderboxz.png");
		m_Sprite->setTexture(sprite->getTexture());
		m_Sprite->setTextureRect(sprite->getTextureRect());
	}
}

int Obj_Player::getPlayerType()
{
	return m_PlayerType;
}

void Obj_Player::updateGravity()
{
	switch (GameData::sharedGameData()->g_Gravity)
	{
	case GRAVITY_UP:
		this->setPositionY(this->getPositionY() + 1);
		break;
	case GRAVITY_DOWN:
		this->setPositionY(this->getPositionY() - 1);
		break;
	case GRAVITY_LEFT:
		this->setPositionX(this->getPositionX() - 1);
		break;
	case GRAVITY_RIGHT:
		this->setPositionX(this->getPositionX() + 1);
		break;
	}
}

void Obj_Player::back()
{
	switch (GameData::sharedGameData()->g_Gravity)
	{
	case GRAVITY_UP:
		this->setPositionY(this->getPositionY() - 1);
		break;
	case GRAVITY_DOWN:
		this->setPositionY(this->getPositionY() + 1);
		break;
	case GRAVITY_LEFT:
		this->setPositionX(this->getPositionX() + 1);
		break;
	case GRAVITY_RIGHT:
		this->setPositionX(this->getPositionX() - 1);
		break;
	}
}

void Obj_Player::updateAngle()
{
	CCLog("update angle -- gravity = %i", GameData::sharedGameData()->g_Gravity);
//	while (m_Sprite->getRotation() < 0)
//		m_Sprite->setRotation(m_Sprite->getRotation() + 360);

	switch (GameData::sharedGameData()->g_Gravity)
	{
	case GRAVITY_UP:
		m_fTargetAngle = 180;
		break;
	case GRAVITY_DOWN:
		m_fTargetAngle = 0;
		break;
	case GRAVITY_LEFT:
		m_fTargetAngle = 90;
		break;
	case GRAVITY_RIGHT:
		m_fTargetAngle = 270;
		break;
	}
//	CCLog("update angle = %f, sprite angle = %f", angle, m_Sprite->getRotation());
	CCFiniteTimeAction*  frequence = CCSequence::create(
					CCRotateTo::create(0.2, m_fTargetAngle),
					CCCallFuncN::create( this, callfuncN_selector(Obj_Player::onDoneRotate) ),
					NULL);
	this->runAction(frequence);
	m_bRotateDone = false;
}

void Obj_Player::updateDirection()
{
	switch (GameData::sharedGameData()->g_Gravity)
	{
	case GRAVITY_UP:
		this->setRotation(180);
		break;
	case GRAVITY_DOWN:
		this->setRotation(0);
		break;
	case GRAVITY_LEFT:
		this->setRotation(90);
		break;
	case GRAVITY_RIGHT:
		this->setRotation(270);
		break;
	}
}

void Obj_Player::onDoneRotate(CCNode* sender)
{
	m_bRotateDone = true;
}

float Obj_Player::getTargetAngle()
{
	return m_fTargetAngle;
}

bool Obj_Player::isRotateDone()
{
	return m_bRotateDone;
}
