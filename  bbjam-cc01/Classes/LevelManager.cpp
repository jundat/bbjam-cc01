/*
 * LevelManager.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "LevelManager.h"
#include "Level.h"

static LevelManager *m_Instance;

LevelManager* LevelManager::sharedLevelManager()
{
	if (m_Instance == 0)
		m_Instance = new LevelManager();
	return m_Instance;

}

LevelManager::LevelManager()
{

}

Level* LevelManager::getLevel(int level)
{
	CCLog("--- Get Level ---");
	return new Level(level);
}
