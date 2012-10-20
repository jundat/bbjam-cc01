#include "Utility.h"

static Utility* instance= NULL;
Utility::Utility()
{

};
CCSprite* Utility::Animation(const char *format, int numImage) // name%d.png
{
//	va_list args;
//	char buffer[BUFSIZ];
//
//	va_start(args, format);
//	vsnprintf(buffer, sizeof buffer, format, args);
//	va_end(args);
//	FlushFunnyStream(buffer);

//	CCAnimation* anim = CCAnimation::animation();
//
//
//
//	for (int i = 0; i < numImage; i++)
//	{
//
//	}
//
//	CCAnimate* theAnim = CCAnimate::actionWithAnimation(anim);
//
//	CCSprite* pSprite = CCSprite::createWithSpriteFrameName(item[0]);
//	pSprite->runAction(theAnim);

//	return pSprite;
	return 0;
}


Utility* Utility::getUtility()
{
	if(instance == NULL)
	{
		instance = new Utility();
	}
	return instance;
}
