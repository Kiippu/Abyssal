#define _ENABLE_EXTENDED_ALIGNED_STORAGE

#include "Core/node/Component/Derivative/Render/Model3D.h"
#include "GameFlow/Updater/MasterUpdate.h"
#include "Core/Framework/Render/Model.h"
#include <functional>

#include <iostream>

struct Model3D::PImpl
{
	PImpl()
	{}
};


Model3D::Model3D()
	:ComponentUpdatable( LABEL_COMPONENT_TYPE::COMP_MODEL3D, LABEL_PRIORITY_TYPE::PRTY_HIGH, "3dModel")
	, m_impl(new PImpl)
{
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
	return m_model;
}

