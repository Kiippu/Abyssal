#define _ENABLE_EXTENDED_ALIGNED_STORAGE

#include "GameFlow/Updater/MasterUpdate.h"
#include "Core/Node/Derivative/DynamicEntityNode.h"
#include "Core/Events/EventHandler.h"
#include "Core/Render/Renderer.h"
#include "Core/Render/Model.h"
#include "Core/Math/Math.h"
#include "Core/Node/Derivative/Shape/Cube.h"

#include "Core/Node/Derivative/Shape/Cube.h"

#include "Core/Component/Derivative/Render/Model3D.h"

MasterUpdate::MasterUpdate()
{
	m_eventHandler = &EventHandler::getInstance();
	//model = std::make_shared<Model>();

	cube = std::make_shared<Cube>();
	
	cube->GetComponentContainer()->AddComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D);
	
	m_EnityList.push_back(cube);

	// Handles a single model with its vertexes and matrix
}

void MasterUpdate::Update()
{
	while (!m_eventHandler->WasQuit())
	{
		// Update our event handler
		m_eventHandler->Update();

		for (long i = 0; i < m_EnityList.size(); i++)
		{
			m_EnityList[i]->Update();
		}
		
		
		for (long i = 0; i < m_EnityList.size(); i++)
		{
			m_EnityList[i]->Update();
			if (m_EnityList[i]->GetComponentContainer()->hasComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D))
			{
				auto modelComponent = m_EnityList[i]->GetComponentContainer()->GetComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D);
				Model3D & model = dynamic_cast<Model3D&>(*modelComponent);
				Renderer::getInstance().Render(model.getModel());
			}
		}
		//UpdateModel(model);

		// TODO: model update!!!!!!!!!!!!!

		
	}
}
//
//void MasterUpdate::UpdateModel(Model & model)
//{
//	
//	if (m_eventHandler->IsKeyDown(SDLK_r))
//	{
//		model.ResetMatrix();
//	}
//	else
//	{
//		if (m_eventHandler->IsKeyDown(SDLK_LCTRL))
//		{
//			glm::vec3 axis = Math::GetRotationAxis(*m_eventHandler);
//
//			if (axis != glm::vec3(0.0f))
//				model.Rotate(axis);
//		}
//		else if (m_eventHandler->IsKeyDown(SDLK_LSHIFT))
//		{
//			glm::vec3 axis = Math::GetScaleAxis(*m_eventHandler);
//			model.Scale(axis);
//		}
//		else
//		{
//			glm::vec3 axis = Math::GetAxis(*m_eventHandler);
//			model.Translate(axis);
//		}
//	}
//}
