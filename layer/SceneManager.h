#ifndef __clock__SceneManager_h__
#define __clock__SceneManager_h__

#include <iostream>
#include "cocos2d.h" 
#include "tools_define.h"
USING_NS_CC;

class SceneManager
{
public:
	//1、进入游戏的加载场景
	Scene * loadScene;
	//2、开始界面的场景
	Scene * openScene;
	//3、时钟的场景
	Scene * clockScene;

	//初始化加载界面的方法
	void createLoadScene();
	//跳转到开始界面的方法
	void goOpenScene();
	//跳转到时钟场景的方法
	void goClockScene();
};

#endif // !__clock__SceneManager_h__
