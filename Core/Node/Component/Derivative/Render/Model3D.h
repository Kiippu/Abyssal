#pragma once
#ifndef MODEL_3D_H
#define MODEL_3D_H

//#include "Core/Component/Derivative/ComponentUpdatable.h"
#include "Core/node/Component/Derivative/ComponentUpdatable.h"
#include "Core/Framework/Render/Model.h"
#include <memory>

/*******************************************************************

							Model3D.h
			Component - Access to 3d model 


*********************************************************************/

//using MODEL_PTR = std::shared_ptr<Model>;

class Model3D : public ComponentUpdatable
{
public:
	Model3D();
	~Model3D();

	virtual bool Update();
	virtual void Serialize();
	virtual void Deserialize(char*data);

	Model & getModel();

private:

	Model m_model;
	struct PImpl;
	std::unique_ptr<PImpl> m_impl;  ///< private implementation data

};

//using MODEL_3D_PTR = std::shared_ptr<Model3D>;


#endif // !MODEL_3D_H
