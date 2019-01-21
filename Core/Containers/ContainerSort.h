#pragma once
#ifndef CONTAINER_SORT_H
#define CONTAINER_SORT_H

#include "Core/Component/Component.h"

struct GetPrioritySort {
	bool operator() (COMPONENT_PTR const & begin, COMPONENT_PTR const & end) {
		if (begin->GetComponentType() < end->GetComponentType())
		{
			return true;
		}
		return false;
	}
};


#endif // !CONTAINER_SORT_H