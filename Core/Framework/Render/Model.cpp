#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <vector>

#include "Core/Framework/Render/Shader/Shader.h"
#include "Model.h"


	Model::Model()
	: m_positionAttributeIndex(0)
	, m_colorAttributeIndex(1)
{
}

glm::mat4 Model::GetModel()
{
	return model;
}

void Model::SetMatrix(glm::mat4 mvp)
{
	m_shader.UseProgram();
	m_shader.SetMatrix( mvp );
}

void Model::Render() const
{
	m_shader.UseProgram();
	//glDrawArrays(GL_TRIANGLES, 0, m_positions.size() / 3 );
}

void Model::ResetMatrix()
{
	model = glm::mat4(1.0f);
	m_rotate = glm::mat4(1.0f);
	m_scale = glm::mat4(1.0f);
	m_translate = glm::mat4(1.0f);
}

void Model::Translate(const glm::vec3 &axis)
{
	m_translate = glm::translate(m_translate, axis);
	UpdateMatrix();
}

void Model::Rotate(glm::vec3 axis, float angle)
{
	m_rotate = glm::rotate(m_rotate, angle, axis);
	UpdateMatrix();
}

void Model::Scale(glm::vec3 axis)
{
	m_scale = glm::scale(m_scale, axis);
	UpdateMatrix();
}

void Model::UpdateMatrix()
{
	model = m_scale * m_translate * m_rotate ;
}

// Cleanup all the things we bound and allocated
void Model::CleanUp()
{
	glDisableVertexAttribArray(0);

	glDeleteBuffers(2, vbo);

	glDeleteVertexArrays(1, vao);

	// Shutdown SDL 2
	SDL_Quit();
}

// This is where we setup the model like we saw in the first part
bool Model::SetupBufferObjects()
{
	m_positions = ReadFile("Data/positions.txt");
	m_colors = ReadFile("Data/colors.txt");

	// Generate and assign two Vertex Buffer Objects to our handle
	glGenBuffers(2, vbo);

	// Generate and assign a Vertex Array Object to our handle
	glGenVertexArrays(1, vao);

	// Bind our Vertex Array Object as the current used object
	glBindVertexArray(vao[0]);

	// Colors
	// =======================
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);

	// Copy the vertex data from diamond to our buffer
	glBufferData(GL_ARRAY_BUFFER, m_colors.size() * sizeof(GLfloat), &m_colors[0], GL_STATIC_DRAW);

	// Specify that our coordinate data is going into attribute index 0, and contains three floats per vertex
	glVertexAttribPointer(m_colorAttributeIndex, 4, GL_FLOAT, GL_FALSE, 0, 0);

	// Positions
	// ===================
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	// Copy the vertex data from diamond to our buffer
	glBufferData(GL_ARRAY_BUFFER, m_positions.size() * sizeof(GLfloat), &m_positions[0], GL_STATIC_DRAW);

	// Specify that our coordinate data is going into attribute index 0, and contains three floats per vertex
	glVertexAttribPointer(m_positionAttributeIndex, 3, GL_FLOAT, GL_FALSE, 0, 0 );

	// Enable our attributes within the current VAO
	glEnableVertexAttribArray(m_positionAttributeIndex);
	glEnableVertexAttribArray(m_colorAttributeIndex);

	// Set up shader 
	// ===================
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(vao[0]);

	return true;
}

// A generic function that takes a path as a paramater
// Returns the information as a char*
static std::vector<GLfloat> ReadFile(const char* file)
{
	// Open file
	std::ifstream t(file);

	std::vector<GLfloat> result;
	std::cout << "Reading : " << file << std::endl;

	while (t.good())
	{
		std::string str;
		t >> str;

		GLfloat f = std::atof(str.c_str());

		result.push_back(f);
	}

	return result;
}

void Model::SetShader(Shader _shader)
{
	m_shader = _shader;
}

Shader & Model::GetShader()
{
	return m_shader;
}

