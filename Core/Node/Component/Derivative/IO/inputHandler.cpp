#include "inputHandler.h"
#include <iostream>


inputHandler::inputHandler()
	:ComponentUpdatable(LABEL_COMPONENT_TYPE::COMP_INPUT, LABEL_PRIORITY_TYPE::PRTY_INPUT, "inputHandler")
{
	std::cout << "constructor - " << GetComponentType() << std::endl;

	m_inputEvents = &InputEventHandler::getInstance();

}

bool inputHandler::Update()
{
	/*auto keyStates = m_inputFunctions[m_currentState];
	for (size_t i = 0; i < keyStates.size(); i++)
	{
		if (m_inputEvents->IsKeyDown(SDLK_r) && checkModKey()) {

		}
	}*/
	
	return true;
}

void inputHandler::add(e_INPUT_STATE state, FuncObj func, SDL_Keycode primaryKey, e_CONDITIONAL_AND_OR con = NEITHER, SDL_Keycode modifierKey = SDLK_UNKNOWN)
{
	auto iterState = m_inputFunctions[state];

	keyObj tempState = keyObj(primaryKey, modifierKey, con, func);
	
	for (auto& obj : iterState) {
		if (obj == tempState) {
			printf(__LINE__ + "[class inputHandler]: Attempt to add Existing Key function pair!");
		}
	}
/*
	auto stateMap = iterState->second;
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
//bool inputHandler::trigger(SDL_Keycode & primaryKey, SDL_Keycode modifierKey = SDLK_UNKNOWN)
//{
//	auto iter = m_inputFunctions.find(m_currentState);
//	if (iter != m_inputFunctions.end()) {
//		for (auto& obj : iter->second) {
//			if (obj.conditional == NEITHER && primaryKey == obj.primary)
//				obj.func.func();
//			if(obj.conditional == AND && primaryKey == obj.primary && obj.modifier == modifierKey)
//				obj.func.func();
//			if (obj.conditional == OR && primaryKey == obj.primary || obj.modifier == modifierKey)
//				obj.func.func();
//		}
//		/*auto func = iter->second.find(std::make_pair(primaryKey, modifierKey));
//		if (func != iter->second.end()) {
//			for (size_t i = 0; i < func->second.size(); i++)
//			{
//				func->second[i]();
//			}
//			return true;
//		}
//		return false;*/
//	}
//	return false;
//}

bool inputHandler::checkModKey()
{
	return(
		m_inputEvents->IsKeyDown(KMOD_CTRL) ||
		m_inputEvents->IsKeyDown(KMOD_ALT) ||
		m_inputEvents->IsKeyDown(KMOD_SHIFT) );
}
