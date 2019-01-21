#pragma once

//#include "Core/Render/Renderer.h"
//#include "Core/Events/EventHandler.h"

//class UpdaterGameLoop;

class GameManager
{
public:
	static GameManager & getInstance() {
		static GameManager instance;
		return instance;
	}

private:
	// private constructor to impl singleton
	GameManager() {};

	//void Render();

	//void MasterUpdate();

	// Handles all our SDL2 event ( quit, keydown, ++ )
	//EventHandler m_handler;

	// Handles everything related to OpenGL
	//Renderer m_renderer;

public:
	// Safety to delete any copies or new instances
	GameManager(const GameManager&) = delete;
	void operator=(GameManager const&) = delete;

	// Scene manager

	//bool InitEngine();

};

