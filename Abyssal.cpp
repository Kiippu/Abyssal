// main

#include <iostream>
#include <functional>
#include <vector>

#include "Core/Framework/Render/Model.h"

#include "GameFlow/GameManager.h"
#include "GameFlow/GameObjects/GameObjects.h"
#include "Core/Node/Derivative/Shape/Cube.h"

GameManager * initGame = &GameManager::getInstance();

class Base {
public:
	virtual bool createNode() = 0;
};

template <typename T>
class Descriptor : public Base {
	T func;
public:
	Descriptor(T & first)
	{
		func = first;
	}
	virtual bool createNode();
	virtual T & getDescriptor();
};

template <class T>
bool Descriptor<T>::createNode()
{
	T node = getDescriptor();

	GameObjects * m_gameObjects;
	m_gameObjects = &GameObjects::getInstance();
	short objListCount = m_gameObjects->getAllObjects().size();
	node();

	if (objListCount > m_gameObjects->getAllObjects().size())
		return true;
	return false;
}

template <class T>
T & Descriptor<T>::getDescriptor()
{
	return func;
}

int main(int argc, char *argv[])
{

	initGame->initGameEngine();

	return 0;
}
