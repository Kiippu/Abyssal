#pragma once
#ifndef ENTITY_NODE_H
#define ENTITY_NODE_H

#include "Core/Node/Node.h"


class EntityNode : public Node
{
public:
	EntityNode();
	~EntityNode();

};

using ENTITY_NODE_PTR = std::shared_ptr<EntityNode>;





#endif // !ENTITY_NODE_H


