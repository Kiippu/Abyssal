
#include "Core/Render/Renderer.h"

// Headerphile - Renderer.h
//
// This file controls most things related to the Renderer. 
// Put in a separate class to avoid code cluttering

#pragma once

// C++ standard
#include <iostream>
#include <string>


// Headerphile
#include "Core/Render/Shader/Shader.h"
#include "Core/Render/Model.h"
#include "GameFlow/GameObjects/GameObjects.h"
#include "Core/Node/Derivative/DynamicEntityNode.h"
#include "Core/Component/Derivative/Render/Model3D.h"

std::string programName = "Headerphile SDL2 - OpenGL thing";

// OpenGL stuff
#define GL3_PROTOTYPES 1
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <SDL.h>

Renderer::Renderer()
{
	m_gameObjects = &GameObjects::getInstance();

	//simpleShader = std::make_shared<Shader>();
	// Set up our matricies
	// I strongly encourage you to mess around with the values here and see what they do
	// It's a lot of fun, and you'll learn a lot
	// It'll also give you a better sense of what's going on
	// ...Which will make it easier for you to debug

	// Set up projection matric
	projection = glm::perspective
	(
		45.0f,       // Field of view ( how far out to the sides we can see
		1.0f / 1.0f, // Aspect ratio ( stretch image in widh or height )
		0.1f,        // Near plane ( anything close than this will be cut off )
		100.0f       // Far plane ( anything further away than this will be cut off )
	);

	// Set up view matric
	view = glm::lookAt
	(
		glm::vec3(0, 0, -4), // Camera is at (0,0,-4), in World Space
		glm::vec3(0, 0, 0),  // And looks at the origin
		glm::vec3(0, -1, 0)  // Head is up ( set to 0,-1,0 to look upside-down )
	);
}


void Renderer::Render(Model & model)
{
	// Tell Renderer to clear everything
	RenderStart();

	
	// Set the matrix in the model
	// This has to be done once per model
	SetMatrix(model.GetModel(), model.GetShader());

	// Render our model
	RenderModel(model);

	// Tell our Renderer to swap the buffers
	RenderEnd();
}

bool Renderer::Init()
{
	// Initialize SDL's Video subsystem
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Failed to init SDL\n";
		return false;
	}

	// Create our window centered at 512x512 resolution
	mainWindow = SDL_CreateWindow(programName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		512, 512, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	// Check that everything worked out okay
	if (!mainWindow)
	{
		std::cout << "Unable to create window\n" << std::endl;;
		CheckSDLError(__LINE__);
		return false;
	}

	SetSDL_GL_Attributes();

	// Create our opengl context and attach it to our window
	mainContext = SDL_GL_CreateContext(mainWindow);

	// This makes our buffer swap syncronized with the monitor's vertical refresh
	// 		( which means it enables v-sync)
	// Setting this to 0 will disable V-sync
	// 		Which means our application could run at unlimited fps
	SDL_GL_SetSwapInterval(1);

	// Init GLEW
	glewExperimental = GL_TRUE;
	glewInit();

	SetOpenGLOptions();

	//if (!CreateSimpleShader()) return false;

	return true;
}

bool Renderer::RenderSetup()
{
	if (!Init())
		return false;

	std::cout << "Controls :"
		<< "\n\tMove left : \t\t\t Left"
		<< "\n\tMove right : \t\t\t Right"
		<< "\n\tMove up : \t\t\t Up"
		<< "\n\tMove down : \t\t\t Down"
		<< "\n\tMove clockwise : \t\t w"
		<< "\n\tMove counter-clockwise : \t s"
		<< std::endl;

	SetUpShader("Core/Render/Shader/Vertex/vert.glsl", "Core/Render/Shader/Fragment/frag.glsl");

	auto dynamicObjects = m_gameObjects->getAllDynamicObjects();
	for (auto & obj : dynamicObjects)
	{
		auto modelComponent = obj->GetComponentContainer()->GetComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D);
		Model3D & model3D = dynamic_cast<Model3D&>(*modelComponent);

		auto & model = model3D.getModel();
		/// TODO: replace with array pf objects etc
		if (!model.SetupBufferObjects())
			return false;

		// Set the shader 
		SetShader(model);
	}




	return true;
}

bool Renderer::RegisterObjects()
{
	return false; 
}

bool Renderer::SetUpShader(const std::string & vertex, const std::string & fragment)
{
	auto dynamicList = m_gameObjects->getAllDynamicObjects();
	for (auto & obj : dynamicList)
	{
		if (obj->GetComponentContainer()->hasComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D))
		{
			auto modelComponent = obj->GetComponentContainer()->GetComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D);
			Model3D & model3D = dynamic_cast<Model3D&>(*modelComponent);
			auto & model = model3D.getModel();
			Shader & shader = model.GetShader();

			if (!shader.Init())
				return false;

			//if (!simpleShader.LoadShader("vert.glsl", GL_VERTEX_SHADER))
			if (!shader.LoadShader(vertex, GL_VERTEX_SHADER))
				return false;

			if (!shader.LoadShader(fragment, GL_FRAGMENT_SHADER))
				return false;

			if (!shader.LinkShaders())
				return false;

		}

	}
	return true;
}

void Renderer::RenderStart()
{
	// Make our background black
	glClearColor(0.5, 0.5, 0.5, 1.0);

	// We need to add GL_DEPTH_BUFFER_BIT so that the depth buffer will be cleared too.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::RenderModel(const Model & model)
{
	model.Render();
}

void Renderer::RenderEnd()
{
	// Swap our buffers to make our changes visible
	SDL_GL_SwapWindow(mainWindow);
}

void Renderer::SetMatrix(const glm::mat4 & model, Shader & shader)
{
	glm::mat4 mvp = projection * view  * model;
	shader.SetMatrix(mvp);
}

void Renderer::SetShader(Model & m)
{
	m.SetShader(m.GetShader());
}

void Renderer::Cleanup()
{
	auto dynamicList = m_gameObjects->getAllDynamicObjects();
	for (auto & obj : dynamicList)
	{
		if (obj->GetComponentContainer()->hasComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D))
		{
			auto modelComponent = obj->GetComponentContainer()->GetComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D);
			Model3D & model3D = dynamic_cast<Model3D&>(*modelComponent);
			auto & model = model3D.getModel();
			Shader & shader = model.GetShader();
			// Cleanup all the things we bound and allocated
			shader.CleanUp();
		}
	}

	// Delete our OpengL context
	SDL_GL_DeleteContext(mainContext);

	// Destroy our window
	SDL_DestroyWindow(mainWindow);

	// Shutdown SDL 2
	SDL_Quit();
}

void Renderer::CheckSDLError(int line)
{
	std::string error = SDL_GetError();

	if (error != "")
	{
		std::cout << "SLD Error : " << error << std::endl;

		if (line != -1)
			std::cout << "\nLine : " << line << std::endl;

		SDL_ClearError();
	}
}

void Renderer::SetOpenGLOptions()
{
	// Enable blending so that we can have transparanet object
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Enable depth testing so that closer triangles will hide the triangles farther away
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}

bool Renderer::SetSDL_GL_Attributes()
{
	// Set our OpenGL version.
		// SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// 3.2 is part of the modern versions of OpenGL, but most video cards whould be able to run it
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	// Turn on double buffering with a 24bit Z buffer.
	// You may need to change this to 16 or 32 for your system
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	return true;
}
