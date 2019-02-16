#include "Node.h"
#include <iostream>

#include "GameFlow/Factories/EntityFactory.h"

ID_NODE_TYPE Node::nextIdForNode = 0;

Node::Node(LABEL_NODE_TYPE lnt)
	:node_ID(nextIdForNode++),node_type(lnt)
{
	std::cout << " Node was created" << std::endl;
	comp_container = std::make_shared<Container>();
}


Node::~Node()
{
}

LABEL_NODE_TYPE const Node::GetNodeType() const
{
	return node_type;
}

ID_NODE_TYPE const Node::GetNodeID() const
{
	return node_ID;
}

CONTAINER_PTR const Node::GetComponentContainer() const
{
	return comp_container;
}
//
//void Node::Update()
//{
//	for (auto comp : comp_container->GetContainerList()) {
//		comp->Update();
//	}
//}

//bool Node::RegisterDescripter(std::string key, Descriptor desc)
//{
//	auto factory = &EntityFactory::getInstance();
//	factory->RegisterDescripter(key,desc);
//
//	return true;
//}