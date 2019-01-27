// main

#include <iostream>

#include "Core/Render/Model.h"

#include "GameFlow/GameManager.h"


GameManager * initGame = &GameManager::getInstance();


int main(int argc, char *argv[])
{

	initGame->initGameEngine();

	return 0;
}
