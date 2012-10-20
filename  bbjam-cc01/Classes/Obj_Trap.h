/*
 * Obj_Trap.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#ifndef OBJ_TRAP_H_
#define OBJ_TRAP_H_

#include "GameObject.h"

class Obj_Trap : public GameObject
{
public:
	Obj_Trap(float x, float y);
	int GetID();
	CCSprite* CreateSprite();
};

#endif /* OBJ_TRAP_H_ */
