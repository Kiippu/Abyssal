#define _DISABLE_EXTENDED_ALIGNED_STORAGE
#include "Container.h"

#include <iostream>
#include <memory>
#include <algorithm>
#include <string>


//components
//#include "Core/node/Component/Derivative/Render/AnimatedSprite.h"
//#include "Core/node/Component/Derivative/IO/ReadWrite.h"
#include "Core/node/Component/Derivative/Render/Model3D.h"

//#include "Core/node/Component/ComponentHeaders.h"


/*
TODO:
- link components to map keys, string?
- Component factory needed - this class needs to use factory to create components and them them to container
	- components add themselves to the container
	- entitys need to call componets from file.


*/

Container::Container()
{
	std::cout << "Container was created" << std::endl;
}


Container::~Container()
{
}

// pulls component out of container to use
COMPONENT_PTR Container::GetComponent(LABEL_COMPONENT_TYPE ct)
{
	for (auto c : ComponentContainer) {
		if (c->GetComponentType() == ct)
			return  c;
	}
	return nullptr;
}

// pulls component out of container to use
COMPONENT_PTR Container::GetComponent(std::string ct)
{
	for (auto c : ComponentContainer) {
		if (c->GetComponentTypeString() == ct)
			return  c;
	}
	return nullptr;
}

// checks to see it the componet already exists in the container
bool Container::hasComponent(LABEL_COMPONENT_TYPE ct)
{
	LABEL_COMPONENT_TYPE temp;
	for (auto c : ComponentContainer) {
		temp = c->GetComponentType();
		if (temp == ct)
			return true;
	}
	return false;
}

// gets the list of compnents
CONTAINER_LIST const & Container::GetContainerList() const
{
	return ComponentContainer;
}

// adds components to list after checking them
void Container::AddComponent(LABEL_COMPONENT_TYPE ct)
{
	//COMPONENT_PTR newComponent;
	if (!hasComponent(ct)) {
		// Creates components depending on what component type is passed
		switch (ct)
		{
			// Animated sprites
		case(LABEL_COMPONENT_TYPE::COMP_ANIMATED_SPRITE): {
			//newComponent = std::make_shared<AnimatedSprite>();
			break;
		}
		case(LABEL_COMPONENT_TYPE::COMP_READ_WRITE): {
			//newComponent = std::make_shared<ReadWrite>();
			break;
		}
		case(LABEL_COMPONENT_TYPE::COMP_MODEL3D): {
			auto newComponent = std::make_shared<Model3D>();
			ComponentContainer.push_back(newComponent);
			std::cout << "Model3D created!" << std::endl;
			break;
		}
		default:
			break;
		}
	}
	else
		std::cout << "LABLE_COMPONENT_TYPE " << ct << " already exists in the container" << std::endl;


	//ComponentContainer.push_back(newComponent);
	SortContainer();
}

void Container::RemoveComponent(LABEL_COMPONENT_TYPE ct)
{
}


// should override sort operator algorithm TEST ME
void Container::SortContainer()
{
	std::sort(ComponentContainer.begin(), ComponentContainer.end());
}



bool operator<(const COMPONENT_PTR & c1, const COMPONENT_PTR & c2)
{
	return c1->GetPriorityType() < c2->GetPriorityType();
}
