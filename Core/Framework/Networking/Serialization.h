#ifndef SERIALIZATION
#define SERIALIZATION
#pragma once

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
public:


	virtual void Serialize(char* data) = 0;

	virtual void Deserialize(char* data) = 0;

private:

	 eNetworkEvent getEvent(char* event);

	char * m_data;
	
};

#endif // !SERIALIZATION