
/*
 * Level.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#ifndef LEVEL_H_
#define LEVEL_H_
#include "cocos2d.h"
#include "GameResourceConstant.h"
USING_NS_CC;
#include "cocos2d.h"

class Level : public cocos2d::CCNode
{
private:
	int* m_ArrayID;
	int* getArrayID(int level)
	{
		CCImage* pImage = new CCImage();
		pImage->initWithImageFile(IMG_LEVEL[level]);
		CCLOG("Image size W = %i",pImage->getWidth());
		CCLOG("Image size H = %i",pImage->getHeight());
		unsigned int* layerPixels = (unsigned int*)pImage->getData();
	}
public:
	Level(int level)
	{
		m_ArrayID = getArrayID(level);
	}
};

#endif /* LEVEL_H_ */
