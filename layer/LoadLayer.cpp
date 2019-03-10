#include "LoadLayer.h"

//能够用把中文转换为utf-8格式输出

#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif // WIN32


bool LoadLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//1、获得当前屏幕大小
	Get_Screen_winSize;
	//2、设置一个加载标签
	Label * label = Label::createWithTTF("加载中...",	//标签名字
									"fonts/white.ttf",	//字体库
										32);			//字体大小
	label->setPosition(Vec2(winSize.width * 7/8 , winSize.height * 1/8));
	this->addChild(label);
	//3、设置定时器延迟，跳到回调函数
	scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce),	//加入回调函数
					2.0);						//秒数
	return true;
}

void LoadLayer::onScheduleOnce(float dt)
{
	//跳转到开始场景
	tsm->goOpenScene();
}
