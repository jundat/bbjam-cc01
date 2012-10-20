/*
 * Obj_Trap.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "Obj_Trap.h"
#include "GameConstant.h"

Obj_Trap::Obj_Trap(int x, int y):GameObject(x, y)
{
	m_Sprite = CreateSprite();

	if (m_Sprite != 0)
	{
		this->addChild(m_Sprite);
		CCRepeatForever *actionForever = new CCRepeatForever();
		actionForever->initWithAction(CCRotateBy::create(1, 360));
		m_Sprite->runAction(actionForever);
	}
}


int Obj_Trap::GetID()
{
	return MAP_TRAP;
}


CCSprite* Obj_Trap::CreateSprite()
{
	return CCSprite::spriteWithFile("block_4.png");
}
