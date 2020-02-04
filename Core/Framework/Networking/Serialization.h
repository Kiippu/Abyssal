#ifndef SERIALIZATION
#define SERIALIZATION
#pragma once

#include <memory>
#include "Core/Framework/Threading/CsLibGuarded/guarded.hpp"

enum class eNetworkEvent : unsigned short 
{
	// unknown
	UNKNOWN,

	// Server
	server_clientAck,
	server_levelData,

	// client
	client_connectionRequest,
	client_input
};


class Serialization
{
protected:

	virtual void Serialize() = 0;

	virtual void Deserialize(char*data) = 0;

private:

	eNetworkEvent getEvent(char* event);

	libguarded::guarded<char*> data;

	/*std::thread th1([&data]() {
		for (int i = 0; i < 10000; ++i) {
			++(*data_handle);
		}
	});*/

	//char * data;
	
};

#endif // !SERIALIZATION