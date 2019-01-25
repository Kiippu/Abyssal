#pragma once
#ifndef UPDATE_CORE_H
#define UPDATE_CORE_H

#include "Core/Component/Component.h"
#include <vector>
#include <memory>

class MasterUpdate;

/*******************************************************************

							UpdateCore.h
			Component - node will update in core thread 


*********************************************************************/

class Node;

class UpdateCore : public Component
{
public:
	UpdateCore();
	~UpdateCore();

	bool AddToCoreUpdate(Node & node);

private:

	MasterUpdate * m_masterUpdater;

	//std::vector<Node&> m_updatables;

};

using UPDATE_CORE_PTR = std::shared_ptr<UpdateCore>;


#endif // !UPDATE_CORE_H
