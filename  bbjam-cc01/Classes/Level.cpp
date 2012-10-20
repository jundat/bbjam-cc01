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
#include "GameData.h"

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

	m_ID = new int*[NUM_GRID_HEIGHT];
	for (int i = 0; i < NUM_GRID_HEIGHT; i++)
	{
		m_ID[i] = new int[NUM_GRID_WIDTH];
		for (int j = 0; j < NUM_GRID_WIDTH; j++)
		{
			m_ID[i][j] = -1;
		}
	}

	m_ArrayID = getArrayID(level);
	initLevel();

	// init gravity
	GameData::sharedGameData()->g_Gravity = GRAVITY_LEVEL[level];
	m_Player->updateDirection();
	scheduleUpdate();
}

void Level::update(float delta)
{
	if (!m_Player->isRotateDone())
		return;

	if (m_bPlayerMovable)
	{
		for (int s = 0; s < GRAVITY_SPEED; s++)
		{
			m_Player->updateGravity();

			int top, left, right, bottom;
			top = (925.5f - m_Player->getPositionY() - 44) / GRID_SIZE;
			bottom = (925 - m_Player->getPositionY() + 44) / GRID_SIZE;
			left = (m_Player->getPositionX() - 44 + 22) / GRID_SIZE;
			right = (m_Player->getPositionX() + 44 + 22.5f) / GRID_SIZE;

			int temp = -10;
			for (int i = top; i <= bottom; i++)
			{
				for (int j = left; j <= right; j++)
				{
					if (m_ID[i][j] == MAP_STONE)
					{
						temp = MAP_STONE;
					}
					else if (m_ID[i][j] == MAP_TARGET)
					{
						if (temp == MAP_TARGET)
						{
							temp = MAP_WIN;
						}
						else
							temp = MAP_TARGET;
					}
					else if (m_ID[i][j] == MAP_TRAP)
					{
						temp = MAP_TRAP;
					}
				}
			}

			if (temp == MAP_WIN)
			{
				m_Player->back();
				m_bPlayerMovable = false;
				m_bWoodMovable = false;
				m_refMain->onWin();
				break;
			}
			else if (temp == MAP_TRAP)
			{
				m_Player->back();
				m_bPlayerMovable = false;
				m_bWoodMovable = false;
				m_refMain->onLost();
				break;
			}
			else if (temp == MAP_STONE)
			{
				m_Player->back();
				m_bPlayerMovable = false;
				break;
			}
		}
	}

	//

	bool collide = false;
	if (m_bWoodMovable)
	{
		m_bWoodMovable = false;
		for (unsigned int i = 0; i < m_ArrWood.size(); i++)
		{
			if (m_ArrWood[i] == 0)
				break;


			for (int s = 0; s < GRAVITY_SPEED; s++)
			{
				m_ArrWood[i]->updateGravity();

				int top, left, right, bottom;
				top = (925.5f - m_ArrWood[i]->getPositionY() - 44) / GRID_SIZE;
				bottom = (925 - m_ArrWood[i]->getPositionY() + 44) / GRID_SIZE;
				left = (m_ArrWood[i]->getPositionX() - 44 + 22) / GRID_SIZE;
				right = (m_ArrWood[i]->getPositionX() + 44 + 22.5f) / GRID_SIZE;

				for (int ia = top; ia <= bottom; ia++)
				{
					for (int j = left; j <= right; j++)
					{
						if (m_ID[ia][j] == MAP_STONE || m_ID[ia][j] == MAP_TARGET || m_ID[ia][j] == MAP_TRAP)
						{
							collide = true;
							goto outside;
						}
						else
							collide = false;
					}
				}
			}
			outside:
			if (collide)
			{
				m_ArrWood[i]->back();
			}
			else
			{
				m_bWoodMovable = true;
			}
		}
	}

	CCRect *playerRect = new CCRect(m_Player->getPositionX() - GRID_SIZE, m_Player->getPositionY() + GRID_SIZE,
			GRID_SIZE * 2, GRID_SIZE * 2);
	for (unsigned int i = 0; i < m_ArrWood.size(); i++)
	{
		CCRect *woodRect = new CCRect(m_ArrWood[i]->getPositionX() - GRID_SIZE, m_ArrWood[i]->getPositionY() + GRID_SIZE,
					GRID_SIZE * 2, GRID_SIZE * 2);

		if (playerRect->intersectsRect(*woodRect))
		{
			switch (GameData::sharedGameData()->g_Gravity)
			{
			case GRAVITY_UP:
				if (m_Player->getPositionY() > m_ArrWood[i]->getPositionY())
				{
					processDead(m_ArrWood[i]);
				}
				else
				{
					m_Player->back();
					m_bPlayerMovable = false;
				}
				break;
			case GRAVITY_DOWN:
				if (m_Player->getPositionY() < m_ArrWood[i]->getPositionY())
				{
					processDead(m_ArrWood[i]);
				}
				else
				{
					m_Player->back();
					m_bPlayerMovable = false;
				}
				break;
			case GRAVITY_LEFT:
				if (m_Player->getPositionX() < m_ArrWood[i]->getPositionX())
				{
					processDead(m_ArrWood[i]);
				}
				else
				{
					m_Player->back();
					m_bPlayerMovable = false;
				}
				break;
			case GRAVITY_RIGHT:
				if (m_Player->getPositionX() > m_ArrWood[i]->getPositionX())
				{

					processDead(m_ArrWood[i]);
				}
				else
				{
					m_Player->back();
					m_bPlayerMovable = false;
				}
				break;
			}
		}
	}
}

