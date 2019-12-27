#pragma once
#ifndef INPUT_HANDLER
#define INPUT_HANDLER

#include <functional>
#include <map>
#include <vector>

#include <SDL.h>

typedef enum : unsigned int {
	INPUT_ALL,
	INPUT_MENU,
	INPUT_WORLD
}e_INPUT_STATE;

using FunctionVec = std::vector<std::function<void()>>;

using KeyMap = std::map<std::pair<SDL_Keycode, SDL_Keycode>, FunctionVec>;

using StateMap = std::map<e_INPUT_STATE, KeyMap>;

using keyHandle = KeyMap::iterator;

class inputHandler
{
public:
	// removed static to allow multiple input controllers.
	/*static inputHandler & getInstance() {
		static inputHandler instance;
		return instance;
	}

private:*/
	// private constructor to impl singleton
	inputHandler() {};
	~inputHandler() {};

public:
	// Safety to delete any copies or new instances
	inputHandler(const inputHandler&) = delete;
	void operator=(inputHandler const&) = delete;

	keyHandle add(e_INPUT_STATE state, std::function<void()> func, SDL_Keycode primaryKey, SDL_Keycode ModifierKey);
	
	bool setState(e_INPUT_STATE);

	//void remove();

	//void get(unsigned&);

	bool trigger(SDL_Keycode&, SDL_Keycode);

private:

	StateMap m_inputFunctions;
	e_INPUT_STATE m_currentState;

};

#endif