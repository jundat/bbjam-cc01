/*
 * LevelManager.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#ifndef LEVELMANAGER_H_
#define LEVELMANAGER_H_

#include "GameConstant.h"
#include "cocos2d.h"

USING_NS_CC;

class Level;

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
