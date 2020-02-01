#pragma once
#ifndef INPUT_HANDLER
#define INPUT_HANDLER

#include <functional>
#include <map>
#include <vector>

#include <SDL.h>

#include "Core/Framework/Events/InputEventHandler.h"
#include "Core/node/Component/Derivative/ComponentUpdatable.h"
#include "Core/Framework/Networking/NetworkTypes.h"

class networkManager;
class inputEventActions;

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
	FuncObj(std::string name = "None", std::function<bool()> fun = std::function<bool()>()) {
		action = name;
		func = fun;
	};
	std::string action = "None";
	std::function<bool()> func;
};

struct keyObj {
	SDL_Keycode primary = SDLK_UNKNOWN;
	SDL_Keycode modifier = SDLK_UNKNOWN;
	e_CONDITIONAL_AND_OR conditional = NEITHER;
	FuncObj func = FuncObj();
	eNetMessage netMessage;

	keyObj(SDL_Keycode key0, SDL_Keycode key1, e_CONDITIONAL_AND_OR con, FuncObj fc, eNetMessage msg) {
		primary = key0;
		modifier = key1;
		conditional = con;
		func = fc;
		netMessage = msg;
	}

	bool operator == (const keyObj &rhs) const
	{ /* your logic for comparision between "*this" and "rhs" */
		return(
			this->primary == rhs.primary && 
			this->modifier == rhs.modifier && 
			func.action == rhs.func.action &&
			rhs.conditional == this->conditional &&
			rhs.netMessage == this->netMessage);
	}
};

using KeyVec = std::vector<keyObj>;

using StateMap = std::map<e_INPUT_STATE, KeyVec>;

using keyHandle = KeyVec::iterator;

class inputHandler : public ComponentUpdatable
{
public:
	inputHandler();
	~inputHandler() {};

	// inherited update for component
	virtual bool Update();
	/// networking inherited
	virtual void Serialize(char* data);
	virtual void Deserialize(char* data);

	// Safety to delete any copies or new instances
	inputHandler(const inputHandler&) = delete;
	void operator=(inputHandler const&) = delete;

	void add(e_INPUT_STATE state, FuncObj func, SDL_Keycode primaryKey, e_CONDITIONAL_AND_OR con, SDL_Keycode ModifierKey, eNetMessage netMsg);
	
	bool setState(e_INPUT_STATE);

	//void remove();

	//void get(unsigned&);

	bool trigger(std::string &);

	void init();

private:

	bool checkModKey();

	StateMap m_inputFunctions;
	e_INPUT_STATE m_currentState;
	InputEventHandler * m_inputEvents;
	std::shared_ptr<inputEventActions> m_inputEventActions;

	NetworkManager * m_networkManager;

};

#endif