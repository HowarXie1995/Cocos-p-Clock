#ifndef __clock__LoadLayer_h__
#define __clock__LoadLayer_h__

#include <iostream>
#include "cocos2d.h"
#include "SceneManager.h"

USING_NS_CC;


class LoadLayer:public Layer
{
public:
	CREATE_FUNC(LoadLayer);
	virtual bool init();
	//计时器回调方法
	void onScheduleOnce(float dt);
public:
	//留一个场景管理指针
	SceneManager * tsm;		
};
#endif //!__clock__LoadLayer_h__


