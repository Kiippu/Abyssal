#include "EntityNode.h"
#include  <iostream>



EntityNode::EntityNode()
	:Node(LABEL_NODE_TYPE::NODE_ENTITY)
{
	std::cout << "EntityNode was created" << std::endl;
	
}


EntityNode::~EntityNode()
{
}
