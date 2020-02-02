#pragma once
#ifndef INPUT_EVENT_ACTIONS
#define INPUT_EVENT_ACTIONS

#include <iostream>
#include "Core/Node/Component/Derivative/IO/inputHandler.h"
#include "Core/Node/Derivative/DynamicEntityNode.h"
#include "Core/Node/Component/Derivative/Render/Model3D.h"
#include "Core/Node/Component/Derivative/Camera/Camera.h"
// network
#include "Core/Framework/Networking/NetworkManager.h"
#include "Core/Framework/Networking/Server.h"
#include "Core/Framework/Networking/Client.h"

#include "GameFlow/GameManager.h"
#include "Core/Framework/Threading/ThreadSpool.h"

class ActionBase
{
public:
	ActionBase(Node* ent, std::string name, e_INPUT_STATE state, SDL_Keycode primaryKey, e_CONDITIONAL_AND_OR con, SDL_Keycode mod, eNetMessage netMsg)
	: m_actionName(name), 
		m_dynamicEntity(dynamic_cast<DynamicEntityNode&>(*ent)), 
		m_intupState(state),
		m_conditional(con),
		m_modifyKey(mod),
		m_netMessage(netMsg),
		m_primaryKey(primaryKey)
	{
	};

	~ActionBase() {};

	virtual bool init() = 0;

	// name of action
	std::string m_actionName;
	// affected node if any
	DynamicEntityNode & m_dynamicEntity;
	// state when it will take effect
	e_INPUT_STATE m_intupState;
	// primary key binding
	SDL_Keycode m_primaryKey;
	// modify key binding
	SDL_Keycode m_modifyKey;
	// conditional
	e_CONDITIONAL_AND_OR m_conditional;
	// linked net message for serialization
	eNetMessage m_netMessage;

};

// camera Contols
class cameraReset : public ActionBase
{
public:

	cameraReset(Node* ent, std::string name, e_INPUT_STATE state, SDL_Keycode primaryKey, e_CONDITIONAL_AND_OR con, SDL_Keycode mod, eNetMessage netMsg)
		: ActionBase(ent, name, state,primaryKey,con,mod,netMsg) {};

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

// strafe the current node to the left 
class strafeLeft : public ActionBase
{
public:

	strafeLeft(Node* ent, std::string name, e_INPUT_STATE state, SDL_Keycode primaryKey, e_CONDITIONAL_AND_OR con, SDL_Keycode mod, eNetMessage netMsg)
		: ActionBase(ent, name, state, primaryKey, con, mod, netMsg) {};

	virtual bool init()
	{
		//set node position
		auto origTrans = m_dynamicEntity.GetTransfrom();
		transform trans = transform(origTrans.worldPosition, origTrans.rotate, origTrans.scale);
		trans.worldPosition.x += 0.1f;
		m_dynamicEntity.setWorldTransform(trans);
		// set look at position of camera
		if (auto* component = m_dynamicEntity.GetComponentContainer()->GetComponent(COMP_CAMERA))
		{
			Camera & camera = dynamic_cast<Camera&>(*component);
			glm::vec3 pos = camera.getLookAtPos();
			pos.x += 0.1f;
			camera.setLookAtPos(pos);
		}
		return true;
	}
};

// strafe the current node to the left 
class strafeRight : public ActionBase
{
public:

	strafeRight(Node* ent, std::string name, e_INPUT_STATE state, SDL_Keycode primaryKey, e_CONDITIONAL_AND_OR con, SDL_Keycode mod, eNetMessage netMsg)
		: ActionBase(ent, name, state, primaryKey, con, mod, netMsg) {};

	virtual bool init()
	{
		//set node position
		auto origTrans = m_dynamicEntity.GetTransfrom();
		transform trans = transform(origTrans.worldPosition, origTrans.rotate, origTrans.scale);
		trans.worldPosition.x -= 0.1f;
		m_dynamicEntity.setWorldTransform(trans);
		// set look at position of camera
		if (auto* component = m_dynamicEntity.GetComponentContainer()->GetComponent(COMP_CAMERA))
		{
			Camera & camera = dynamic_cast<Camera&>(*component);
			glm::vec3 pos = camera.getLookAtPos();
			pos.x -= 0.1f;
			camera.setLookAtPos(pos);
		}
		return true;
	}
};

// strafe the current node backward in world 
class strafeBackward : public ActionBase
{
public:

	strafeBackward(Node* ent, std::string name, e_INPUT_STATE state, SDL_Keycode primaryKey, e_CONDITIONAL_AND_OR con, SDL_Keycode mod, eNetMessage netMsg)
		: ActionBase(ent, name, state, primaryKey, con, mod, netMsg) {};

	virtual bool init()
	{
		//set node position
		auto origTrans = m_dynamicEntity.GetTransfrom();
		transform trans = transform(origTrans.worldPosition, origTrans.rotate, origTrans.scale);
		trans.worldPosition.y += 0.1f;
		m_dynamicEntity.setWorldTransform(trans);
		// set look at position of camera
		if (auto* component = m_dynamicEntity.GetComponentContainer()->GetComponent(COMP_CAMERA))
		{
			Camera & camera = dynamic_cast<Camera&>(*component);
			glm::vec3 pos = camera.getLookAtPos();
			pos.y += 0.1f;
			camera.setLookAtPos(pos);
		}
		return true;
	}
};

// strafe the current node forward in world
class strafeForward : public ActionBase
{
public:

