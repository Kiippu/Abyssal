#include "EntityFactory.h"


EntityFactory::EntityFactory()
{
	setMasterPath("Data/Entities/EntityList.txt");
}

bool EntityFactory::ImportEntities()
{
	std::string data = getFileSystemHelper()->ReadFile(getMasterPath().string().c_str());

	std::vector<std::string> line = split(data, '\n');
	//std::string firstWord = data.substr(0, data.find(" "));
	
	for (auto & singleLine : line)
	{

		printf("entity-singleLine: %s\n", singleLine.c_str());
		std::vector<std::string> word = split(data, ' ');

		printf("entity: %s\n", word[0].c_str());
		//std::cout << word[word.size()-1] << std::endl;

		//TODO: SERIALIZE FILE DATA for entities!
		// CALL COMPONENT FACTORY!
	}


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
