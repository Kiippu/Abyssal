#pragma once
#ifndef COMPONENT_LABEL_CONVERTER_H
#define COMPONENT_LABEL_CONVERTER_H

#include <string>
#include <map>
#include "Core/Node/Component/ComponentTypes.h"

class componentLabelConverter
{
public:
	static componentLabelConverter & getInstance() {
		static componentLabelConverter instance;
		return instance;
	}

private:
	// private constructor to impl singleton
	componentLabelConverter() {};

public:
	// Safety to delete any copies or new instances
	componentLabelConverter(const componentLabelConverter&) = delete;
	void operator=(componentLabelConverter const&) = delete;


	void add(LABEL_COMPONENT_TYPE, std::string&);

	std::string getLabel(LABEL_COMPONENT_TYPE);
	LABEL_COMPONENT_TYPE getLebel(std::string);

private:
	std::map<LABEL_COMPONENT_TYPE, std::string> m_enumToString;
	std::map<std::string, LABEL_COMPONENT_TYPE> m_stringToEnum;
};

#endif
