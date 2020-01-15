#include "Server.h"
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <vector>

struct Server::PImpl
{
	PImpl()
	{}


	// Address info 
	int portNum;
	char * ipAddress;
	int socket_d;
	struct sockaddr_in server_addr;

	std::vector<ClientAddr> clientList;

};

Server::Server() 
	: INet(eNetType::server), m_impl(new PImpl) {};

void Server::Update()
{
}

void Server::AddUser()
{
}

void Server::Init()
{
}

void Server::Serialize()
{
}

void Server::Deserialize()
{
}
