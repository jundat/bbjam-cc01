
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
#include "MainGameScene.h"

USING_NS_CC;

class Obj_Player;
class Obj_Wood;

class Level : public cocos2d::CCNode
{
private:
	unsigned int* m_ArrayID;
	int **m_ID;

	unsigned int* getArrayID(int level);
	void initLevel();
	void processDead(Obj_Wood *wood);

	Obj_Player *m_Player;
	std::vector<Obj_Wood*> m_ArrWood;


	bool m_bPlayerMovable;
	bool m_bWoodMovable;

public:
	Level(int level);
	Obj_Player* getPlayer();
	std::vector<Obj_Wood*> getListWood();
	void update(float delta);
	void updateGravity();
	bool isDroping();

	MainGameScene *m_refMain;
};
#endif /* LEVEL_H_ */
