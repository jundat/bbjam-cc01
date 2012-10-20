/*
 * Obj_Target.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "Obj_Target.h"
#include "GameConstant.h"
#include "stdlib.h"

Obj_Target::Obj_Target(float x, float y):GameObject(x, y)
{
	m_Sprite = CreateSprite();

	if (m_Sprite != 0)
	{
		this->addChild(m_Sprite);
		this->setRotation(rand());
		CCRepeatForever *actionForever = new CCRepeatForever();
		actionForever->initWithAction(CCRotateBy::create(1.0, 360));
		m_Sprite->runAction(actionForever);
	}
}

int Obj_Target::GetID()
{
	return MAP_TARGET;
}

CCSprite* Obj_Target::CreateSprite()
{
	return CCSprite::spriteWithFile("block_3.png");
}
