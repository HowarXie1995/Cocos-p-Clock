#include "ClockLayer.h"

#ifdef
#pragma execution_character_set("utf-8")
#endif

bool ClockLayer::init()
{
	//1、获得窗口大小
	Get_Screen_winSize;

	//2、设置返回菜单按钮
	MenuItemLabel * menuItem = MenuItemLabel::create(
				Label::createWithTTF("返回", "fonts/white.ttf", 30), 
					CC_CALLBACK_1(ClockLayer::menuCallBack, this));
		//设置位置
	menuItem->setPosition(Vec2(winSize.width * 0.9, winSize.height * 0.9));
		//创建菜单对象
	auto menu = Menu::create(menuItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	//3、设置精灵
		/*时针精灵*/
	_hour = Sprite::create("res/shi.png");
			//设置位置
	_hour->setPosition(Vec2(winSize.width / 2, winSize.length / 2));
			//设置缩放大小
	_hour->setScale(0.3);
			//修改锚点
	_hour->setAnchorPoint(Vec2(0.5, 0));
			//添加
	this->addChild(_hour, 1);

		/*分针精灵*/
	_minute = Sprite::create("res/fen.png");
			//设置位置
	_minute->setPosition(Vec2(winSize.width / 2, winSize.length / 2));
			//设置缩放大小
	_minute->setScale(0.3);
			//修改锚点
	_hour->setAnchorPoint(Vec2(0.5, 0));
			//添加
	this->addChild(_minute, 2);

		/*秒针精灵*/
	_second = Sprite::create("res/miao.jpg");
			//设置位置
	_second->setPosition(Vec2(winSize.width / 2, winSize.length / 2));
			//设置缩放大小
	_second->setScale(0.3);
			//修改锚点
	_hour->setAnchorPoint(Vec2(0.5, 0));
			//添加
	this->addChild(_second, 3);

		/*背景精灵*/
	_background = Sprite::create("res/background.jpg");
			//设置位置
	_background->setPosition(Vec2(winSize.width / 2, winSize.length / 2));
			//设置缩放大小
	_background->setScale(0.5);
			//修改锚点
	_hour->setAnchorPoint(Vec2(0.5, 0));
			//添加
	this->addChild(_background, 4);

	//4、获取当前系统的时分秒
	struct timeval nowTimeval;
	gettimeofday(&nowTimeval, NULL);
	struct tm * tm;
	time_t time_sec;
	time_sec = nowTimeval.tv_sec;
	tm = localtime(&time_sec);
	
		//打印出时间进行测试
	//CCLOG("时 = %d, 分 = %d, 秒 = %d", tm->tm_hour, tm->tm_min, tm->sec);

	//5、设置偏转角度
		//分针
	mRotation = tm->tm_min * 6;
		//秒针
	sRotation = tm->tm_sec * 6;

		//时针
			//1、转换小时制，方便计算
				//如18点自动转换为6点
	if (tm->tm_hour > 12)
	{
		//时针本来的偏转角 + 分针带给时针的偏转角度
		//按照每段来计算
			//360度有12大段，一大段30度，一大段有5小段，一小段6度
			//具体到一大段  （5 * 6）               按时针走一小段 分针就走72度（360/5） 一小段6度
		hRotation = (tm->tm_hour - 12) * 5 * 6 + (mRotation/72) * 6;
	}else
	{
		hRotation = tm->tm_hour * 5 * 6 + (mRotation/72) * 6;
	}
		//设置到具体的精灵上
	_hour->setRotation(hRotation);
	_minute->setRotation(mRotation);
	_minute->setRotation(sRotation);

	//6、设置定时器，让时钟动起来
	schedule(CC_SCHEDULE_SELECTOR(ClockLayer::timeUpdate), 1.0);
	
	

	return true;
}

//计时器回调函数：时钟逻辑函数
void ClockLayer::timeUpdate(float dt)
{
	//1、每一秒，让秒针走一刻，加6度
	_second->setRotation(_second->getRotation() + 6);
	//2、当秒针转到360度时
	if(360 == (int)(_second->getRotation()))
	{
		//分针走一刻，加6度
		_minute->setRotation(_minute->getRotation() + 6)
		//秒针清零
		_second->setRotation(0);
		//当分针走了72度时
		if(0 == (int)(_minute->getRotation()%72))
		{
			//时针走一刻，加6度	
			_hour->setRotation(_hour->getRotation() + 6)
			//当分针走了360度时
			if(360 == (int)(_minute->getRotation()))
			{
				//分针清零
				_minute->setRotation(0);
			}
			//如果时针走了360度
			if(360 == (_hour->getRotation()))
			{
				//时针清零
				_hour->setRotation(0);
			}	
		}

	}
}

//按钮回调函数
void ClockLayer::menuCallBack(Ref * pSender)
{
	//跳转到菜单
	tsm->goClockScene();
}