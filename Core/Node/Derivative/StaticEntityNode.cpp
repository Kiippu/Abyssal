#include "StaticEntityNode.h"
#include  <iostream>



StaticEntityNode::StaticEntityNode()
	:Node(LABEL_NODE_TYPE::NODE_ENTITY)
{
	std::cout << "EntityNode was created" << std::endl;
	
}


StaticEntityNode::~StaticEntityNode()
{
}
