/*
 * Obj_Player.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "Obj_Player.h"
#include "GameConstant.h"

Obj_Player::Obj_Player(int x, int y):GameObject(x, y)
{
	m_Sprite = CreateSprite();

	if (m_Sprite != 0)
		this->addChild(m_Sprite);
}

int Obj_Player::GetID()
{
	return MAP_PLAYER;
}

CCSprite* Obj_Player::CreateSprite()
{
	return CCSprite::spriteWithFile("block_1.png");
}
