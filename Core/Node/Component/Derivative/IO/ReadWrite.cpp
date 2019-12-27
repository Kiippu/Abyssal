#include "Core/Node/Component/Derivative/IO/ReadWrite.h"
#include "Core/Node/Containers/PriorityType.h"
#include <iostream>


ReadWrite::ReadWrite()
	:Component(LABEL_COMPONENT_TYPE::COMP_READ_WRITE, LABEL_PRIORITY_TYPE::PRTY_LOW, "readWrite")
{
	std::cout << "ReadWrite created" << std::endl;
}


ReadWrite::~ReadWrite()
{
}
