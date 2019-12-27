#pragma once
#ifndef I_Factory_H
#define I_Factory_H

#include <filesystem>
#include <map>
#include <functional>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

#include "Core/framework/IO/FileSystemHelper.h"
#include "GameFlow/GameObjects/GameObjects.h"

class FileSystemHelper;
class GameObjects;



using namespace std::experimental::filesystem;

class IFactory //: public Descriptor
{

private:

	path m_path;
	FileSystemHelper * m_fileSystemHelper = &FileSystemHelper::getInstance();
	GameObjects * m_gameObjects = &GameObjects::getInstance();

public:

	virtual unsigned create(std::string) = 0;

	virtual void setMasterPath(path filePath) { m_path = filePath; };
	virtual const path& getMasterPath() { return m_path; };

	virtual FileSystemHelper * getFileSystemHelper() { return m_fileSystemHelper; };
	virtual GameObjects * getGameObjects() { return m_gameObjects; };

};


template<typename Out>
inline void split(const std::string &s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

inline std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

#endif // !I_Factory_H