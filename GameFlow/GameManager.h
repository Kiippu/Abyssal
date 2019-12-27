#pragma once

//#include "Core/Render/Renderer3D.h"
//#include "Core/Events/InputEventHandler.h"
//#include <memory>
//#include <iostream>

//class UpdaterGameLoop;
//class InputEventHandler;
//class Renderer3D;
#include <memory>

class Renderer3D;
class MasterUpdate;
class Model;

class GameManager
{
public:
	static GameManager & getInstance() {
		static GameManager instance;
		return instance;
	}

private:
	// private constructor to impl singleton
	GameManager();

	bool Render();

	void Update();

	void RunGameLoop();

	void Factories();

	MasterUpdate * m_masterUpdate;

	Renderer3D * m_renderer;

public:
	// Safety to delete any copies or new instances
	GameManager(const GameManager&) = delete;
	void operator=(GameManager const&) = delete;

	void initGameEngine();

};

