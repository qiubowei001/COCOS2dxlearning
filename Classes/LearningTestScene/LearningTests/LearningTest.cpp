#include "LearningTest.h"
#include "../LearningTestScene.h"
//------------------------------------------------------------------
//
// LearningTest
//
//------------------------------------------------------------------

LearningTest::LearningTest(void)
{
}

LearningTest::~LearningTest(void)
{
}

std::string LearningTest::title() const
{
	return "ActionManager Test";
}
std::string LearningTest::subtitle() const
{
	return "No title";
}
void LearningTest::restartCallback(Ref* sender)
{
	((LearningTestScene* )getParent())->OnTestQuit();
	this->removeFromParent();
}

void LearningTest::nextCallback(Ref* sender)
{
}

void LearningTest::backCallback(Ref* sender)
{
}
