#pragma once

#include "NodeTypes.h"
#include "Containers/Container.h"
#include <functional>


class Node
{
protected:
	explicit Node(LABEL_NODE_TYPE lnt);

public:
	
	virtual ~Node();

	// gets type name
	LABEL_NODE_TYPE const GetNodeType() const;
	ID_NODE_TYPE const GetNodeID() const;
	CONTAINER_PTR const GetComponentContainer() const;

	//holds next the incrememnted id tag
	static ID_NODE_TYPE			nextIdForNode;

private:
	//variable types to hold the enties ID and the type of object the entity is.
	ID_NODE_TYPE				node_ID;
	LABEL_NODE_TYPE				node_type;
	CONTAINER_PTR				comp_container;

};

