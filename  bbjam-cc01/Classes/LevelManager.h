/*
 * LevelManager.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */
#include "Level.h"
#include "cocos2d.h"

#ifndef LEVELMANAGER_H_
#define LEVELMANAGER_H_

USING_NS_CC;

// singleton
class LevelManager
{
public:
	Level* getLevel(int level);
};

#endif /* LEVELMANAGER_H_ */
