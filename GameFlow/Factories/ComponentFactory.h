#pragma once
#ifndef COMPONENT_FACTOR_H
#define COMPONENT_FACTOR_H

#include "IFactory.h"
#include "Core/Node/Component/ComponentTypes.h"

class Component;
class componentLabelConverter;
class Node;

//using namespace std::experimental::filesystem;


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

	virtual bool BuildComponents();

	virtual unsigned create(std::string, Node*);

	std::pair< LABEL_COMPONENT_TYPE, Component* > getComponetPair(unsigned);

private:
	// story copyable components
	std::map<LABEL_COMPONENT_TYPE,Component*> m_componentList;
	// list of components
	std::map<unsigned,std::pair< LABEL_COMPONENT_TYPE, Component* >> m_activeComponents;
	componentLabelConverter *m_labelConverter;
};



#endif // !COMPONENT_FACTOR_H