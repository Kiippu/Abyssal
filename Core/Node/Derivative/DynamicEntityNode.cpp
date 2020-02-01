#include "DynamicEntityNode.h"

#include "Core/Node/Component/Derivative/ComponentUpdatable.h"

#include "Core/Framework/Events/InputEventHandler.h"
#include "Core/Node/Component/Derivative/Render/Model3D.h"
#include "Core/Node/Component/Derivative/IO/inputHandler.h"
#include "Core/MathHelpers/Math/Math.h"

#include  <iostream>


InputEventHandler * m_eventHandler = &InputEventHandler::getInstance();

DynamicEntityNode::DynamicEntityNode()
	:Node(LABEL_NODE_TYPE::NODE_ENTITY)
{
	std::cout << "EntityNode was created" << std::endl;
}


DynamicEntityNode::~DynamicEntityNode()
{
}

bool DynamicEntityNode::Update()
{
	// get list of updatable comps and run their updates
	auto list = GetComponentContainer();
	for (auto* comp : list->GetContainerList())
	{
		//ComponentUpdatable
		auto& updatable = dynamic_cast<ComponentUpdatable&>(*comp);
		updatable.Update();
	}


	return true;
	
}