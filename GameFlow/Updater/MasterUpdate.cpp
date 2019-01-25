#include "GameFlow/Updater/MasterUpdate.h"
#include "Core/Events/EventHandler.h"
#include "Core/Render/Renderer.h"
#include "Core/Render/Model.h"
#include "Core/Math/Math.h"

MasterUpdate::MasterUpdate()
{
	m_eventHandler = &EventHandler::getInstance();
	//model = std::make_shared<Model>();

	// Handles a single model with its vertexes and matrix
}

void MasterUpdate::Update(Model & model)
{
	while (!m_eventHandler->WasQuit())
	{
		// Update our event handler
		m_eventHandler->Update();
		
		UpdateModel(model);

		Renderer::getInstance().Render(model);
	}
}

void MasterUpdate::UpdateModel(Model & model)
{
	
	if (m_eventHandler->IsKeyDown(SDLK_r))
	{
		model.ResetMatrix();
	}
	else
	{
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
			glm::vec3 axis = Math::GetAxis(*m_eventHandler);
			model.Translate(axis);
		}
	}
}
