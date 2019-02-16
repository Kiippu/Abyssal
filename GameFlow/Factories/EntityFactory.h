#pragma once
#ifndef Entity_Factory_H
#define Entity_Factory_H

#include <filesystem>
#include <map>
#include <functional>

class FileSystemHelper;
class GameObjects;

using namespace std::experimental::filesystem;


class EntityFactory //: public Descriptor
{
public:
	static EntityFactory & getInstance() {
		static EntityFactory instance;
		return instance;
	}

private:
	// private constructor to impl singleton
	EntityFactory();

	path m_path = "Data/Entities/EntityList.txt";

	FileSystemHelper * m_fileSystemHelper;

	GameObjects * m_gameObjects;

public:
	// Safety to delete any copies or new instances
	EntityFactory(const EntityFactory&) = delete;
	void operator=(EntityFactory const&) = delete;

	bool ImportEntities();
};



#endif // !EntityFactory