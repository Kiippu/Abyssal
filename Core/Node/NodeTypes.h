#pragma once

#ifndef NODE_TYPES_H
#define NODE_TYPES_H

/*
creates the enum which makes the ID types which are used to attach
to the entities and then again used for collisions
*/
enum class LABEL_NODE_TYPE : unsigned
{
	NODE_ADVANCED = 0,
	NODE_ENTITY

};

typedef unsigned int ID_NODE_TYPE;





#endif
