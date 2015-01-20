#include "cocos2d.h"
#include "LearningTest.h"

class LearningTest1 : public LearningTest
{
public:
	virtual std::string subtitle() const override;
	virtual void onEnter() override;
	void removeThis();
};