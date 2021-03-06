#include "GameManager.h"

#include "GameFlow\Updater\MasterUpdate.h"
#include "Core/Framework/Render/Renderer3D.h"
#include "Core/Framework/Networking/NetworkManager.h"
#include "Core/Framework/Render/Model.h"
#include "GameFlow/Factories/EntityFactory.h"
#include "GameFlow/Factories/ComponentFactory.h"
//threading

#include <memory>

GameManager::GameManager()
{
	m_masterUpdate = &MasterUpdate::getInstance();
	m_renderer = &Renderer3D::getInstance();
	m_networkManager = &NetworkManager::getInstance();
	m_threadSpool = &ThreadSpool::getInstance();
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
	ComponentFactory::getInstance();
	EntityFactory::getInstance();
}

void GameManager::initGameEngine()
{
	Factories();

	RunGameLoop();
}

ThreadSpool& GameManager::getThreadMaster()
{
	return *m_threadSpool;
}
