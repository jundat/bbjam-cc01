/*
 * LevelManager.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "LevelManager.h"

static LevelManager *m_Instance;

LevelManager::LevelManager()
{

}

Level* LevelManager::getLevel(int level)
{
	CCLog("--- Get Level ---");
	return new Level(level);
}

LevelManager* LevelManager::sharedLevelManager()
{
	if (m_Instance == 0)
		m_Instance = new LevelManager();
	return m_Instance;

}

//short** LevelManager::getArray()
//{
//	short **mArray = new short[NUM_GRID_WIDTH][NUM_GRID_HEIGHT];
//	for (int i = 0; i < NUM_GRID_WIDTH; i++)
//	{
//		for (int j = 0; j < NUM_GRID_HEIGHT; j++)
//		{
//			mArray[i][j] = i % 5;
//		}
//	}
//	return mArray;
//}
