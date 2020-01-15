#pragma once
#ifndef MASTER_UPDATE_H
#define MASTER_UPDATE_H

#include <memory>
#include <vector>
//#include "Core/Render/Model.h"
//#include "Core/Node/Derivative/DynamicEntityNode.h"

#include "GameFlow/GameObjects/GameObjects.h"

class InputEventHandler;
class DynamicEntityNode;
class Cube;
class NetworkManager;


using DYNAMIC_ENTITY_PTR = std::shared_ptr<DynamicEntityNode>;

class MasterUpdate
{
public:
	static MasterUpdate & getInstance() {
		static MasterUpdate instance;
		return instance;
	}

private:
	// private constructor to impl singleton
	MasterUpdate();

	InputEventHandler * m_eventHandler;

	//Model model;

	//std::vector<DYNAMIC_ENTITY_PTR> m_EnityList;

	GameObjects * m_gameObjects;

	NetworkManager * m_networkManager;

	std::shared_ptr<Cube> cube;


public:
	// Safety to delete any copies or new instances
	MasterUpdate(const MasterUpdate&) = delete;
	void operator=(MasterUpdate const&) = delete;

	void Update();

	//void UpdateModel(Model &);

};




#endif 