#include "Component.h"
#include "Core/Node/componentLabelConverter.h"
#include "Core/Node/Node.h"
#include <iostream>

ID_COMPONENT_TYPE Component::nextIdForComponent = 0;

Component::Component(LABEL_COMPONENT_TYPE ct, LABEL_PRIORITY_TYPE pt, std::string type)
	:comp_type(ct),comp_ID(nextIdForComponent++),prty_type(pt), m_type(type)
{
	m_labelConverter = &componentLabelConverter::getInstance();
	m_labelConverter->add(ct, type);
}

Component::~Component()
{
}

LABEL_COMPONENT_TYPE const Component::GetComponentType() const
{
	return comp_type;
}

std::string const Component::GetComponentTypeString()
{
	return m_type;
}

LABEL_PRIORITY_TYPE const Component::GetPriorityType() const
{
	return prty_type;
}

unsigned const Component::GetID() const
{
	return comp_ID;
}

Node * Component::GetParent() const
{
	return m_parentNode;
}

void Component::SetParent(Node * node)
{
	m_parentNode = node;
}
