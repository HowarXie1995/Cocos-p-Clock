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
};

#endif // !__clock__ClockLayer_h__
