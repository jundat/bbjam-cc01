/*
 * Level.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#include "Level.h"

int* Level::getArrayID(int level)
{
	CCImage* pImage = new CCImage();
	pImage->initWithImageFile(IMG_LEVEL[level]);
	CCLOG("Image size W = %i",pImage->getWidth());
	CCLOG("Image size H = %i",pImage->getHeight());
	unsigned int* layerPixels = (unsigned int*)pImage->getData();

	return layerPixels;
}


Level::Level(int level)
{
	m_ArrayID = getArrayID(level);
}
