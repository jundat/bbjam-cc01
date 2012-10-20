/*
 * Obj_Wood.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "Obj_Wood.h"
#include "GameConstant.h"
#include "GameData.h"

Obj_Wood::Obj_Wood(float x, float y):GameObject(x, y)
{
	m_Sprite = CreateSprite();

	if (m_Sprite != 0)
		this->addChild(m_Sprite);
	m_iW = GRID_SIZE * 2;
	m_iH = GRID_SIZE * 2;
}


int Obj_Wood::GetID()
{
	return MAP_WOOD;
}


CCSprite* Obj_Wood::CreateSprite()
{
	return CCSprite::spriteWithFile("block_1.png");
}

void Obj_Wood::updateGravity()
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

void Obj_Wood::back()
{
	CCLog("1");
	switch (GameData::sharedGameData()->g_Gravity)
	{
	case GRAVITY_UP:
		this->setPositionY(this->getPositionY() - 1);CCLog("2");
		break;
	case GRAVITY_DOWN:
		this->setPositionY(this->getPositionY() + 1);CCLog("3");
		break;
	case GRAVITY_LEFT:
		this->setPositionX(this->getPositionX() + 1);CCLog("4");
		break;
	case GRAVITY_RIGHT:
		this->setPositionX(this->getPositionX() - 1);CCLog("5");
		break;
	}
}
