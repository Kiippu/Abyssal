#pragma once
#ifndef MASTER_UPDATE_H
#define MASTER_UPDATE_H

#include <memory>

class EventHandler;
class Model;

class MasterUpdate
{
public:
	static MasterUpdate & getInstance() {
		static MasterUpdate instance;
		return instance;
	}

private:
	// private constructor to impl singleton
	MasterUpdate();

	std::unique_ptr<EventHandler> m_eventHandler;

	Model * model;

public:
	// Safety to delete any copies or new instances
	MasterUpdate(const MasterUpdate&) = delete;
	void operator=(MasterUpdate const&) = delete;

	void Update();

	void UpdateModel();

};

#endif 