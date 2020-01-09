#define _DISABLE_EXTENDED_ALIGNED_STORAGE
#include "Container.h"

#include <iostream>
#include <memory>
#include <algorithm>
#include <string>


//components
//#include "Core/node/Component/Derivative/Render/AnimatedSprite.h"
#include "Core/node/Component/Derivative/IO/ReadWrite.h"
#include "Core/node/Component/Derivative/Render/Model3D.h"
#include "Core/node/Component/Derivative/IO/inputHandler.h"

#include "GameFlow/Factories/ComponentFactory.h"
#include "Core/Node/componentLabelConverter.h"


//#include "Core/node/Component/ComponentHeaders.h"


/*
TODO:
- link components to map keys, string?
- Component factory needed - this class needs to use factory to create components and them them to container
	- components add themselves to the container
	- entitys need to call componets from file.


*/


struct Container::PImpl
{
	PImpl()
	{
	}
	// component Factory
	ComponentFactory * m_componentFactory = &ComponentFactory::getInstance();
	componentLabelConverter *m_labelConverter = &componentLabelConverter::getInstance();
};

Container::Container(Node* node) : m_impl(new PImpl)
{
	std::cout << "Container was created" << std::endl;
	m_parentNode = node;
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

		// imple function componet creation here
		auto label = m_impl->m_labelConverter->getLabel(ct);
		unsigned id = m_impl->m_componentFactory->create(label);

		auto componentPair = m_impl->m_componentFactory->getComponetPair(id);
		componentPair.second->SetParent(m_parentNode);
		//auto component = *componentPair.second;
		//COMPONENT_PTR component_ptr = std::make_shared<Component>(component);
		ComponentContainer.push_back(componentPair.second);
		//std::cout << "inputHandler created!" << std::endl;

		/*auto itr = s_componentFactory.find(ct);
		if (itr != s_componentFactory.end()) {
			if (itr->second())
				std::cout << "Container - added component " << this->GetComponent(ct)->GetComponentTypeString() << std::endl;
		}*/
		//

		// Creates components depending on what component type is passed
	//	switch (ct)
	//	{
	//		// Animated sprites
	//	case(LABEL_COMPONENT_TYPE::COMP_ANIMATED_SPRITE): {
	//		//newComponent = std::make_shared<AnimatedSprite>();
	//		break;
	//	}
	//	case(LABEL_COMPONENT_TYPE::COMP_READ_WRITE): {
	//		auto newComponent = std::make_shared<ReadWrite>();
	//		ComponentContainer.push_back(newComponent);
	//		std::cout << "ReadWrite created!" << std::endl;
	//		break;
	//	}
	//	case(LABEL_COMPONENT_TYPE::COMP_INPUT): {
	//		auto newComponent = std::make_shared<inputHandler>();
	//		ComponentContainer.push_back(newComponent);
	//		std::cout << "inputHandler created!" << std::endl;
	//		break;
	//	}
	//	case(LABEL_COMPONENT_TYPE::COMP_MODEL3D): {
	//		auto newComponent = std::make_shared<Model3D>();
	//		ComponentContainer.push_back(newComponent);
	//		std::cout << "Model3D created!" << std::endl;
	//		break;
	//	}
	//	default:
	//		break;
	//	}
	}
	//else
	//	std::cout << "LABLE_COMPONENT_TYPE " << ct << " already exists in the container" << std::endl;


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



bool operator<(const Component & c1, const Component & c2)
{
	return c1.GetPriorityType() < c2.GetPriorityType();
}
