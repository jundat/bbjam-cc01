#ifndef _UTILITY_H_
#define _UTILITY_H_
#include "cocos2d.h"
#include <stdarg.h>
USING_NS_CC;
class Utility
{
public:
	//CCSprite* Animation (const char *format, ...)
	static Utility* getUtility();
private:	
	Utility();
};
#endif