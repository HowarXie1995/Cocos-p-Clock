#include "SceneManager.h"
#include "LoadLayer.h"
#include "OpenLayer.h"
#include "ClockLayer.h"

void SceneManager::createLoadScene()
{
	//1���Գ��������ʼ��
	loadScene = Scene::create();
	//2�������㣬����LoadLayer�����create����
	LoadLayer * layer = LoadLayer::create();
	layer->tsm = this;
	//3���Ѳ���ӵ����س�����
	loadScene->addChild(layer);

}

void SceneManager::goOpenScene()
{
	//1���Գ��������ʼ��
	openScene = Scene::create();
	//2�������㣬����OpenLayer�����create����
	OpenLayer * layer = OpenLayer::create();
	layer->tsm = this;
	//3���Ѳ���ӵ����س�����
	openScene->addChild(layer);
	//4����Ϊ����ת���������Բ��õ��������ת����
	Director::getInstance()->replaceScene(openScene);
}

void SceneManager::goClockScene()
{	
	//1���Գ��������ʼ��
	clockScene = Scene::create();
	//2�������㣬����OpenLayer�����create����
	ClockLayer * layer = ClockLayer::create();
	layer->tsm = this;
	//3���Ѳ���ӵ����س�����
	clockScene->addChild(layer);
	//4����Ϊ����ת���������Բ��õ��������ת����
	Director::getInstance()->replaceScene(clockScene);
}
