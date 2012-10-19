/*
 * LevelManager.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */
#include "Level.h"
#include "GameConstant.h"
#include "cocos2d.h"

#ifndef LEVELMANAGER_H_
#define LEVELMANAGER_H_

USING_NS_CC;

// singleton
class LevelManager
{
public:
	Level* getLevel(int level);

	static LevelManager* sharedLevelManager();

private:
	LevelManager();
	void init();
};

#endif /* LEVELMANAGER_H_ */
