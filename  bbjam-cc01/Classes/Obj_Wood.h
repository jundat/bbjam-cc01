/*
 * Obj_Wood.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#ifndef OBJ_WOOD_H_
#define OBJ_WOOD_H_

#include "GameObject.h"

class Obj_Wood : public GameObject
{
public:
	Obj_Wood(float x, float y);
	int GetID();
	CCSprite* CreateSprite();
	void updateGravity();
	void back();
};

#endif /* OBJ_WOOD_H_ */
