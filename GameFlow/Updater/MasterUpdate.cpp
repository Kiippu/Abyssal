#define _ENABLE_EXTENDED_ALIGNED_STORAGE

#include "GameFlow/Updater/MasterUpdate.h"
#include "Core/Node/Derivative/DynamicEntityNode.h"
#include "Core/Framework/Events/InputEventHandler.h"
#include "Core/Framework/Render/Renderer3D.h"
#include "Core/Framework/Render/Model.h"
#include "Core/MathHelpers/Math/Math.h"
#include "Core/Node/Derivative/Shape/Cube.h"
#include "Core/Framework/Networking/NetworkManager.h"

#include "Core/Node/Derivative/Shape/Cube.h"

#include "Core/node/Component/Derivative/Render/Model3D.h"

MasterUpdate::MasterUpdate()
{
	m_gameObjects = &GameObjects::getInstance();
	m_eventHandler = &InputEventHandler::getInstance();
	m_networkManager = &NetworkManager::getInstance();
	//model = std::make_shared<Model>();

	/*cube = std::make_shared<Cube>();
	
	cube->GetComponentContainer()->AddComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D);
	

	std::shared_ptr<Node> node = std::dynamic_pointer_cast<Node>(cube);

	m_gameObjects->RegisterWorldObject(node);*/
	//m_EnityList.push_back(cube);



	// Handles a single model with its vertexes and matrix
}

void MasterUpdate::Update()
{
	while (!m_eventHandler->WasQuit())
	{

		auto & dynamicObjects = m_gameObjects->getAllDynamicObjects();
		// Update our event handler
		/// TODO: make isHost work!!
		if (m_networkManager->isHost() || true)
			m_eventHandler->Update();
		else
			m_networkManager->Update();

		
		// Render scene
		for (auto & obj : dynamicObjects)
		{
			//m_EnityList[i]->Update();
			if (obj->GetComponentContainer()->hasComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D))
			{
				auto modelComponent = obj->GetComponentContainer()->GetComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D);
				Model3D & model3D = dynamic_cast<Model3D&>(*modelComponent);
				
				auto & model = model3D.getModel();

				Renderer3D::getInstance().Render(model);
			}
		}

		// update dynamic objects
		for (auto & obj : dynamicObjects)
		{
			obj->Update();
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
