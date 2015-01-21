#include "cocos2d.h"
#include "LearningTest.h"


#ifndef __WATER_EFFECT_SPRITE_H__
#define __WATER_EFFECT_SPRITE_H__

USING_NS_CC;

class WaterEffectSprite : public Sprite {
public:
	static WaterEffectSprite* create(const char *pszFileName, int ShaderIndex);
public:
	bool initWithTexture(Texture2D* texture, const Rect&  rect);
	void initGLProgram(int ShaderIndex);
};

#endif

class water : public LearningTest
{
private:
	WaterEffectSprite* mWater;
public:
	virtual std::string subtitle() const override;
	virtual void onEnter() override;
	void removeThis();
	void nextCallback(Ref* sender);
};

