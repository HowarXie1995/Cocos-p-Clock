#ifndef __clock__OpenLayer_h__
#define __clock__OpenLayer_h__

#include <iostream>
#include "cocos2d.h" 

#include "SceneManager.h"
USING_NS_CC;

class OpenLayer:public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(OpenLayer);
	//回调菜单回调函数
	void menuCallBack(Ref * pSender);//参数：被点击item的对象
public:
	//留一个场景管理指针
	SceneManager * tsm;
};

#endif//!__clock__OpenLayer_h__

