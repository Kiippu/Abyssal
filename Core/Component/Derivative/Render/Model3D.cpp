#define _ENABLE_EXTENDED_ALIGNED_STORAGE

#include "Core/Component/Derivative/Render/Model3D.h"
#include "GameFlow/Updater/MasterUpdate.h"
#include "Core/Render/Model.h"

#include <iostream>

Model3D::Model3D()
	:ComponentUpdatable(LABEL_COMPONENT_TYPE::COMP_MODEL3D,LABEL_PRIORITY_TYPE::PRTY_HIGH)
{
	m_model = std::make_shared<Model>();
	std::cout << "constructor - model3D" << std::endl;
}

Model3D::~Model3D()
{
}

bool Model3D::Update()
{
	return true;
}

Model & Model3D::getModel()
{
	return *m_model;
}

