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

	auto component = GetComponentContainer()->GetComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D);
	if (component != nullptr)
	{

		Model3D & modelComponent = dynamic_cast<Model3D&>(*component);
		auto & model = modelComponent.getModel();

		//update input component;
		/*auto inputComponentPtr = GetComponentContainer()->GetComponent(LABEL_COMPONENT_TYPE::COMP_INPUT);
		if (inputComponentPtr != nullptr) {
			inputHandler & inputComponent = dynamic_cast<inputHandler&>(*inputComponentPtr);
			inputComponent.Update();
		}*/
		
		

		/*if (m_eventHandler->IsKeyDown(SDLK_r))
		{
			model.ResetMatrix();
		}
		else*/
		//{
			if (m_eventHandler->IsKeyDown(SDLK_LCTRL))
			{
				glm::vec3 axis = Math::GetRotationAxis(*m_eventHandler);

				if (axis != glm::vec3(0.0f))
					model.Rotate(axis);
			}
			else if (m_eventHandler->IsKeyDown(SDLK_LSHIFT))
			{
				glm::vec3 axis = Math::GetScaleAxis(*m_eventHandler);
				model.Scale(axis);
			}
			else
			{
				//glm::vec3 axis = Math::GetAxis(*m_eventHandler);
				//model.Translate(axis);
			}
		//}
	}

	return true;
	
}