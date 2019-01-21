#include "AnimatedSprite.h"
#include <iostream>

AnimatedSprite::AnimatedSprite()
	:Component(LABEL_COMPONENT_TYPE::COMP_ANIMATED_SPRITE,LABEL_PRIORITY_TYPE::PRTY_LOWEST)
{
	std::cout << "AnimatedSprite created" << std::endl;
}


AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::Update()
{
	std::cout << "AnimatedSprite was updated" << std::endl;
	std::cout << "AnimatedSprite should update 1st" << std::endl;
}
