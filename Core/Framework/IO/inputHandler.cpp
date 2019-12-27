#include "inputHandler.h"


keyHandle inputHandler::add(e_INPUT_STATE state, std::function<void()> func, SDL_Keycode primaryKey, SDL_Keycode modifierKey = SDLK_UNKNOWN)
{
	auto iterState = m_inputFunctions.find(state);
	if (iterState == m_inputFunctions.end()) {
		m_inputFunctions.insert(std::make_pair(state, KeyMap()));
		iterState = m_inputFunctions.find(state);
	}

	auto stateMap = iterState->second;
	auto keyPair = std::make_pair(primaryKey, modifierKey);
	auto iterKey = stateMap.find(keyPair);
	if (iterKey == stateMap.end()) {
		stateMap.insert(std::make_pair(keyPair, FunctionVec()));
		iterKey = stateMap.find(keyPair);
	}

	iterKey->second.push_back(func);
	return stateMap.find(keyPair);
}

bool inputHandler::setState(e_INPUT_STATE state)
{
	return (m_currentState = state);
}

bool inputHandler::trigger(SDL_Keycode & primaryKey, SDL_Keycode modifierKey = SDLK_UNKNOWN)
{
	auto iter = m_inputFunctions.find(m_currentState);
	if (iter != m_inputFunctions.end()) {
		auto func = iter->second.find(std::make_pair(primaryKey, modifierKey));
		if (func != iter->second.end()) {
			for (size_t i = 0; i < func->second.size(); i++)
			{
				func->second[i]();
			}
			return true;
		}
		return false;
	}
	return false;
}
