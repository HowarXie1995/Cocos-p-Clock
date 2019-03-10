#include "LoadLayer.h"

//�ܹ��ð�����ת��Ϊutf-8��ʽ���

#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif // WIN32


bool LoadLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//1����õ�ǰ��Ļ��С
	Get_Screen_winSize;
	//2������һ�����ر�ǩ
	Label * label = Label::createWithTTF("������...",	//��ǩ����
									"fonts/white.ttf",	//�����
										32);			//�����С
	label->setPosition(Vec2(winSize.width * 7/8 , winSize.height * 1/8));
	this->addChild(label);
	//3�����ö�ʱ���ӳ٣������ص�����
	scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce),	//����ص�����
					2.0);						//����
	return true;
}

void LoadLayer::onScheduleOnce(float dt)
{
	//��ת����ʼ����
	tsm->goOpenScene();
}
