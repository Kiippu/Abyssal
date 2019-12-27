#pragma once
#ifndef Entity_Factory_H
#define Entity_Factory_H

#include "IFactory.h"
#include <map>

class componentLabelConverter;

using namespace std::experimental::filesystem;

struct entityConfig
{
	std::string key;
	std::string name;
	std::string type;
	std::vector<std::string> components;
	std::string entityType;
};

class EntityFactory : public IFactory
{
public:
	static EntityFactory & getInstance() {
		static EntityFactory instance;
		return instance;
	}

private:
	// private constructor to impl singleton
	EntityFactory();

	virtual bool ImportEntities();
	virtual bool setKeyValue(entityConfig&,std::string, std::vector<std::string>);
	
	std::map<std::string,std::unique_ptr<entityConfig>> m_entityConfigurationList;

	componentLabelConverter* m_labelConverter;


public:
	// Safety to delete any copies or new instances
	EntityFactory(const EntityFactory&) = delete;
	void operator=(EntityFactory const&) = delete;

	virtual unsigned create(std::string);
	virtual bool addUniqueEntityConfig(std::unique_ptr<entityConfig> config);
};



#endif // !EntityFactory