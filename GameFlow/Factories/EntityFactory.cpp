#include "EntityFactory.h"
#include <algorithm>
//#include "Core/Node/Component/ComponentTypes.h"
//#include "Core/Node/Derivative/Shape/Cube.h"
#include "Core/Node/componentLabelConverter.h"
#include "Core/Node/Derivative/DynamicEntityNode.h"

EntityFactory::EntityFactory()
{
	m_labelConverter = &componentLabelConverter::getInstance();
	setMasterPath("Debug/Data/Entities/EntityList.txt");
	ImportEntities();
	create("cube_geometry");
	create("camera");

}

bool EntityFactory::ImportEntities()
{
	std::string data = getFileSystemHelper()->ReadFile(getMasterPath().string().c_str());

	std::vector<std::string> entityData = split(data, '{');
	//std::string firstWord = data.substr(0, data.find(" "));
	
	for (auto & config : entityData)
	{
		entityConfig entData;
		std::vector<std::string> line = split(config, '\n');

		for (auto & lineSection : line)
		{
			if (lineSection.size() > 0)
			{
				lineSection.erase(std::remove(lineSection.begin(), lineSection.end(), ' '), lineSection.end());
				lineSection.erase(std::remove(lineSection.begin(), lineSection.end(), '\"'), lineSection.end());
				lineSection.erase(std::remove(lineSection.begin(), lineSection.end(), '\n'), lineSection.end());
				lineSection.erase(std::remove(lineSection.begin(), lineSection.end(), '\t'), lineSection.end());
				if (lineSection != "}") {
					std::vector<std::string> keyPair = split(lineSection, ':');

					if (keyPair[1].find('[') != std::string::npos)
					{
						keyPair[1].erase(std::remove(keyPair[1].begin(), keyPair[1].end(), '['), keyPair[1].end());
						keyPair[1].erase(std::remove(keyPair[1].begin(), keyPair[1].end(), ']'), keyPair[1].end());
						std::vector<std::string> arrayData = split(keyPair[1], ',');
						setKeyValue(entData, keyPair[0], arrayData);
					}
					else
					{
						std::vector<std::string> subData;
						subData.push_back(keyPair[1]);
						setKeyValue(entData, keyPair[0], subData);
					}
				}
			}
		}
		if(entData.key.size() > 0)
			m_entityConfigurationList.insert(std::make_pair(entData.key,std::make_unique<entityConfig>(entData)));
		
	}
	return false;
}


bool EntityFactory::setKeyValue(entityConfig& config, std::string key, std::vector<std::string> val)
{
	if (key == "key")
		config.key = val[0];
	else if (key == "name")
		config.name = val[0];
	else if (key == "type")
		config.type = val[0];
	else if (key == "component")
		config.components = val;
	else if (key == "entityType")
		config.entityType = val[0];
	else
		return false;
	return true;
}

unsigned EntityFactory::create(std::string key)
{
	auto itr = m_entityConfigurationList.find(key);
	if (itr != m_entityConfigurationList.end())
	{
		auto& descriptor = itr->second;
		std::shared_ptr<Node> node;
		if (descriptor->type == "dynamic") {
			node = std::make_shared<DynamicEntityNode>();
		}
		else if(descriptor->type == "static") {
			node = std::make_shared<DynamicEntityNode>();
		}
		for (auto& comp : descriptor->components)
		{
			auto label = m_labelConverter->getLebel(comp);
			node->GetComponentContainer()->AddComponent(label);
			/*node->GetComponentContainer()->AddComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D);
			node->GetComponentContainer()->AddComponent(LABEL_COMPONENT_TYPE::COMP_READ_WRITE);
			node->GetComponentContainer()->AddComponent(LABEL_COMPONENT_TYPE::COMP_INPUT);*/
		}

		getGameObjects()->RegisterWorldObject(node);

		return node->GetNodeID();

		/*std::shared_ptr<Cube> cube;

		cube = std::make_shared<Cube>();

		cube->GetComponentContainer()->AddComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D);

		std::shared_ptr<Node> node = std::dynamic_pointer_cast<Node>(cube);

		getGameObjects()->RegisterWorldObject(node);*/
	}
	return 0;
}
bool EntityFactory::addUniqueEntityConfig(std::unique_ptr<entityConfig> config)
{
	return false;
}
//
//bool EntityFactory::RegisterDescripter(std::string key, Descriptor & desc)
//{
//	descriptorObj descipt();
//	m_objectDescripters.insert(std::make_pair(key, std::move(desc)));
//	return true;
//}
//
//bool EntityFactory::createNode(std::string key)
//{
//	auto & node = m_objectDescripters.at(key);
//
//	//auto modelComponent = obj->GetComponentContainer()->GetComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D);
//	descriptorObj & model3D = dynamic_cast<descriptorObj&>(*node);
//
//
//	m_gameObjects->RegisterWorldObject(node);
//}
