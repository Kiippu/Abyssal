#include "ReadWrite.h"
#include <iostream>


ReadWrite::ReadWrite()
	:Component(LABEL_COMPONENT_TYPE::COMP_READ_WRITE, LABEL_PRIORITY_TYPE::PRTY_LOW)
{
	std::cout << "ReadWrite created" << std::endl;
}


ReadWrite::~ReadWrite()
{
}

void ReadWrite::Update()
{
	std::cout << "ReadWrite was updated" << std::endl;
	std::cout << "ReadWrite should update 2rd" << std::endl;
}
