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
	//函数：按钮的回调方法
	void menuCallBack(Ref * pSender);

	//函数：计时器
	void timeUpdate(float dt);
public:
	//留一个场景管理指针
	SceneManager * tsm;
	
	/*   精灵   */
	Sprite * _hour;  		//时针
	Sprite * _minute;		//分针
	Sprite * _second;		//秒针
	Sprite * _background;	//背景

	/*  偏转角度  */
	int hRotation = 0;		//时针的偏转角度
	int mRotation = 0;		//分针的偏转角度
	int sRotation = 0;		//秒针的偏转角度
};

#endif // !__clock__ClockLayer_h__
