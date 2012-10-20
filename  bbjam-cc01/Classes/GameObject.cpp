/*
 * GameObject.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "GameObject.h"
#include "GameConstant.h"

GameObject::GameObject(float x, float y)
{
	m_iX = x;
	m_iY = y;
	m_iW = GRID_SIZE;
	m_iH = GRID_SIZE;
}
