/*
 * Obj_Stone.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#ifndef OBJ_STONE_H_
#define OBJ_STONE_H_

#include "GameObject.h"

class Obj_Stone : public GameObject
{
public:
	Obj_Stone(int x, int y);
	int GetID();
	CCSprite* CreateSprite();
};

#endif /* OBJ_STONE_H_ */
