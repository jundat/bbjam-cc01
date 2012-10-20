#ifndef _PLAYER_EYES_H_
#define _PLAYER_EYES_H_
#include "cocos2d.h"
USING_NS_CC;
class PlayerEyes : public  CCNode
{
private:
	CCSprite* m_pSprite;
	int m_State;
	int m_Frame;
public:
	PlayerEyes();
	~PlayerEyes();
	void setState(int state);
	CCSprite* getSprite ();
	CCSprite* getAnimation_Dead ();
	CCSprite* getAnimation_Looking ();
	CCSprite* getAnimation_Scaring ();
	CCSprite* getAnimation_Smoking ();
	CCSprite* getAnimation_Default ();

};
#endif