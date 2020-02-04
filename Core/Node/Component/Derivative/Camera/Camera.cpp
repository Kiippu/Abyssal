#include "GameFlow/Updater/MasterUpdate.h"
#include "Core/Node/Component/Derivative/Camera/Camera.h"
#include "Core/Node/Node.h"

#define GL3_PROTOTYPES 1
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <iostream>

struct Camera::PImpl
{
	PImpl(){}
	glm::vec3 position = glm::vec3(0,0,0);
	glm::vec3 forward = glm::vec3(0,0,1);
	glm::vec3 up = glm::vec3(0,1,0);

	glm::vec3 lookAtPos = glm::vec3();

	float fieldOfView = 70.f; // close to human eye
	float aspectRatio = 0.f;
	float minDis = 0.1f;
	float maxDis = 1000.f;
	glm::mat4 perspective = glm::perspective
	(
		fieldOfView,		// Field of view ( how far out to the sides we can see
		1600.f / 900.f,		// Aspect ratio ( stretch image in widh or height )
		minDis,				// Near plane ( anything close than this will be cut off )
		maxDis				// Far plane ( anything further away than this will be cut off )
	);
};

Camera::Camera()
	:ComponentUpdatable( LABEL_COMPONENT_TYPE::COMP_CAMERA, LABEL_PRIORITY_TYPE::PRTY_HIGH, "camera")
	, m_impl(new PImpl)
{
}

Camera::~Camera()
{
}

bool Camera::Update()
{
	auto p = m_impl->position.length();

	if (m_impl->position == glm::vec3(0,0,0)) {
		auto trans = GetParent()->GetTransfrom();
		trans.worldPosition = glm::vec3(0, -10, 20);
		GetParent()->setWorldTransform(trans);
	}
	auto pos = GetParent()->GetTransfrom().worldPosition;
	m_impl->position = glm::vec3(pos);
	return true;
}

void Camera::Serialize()
{
	printf("Serializing %s", GetComponentTypeString().c_str());
}

void Camera::Deserialize(char*data)
{
	printf("Deserializing %s", GetComponentTypeString().c_str());
}

glm::mat4 Camera::getViewPerspective() const
{
	//auto view = glm::lookAt
	//(
	//	glm::vec3(0, 0, -4), // Camera is at (0,0,-4), in World Space
	//	glm::vec3(0, 0, 0),  // And looks at the origin
	//	glm::vec3(0, -1, 0)  // Head is up ( set to 0,-1,0 to look upside-down )
	//);
	auto view = glm::lookAt(m_impl->position, m_impl->lookAtPos , m_impl->up);//(m_impl->position + m_impl->forward)
	return (m_impl->perspective * view);// 
}

glm::vec3 const Camera::getLookAtPos()
{
	return m_impl->lookAtPos;
}

void Camera::setLookAtPos(glm::vec3 pos)
{
	m_impl->lookAtPos = pos;
}


