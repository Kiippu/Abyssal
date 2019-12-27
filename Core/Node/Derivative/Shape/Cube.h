#pragma once
#ifndef CUBE
#define CUBE

//std includes
#include <memory>

//Engine includes
#include "Core/Node/Derivative/DynamicEntityNode.h"
#include "Core/Framework/Render/Model.h"

class Model;

class Cube : public DynamicEntityNode
{
public:
	Cube();
	~Cube();

	bool Update();


private:

	//std::unique_ptr<Model> m_model;
};



#endif // !CUBE

