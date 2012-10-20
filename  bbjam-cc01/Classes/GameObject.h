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
	GameObject(float x, float y);

	virtual int GetID() = 0;
	virtual CCSprite* CreateSprite() = 0;
	CCSprite *m_Sprite;

	float m_iX;
	float m_iY;
	int m_iW;
	int m_iH;
};

#endif /* GAMEOBJECT_H_ */
