#include "core/Component/Derivative/Update/UpdateCore.h"
#include "GameFlow/Updater/MasterUpdate.h"
#include "Core/Node/Node.h"
#include <iostream>

UpdateCore::UpdateCore()
	:Component(LABEL_COMPONENT_TYPE::COMP_ANIMATED_SPRITE,LABEL_PRIORITY_TYPE::PRTY_LOWEST)
{
	std::cout << "update created" << std::endl;
	m_masterUpdater = &MasterUpdate::getInstance();
	//m_updatables = std::vector<Node&>();
}


UpdateCore::~UpdateCore()
{
}

bool UpdateCore::AddToCoreUpdate(Node & node)
{
	//m_updatables.push_back(node);
	return true;
}
