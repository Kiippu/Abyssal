#include "Core/node/Component/Derivative/Render/AnimatedSprite.h"
#include "Core/Node/Containers/PriorityType.h"
#include <iostream>

AnimatedSprite::AnimatedSprite()
	:ComponentUpdatable(LABEL_COMPONENT_TYPE::COMP_ANIMATED_SPRITE,LABEL_PRIORITY_TYPE::PRTY_LOWEST, "animatedSprite")
{
	std::cout << "AnimatedSprite created" << std::endl;
}

AnimatedSprite::~AnimatedSprite()
{
}

bool AnimatedSprite::Update()
{
	return false;
}

