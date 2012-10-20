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

//bool GameObject::overlap(int x1, int y1, int x2, int y2)
//{
//	return x1 < x2 ? y1 > x2 : y2 > x1;
//}
//
//bool GameObject::collideWith(GameObject obj)
//{
//	return overlap(obj.x - (obj.m_iW >> 1), obj.x + (obj.m_iW >> 1), obj.x - (GRID_SIZE >> 1), this.getX() + this.getWidth())
//			&& overlap(e.getY() - obj.m_iH, e.getY() + obj.m_iH, this.getY(), this.getY() + this.getHeight());
//}
