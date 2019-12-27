#pragma once
#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "Core/node/Component/Derivative/ComponentUpdatable.h"


/*******************************************************************

							AnimatedSprite.h
			Component - Access to animated sprite sheets 


	TODO:
	- expand  and add SDL2.0 features

*********************************************************************/

class AnimatedSprite : public ComponentUpdatable
{
public:
	AnimatedSprite();
	~AnimatedSprite();

	bool Update();

};

using ANIMATED_SPRITE_PTR = std::shared_ptr<AnimatedSprite>;


#endif // !ANIMATED_SPRITE_H
