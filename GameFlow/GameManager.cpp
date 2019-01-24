#include "GameManager.h"

#include "Core/Events/EventHandler.h"
#include "GameFlow\Updater\MasterUpdate.h"
#include "Core/Render/Renderer.h"

#include <memory>

GameManager::GameManager()
{
	m_masterUpdate = &MasterUpdate::getInstance();
	m_renderer - &Renderer::getInstance();
}

void GameManager::Render()
{

}

void GameManager::Update()
{



}

void GameManager::RunGameLoop()
{

}
