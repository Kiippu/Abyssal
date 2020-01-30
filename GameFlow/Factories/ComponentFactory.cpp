#include "ComponentFactory.h"
#include "Core/Node/Component/Component.h"
#include "Core/Node/Component/ComponentTypes.h"
#include "Core/node/Component/Derivative/IO/ReadWrite.h"
#include "Core/node/Component/Derivative/Render/Model3D.h"
#include "Core/node/Component/Derivative/IO/inputHandler.h"
#include "Core/Node/Component/Derivative/Camera/Camera.h"
#include "Core/Node/componentLabelConverter.h"


ComponentFactory::ComponentFactory()
{
	BuildComponents();
	m_labelConverter = &componentLabelConverter::getInstance();
}

bool ComponentFactory::BuildComponents()
{
	m_componentList.insert(std::make_pair(LABEL_COMPONENT_TYPE::COMP_MODEL3D, new Model3D));
	m_componentList.insert(std::make_pair(LABEL_COMPONENT_TYPE::COMP_INPUT, new inputHandler));
	m_componentList.insert(std::make_pair(LABEL_COMPONENT_TYPE::COMP_READ_WRITE, new ReadWrite));
	m_componentList.insert(std::make_pair(LABEL_COMPONENT_TYPE::COMP_CAMERA, new Camera));
	return true;
}

unsigned ComponentFactory::create(std::string name, Node* node) 
{
	auto label = m_labelConverter->getLebel(name);
	auto itr = m_componentList.find(label);
	if (itr != m_componentList.end()) {
		auto component = itr->second;
		if (component->GetComponentType() == LABEL_COMPONENT_TYPE::COMP_INPUT) {
			inputHandler & inputComponent = dynamic_cast<inputHandler&>(*component);
			inputComponent.SetParent(node);
			inputComponent.init();
		}
		m_activeComponents.insert(std::make_pair(component->GetID(), std::make_pair(label ,component)));
		return component->GetID();
	}
	return UINT_MAX;
}

std::pair<LABEL_COMPONENT_TYPE, Component*> ComponentFactory::getComponetPair(unsigned id)
{
	auto itr = m_activeComponents.find(id);
	if (itr != m_activeComponents.end()) {
		return itr->second;
	}
	return std::make_pair(LABEL_COMPONENT_TYPE::COMP_ERROR, nullptr);
}

