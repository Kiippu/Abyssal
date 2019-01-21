#pragma once
#ifndef COMPONENT_TYPES_H
#define COMPONENT_TYPES_H

/*******************************************************************

						componentTypes.h
		All the component types that are able to be added to nodes


	TODO :
	- expand with each new component

*********************************************************************/

typedef enum : unsigned int
{
	COMP_INPUT = 0,					//NOT DONE
	COMP_ANIMATED_SPRITE,			//CREATED - NOT FINISHED
	COMP_PHYSICS,					//NOT DONE
	COMP_COLLISION,					//NOT DONE
	COMP_DELTA_TIME,				//NOT DONE
	COMP_ENTITY,					//NOT DONE
	COMP_CONTROL,					//NOT DONE
	COMP_READ_WRITE,				//CREATED - NOT FINISHED
	COMP_RENDER,					//CREATED - NOT FINISHED
	COMP_NODE_CONTAINER				//NEW IDEA - Component that has a container that holds nodes (item bags, inventory)

} LABEL_COMPONENT_TYPE;

typedef unsigned int ID_COMPONENT_TYPE;


#endif // 
