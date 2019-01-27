#pragma once

//#include "Core/Render/Renderer.h"
//#include "Core/Events/EventHandler.h"
//#include <memory>
//#include <iostream>

//class UpdaterGameLoop;
//class EventHandler;
//class Renderer;
#include <memory>

class Renderer;
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

	MasterUpdate * m_masterUpdate;

	Renderer * m_renderer;

	// Handles a single model with its vertexes and matrix
	//std::unique_ptr<Model> m_model;

	// Handles all our SDL2 event ( quit, keydown, ++ )
	/*std::unique_ptr<EventHandler> m_handler = std::make_unique<EventHandler>();
	std::unique_ptr<Renderer> m_renderer = std::make_unique<Renderer>();
*/
	// Handles everything related to OpenGL
	 //m_renderer;

public:
	// Safety to delete any copies or new instances
	GameManager(const GameManager&) = delete;
	void operator=(GameManager const&) = delete;

	void initGameEngine();

	// Scene manager

	//r

	//bool InitEngine();

};

