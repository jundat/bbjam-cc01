/*
 * GameObject.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "GameObject.h"

GameObject::GameObject(int x, int y)
{
	m_iX = x;
	m_iY = y;
}

int GameObject::GetX()
{
	return m_iX;
}

int GameObject::GetY()
{
	return m_iY;
}
