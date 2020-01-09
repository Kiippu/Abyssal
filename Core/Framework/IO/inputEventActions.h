#pragma once
#ifndef INPUT_EVENT_ACTIONS
#define INPUT_EVENT_ACTIONS

#include <iostream>
#include "Core/Node/Component/Derivative/IO/inputHandler.h"
#include "Core/Node/Derivative/DynamicEntityNode.h"
#include "Core/Node/Component/Derivative/Render/Model3D.h"


class ActionBase
{
public:
	ActionBase(Node* ent, std::string name)
	: m_actionName(name), m_dynamicEntity(dynamic_cast<DynamicEntityNode&>(*ent)){
		//m_dynamicEntity = dynamic_cast<DynamicEntityNode&>(*ent);
		//m_dynamicEntity = std::weak_ptr<DynamicEntityNode>(dynaNode);
	};

	~ActionBase() {};

	virtual bool init() = 0;

	std::string m_actionName;
	DynamicEntityNode & m_dynamicEntity;
};

class cameraReset : public ActionBase
{
public:

	cameraReset(Node* ent, std::string name)
		: ActionBase(ent, name) {};

	virtual bool init()
	{
		if (auto* component = m_dynamicEntity.GetComponentContainer()->GetComponent(COMP_MODEL3D))
		{
			Model3D & modelComponent = dynamic_cast<Model3D&>(*component);
			modelComponent.getModel().ResetMatrix();
			return true;
		}
		return false;
	}
};


class inputEventActions
{
public:
	inputEventActions(Node* ent)
		: m_dynamicEntity(ent) {};

	~inputEventActions() {};

	void Initialise() 
	{
		//m_actions.push_back(std::make_shared<cameraReset>(m_dynamicEntity, "cameraReset"));
		//auto & name = m_actions[m_actions.size()]->m_actionName;
		//std::weak_ptr<ActionBase> action = m_actions[m_actions.size()];
		//m_actionsMaping.insert(std::make_pair(name, action));

		//auto fundc = [&reset](bool) {reset.init(); return true; };
		//std::function<bool()> func = [&]() {reset.init(); return true; };
		//m_inputHandler.add(e_INPUT_STATE::INPUT_ALL, FuncObj(reset.m_actionName, func), SDLK_r, e_CONDITIONAL_AND_OR::NEITHER, 0);

	};

	//std::vector<std::shared_ptr<ActionBase>>		m_actions;
	//std::map<std::string&, std::weak_ptr<ActionBase> >		m_actionsMaping;

	Node * m_dynamicEntity;
};

#endif // !INPUT_EVENT_ACTIONS


