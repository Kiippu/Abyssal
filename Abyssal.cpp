// main

#include <iostream>
#include <functional>
#include <vector>

#include "Core/Render/Model.h"

#include "GameFlow/GameManager.h"
#include "GameFlow/Factories/EntityFactory.h"
#include "GameFlow/GameObjects/GameObjects.h"
#include "Core/Node/Derivative/Shape/Cube.h"

GameManager * initGame = &GameManager::getInstance();

class Base {
public:
	virtual bool createNode() = 0;
};

//template<class T>
//class DescBase : public base {
//	virtual T & getDescriptor() = 0;
//};

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

	/*auto funnn = myobject.createNode();
	funnn();*/

}

template <class T>
T & Descriptor<T>::getDescriptor()
{
	return func;
}

int main(int argc, char *argv[])
{
	std::function<bool()> glambda = [&]()
	{ 
		GameObjects * m_gameObjects = &GameObjects::getInstance();

		std::shared_ptr<Cube> cube;

		cube = std::make_shared<Cube>();

		cube->GetComponentContainer()->AddComponent(LABEL_COMPONENT_TYPE::COMP_MODEL3D);

		std::shared_ptr<Node> node = std::dynamic_pointer_cast<Node>(cube);

		m_gameObjects->RegisterWorldObject(node);
		return true;
	};

	Descriptor <std::function<bool()>> * myobject = new Descriptor <std::function<bool()>>(glambda);
	
	using DE = Descriptor <std::function<bool()>>;


	std::vector<Base*> cont;

	cont.push_back(myobject);

	cont[0]->createNode();

	//DE * bill = container[0];



	/*std::vector< std::unique_ptr<DescBase>> container;
	container.push_back(std::unique_ptr<DescBase>(myobject));

	auto & model3D = dynamic_cast<Descriptor <std::function<bool()>> *>(*myobject);

	auto b = std::static_cast<Descriptor<bool>>(container[0]);
*/


	/*
	DescriptorContainer<DescBase> container;

	container.push_back(myobject);

	auto descList = container.getContainer();

	descList[0]*/

	/*auto funnn = myobject.createNode();
	funnn();*/


	EntityFactory::getInstance().ImportEntities();

	initGame->initGameEngine();

	return 0;
}
