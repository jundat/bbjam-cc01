/*
 * Obj_Stone.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "Obj_Stone.h"
#include "GameConstant.h"

Obj_Stone::Obj_Stone(int x, int y):GameObject(x, y)
{
	m_Sprite = CreateSprite();

	if (m_Sprite != 0)
		this->addChild(m_Sprite);
}


int Obj_Stone::GetID()
{
	return MAP_STONE;
}

CCSprite* Obj_Stone::CreateSprite()
{
	return CCSprite::spriteWithFile("block_2.png");
}
