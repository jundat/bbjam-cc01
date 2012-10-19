/*
 * Obj_Target.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#ifndef OBJ_TARGET_H_
#define OBJ_TARGET_H_

#include "GameObject.h"

class Obj_Target : public GameObject
{
public:
	int getID() = 0;
};

#endif /* OBJ_TARGET_H_ */
