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

	//4����ȡ��ǰϵͳ��ʱ����
	struct timeval nowTimeval;
	gettimeofday(&nowTimeval, NULL);
	struct tm * tm;
	time_t time_sec;
	time_sec = nowTimeval.tv_sec;
	tm = localtime(&time_sec);
	
		//��ӡ��ʱ����в���
	//CCLOG("ʱ = %d, �� = %d, �� = %d", tm->tm_hour, tm->tm_min, tm->sec);

	//5������ƫת�Ƕ�
		//����
	mRotation = tm->tm_min * 6;
		//����
	sRotation = tm->tm_sec * 6;

		//ʱ��
			//1��ת��Сʱ�ƣ��������
				//��18���Զ�ת��Ϊ6��
	if (tm->tm_hour > 12)
	{
		//ʱ�뱾����ƫת�� + �������ʱ���ƫת�Ƕ�
		//����ÿ��������
			//360����12��Σ�һ���30�ȣ�һ�����5С�Σ�һС��6��
			//���嵽һ���  ��5 * 6��               ��ʱ����һС�� �������72�ȣ�360/5�� һС��6��
		hRotation = (tm->tm_hour - 12) * 5 * 6 + (mRotation/72) * 6;
	}else
	{
		hRotation = tm->tm_hour * 5 * 6 + (mRotation/72) * 6;
	}
		//���õ�����ľ�����
	_hour->setRotation(hRotation);
	_minute->setRotation(mRotation);
	_minute->setRotation(sRotation);

	//6�����ö�ʱ������ʱ�Ӷ�����
	schedule(CC_SCHEDULE_SELECTOR(ClockLayer::timeUpdate), 1.0);
	
	

	return true;
}

//��ʱ���ص�������ʱ���߼�����
void ClockLayer::timeUpdate(float dt)
{
	//1��ÿһ�룬��������һ�̣���6��
	_second->setRotation(_second->getRotation() + 6);
	//2��������ת��360��ʱ
	if(360 == (int)(_second->getRotation()))
	{
		//������һ�̣���6��
		_minute->setRotation(_minute->getRotation() + 6)
		//��������
		_second->setRotation(0);
		//����������72��ʱ
		if(0 == (int)(_minute->getRotation()%72))
		{
			//ʱ����һ�̣���6��	
			_hour->setRotation(_hour->getRotation() + 6)
			//����������360��ʱ
			if(360 == (int)(_minute->getRotation()))
			{
				//��������
				_minute->setRotation(0);
			}
			//���ʱ������360��
			if(360 == (_hour->getRotation()))
			{
				//ʱ������
				_hour->setRotation(0);
			}	
		}

	}
}

//��ť�ص�����
void ClockLayer::menuCallBack(Ref * pSender)
{
	//��ת���˵�
	tsm->goClockScene();
}