#pragma once

//#include "Core/Render/Renderer.h"
//#include "Core/Events/EventHandler.h"
//#include <memory>
//#include <iostream>

//class UpdaterGameLoop;
//class EventHandler;
//class Renderer;

class Renderer;
class MasterUpdate;

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

	void Render();

	void Update();

	void RunGameLoop();

	MasterUpdate * m_masterUpdate;

	Renderer * m_renderer;

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

	// Scene manager

	//r

	//bool InitEngine();

};

