#pragma once
#ifndef INPUT_HANDLER
#define INPUT_HANDLER

#include <functional>
#include <map>
#include <vector>

#include <SDL.h>

#include "Core/Framework/Events/InputEventHandler.h"
#include "Core/node/Component/Derivative/ComponentUpdatable.h"

typedef enum : unsigned int {
	INPUT_ALL,
	INPUT_MENU,
	INPUT_WORLD
}e_INPUT_STATE;

typedef enum : unsigned int {
	OR,
	AND,
	NEITHER
}e_CONDITIONAL_AND_OR;

using FunctionVec = std::vector<std::function<void()>>;
struct FuncObj {
	// TODO: change actionName to EUM when ready!
	std::string action = "None";
	std::function<void()> func;
};

struct keyObj {
	SDL_Keycode primary = SDLK_UNKNOWN;
	SDL_Keycode modifier = SDLK_UNKNOWN;
	e_CONDITIONAL_AND_OR conditional = NEITHER;
	FuncObj func = FuncObj();

	keyObj(SDL_Keycode key0, SDL_Keycode key1, e_CONDITIONAL_AND_OR con, FuncObj fc) {
		primary = key0;
		modifier = key1;
		conditional = con;
		func = fc;
	}

	bool operator == (const keyObj &rhs) const
	{ /* your logic for comparision between "*this" and "rhs" */
		return(
			this->primary == rhs.primary && 
			this->modifier == rhs.modifier && 
			func.action == rhs.func.action &&
			rhs.conditional == this->conditional);
	}
};

using KeyVec = std::vector<keyObj>;

using StateMap = std::map<e_INPUT_STATE, KeyVec>;

using keyHandle = KeyVec::iterator;

class inputHandler : public ComponentUpdatable
{
public:
	// removed static to allow multiple input controllers.
	/*static inputHandler & getInstance() {
		static inputHandler instance;
		return instance;
	}

private:*/
	// private constructor to impl singleton
	inputHandler();
	~inputHandler() {};

//public:
	// inherited update for component
	bool Update();

	// Safety to delete any copies or new instances
	inputHandler(const inputHandler&) = delete;
	void operator=(inputHandler const&) = delete;

	void add(e_INPUT_STATE state, FuncObj func, SDL_Keycode primaryKey, e_CONDITIONAL_AND_OR con, SDL_Keycode ModifierKey);
	
	bool setState(e_INPUT_STATE);

	//void remove();

	//void get(unsigned&);

	//bool trigger(SDL_Keycode&, SDL_Keycode);

private:

	bool checkModKey();

	StateMap m_inputFunctions;
	e_INPUT_STATE m_currentState;
	InputEventHandler * m_inputEvents;
};

#endif