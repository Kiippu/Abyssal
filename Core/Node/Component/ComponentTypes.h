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
	COMP_INPUT = 0,					// DONE
	COMP_ANIMATED_SPRITE,			//CREATED - NOT FINISHED
	COMP_READ_WRITE,				//CREATED - NOT FINISHED
	COMP_RENDER,					//CREATED - NOT FINISHED
	COMP_MODEL3D,
	COMP_NODE_CONTAINER,				//NEW IDEA - Component that has a container that holds nodes (item bags, inventory)
	COMP_CAMERA,



	COMP_ERROR = UINT_MAX

} LABEL_COMPONENT_TYPE;

typedef unsigned int ID_COMPONENT_TYPE;



#endif // 
