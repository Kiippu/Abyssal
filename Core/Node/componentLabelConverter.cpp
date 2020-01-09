#include "componentLabelConverter.h"



void componentLabelConverter::add(LABEL_COMPONENT_TYPE typeEnum, std::string& typeString)
{
	m_enumToString.insert(std::make_pair( typeEnum, typeString));
	m_stringToEnum.insert(std::make_pair( typeString, typeEnum));
}

std::string componentLabelConverter::getLabel(LABEL_COMPONENT_TYPE ct)
{
	return m_enumToString.find(ct)->second;
}

LABEL_COMPONENT_TYPE componentLabelConverter::getLebel(std::string label)
{
	auto itr = m_stringToEnum.find(label);
	if (itr == m_stringToEnum.end()) {
		printf("ERROR: Get label [%s] does not exist!", label.c_str());
		return LABEL_COMPONENT_TYPE::COMP_ERROR;
	}
	return itr->second;
}
