#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H

#include <memory>
#include "Core/Node/Component/ComponentTypes.h"
#include "Core/Node/Containers/PriorityType.h"
#include <string>

/*******************************************************************

							Component.h
	Abstract class to to where all components derive from.

*********************************************************************/

class componentLabelConverter;

class Component
{
protected:
	explicit Component(LABEL_COMPONENT_TYPE ct, LABEL_PRIORITY_TYPE pt, std::string type);
	
public:
	virtual ~Component();
	// gets type name
	LABEL_COMPONENT_TYPE const GetComponentType() const;
	std::string const GetComponentTypeString() const;
	LABEL_PRIORITY_TYPE const GetPriorityType() const;

	//holds next the incrememnted id tag
	static ID_COMPONENT_TYPE	nextIdForComponent;

	//virtual void Update() = 0;

private:
	// components name
	LABEL_COMPONENT_TYPE		comp_type;
	ID_COMPONENT_TYPE			comp_ID;
	LABEL_PRIORITY_TYPE			prty_type;
	std::string					m_type;
	componentLabelConverter		*m_labelConverter;
};

using COMPONENT_PTR = std::shared_ptr<Component>;



#endif

