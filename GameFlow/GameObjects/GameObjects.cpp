#include "GameObjects.h"
#include <memory>

#include "Core/Node/Derivative/DynamicEntityNode.h"
#include "Core/Node/Derivative/StaticEntityNode.h"


GameObjects::GameObjects()
{
	
}



std::vector<std::shared_ptr<Node>>& GameObjects::getAllObjects()
{
	return m_worldObjects;
}

std::vector< std::shared_ptr<DynamicEntityNode>>& GameObjects::getAllDynamicObjects()
{
	return m_worldDynamicObjects;
}

bool GameObjects::RegisterWorldObject(std::shared_ptr<Node> & object)
{

	m_worldObjects.push_back(object);
	//DynamicEntityNode * dynamic = dynamic_cast<DynamicEntityNode*>(object);

	std::shared_ptr<DynamicEntityNode> dynamic = std::dynamic_pointer_cast<DynamicEntityNode>(object);
	std::shared_ptr<StaticEntityNode> statics = std::dynamic_pointer_cast<StaticEntityNode>(object);

	//auto statics = dynamic_cast<StaticEntityNode*>(*object);
	
	if (dynamic != NULL)
	{
		m_worldDynamicObjects.push_back(dynamic);
		return true;
	}
	else if (statics != NULL)
	{
		m_worldStaticObjects.push_back(statics);
		return true;
	}
	return false;
}

