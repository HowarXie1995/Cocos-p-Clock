#ifndef __clock__ClockLayer_h__
#define __clock__ClockLayer_h__

#include <iostream>
#include "cocos2d.h" 

#include "SceneManager.h"
USING_NS_CC;

class ClockLayer:public Layer
{
public:
	CREATE_FUNC(ClockLayer);
	virtual bool init();
	void menuCallBack(Ret * pSender);
public:
	//留一个场景管理指针
	SceneManager * tsm;

	Sprite * _hour;
	Sprite * _minute;
	Sprite * _second;
	Sprite * _background;
};

#endif // !__clock__ClockLayer_h__
