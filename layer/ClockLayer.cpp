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


	return true;
}

void ClockLayer::timeUpdate(float dt)
{

}
void ClockLayer::menuCallBack(Ref * pSender)
{


}