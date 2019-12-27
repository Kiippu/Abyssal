#include "Cube.h"
#include "Core/Framework/Events/InputEventHandler.h"
#include "Core/Node/Component/Derivative/Render/Model3D.h"
#include "Core/MathHelpers/Math/Math.h"

//InputEventHandler * m_eventHandler = &InputEventHandler::getInstance();

Cube::Cube()
{}

Cube::~Cube()
{}

bool Cube::Update()
{
	 //auto component = GetComponentContainer()->GetComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D);
	 //if (component != nullptr)
	 //{
		// Model3D & modelComponent = dynamic_cast<Model3D&>(*component);
		// auto & model = modelComponent.getModel();

		// //Model model;

		// if (m_eventHandler->IsKeyDown(SDLK_r))
		// {
		//	 model.ResetMatrix();
		// }
		// else
		// {
		//	 if (m_eventHandler->IsKeyDown(SDLK_LCTRL))
		//	 {
		//		 glm::vec3 axis = Math::GetRotationAxis(*m_eventHandler);

		//		 if (axis != glm::vec3(0.0f))
		//			 model.Rotate(axis);
		//	 }
		//	 else if (m_eventHandler->IsKeyDown(SDLK_LSHIFT))
		//	 {
		//		 glm::vec3 axis = Math::GetScaleAxis(*m_eventHandler);
		//		 model.Scale(axis);
		//	 }
		//	 else
		//	 {
		//		 glm::vec3 axis = Math::GetAxis(*m_eventHandler);
		//		 model.Translate(axis);
		//	 }
		// }
	 //}
	return true;
}

