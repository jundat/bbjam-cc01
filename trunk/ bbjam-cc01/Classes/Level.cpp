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

unsigned int* Level::getArrayID(int level)
{
	CCImage* pImage = new CCImage();
	pImage->initWithImageFile(IMG_LEVEL[level]);
	CCLOG("Image size W = %i",pImage->getWidth());
	CCLOG("Image size H = %i",pImage->getHeight());
	unsigned int* layerPixels = (unsigned int*)pImage->getData();

	return layerPixels;
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
//	CCSpriteBatchNode *batch = new CCSpriteBatchNode::batchNodeWithFile();
	unsigned int ID;
	GameObject *obj;

	CCLog("m_ArrayID = %i", MAP_COLOR_PLAYER);
	CCLog("m_ArrayID = %i", MAP_COLOR_STONE);
	CCLog("m_ArrayID = %i", MAP_COLOR_TRAP);
	CCLog("m_ArrayID = %i", MAP_COLOR_WOOD);
	CCLog("m_ArrayID = %i", MAP_COLOR_TARGET);
	for (int i = 0; i < NUM_GRID_HEIGHT; i++)
	{
		for (int j = 0; j < NUM_GRID_WIDTH; j++)
		{
			CCLog("i = %i", i);
			CCLog("j = %i", j);
			ID = m_ArrayID[i * NUM_GRID_WIDTH + j];
			CCLog("m_ArrayID = %i", ID);
			int random = (i * NUM_GRID_WIDTH + j);
			CCLog("random = %i", random);
			random = random % 5;
			CCLog("random2 = %i", random);
			switch (random)
			{
			case MAP_PLAYER:
				CCLog("MAP_COLOR_PLAYER");
				obj = new Obj_Player(j, i);
				obj->setPosition(j * GRID_SIZE, i * GRID_SIZE);
				this->addChild(obj);
				break;
			case MAP_STONE:
				CCLog("MAP_COLOR_STONE");
				obj = new Obj_Stone(j, i);
				obj->setPosition(j * GRID_SIZE, i * GRID_SIZE);
				this->addChild(obj);
				break;
			case MAP_TRAP:
				CCLog("MAP_COLOR_TRAP");
				obj = new Obj_Trap(j, i);
				obj->setPosition(j * GRID_SIZE, i * GRID_SIZE);
				this->addChild(obj);
				break;
			case MAP_WOOD:
				CCLog("MAP_COLOR_WOOD");
				obj = new Obj_Wood(j, i);
				obj->setPosition(j * GRID_SIZE, i * GRID_SIZE);
				this->addChild(obj);
				break;
			case MAP_TARGET:
				CCLog("MAP_COLOR_TARGET");
				obj = new Obj_Target(j, i);
				obj->setPosition(j * GRID_SIZE, i * GRID_SIZE);
				this->addChild(obj);
				break;
			}
		}
	}
}
