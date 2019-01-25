#pragma once
#ifndef READ_WRITE_H
#define READ_WRITE_H

#include "Core/Component/Component.h"

class ReadWrite : public Component
{
public:
	ReadWrite();
	~ReadWrite();

};

using READ_WRITE_PTR = std::shared_ptr<ReadWrite>;

#endif // !READ_WRITE_H




