#pragma once

#include "NodeTypes.h"
#include "Containers/Container.h"
#include <functional>
#include <glm/glm.hpp>

struct transform {
	transform() {}
	transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 sc) {
		worldPosition = pos;
		rotate = rot;
		scale = sc;
	}
	glm::vec3 worldPosition = glm::vec3(0);
	glm::vec3 scale = glm::vec3(0);
	glm::vec3 rotate = glm::vec3(0);
};

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
	transform const GetTransfrom();

	void setWorldTransform(const transform);

	//holds next the incrememnted id tag
	static ID_NODE_TYPE			nextIdForNode;

private:
	//variable types to hold the enties ID and the type of object the entity is.
	ID_NODE_TYPE				node_ID;
	LABEL_NODE_TYPE				node_type;
	CONTAINER_PTR				comp_container;
	transform					m_transform;

};