void Level::processDead(Obj_Wood *wood)
{
	CCLog("player dead");
	if (m_Player->getPlayerType() == PLAYER_ROCKBOXZ)
	{
		wood->back();
	}
	else
	{
		m_bPlayerMovable = false;
		m_bWoodMovable = false;
		m_refMain->onLost();
	}
}

void Level::updateGravity()
{
	m_Player->updateAngle();
	m_bPlayerMovable = true;
	m_bWoodMovable = true;
}

bool Level::isDroping()
{
	return m_bPlayerMovable && m_bWoodMovable;
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
				m_Player->setPosition(j * GRID_SIZE + (GRID_SIZE >> 1), (NUM_GRID_HEIGHT - i) * GRID_SIZE - 21);
				this->addChild(m_Player);
				break;
			case MAP_COLOR_STONE:
				CCLog("MAP_COLOR_STONE");
				m_ID[i][j] = MAP_STONE;
				obj = new Obj_Stone(j, i);
				obj->setPosition(j * GRID_SIZE, (NUM_GRID_HEIGHT - i) * GRID_SIZE);
				this->addChild(obj);
				break;
			case MAP_COLOR_TRAP:
				CCLog("MAP_COLOR_TRAP");
				m_ID[i][j] = MAP_TRAP;
				obj = new Obj_Trap(j, i);
				obj->setPosition(j * GRID_SIZE, (NUM_GRID_HEIGHT - i) * GRID_SIZE);
				this->addChild(obj);
				break;
			case MAP_COLOR_WOOD:
				if (j == NUM_GRID_WIDTH) break;
				if (i == NUM_GRID_HEIGHT - 1) break;

				if ((m_ArrayID[i * NUM_GRID_WIDTH + j + 1] & 0x00ffffff) != MAP_COLOR_WOOD
						|| (m_ArrayID[(i + 1) * NUM_GRID_WIDTH + j] & 0x00ffffff) != MAP_COLOR_WOOD) break;

				CCLog("MAP_COLOR_WOOD");
				obj = new Obj_Wood(j, i);
				obj->setPosition(j * GRID_SIZE + (GRID_SIZE >> 1), (NUM_GRID_HEIGHT - i) * GRID_SIZE - 21);
				this->addChild(obj);
				m_ArrWood.push_back((Obj_Wood*)obj);
				break;
			case MAP_COLOR_TARGET:
				CCLog("MAP_COLOR_TARGET");
				m_ID[i][j] = MAP_TARGET;
				obj = new Obj_Target(j, i);
				obj->setPosition(j * GRID_SIZE, (NUM_GRID_HEIGHT - i) * GRID_SIZE);
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
