/*
 * GameData.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */


#include "GameData.h"
#include "GameConstant.h"
#include "FileOperation.h"
#include "string.h"
#include <sstream>
#include "actions\CCActionInstant.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

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
	g_UnlockLevel = 28;
}
void GameData::readLevel ()
{
	//int temp = 0;
	char* temp =FileOperation::readFile("score");
	//temp =
	
}
void GameData::writeLevel ()
{
	/*char buff[100];
	sprintf(buff, "%i", i+index*20+1);*/
	char buff[4];
	sprintf(buff,"%i",g_UnlockLevel);
	FileOperation::saveFile("score",buff);
}