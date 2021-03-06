#pragma once
#ifndef CONTAINER_H
#define CONTAINER_H

#include <list>
#include <map>
#include <functional>
#include "Core/Node/Component/Component.h"
#include "Core/Node/Component/ComponentTypes.h"
#include "Core/Node/Containers/PriorityType.h"
#include "Core/Node/Containers/ContainerSort.h"

#include <queue>
#include <vector>

/*******************************************************************

							Container.h
		Container class which holds components for nodes

*********************************************************************/
// change this to a map
using CONTAINER_LIST = std::vector<COMPONENT_PTR>;

class Container
{
public:
	Container(Node*);
	~Container();
	// finds out if a component exists in the container
	bool hasComponent(LABEL_COMPONENT_TYPE ct);

	// gets a component out of the container to access it, if it exists
	COMPONENT_PTR GetComponent(LABEL_COMPONENT_TYPE ct);
	// gets a component out of the container to access it, if it exists
	// @param type name of component
	COMPONENT_PTR GetComponent(std::string ct);

	//get component contain list
	CONTAINER_LIST const & GetContainerList() const;

	// Add a component to the containers list
	void AddComponent(LABEL_COMPONENT_TYPE ct);

	//remove a component
	void RemoveComponent(LABEL_COMPONENT_TYPE ct);

	//sort container
	void SortContainer();

private:
	// list of components belonging to parent
	CONTAINER_LIST		ComponentContainer;
	// parent node from entity
	Node * m_parentNode;
	// private implementation data
	struct PImpl;
	std::unique_ptr<PImpl> m_impl;
};

using CONTAINER_PTR = std::shared_ptr<Container>;

// overrides < operator
bool operator<(const Component & c1, const Component & c2);

#endif


