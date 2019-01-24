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
//#include "Core/Render/Model.h"

// OpenGL stuff
#define GL3_PROTOTYPES 1
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <SDL.h>

class Model;
class Shader;

class Renderer
{
public:
	static Renderer & getInstance() {
		static Renderer instance;
		return instance;
	}


private:
	// private constructor to impl singleton
	Renderer();

public:
	// Safety to delete any copies or new instances
	Renderer(const Renderer&) = delete;
	void operator=(Renderer const&) = delete;

	void Render(Model & model);

	bool Init();

	bool SetUpShader(const std::string &vertex, const std::string &fragment);

	// Do the first step of rendering ( clearing everything )
	void RenderStart();

	// Renders a Model
	void RenderModel(const Model &model);

	// Called at the end to swap the buffers
	void RenderEnd();

	void SetMatrix(const glm::mat4 &model);

	void SetShader(Model &m);

	void Cleanup();

	void CheckSDLError(int line = -1);

private:

	// This set our extra OpenGL options we'll need
	void SetOpenGLOptions();

	bool SetSDL_GL_Attributes();

	// Our SDL_Window ( just like with SDL2 wihout OpenGL)
	SDL_Window *mainWindow;

	// Our opengl context handle
	SDL_GLContext mainContext;

	// Our wrapper to simplify the shader code
	std::shared_ptr<Shader> simpleShader;

	// Matricies
	glm::mat4 projection;
	glm::mat4 view;
};
