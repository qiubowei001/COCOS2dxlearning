#include "LearningTestScene.h"
#include "../testResource.h"
#include "cocos2d.h"
#include "./LearningTests/LearningTest.h"

#include "./LearningTests/LearningTest1.h"
#include "./LearningTests/water.h"
#define LINE_SPACE 40

typedef struct _Lessons
{
	std::string test_name;
	std::function<BaseTest*()> callback;
}Lessons;

Lessons learn_testNames[] =
{
	{ "learning1"	, [](){return new LearningTest1(); } },
	{ "water"		, [](){return new water(); } },
};

int lessonNum = sizeof(learn_testNames) / sizeof(learn_testNames[0]);


enum 
{
    kTagNode,
    kTagGrossini,
    kTagSequence,
}; 


static int sceneIdx = -1; 


Layer* createLearningTestLayer(int nIndex)
{
	return learn_testNames[nIndex].callback();
}

//------------------------------------------------------------------
//
// LearningTestScene
//
//------------------------------------------------------------------
void LearningTestScene::runThisTest()
{
	createMenu();
    Director::getInstance()->replaceScene(this);
}
static Vec2 s_tCurPos = Vec2::ZERO;
void LearningTestScene::createMenu()
{
	_menu = Menu::create();
	TTFConfig ttfConfig("fonts/arial.ttf", 24);
	for (int i = 0; i < lessonNum; i ++)
	{
		auto label = Label::createWithTTF(ttfConfig, learn_testNames[i].test_name);
		auto menuItem = MenuItemLabel::create(label, CC_CALLBACK_1(LearningTestScene::menuCallback, this));
		_menu->addChild(menuItem, i + 10000);
		menuItem->setPosition(VisibleRect::center().x, (VisibleRect::top().y - (i + 1) * 40));
	}
	_menu->setContentSize(Size(VisibleRect::getVisibleRect().size.width, (lessonNum + 1) * (LINE_SPACE)));
	_menu->setPosition(s_tCurPos);
	addChild(_menu);

}

void LearningTestScene::OnTestQuit()
{
	_menu->setVisible(true);
}

void LearningTestScene::menuCallback(Ref * sender)
{
	Director::getInstance()->purgeCachedData();

	// get the userdata, it's the index of the menu item clicked
	auto menuItem = static_cast<MenuItem *>(sender);
	int idx = menuItem->getLocalZOrder() - 10000;

	// create the test scene and run it
	auto testlayer = learn_testNames[idx].callback();

	if (testlayer)
	{
		_testlayer = createLearningTestLayer(idx);
		addChild(testlayer);
		_menu->setVisible(false);
	}
}