#ifndef COMPONENT_UPDATABLE_H
#define COMPONENT_UPDATABLE_H
#include "Core/node/Component/Component.h"
#include "GameFlow/Updater/MasterUpdate.h"
#include "Core/Node/Containers/PriorityType.h"
#include "Core/Framework/Networking/Serialization.h"

class ComponentUpdatable : public Component, Serialization
{
protected:
	explicit ComponentUpdatable(LABEL_COMPONENT_TYPE lableType, LABEL_PRIORITY_TYPE lablePriority, std::string type);
public:

	virtual ~ComponentUpdatable() {};

	virtual bool Update() = 0;

};

#endif // !COMPONENT_UPDATABLE_H
