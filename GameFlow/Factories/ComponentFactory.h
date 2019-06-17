#pragma once
#ifndef COMPONENT_FACTOR_H
#define COMPONENT_FACTOR_H

#include "IFactory.h"

using namespace std::experimental::filesystem;


class ComponentFactory : public IFactory
{
public:
	static ComponentFactory & getInstance() {
		static ComponentFactory instance;
		return instance;
	}

private:
	// private constructor to impl singleton
	ComponentFactory();

public:
	// Safety to delete any copies or new instances
	ComponentFactory(const ComponentFactory&) = delete;
	void operator=(ComponentFactory const&) = delete;

	virtual bool ImportEntities();
};



#endif // !COMPONENT_FACTOR_H