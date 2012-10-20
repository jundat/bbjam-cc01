#ifndef _SELECT_LEVEL_SENCE_H_
#define _SELECT_LEVEL_SENCE_H_
#include "cocos2d.h"
USING_NS_CC;

class SelectLevelScene : public CCLayer
{
public:
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(SelectLevelScene);

	void onTouchbtnNext (CCObject* pSender);
	void onTouchbtnPrev (CCObject* pSender);
	void onTouchbtnHome (CCObject* pSender);
	void onTouchbtnLevel (CCObject* pSender);
	void initControll ();
	CCLayer* initLevelLayer (int index);
	void showIndexLayer ();
	void onChangeLayerComplete(CCNode* psender);
private:
	CCSprite *m_pSpritebackground;
	CCLayer* m_pLayerControll;
	CCLayer* m_pLayerLevel;
	CCLayer* m_pLayerIndex;
	int m_index ,m_total;

};
#endif