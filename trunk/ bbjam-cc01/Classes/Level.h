
/*
 * Level.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#ifndef LEVEL_H_
#define LEVEL_H_

#include "cocos2d.h"
#include "GameResourceConstant.h"
#include "vector"

USING_NS_CC;

class Obj_Player;
class Obj_Wood;

class Level : public cocos2d::CCNode
{
private:
	unsigned int* m_ArrayID;

	unsigned int* getArrayID(int level);
	void initLevel();

	Obj_Player *m_Player;
	std::vector<Obj_Wood*> m_ArrWood;
public:
	Level(int level);
	Obj_Player* getPlayer();
	std::vector<Obj_Wood*> getListWood();
};
#endif /* LEVEL_H_ */
