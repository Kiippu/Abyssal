#pragma once

#include <memory>
#include <vector>

class Node;
class DynamicEntityNode;
class StaticEntityNode;


class GameObjects
{
public:
	static GameObjects & getInstance() {
		static GameObjects instance;
		return instance;
	}

private:
	// private constructor to impl singleton
	GameObjects();

	std::vector< std::shared_ptr<Node>> m_worldObjects;

	std::vector< std::shared_ptr<DynamicEntityNode>> m_worldDynamicObjects;

	std::vector< std::shared_ptr<StaticEntityNode>> m_worldStaticObjects;


public:

	std::vector< std::shared_ptr<Node>> & getAllObjects();

	std::vector< std::shared_ptr<DynamicEntityNode>> & getAllDynamicObjects();

	std::vector< std::shared_ptr<StaticEntityNode>> & getAllStaticicObjects();


	bool RegisterWorldObject(std::shared_ptr < Node> &);

	// Safety to delete any copies or new instances
	GameObjects(const GameObjects&) = delete;
	void operator=(GameObjects const&) = delete;

};

