/*
 * GameData.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#ifndef GAMEDATA_H_
#define GAMEDATA_H_


class GameData
{

public:
	static GameData* sharedGameData();
	int g_Gravity;
	int g_CurrentLevel;
	int g_UnlockLevel;
private:
	GameData();
};

#endif /* GAMEDATA_H_ */
