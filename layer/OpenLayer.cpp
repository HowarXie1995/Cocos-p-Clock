#include "OpenLayer.h"

//�ܹ��ð�����ת��Ϊutf-8��ʽ���

#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif // WIN32


bool OpenLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//1����ȡ���ڴ�С
	Get_Screen_winSize;
	//2�����һ����ǩ
	Label * label = Label::createWithTTF("ʱ�ӳ���",
		"fonts/white.ttf",
		48);
	/*�ɵ�����ɫ*/
	//label->setColor(Color3B(255, 0, 0));
	label->setPosition(Vec2(winSize.width / 2, winSize.height * 3 / 4));
	this->addChild(label);
	//3������һ�����ְ�ť
	/*��ʼ��ť*/
	MenuItemLabel * menuItem = MenuItemLabel::create(Label::createWithTTF("��ʼ", "fonts/white.ttf", 30), 
													CC_CALLBACK_1(OpenLayer::menuCallBack, this));
		//��menuItem����һ��Tag
	menuItem->setTag(101);
	menuItem->setPosition(Vec2(winSize.width / 2, winSize.height * 0.3));
	/*������ť*/
	MenuItemLabel * menuItem_2 = MenuItemLabel::create(Label::createWithTTF("����", "fonts/white.ttf", 30), 
													CC_CALLBACK_1(OpenLayer::menuCallBack, this));
		//��menuItem����һ��Tag
	menuItem_2->setTag(102);
	menuItem_2->setPosition(Vec2(winSize.width / 2, winSize.height * 0.15));

		//�����˵�����
	auto menu = Menu::create(menuItem, menuItem_2, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	return true;
}

//��ť�ص�����
//��Ҫ����
void OpenLayer::menuCallBack(Ref * pSender)
{
	//1����ťת��
	switch (((MenuItem *)pSender)->getTag())
	{
		case 101:		//��ʼ��ť
		{
			tsm->goClockScene();
		}
			break;
		case 102:		//�˳���ť
		{
			Director::getInstance()->end();
			exit(0);
		}
			break;
		default:
			break;
	}
}
