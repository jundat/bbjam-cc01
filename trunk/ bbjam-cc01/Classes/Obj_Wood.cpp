/*
 * Obj_Wood.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "Obj_Wood.h"
#include "GameConstant.h"

Obj_Wood::Obj_Wood(int x, int y):GameObject(x, y)
{
	m_Sprite = CreateSprite();

	if (m_Sprite != 0)
		this->addChild(m_Sprite);
}


int Obj_Wood::GetID()
{
	return MAP_WOOD;
}


CCSprite* Obj_Wood::CreateSprite()
{
	return CCSprite::spriteWithFile("block_1.png");
}
