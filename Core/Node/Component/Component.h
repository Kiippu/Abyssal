#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H

#include <memory>
#include "Core/Node/Component/ComponentTypes.h"
#include "Core/Node/Containers/PriorityType.h"
#include <string>
#include <functional>

/*******************************************************************

							Component.h
	Abstract class to to where all components derive from.

*********************************************************************/

class componentLabelConverter;
class Node;

class Component
{
protected:
	explicit Component(LABEL_COMPONENT_TYPE ct, LABEL_PRIORITY_TYPE pt, std::string type);
	
public:
	virtual ~Component();
	// gets type name
	LABEL_COMPONENT_TYPE const GetComponentType() const;
	std::string const GetComponentTypeString();
	LABEL_PRIORITY_TYPE const GetPriorityType() const;
	unsigned const GetID() const;
	Node * GetParent() const;
	void SetParent(Node*);

	//holds next the incrememnted id tag
	static ID_COMPONENT_TYPE	nextIdForComponent;

private:
	// components name
	LABEL_COMPONENT_TYPE		comp_type;
	ID_COMPONENT_TYPE			comp_ID;
	LABEL_PRIORITY_TYPE			prty_type;
	std::string					m_type;
	componentLabelConverter		*m_labelConverter;
	Node						*m_parentNode;
};

using COMPONENT_PTR = Component*;



#endif

