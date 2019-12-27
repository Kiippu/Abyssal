#include "Core/Node/Component/Derivative/ComponentUpdatable.h"
#include "GameFlow/Updater/MasterUpdate.h"

ComponentUpdatable::ComponentUpdatable(LABEL_COMPONENT_TYPE lableType, LABEL_PRIORITY_TYPE lablePriority, std::string type)
	:Component(lableType, lablePriority, type)
{
}
