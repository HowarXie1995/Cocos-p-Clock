#ifndef __clock__SceneManager_h__
#define __clock__SceneManager_h__

#include <iostream>
#include "cocos2d.h" 
#include "tools_define.h"
USING_NS_CC;

class SceneManager
{
public:
	//1��������Ϸ�ļ��س���
	Scene * loadScene;
	//2����ʼ����ĳ���
	Scene * openScene;
	//3��ʱ�ӵĳ���
	Scene * clockScene;

	//��ʼ�����ؽ���ķ���
	void createLoadScene();
	//��ת����ʼ����ķ���
	void goOpenScene();
	//��ת��ʱ�ӳ����ķ���
	void goClockScene();
};

#endif // !__clock__SceneManager_h__
