// Headerphile - Renderer3D.h
//
// This file controls most things related to the Renderer3D. 
// Put in a separate class to avoid code cluttering

#pragma once

// C++ standard
#include <iostream>
#include <string>

#include "Core/Framework/Render/Shader/Shader.h"


// OpenGL stuff
#define GL3_PROTOTYPES 1
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <SDL.h>

#include "GameFlow/GameObjects/GameObjects.h"

class Model;
class Shader;
class GameObjects;

class Renderer3D
{
public:
	static Renderer3D & getInstance() {
		static Renderer3D instance;
		return instance;
	}

private:
	// private constructor to impl singleton
	Renderer3D();

public:
	// Safety to delete any copies or new instances
	Renderer3D(const Renderer3D&) = delete;
	void operator=(Renderer3D const&) = delete;

	void Render(Model & model);

	bool RenderSetup();

	bool RegisterObjects();

	// Do the first step of rendering ( clearing everything )
	void RenderStart();

	// Renders a Model
	void RenderModel(const Model &model);

	// Called at the end to swap the buffers
	void RenderEnd();

	void SetMatrix(const glm::mat4 &model, Shader & shader);

	void Cleanup();

	void CheckSDLError(int line = -1);

private:


	bool SetUpShader(const std::string &vertex, const std::string &fragment);

	void SetShader(Model &m);

	bool Init();

	// This set our extra OpenGL options we'll need
	void SetOpenGLOptions();

	bool SetSDL_GL_Attributes();

	// Our SDL_Window ( just like with SDL2 wihout OpenGL)
	SDL_Window *mainWindow;

	// Our opengl context handle
	SDL_GLContext mainContext;

	// Our wrapper to simplify the shader code
	//std::shared_ptr<Shader> simpleShader;

	// Matricies
	glm::mat4 projection;
	glm::mat4 view;

	GameObjects * m_gameObjects;

};
