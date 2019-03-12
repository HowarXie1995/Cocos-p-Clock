#include "ClockLayer.h"

#ifdef
#pragma execution_character_set("utf-8")
#endif

bool ClockLayer::init()
{
	//1����ô��ڴ�С
	Get_Screen_winSize;

	//2�����÷��ز˵���ť
	MenuItemLabel * menuItem = MenuItemLabel::create(
				Label::createWithTTF("����", "fonts/white.ttf", 30), 
					CC_CALLBACK_1(ClockLayer::menuCallBack, this));
		//����λ��
	menuItem->setPosition(Vec2(winSize.width * 0.9, winSize.height * 0.9));
		//�����˵�����
	auto menu = Menu::create(menuItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	//3�����þ���
		/*ʱ�뾫��*/
	_hour = Sprite::create("res/shi.png");
			//����λ��
	_hour->setPosition(Vec2(winSize.width / 2, winSize.length / 2));
			//�������Ŵ�С
	_hour->setScale(0.3);
			//�޸�ê��
	_hour->setAnchorPoint(Vec2(0.5, 0));
			//���
	this->addChild(_hour, 1);

		/*���뾫��*/
	_minute = Sprite::create("res/fen.png");
			//����λ��
	_minute->setPosition(Vec2(winSize.width / 2, winSize.length / 2));
			//�������Ŵ�С
	_minute->setScale(0.3);
			//�޸�ê��
	_hour->setAnchorPoint(Vec2(0.5, 0));
			//���
	this->addChild(_minute, 2);

		/*���뾫��*/
	_second = Sprite::create("res/miao.jpg");
			//����λ��
	_second->setPosition(Vec2(winSize.width / 2, winSize.length / 2));
			//�������Ŵ�С
	_second->setScale(0.3);
			//�޸�ê��
	_hour->setAnchorPoint(Vec2(0.5, 0));
			//���
	this->addChild(_second, 3);

		/*��������*/
	_background = Sprite::create("res/background.jpg");
			//����λ��
	_background->setPosition(Vec2(winSize.width / 2, winSize.length / 2));
			//�������Ŵ�С
	_background->setScale(0.5);
			//�޸�ê��
	_hour->setAnchorPoint(Vec2(0.5, 0));
			//���
	this->addChild(_background, 4);


	return true;
}

void ClockLayer::timeUpdate(float dt)
{

}
void ClockLayer::menuCallBack(Ref * pSender)
{


}