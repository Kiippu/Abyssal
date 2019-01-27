#pragma once
#ifndef MODEL_3D_H
#define MODEL_3D_H

//#include "Core/Component/Derivative/ComponentUpdatable.h"
#include "Core/Component/Derivative/ComponentUpdatable.h"
#include "Core/Render/Model.h"
#include <memory>

/*******************************************************************

							Model3D.h
			Component - Access to 3d model 


	TODO:
	- expand  and add SDL2.0 features

*********************************************************************/

//using MODEL_PTR = std::shared_ptr<Model>;


class Model3D : public ComponentUpdatable
{
public:
	Model3D();
	~Model3D();

	bool Update();

	Model & getModel();

private:

	std::shared_ptr<Model> m_model;

};

//using MODEL_3D_PTR = std::shared_ptr<Model3D>;


#endif // !MODEL_3D_H
