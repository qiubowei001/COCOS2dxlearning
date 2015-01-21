
#include "water.h"


std::string shaders[] =
{
	"Shaders/WaterEffect1.fsh",
	"Shaders/WaterEffect2.fsh",
	"Shaders/WaterEffect3.fsh",
};

static int ShaderIndex = 2;
static int ShaderNum = sizeof(shaders) / sizeof(shaders[0]);

WaterEffectSprite* createWaterSprite()
{
	auto WinSize = Director::getInstance()->getWinSize();
	auto water = WaterEffectSprite::create("Images/HelloWorld.png", ShaderIndex);
	water->setPosition(WinSize.width / 2, WinSize.height / 2);
	return water;
}


WaterEffectSprite* WaterEffectSprite::create(const char *pszFileName, int ShaderIndex) {
	auto pRet = new (std::nothrow) WaterEffectSprite();
	if (pRet && pRet->initWithFile(pszFileName)) {
		pRet->autorelease();
	}
	else {
		CC_SAFE_DELETE(pRet);
	}
	pRet->initGLProgram(ShaderIndex);
	return pRet;
}

bool WaterEffectSprite::initWithTexture(Texture2D* texture, const Rect& rect) {
	if (Sprite::initWithTexture(texture, rect)) {
#if CC_ENABLE_CACHE_TEXTURE_DATA
		auto listener = EventListenerCustom::create(EVENT_RENDERER_RECREATED, [this](EventCustom* event) {
			setGLProgram(nullptr);
			initGLProgram();
		});

		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
#endif
		
		return true;
	}

	return false;
}

void WaterEffectSprite::initGLProgram(int ShaderIndex) {
	auto shaderPath = FileUtils::getInstance()->fullPathForFilename(shaders[ShaderIndex]);// "Shaders/WaterEffect.fsh");
	auto fragSource = (GLchar*)String::createWithContentsOfFile(shaderPath.c_str())->getCString();
	auto program = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, fragSource);

	auto glProgramState = GLProgramState::getOrCreateWithGLProgram(program);
	setGLProgramState(glProgramState);
}

void water::onEnter()
{
	LearningTest::onEnter();

	static const char s_pathGrossini[] = "Images/grossini.png";
    auto child = Sprite::create(s_pathGrossini);
    child->setPosition( 100,100);
    addChild(child, 1);

	mWater = createWaterSprite();
	addChild(mWater);
}

void water::removeThis()
{
    _parent->removeChild(this, true);
}

std::string water::subtitle() const
{
    return "Test 1. Should not crash";
}

void water::nextCallback(Ref* sender)
{
	ShaderIndex = ShaderIndex+1 < ShaderNum ? ShaderIndex+1 : 0;
	mWater->removeFromParent();

	mWater = createWaterSprite();
	addChild(mWater);
}