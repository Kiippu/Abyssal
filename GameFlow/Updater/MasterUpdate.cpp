#include "GameFlow/Updater/MasterUpdate.h"
#include "Core/Events/EventHandler.h"
#include "Core/Render/Renderer.h"
#include "Core/Render/Model.h"
#include "Core/Math/Math.h"

MasterUpdate::MasterUpdate()
{
	m_eventHandler = std::make_unique<EventHandler>();

	Model m;
	model = &m;

	// Handles a single model with its vertexes and matrix
}

void MasterUpdate::Update()
{
	while (!m_eventHandler->WasQuit())
	{
		// Update our event handler
		Update();

		// Update our model position
		UpdateModel();

		Renderer::getInstance().Render(*model);
	}
}

void MasterUpdate::UpdateModel()
{
	
	if (m_eventHandler->IsKeyDown(SDLK_r))
	{
		model->ResetMatrix();
	}
	else
	{
		if (m_eventHandler->IsKeyDown(SDLK_LCTRL))
		{
			glm::vec3 axis = Math::GetRotationAxis(*m_eventHandler);

			if (axis != glm::vec3(0.0f))
				model->Rotate(axis);
		}
		else if (m_eventHandler->IsKeyDown(SDLK_LSHIFT))
		{
			glm::vec3 axis = Math::GetScaleAxis(*m_eventHandler);
			model->Scale(axis);
		}
		else
		{
			glm::vec3 axis = Math::GetAxis(*m_eventHandler);
			model->Translate(axis);
		}
	}
}
