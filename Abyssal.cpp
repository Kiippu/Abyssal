// headerphile.com - main.cpp
// This is the main manager the class that controls everything
// It doesn't do much on it's own, it just tells the other classes do to stuff
//
// Compile : clang++ main.cpp EventHandler.cpp -lSDL2 -lGL -lGLEW -std=c++11 -o Part5
//

#include <iostream>

#include "Core/Render/Renderer.h"
#include "Core/Render/Model.h"
#include "Core/Events/EventHandler.h"
#include "Core/Math/Math.h"

// Handles all our SDL2 event ( quit, keydown, ++ )
EventHandler handler;

// Handles everything related to OpenGL
Renderer * renderer = &Renderer::getInstance();

// Handles a single model with its vertexes and matrix
Model model;

void PrintCommands();
void UpdateModel();


void Update()
{
	while (!handler.WasQuit())
	{
		// Update our event handler
		handler.Update();

		// Update our model position
		UpdateModel();

		Renderer::getInstance().Render(model);
	}
}

void UpdateModel()
{
	if (handler.IsKeyDown(SDLK_r))
	{
		model.ResetMatrix();
	}
	else
	{
		if (handler.IsKeyDown(SDLK_LCTRL))
		{
			glm::vec3 axis = Math::GetRotationAxis(handler);

			if (axis != glm::vec3(0.0f))
				model.Rotate(axis);
		}
		else if (handler.IsKeyDown(SDLK_LSHIFT))
		{
			glm::vec3 axis = Math::GetScaleAxis(handler);
			model.Scale(axis);
		}
		else
		{
			glm::vec3 axis = Math::GetAxis(handler);
			model.Translate(axis);
		}
	}
}

int main(int argc, char *argv[])
{
	if (!renderer->Init())
		return -1;

	PrintCommands();

	// Set up our only shader in Shader
	renderer->SetUpShader("Core/Render/Shader/Vertex/vert.glsl", "Core/Render/Shader/Fragment/frag.glsl");

	// Create the Model
	if (!model.SetupBufferObjects())
		return -1;

	// Set the shader 
	renderer->SetShader(model);

	// Run our main update loop
	Update();

	renderer->Cleanup();

	return 0;
}

void PrintCommands()
{
	std::cout << "Controls :"
		<< "\n\tMove left : \t\t\t Left"
		<< "\n\tMove right : \t\t\t Right"
		<< "\n\tMove up : \t\t\t Up"
		<< "\n\tMove down : \t\t\t Down"
		<< "\n\tMove clockwise : \t\t w"
		<< "\n\tMove counter-clockwise : \t s"
		<< std::endl;
}
