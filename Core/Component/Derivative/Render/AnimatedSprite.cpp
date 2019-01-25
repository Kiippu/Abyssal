#include "Core/Component/Derivative/Render/AnimatedSprite.h"
#include <iostream>

AnimatedSprite::AnimatedSprite()
	:Component(LABEL_COMPONENT_TYPE::COMP_ANIMATED_SPRITE,LABEL_PRIORITY_TYPE::PRTY_LOWEST)
{
	std::cout << "AnimatedSprite created" << std::endl;
}


AnimatedSprite::~AnimatedSprite()
{
}
