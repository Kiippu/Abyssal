// main - OLD CODE STARTS HERE!!
//
//#include <iostream>
//#include <functional>
//#include <vector>
//
//#include "Core/Framework/Render/Model.h"
//
//#include "GameFlow/GameManager.h"
//#include "GameFlow/GameObjects/GameObjects.h"
//#include "Core/Node/Derivative/Shape/Cube.h"
//
//GameManager * initGame = &GameManager::getInstance();
//
//class Base {
//public:
//	virtual bool createNode() = 0;
//};
//
//template <typename T>
//class Descriptor : public Base {
//	T func;
//public:
//	Descriptor(T & first)
//	{
//		func = first;
//	}
//	virtual bool createNode();
//	virtual T & getDescriptor();
//};
//
//template <class T>
//bool Descriptor<T>::createNode()
//{
//	T node = getDescriptor();
//
//	GameObjects * m_gameObjects;
//	m_gameObjects = &GameObjects::getInstance();
//	short objListCount = m_gameObjects->getAllObjects().size();
//	node();
//
//	if (objListCount > m_gameObjects->getAllObjects().size())
//		return true;
//	return false;
//}
//
//template <class T>
//T & Descriptor<T>::getDescriptor()
//{
//	return func;
//}
// main - OLD CODE ENDS HERE!!


//int main(int argc, char *argv[])
//{
//	/// OLD CODE STARTS HERE
//	//initGame->initGameEngine();
//	/// OLD CODE ENDS HERE
//
//
//
//
//
//	return 0;
//}

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include "Core/Framework/Render/VulkanMaster.h"

#include <iostream>

int main() {
	
	VulkanMaster app;

	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;

	return 0;
}
