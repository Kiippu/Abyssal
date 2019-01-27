#include "Cube.h"
#include "Core/Events/EventHandler.h"
#include "Core/Component/Derivative/Render/Model3D.h"
#include "Core/Math/Math.h"

EventHandler * m_eventHandler = &EventHandler::getInstance();

Cube::Cube()
{
}


Cube::~Cube()
{
}

bool Cube::Update()
{
	 auto component = GetComponentContainer()->GetComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D);
	 if (component)
	 {
		 Model3D & modelComponent = dynamic_cast<Model3D&>(*component);
		 //auto model = modelComponent.getModel();

		 Model model;

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
	 


	return true;
}
