#include "GameManager.h"

#include "GameFlow\Updater\MasterUpdate.h"
#include "Core/Render/Renderer.h"
#include "Core/Render/Model.h"

#include <memory>

GameManager::GameManager()
{
	m_masterUpdate = &MasterUpdate::getInstance();
	m_renderer = &Renderer::getInstance();
	m_model = std::make_unique<Model>();
}

bool GameManager::Render()
{
	if (!m_renderer->Init())
		return -1;

	std::cout << "Controls :"
		<< "\n\tMove left : \t\t\t Left"
		<< "\n\tMove right : \t\t\t Right"
		<< "\n\tMove up : \t\t\t Up"
		<< "\n\tMove down : \t\t\t Down"
		<< "\n\tMove clockwise : \t\t w"
		<< "\n\tMove counter-clockwise : \t s"
		<< std::endl;

	m_renderer->SetUpShader("Core/Render/Shader/Vertex/vert.glsl", "Core/Render/Shader/Fragment/frag.glsl");

	/// TODO: replace with array pf objects etc
	if (!m_model->SetupBufferObjects())
		return -1;

	// Set the shader 
	m_renderer->SetShader(*m_model);
}

void GameManager::Update()
{
	m_masterUpdate->Update(*m_model);
}

void GameManager::RunGameLoop()
{
	Render();

	// Run our main update loop
	Update();

	m_renderer->Cleanup();

}

void GameManager::initGameEngine()
{
	RunGameLoop();
}