	strafeForward(Node* ent, std::string name, e_INPUT_STATE state, SDL_Keycode primaryKey, e_CONDITIONAL_AND_OR con, SDL_Keycode mod, eNetMessage netMsg)
		: ActionBase(ent, name, state, primaryKey, con, mod, netMsg) {};

	virtual bool init()
	{
		//set node position
		auto origTrans = m_dynamicEntity.GetTransfrom();
		transform trans = transform(origTrans.worldPosition, origTrans.rotate, origTrans.scale);
		trans.worldPosition.y -= 0.1f;
		m_dynamicEntity.setWorldTransform(trans);
		// set look at position of camera
		if (auto* component = m_dynamicEntity.GetComponentContainer()->GetComponent(COMP_CAMERA))
		{
			Camera & camera = dynamic_cast<Camera&>(*component);
			glm::vec3 pos = camera.getLookAtPos();
			pos.y -= 0.1f;
			camera.setLookAtPos(pos);
		}
		return true;
	}
};

class InitServer : public ActionBase
{
public:

	InitServer(Node* ent, std::string name, e_INPUT_STATE state, SDL_Keycode primaryKey, e_CONDITIONAL_AND_OR con, SDL_Keycode mod, eNetMessage netMsg)
		: ActionBase(ent, name, state, primaryKey, con, mod, netMsg) {};

	virtual bool init()
	{
		auto* networkManager = &NetworkManager::getInstance();
		if (networkManager->isSolo()) {
			networkManager->setLocalInterface(std::make_unique<Server>(Server()));
			auto& motherSchedual = GameManager::getInstance().getThreadMaster();
			// TODO: fix this!!!
			auto thread = motherSchedual.getAvaliable();
			thread->addFiber(Fiber([&networkManager]() {
				networkManager->getInstance().getlocalInterface().InitUDP();
			}));
			return true;
		}
		return true;
	}
};

class InitClient : public ActionBase
{
public:

	InitClient(Node* ent, std::string name, e_INPUT_STATE state, SDL_Keycode primaryKey, e_CONDITIONAL_AND_OR con, SDL_Keycode mod, eNetMessage netMsg)
		: ActionBase(ent, name, state, primaryKey, con, mod, netMsg) {};

	virtual bool init()
	{
		auto* networkManager = &NetworkManager::getInstance();
		if (networkManager->isSolo()) {
			networkManager->setLocalInterface(std::make_unique<Client>(Client()));
			auto& motherSchedual = GameManager::getInstance().getThreadMaster();
			// TODO: fix this!!!
			auto thread = motherSchedual.getAvaliable();
			thread->addFiber(Fiber([&networkManager]() {
				networkManager->getInstance().getlocalInterface().InitUDP();
			}));
			return true;
		}
		return true;
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
		// reset camera to default state
		m_actions.push_back(std::make_shared<cameraReset>(m_dynamicEntity, "cameraReset", INPUT_WORLD, SDLK_r, NEITHER, 0, eNetMessage::resetCamera ));

		// server client initiation
		m_actions.push_back(std::make_shared<InitServer>(m_dynamicEntity, "initServer", INPUT_WORLD, SDLK_p, NEITHER, 0, eNetMessage::UNKNOWN ));
		m_actions.push_back(std::make_shared<InitClient>(m_dynamicEntity, "initClient", INPUT_WORLD, SDLK_m, NEITHER, 0, eNetMessage::UNKNOWN ));

		// camera movement
		m_actions.push_back(std::make_shared<strafeLeft>(m_dynamicEntity, "strafeLeft", INPUT_WORLD, SDLK_LEFT, NEITHER, 0, eNetMessage::strafeLeft));
		m_actions.push_back(std::make_shared<strafeRight>(m_dynamicEntity, "strafeRight", INPUT_WORLD, SDLK_RIGHT, NEITHER, 0, eNetMessage::strafeRight));
		m_actions.push_back(std::make_shared<strafeForward>(m_dynamicEntity, "strafeForward", INPUT_WORLD, SDLK_UP, NEITHER, 0, eNetMessage::strafeForward));
		m_actions.push_back(std::make_shared<strafeBackward>(m_dynamicEntity, "strafeBackward", INPUT_WORLD, SDLK_DOWN, NEITHER, 0, eNetMessage::strafeBackward));
		//auto & name = m_actions[m_actions.size() - 1]->m_actionName;
		//std::weak_ptr<ActionBase> action = m_actions[m_actions.size() - 1];

		//m_actionsMaping.insert(std::make_pair(name, action));

		//auto fundc = [&reset](bool) {reset.init(); return true; };
		//std::function<bool()> func = [&]() {reset.init(); return true; };
		//m_inputHandler.add(e_INPUT_STATE::INPUT_ALL, FuncObj(reset.m_actionName, func), SDLK_r, e_CONDITIONAL_AND_OR::NEITHER, 0);

	};

	std::vector<std::shared_ptr<ActionBase>>		m_actions;
	//std::map<std::string&, std::weak_ptr<ActionBase> >		m_actionsMaping;

	Node * m_dynamicEntity;
};

#endif // !INPUT_EVENT_ACTIONS


