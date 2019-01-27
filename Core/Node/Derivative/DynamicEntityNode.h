#pragma once
#ifndef DYNAMIC_ENTITY_NODE_H
#define DYNAMIC_ENTITY_NODE_H

#include "Core/Node/Node.h"


class DynamicEntityNode : public Node
{
public:
	DynamicEntityNode();
	~DynamicEntityNode();

	virtual bool Update() = 0;

private:


};






#endif // !DYNAMIC_ENTITY_NODE_H


