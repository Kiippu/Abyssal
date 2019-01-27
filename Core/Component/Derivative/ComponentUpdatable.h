#ifndef COMPONENT_UPDATABLE_H
#define COMPONENT_UPDATABLE_H
#include "Core/Component/Component.h"
#include "GameFlow/Updater/MasterUpdate.h"

class ComponentUpdatable : public Component
{
protected:
	explicit ComponentUpdatable(LABEL_COMPONENT_TYPE lableType, LABEL_PRIORITY_TYPE lablePriority);
public:

	virtual ~ComponentUpdatable() {};

	virtual bool Update() = 0;

};

#endif // !COMPONENT_UPDATABLE_H
