#ifndef _LEARNING_TEST_H_
#define _LEARNING_TEST_H_
#include "cocos2d.h"
#include "../../BaseTest.h"
using namespace cocos2d;

class LearningTest : public BaseTest
{
protected:

	std::string    _title;

public:
	LearningTest(void);
	~LearningTest(void);

	virtual std::string title() const override;
	virtual std::string subtitle() const override;
	virtual void restartCallback(Ref* sender);
	virtual void nextCallback(Ref* sender);
	virtual void backCallback(Ref* sender);
};
#endif