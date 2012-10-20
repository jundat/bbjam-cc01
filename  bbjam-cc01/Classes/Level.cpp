/*
 * Level.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "Level.h"
#include "GameConstant.h"
#include "GameResourceConstant.h"
#include "GameObject.h"
#include "Obj_Player.h"
#include "Obj_Stone.h"
#include "Obj_Target.h"
#include "Obj_Trap.h"
#include "Obj_Wood.h"

int* Level::getArrayID(int level)
{
	CCImage* pImage = new CCImage();
	pImage->initWithImageFile(IMG_LEVEL[level]);
	CCLOG("Image size W = %i",pImage->getWidth());
	CCLOG("Image size H = %i",pImage->getHeight());
	unsigned int* layerPixels = (unsigned int*)pImage->getData();

	return (int*)layerPixels;
}


Level::Level(int level)
{
	if (level <= 0 || level > MAX_LEVEL)
		return;

	m_ArrayID = getArrayID(level);
	CCLog("--- Get Array ---");
	initLevel();
	CCLog("--- Init Level ---");
}


void Level::initLevel()
{
	int ID;
	GameObject *obj;

	for (int i = 0; i < NUM_GRID_WIDTH; i++)
	{
		for (int j = 0; j < NUM_GRID_HEIGHT; j++)
		{
			CCLog("m_ArrayID");
			ID = m_ArrayID[j * NUM_GRID_WIDTH + i];
			switch (ID & 0x00ffffff)
			{
			case MAP_COLOR_PLAYER:
				CCLog("MAP_COLOR_PLAYER");
				obj = new Obj_Player(i, j);
				this->addChild(obj);
				break;
			case MAP_COLOR_STONE:
				CCLog("MAP_COLOR_STONE");
				obj = new Obj_Stone(i, j);
				this->addChild(obj);
				break;
			case MAP_COLOR_TRAP:
				CCLog("MAP_COLOR_TRAP");
				obj = new Obj_Trap(i, j);
				this->addChild(obj);
				break;
			case MAP_COLOR_WOOD:
				CCLog("MAP_COLOR_WOOD");
				obj = new Obj_Wood(i, j);
				this->addChild(obj);
				break;
			case MAP_COLOR_TARGET:
				CCLog("MAP_COLOR_TARGET");
				obj = new Obj_Target(i, j);
				this->addChild(obj);
				break;
			}
		}
	}
}
