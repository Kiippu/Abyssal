#include "componentLabelConverter.h"



void componentLabelConverter::add(LABEL_COMPONENT_TYPE typeEnum, std::string& typeString)
{
	m_enumToString.insert(std::make_pair( typeEnum, typeString));
	m_stringToEnum.insert(std::make_pair( typeString, typeEnum));
}
