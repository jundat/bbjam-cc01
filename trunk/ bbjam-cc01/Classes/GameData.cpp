/*
 * GameData.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */


#include "GameData.h"
#include "GameConstant.h"

static GameData *m_Instance;

GameData* GameData::sharedGameData()
{
	if (m_Instance == 0)
		m_Instance = new GameData();
	return m_Instance;

}

GameData::GameData()
{
	g_Gravity = GRAVITY_DOWN;
	g_CurrentLevel = 22;
}
