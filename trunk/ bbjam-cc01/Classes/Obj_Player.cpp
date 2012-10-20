/*
 * Obj_Player.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "Obj_Player.h"
#include "GameConstant.h"

Obj_Player::Obj_Player(float x, float y):GameObject(x, y)
{
//	m_Sprite = CreateSprite();
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("character.plist");
	m_Sprite = CCSprite::createWithSpriteFrameName("megaboxz.png");
	if (m_Sprite != 0)
		this->addChild(m_Sprite);

	m_PlayerType = PLAYER_MEGABOXZ;
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
	CCLog("1");
	m_PlayerType = playerID;
	CCLog("2");
	if (m_PlayerType == PLAYER_MEGABOXZ)
	{
		m_Sprite->spriteWithSpriteFrameName("megaboxz.png");CCLog("3");
	}
	else if (m_PlayerType == PLAYER_ROCKBOXZ)
	{
		m_Sprite->spriteWithSpriteFrameName("rockboxz.png");CCLog("4");
	}
	else if (m_PlayerType == PLAYER_SPIDERBOXZ)
	{
		m_Sprite->spriteWithSpriteFrameName("spiderboxz.png");CCLog("5");
	}
	CCLog("6");
}

int Obj_Player::getPlayerType()
{
	return m_PlayerType;
}

void Obj_Player::updateGravity()
{
	switch (g_Gravity)
	{
	case GRAVITY_UP:
		break;
	case GRAVITY_DOWN:
		break;
	case GRAVITY_LEFT:
		break;
	case GRAVITY_RIGHT:
		break;
	}
}
