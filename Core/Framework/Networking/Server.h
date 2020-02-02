#ifndef SERVER_H
#define SERVER_H
#pragma once

#include "Core/Framework/Networking/INet.h"


//struct ClientAddr
//{
	//int ip;
	//int port;

	//ClientAddr(int IP, int PORT) : ip(IP), port(PORT) {}
//};

class Server : public INet
{
public:
	Server();
	~Server() {};

	// Safety to delete any copies or new instances
	//Server(const Server&)	= delete;
	//void operator=(Server const&)		= delete;
	
	virtual void Update();

	virtual void AddUser();

	virtual void InitTCP();

	virtual void InitUDP();

	virtual void Serialize(eNetMessage);

	virtual void Deserialize(char*data);

private:
	/// private implementation for members
	//struct PImpl;
	//std::unique_ptr<PImpl> m_impl;
};

#endif // !SERVER_H