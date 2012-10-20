/*
 * GameObject.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "cocos2d.h"
USING_NS_CC;

class GameObject : public CCNode
{
public:
	GameObject(int x, int y);

	virtual int GetID() = 0;
	virtual CCSprite* CreateSprite() = 0;
	int GetX();
	int GetY();
	CCSprite *m_Sprite;

private:
	int m_iX;
	int m_iY;
};

#endif /* GAMEOBJECT_H_ */
