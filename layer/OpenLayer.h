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
	//�ص��˵��ص�����
	void menuCallBack(Ref * pSender);//�����������item�Ķ���
public:
	//��һ����������ָ��
	SceneManager * tsm;
};

#endif//!__clock__OpenLayer_h__

