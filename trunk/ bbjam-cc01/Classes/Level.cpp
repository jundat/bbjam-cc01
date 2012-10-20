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
	initLevel();

	// init gravity
	g_Gravity = GRAVITY_LEVEL[level];
}


void Level::initLevel()
{
//	CCSpriteBatchNode *batch = new CCSpriteBatchNode::batchNodeWithFile();
	unsigned int ID;
	GameObject *obj;
	bool isLoadPlayer = false;

	for (int i = 0; i < NUM_GRID_HEIGHT; i++)
	{
		for (int j = 0; j < NUM_GRID_WIDTH; j++)
		{
			ID = m_ArrayID[i * NUM_GRID_WIDTH + j];
			switch (ID & 0x00ffffff)
			{
			case MAP_COLOR_PLAYER:
				if (isLoadPlayer) continue;
				isLoadPlayer = true;
				CCLog("MAP_COLOR_PLAYER");
				m_Player = new Obj_Player(j, i);
				m_Player->setPosition(j * GRID_SIZE + (GRID_SIZE >> 1), (NUM_GRID_HEIGHT - i - 1) * GRID_SIZE - (GRID_SIZE >> 1));
				this->addChild(m_Player);
				break;
			case MAP_COLOR_STONE:
				CCLog("MAP_COLOR_STONE");
				obj = new Obj_Stone(j, i);
				obj->setPosition(j * GRID_SIZE, (NUM_GRID_HEIGHT - i - 1) * GRID_SIZE);
				this->addChild(obj);
				break;
			case MAP_COLOR_TRAP:
				CCLog("MAP_COLOR_TRAP");
				obj = new Obj_Trap(j, i);
				obj->setPosition(j * GRID_SIZE, (NUM_GRID_HEIGHT - i - 1) * GRID_SIZE);
				this->addChild(obj);
				break;
			case MAP_COLOR_WOOD:
				if (j == NUM_GRID_WIDTH) break;
				if (i == NUM_GRID_HEIGHT - 1) break;

				if ((m_ArrayID[i * NUM_GRID_WIDTH + j + 1] & 0x00ffffff) != MAP_COLOR_WOOD
						|| (m_ArrayID[(i + 1) * NUM_GRID_WIDTH + j] & 0x00ffffff) != MAP_COLOR_WOOD) break;

				CCLog("MAP_COLOR_WOOD");
				obj = new Obj_Wood(j, i);
				obj->setPosition(j * GRID_SIZE + (GRID_SIZE >> 1), (NUM_GRID_HEIGHT - i - 1) * GRID_SIZE - (GRID_SIZE >> 1));
				this->addChild(obj);
				m_ArrWood.push_back((Obj_Wood*)obj);
				break;
			case MAP_COLOR_TARGET:
				CCLog("MAP_COLOR_TARGET");
				obj = new Obj_Target(j, i);
				obj->setPosition(j * GRID_SIZE, (NUM_GRID_HEIGHT - i - 1) * GRID_SIZE);
				this->addChild(obj);
				break;
			}
		}
	}
}

Obj_Player* Level::getPlayer()
{
	return m_Player;
}

std::vector<Obj_Wood*> Level::getListWood()
{
	return m_ArrWood;
}
