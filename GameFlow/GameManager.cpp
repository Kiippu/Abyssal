#include "GameManager.h"

#include "GameFlow\Updater\MasterUpdate.h"
#include "Core/Framework/Render/Renderer3D.h"
#include "Core/Framework/Render/Model.h"

#include <memory>

GameManager::GameManager()
{
	m_masterUpdate = &MasterUpdate::getInstance();
	m_renderer = &Renderer3D::getInstance();
	//m_model = std::make_unique<Model>();
}

bool GameManager::Render()
{
	m_renderer->RenderSetup();

	return true;
}

void GameManager::Update()
{
	m_masterUpdate->Update();
}

void GameManager::RunGameLoop()
{
	Render();

	// Run our main update loop
	Update();

	m_renderer->Cleanup();

}

void GameManager::Factories()
{
	/// TODO: create factories here !!!!!
}

void GameManager::initGameEngine()
{
	Factories();

	RunGameLoop();
}
