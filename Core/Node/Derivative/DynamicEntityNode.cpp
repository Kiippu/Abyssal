#include "DynamicEntityNode.h"
#include  <iostream>



DynamicEntityNode::DynamicEntityNode()
	:Node(LABEL_NODE_TYPE::NODE_ENTITY)
{
	std::cout << "EntityNode was created" << std::endl;
	
}


DynamicEntityNode::~DynamicEntityNode()
{
}
