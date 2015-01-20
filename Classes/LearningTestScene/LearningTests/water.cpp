
#include "water.h"
void water::onEnter()
{
	LearningTest::onEnter();

	static const char s_pathGrossini[] = "Images/grossini.png";
    auto child = Sprite::create(s_pathGrossini);
    child->setPosition( 100,100);
    addChild(child, 1);

    //Sum of all action's duration is 1.5 second.
    child->runAction(RotateBy::create(1.5f, 90));
    child->runAction(Sequence::create(
                                            DelayTime::create(1.4f),
                                            FadeOut::create(1.1f),
                                            nullptr)
                    );
    
    //After 1.5 second, self will be removed.
    runAction( Sequence::create(
                                    DelayTime::create(1.4f),
                                  //  CallFunc::create( CC_CALLBACK_0(water::removeThis,this)),
                                    nullptr)
             );
}

void water::removeThis()
{
    _parent->removeChild(this, true);
}

std::string water::subtitle() const
{
    return "Test 1. Should not crash";
}
