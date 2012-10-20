/*
 * Obj_Target.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "Obj_Target.h"
#include "GameConstant.h"

Obj_Target::Obj_Target(int x, int y):GameObject(x, y)
{
	m_Sprite = CreateSprite();

	if (m_Sprite != 0)
		this->addChild(m_Sprite);
}

int Obj_Target::GetID()
{
	return MAP_TARGET;
}

CCSprite* Obj_Target::CreateSprite()
{
	return CCSprite::spriteWithFile("block_1.png");
}
