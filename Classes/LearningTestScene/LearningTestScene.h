#ifndef _LEARNING_TEST_S_H_
#define _LEARNING_TEST_S_H_

#include "../testBasic.h"
#include "../BaseTest.h"


Layer* nextLearningTest();
Layer* backLearningTest();
Layer* restartLearningTest();

class LearningTestScene : public TestScene
{
private:
	Layer* _testlayer;
	Menu* _menu;
public:
	void createMenu();
    virtual void runThisTest();
	void LearningTestScene::menuCallback(Ref * sender);

	void LearningTestScene::OnTestQuit();
};

#endif