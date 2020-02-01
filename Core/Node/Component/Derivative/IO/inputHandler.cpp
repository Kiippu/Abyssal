#include "inputHandler.h"
#include <iostream>
#include "SDL_keycode.h"
#include <functional>
#include "Core/Framework/IO/inputEventActions.h"
//#include "Core/Framework/Networking/NetworkManager.h"



inputHandler::inputHandler()
	:ComponentUpdatable(LABEL_COMPONENT_TYPE::COMP_INPUT, LABEL_PRIORITY_TYPE::PRTY_INPUT, "inputHandler")
{
	std::cout << "constructor - " << GetComponentTypeString() << std::endl;
	m_currentState = e_INPUT_STATE::INPUT_WORLD;
	m_inputEvents = &InputEventHandler::getInstance();
	m_networkManager = &NetworkManager::getInstance();
	
	/*std::function<bool()> func = []() {
		std::cout << "Function run!!" << std::endl;
		return true;
	};

	FuncObj tempFunc;
	tempFunc.action = "TEST";
	tempFunc.func = func;

	add(e_INPUT_STATE::INPUT_ALL, tempFunc, SDLK_w, e_CONDITIONAL_AND_OR::NEITHER, 0);*/

	//auto parent = GetParent();
	//m_inputEventActions = std::make_shared<inputEventActions>(GetParent());
	//m_inputEventActions->Initialise();
	//auto & actionsList = m_inputEventActions->m_actions;
	//for (size_t i = 0; i < actionsList.size(); i++)
	//{
	//	auto & action = actionsList[i];
	//	//auto fundc = [&](bool) {action.init(); return true; };
	//	std::function<bool()> func = [&]() {action->init(); return true; };
	//	add(e_INPUT_STATE::INPUT_ALL, FuncObj(action->m_actionName, func), SDLK_r, e_CONDITIONAL_AND_OR::NEITHER, 0);
	//}

}

bool inputHandler::Update()
{
	auto keyState = m_inputFunctions[m_currentState];
	for (size_t i = 0; i < keyState.size(); i++)
	{
		// TODO: uncomment to have serialization!
		// send input to network manger if client
		//if (m_networkManager->isClient()) {
		//	m_networkManager->Serialize(keyState[i].netMessage);
		//	continue;
		//}
		// if host/solo run functions; 
		switch (keyState[i].conditional)
		{
		case e_CONDITIONAL_AND_OR::NEITHER:{
			if (m_inputEvents->IsKeyDown(keyState[i].primary))
				keyState[i].func.func();
			break;
		case e_CONDITIONAL_AND_OR::AND:
			if (m_inputEvents->IsKeyDown(keyState[i].primary) && m_inputEvents->IsKeyDown(keyState[i].modifier))
				keyState[i].func.func();
			}
			break;
		case e_CONDITIONAL_AND_OR::OR:
			if (m_inputEvents->IsKeyDown(keyState[i].primary) || m_inputEvents->IsKeyDown(keyState[i].modifier))
				keyState[i].func.func();
			break;
		default:
			break;
		}
	}

	return true;
}

void inputHandler::Serialize(char * data)
{
	printf("Serializing %s" , GetComponentTypeString().c_str());
}

void inputHandler::Deserialize(char * data)
{
	printf("Deserializing %s", GetComponentTypeString().c_str());
}

void inputHandler::add(e_INPUT_STATE state, 
	FuncObj func, 
	SDL_Keycode primaryKey, 
	e_CONDITIONAL_AND_OR con = NEITHER, 
	SDL_Keycode modifierKey = SDLK_UNKNOWN, 
	eNetMessage netMsg = eNetMessage::UNKNOWN)
{
	auto& iterState = m_inputFunctions[state];

	keyObj tempState = keyObj(primaryKey, modifierKey, con, func, netMsg);
	
	for (auto& obj : iterState) {
		if (obj == tempState) {
			printf(__LINE__ + "[class inputHandler]: Attempt to add Existing Key function pair!");
		}
	}

	/*auto stateMap = iterState->second;
	auto keyPair = std::make_pair(primaryKey, modifierKey);
	auto iterKey = stateMap.find(keyPair);
	if (iterKey == stateMap.end()) {
		stateMap.insert(std::make_pair(keyPair, FunctionVec()));
		iterKey = stateMap.find(keyPair);
	}*/

	iterState.push_back(tempState);
}

bool inputHandler::setState(e_INPUT_STATE state)
{
	return (m_currentState = state);
}
//
bool inputHandler::trigger(std::string & action)
{
	//auto iter = m_inputFunctions.find(m_currentState);
	//if (iter != m_inputFunctions.end()) {


	//	// add get key event here check if pressed in SDL@


	//	for (auto& obj : iter->second) {
	//		if (obj.conditional == NEITHER && primaryKey == obj.primary)
	//			return obj.func.func();
	//		if(obj.conditional == AND && primaryKey == obj.primary && obj.modifier == modifierKey)
	//			return obj.func.func();
	//		if (obj.conditional == OR && primaryKey == obj.primary || obj.modifier == modifierKey)
	//			return obj.func.func();
	//	}
	//}
	return false;
}

void inputHandler::init()
{
	auto parent = GetParent();
	m_inputEventActions = std::make_shared<inputEventActions>(GetParent());
	m_inputEventActions->Initialise();
	auto & actionsList = m_inputEventActions->m_actions;
	for (size_t i = 0; i < actionsList.size(); i++)
	{
		auto & action = actionsList[i];
		std::function<bool()> func = [&]() {action->init(); return true; };
		add(action->m_intupState, FuncObj(action->m_actionName, func), action->m_primaryKey, action->m_conditional, action->m_modifyKey, action->m_netMessage);
	}
}

bool inputHandler::checkModKey()
{
	return(
		m_inputEvents->IsKeyDown(KMOD_CTRL) ||
		m_inputEvents->IsKeyDown(KMOD_ALT) ||
		m_inputEvents->IsKeyDown(KMOD_SHIFT) );
}
