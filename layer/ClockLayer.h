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
	//��������ť�Ļص�����
	void menuCallBack(Ref * pSender);

	//��������ʱ��
	void timeUpdate(float dt);
public:
	//��һ����������ָ��
	SceneManager * tsm;
	
	/*   ����   */
	Sprite * _hour;  		//ʱ��
	Sprite * _minute;		//����
	Sprite * _second;		//����
	Sprite * _background;	//����

	/*  ƫת�Ƕ�  */
	int hRotation = 0;		//ʱ���ƫת�Ƕ�
	int mRotation = 0;		//�����ƫת�Ƕ�
	int sRotation = 0;		//�����ƫת�Ƕ�
};

#endif // !__clock__ClockLayer_h__
