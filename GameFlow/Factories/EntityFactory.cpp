#include "EntityFactory.h"
#include "Core/IO/FileSystemHelper.h"
#include "GameFlow/GameObjects/GameObjects.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>



template<typename Out>
void split(const std::string &s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

EntityFactory::EntityFactory()
{
	m_fileSystemHelper = &FileSystemHelper::getInstance();
	m_gameObjects = &GameObjects::getInstance();
}

bool EntityFactory::ImportEntities()
{
	std::string data = m_fileSystemHelper->ReadFile(m_path.string().c_str());

	std::vector<std::string> line = split(data, '\n');
	//std::string firstWord = data.substr(0, data.find(" "));
	
	for (auto & singleLine : line)
	{

		std::vector<std::string> word = split(data, ' ');


		//std::cout << word << std::endl;
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
