#include "Utility.h"

static Utility* instance= NULL;
Utility::Utility()
{

};
/*CCSprite* Utility::Animation(const char *format, ...)
{
	va_list args;
	char buffer[BUFSIZ];

	va_start(args, format);
	vsnprintf(buffer, sizeof buffer, format, args);
	va_end(args);
	FlushFunnyStream(buffer);

	CCAnimation* anim = CCAnimation::animation();

	for (int i =1;i < sizeof(item)/(sizeof(item[0]));i++)
	{
		anim->addSpriteFrameWithFileName(item[i]);
	}

	CCAnimate* theAnim = CCAnimate::actionWithAnimation(anim);

	CCSprite* pSprite = CCSprite::createWithSpriteFrameName(item[0]);
	pSprite->runAction(theAnim);

	return pSprite;

}*/
Utility* Utility::getUtility()
{
	if(instance == NULL)
	{
		instance = new Utility();
	}
	return instance;
}