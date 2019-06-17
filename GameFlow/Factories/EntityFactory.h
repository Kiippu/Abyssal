#pragma once
#ifndef Entity_Factory_H
#define Entity_Factory_H

#include "IFactory.h"

using namespace std::experimental::filesystem;


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

public:
	// Safety to delete any copies or new instances
	EntityFactory(const EntityFactory&) = delete;
	void operator=(EntityFactory const&) = delete;

	virtual bool ImportEntities();
};



#endif // !EntityFactory