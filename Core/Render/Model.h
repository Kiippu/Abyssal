#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <vector>

#include "Core/Render/Shader/Shader.h"

class Model
{
	public: 

	Model();

	glm::mat4 GetModel();

	void SetMatrix(glm::mat4 mvp);

	void Render() const;

	void ResetMatrix();

	void Translate(const glm::vec3 &axis);

	void Rotate(glm::vec3 axis, float angle = 0.1);

	void Scale(glm::vec3 axis);

	void UpdateMatrix();

	// Cleanup all the things we bound and allocated
	void CleanUp();

	// This is where we setup the model like we saw in the first part
	bool SetupBufferObjects();


	void SetShader(Shader _shader);

	private:

	// VBO data
	std::vector<GLfloat> m_positions;
	std::vector<GLfloat> m_colors;

	// Create variables for storing the ID of our VAO and VBO
	GLuint vbo[2], vao[1]; 

	// The positons of the position and color data within the VAO
	const uint32_t m_positionAttributeIndex, m_colorAttributeIndex;

	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 m_model;
	glm::mat4 m_rotate;
	glm::mat4 m_translate;
	glm::mat4 m_scale;

	Shader m_shader;
};

// A generic function that takes a path as a paramater
// Returns the information as a char*
static std::vector<GLfloat> ReadFile(const char* file);
