#include "Client.h"
#include <WinSock2.h>
#include <ws2tcpip.h>

#include <iostream>
#include <string>

#include "Core/Node/Derivative/DynamicEntityNode.h"
#include "Core/Node/Component/Derivative/ComponentUpdatable.h"
//#include "GameFlow/GameObjects/GameObjects.h"
//#include "Core/Node/Containers/Container.h"

#pragma comment(lib, "ws2_32.lib")
//
//struct Client::PImpl
//{
//	PImpl()
//	{}
//	~PImpl() {}
//
//
//};

Client::Client()
	: INet(eNetType::client)
{
};

void Client::Update()
{
}

void Client::AddUser()
{
}

void Client::InitTCP()
{

}

void Client::InitUDP()
{
	printf("\nInit Server begin\n");
	// Port number
	const unsigned short PORT_NUMBER = 54000;

	// start winSock
	WSADATA data;
	WORD version = MAKEWORD(2, 2);
	int wsOk = WSAStartup(version, &data);
	if (wsOk != 0) 
	{
		printf("Cant't start Winsock: %d!", wsOk);
		return;
	}

	// create hint structure for srever
	sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(9900);

	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

	//socket creation
	SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);

	printf("\nentering client loop now!\n");
	// write to socket
	std::string buf;
	while (true)
	{
		buf.clear();
		std::cin >> buf;
		if (!buf.empty()) {
			int sendOk = sendto(out, buf.c_str(), buf.size() + 1, 0, (sockaddr*)&server, sizeof(server));

			if (sendOk == SOCKET_ERROR)
			{
				printf("Cant't bind socket!: %d!", WSAGetLastError());
			}
		}
	}
	

	// close socket
	closesocket(out);
	
	// clean up
	WSACleanup();

}

void Client::Serialize(eNetMessage)
{
	m_gameObjects->getAllDynamicObjects();
	for (auto obj : m_gameObjects->getAllDynamicObjects())
	{
		for (auto base : obj->GetComponentContainer()->GetContainerList()) 
		{
			auto& comp = dynamic_cast<ComponentUpdatable&>(*base);
			comp.Serialize();
		}
	}
}

void Client::Deserialize(char*data)
{
}