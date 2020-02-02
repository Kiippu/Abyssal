#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "Core/node/Component/Derivative/ComponentUpdatable.h"
#include <memory>
#include <glm/glm.hpp>


class Camera : public ComponentUpdatable
{
public:
	Camera();
	~Camera();

	virtual bool Update();
	virtual void Serialize();
	virtual void Deserialize(char*data);

	glm::mat4 getViewPerspective() const;

	void setLookAtPos(glm::vec3 pos);
	glm::vec3 const getLookAtPos();

private:

	struct PImpl;
	std::unique_ptr<PImpl> m_impl;  ///< private implementation data

};

//using MODEL_3D_PTR = std::shared_ptr<Model3D>;


#endif // !MODEL_3D_H
