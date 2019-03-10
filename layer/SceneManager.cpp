#include "SceneManager.h"
#include "LoadLayer.h"
#include "OpenLayer.h"
#include "ClockLayer.h"

void SceneManager::createLoadScene()
{
	//1、对场景对象初始化
	loadScene = Scene::create();
	//2、创建层，调用LoadLayer里面的create方法
	LoadLayer * layer = LoadLayer::create();
	layer->tsm = this;
	//3、把层添加到加载场景上
	loadScene->addChild(layer);

}

void SceneManager::goOpenScene()
{
	//1、对场景对象初始化
	openScene = Scene::create();
	//2、创建层，调用OpenLayer里面的create方法
	OpenLayer * layer = OpenLayer::create();
	layer->tsm = this;
	//3、把层添加到加载场景上
	openScene->addChild(layer);
	//4、因为是跳转方法，所以采用导演类的跳转函数
	Director::getInstance()->replaceScene(openScene);
}

void SceneManager::goClockScene()
{	
	//1、对场景对象初始化
	clockScene = Scene::create();
	//2、创建层，调用OpenLayer里面的create方法
	ClockLayer * layer = ClockLayer::create();
	layer->tsm = this;
	//3、把层添加到加载场景上
	clockScene->addChild(layer);
	//4、因为是跳转方法，所以采用导演类的跳转函数
	Director::getInstance()->replaceScene(clockScene);
}
