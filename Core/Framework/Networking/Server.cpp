#include "Server.h"
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <vector>

#pragma comment(lib, "ws2_32.lib")


Server::Server()
	: INet(eNetType::server)
{}

void Server::Update()
{
}

void Server::AddUser()
{
}

void Server::InitTCP()
{

}

void Server::InitUDP()
{
	printf("\nInit Server begin\n");
	// Port number
	const unsigned short PORT_NUMBER = 9900;

	// start winSock
	WSADATA data;
	WORD version = MAKEWORD(2,2);
	int wsOk = WSAStartup(version, &data);
	if (wsOk != 0) {
		printf("Cant't start Winsock: %d!" , wsOk);
		return;
	}

	// bind socket to IP address and port
	SOCKET in = socket(AF_INET, SOCK_DGRAM, 0);
	sockaddr_in serverHint;
	serverHint.sin_addr.S_un.S_addr = ADDR_ANY;
	serverHint.sin_family = AF_INET;
	serverHint.sin_port = htons(PORT_NUMBER);

	if (bind(in,(sockaddr*)&serverHint, sizeof(serverHint)) == SOCKET_ERROR) {
		printf("Cant't bind socket!: %d!", WSAGetLastError());
		return;
	}

	sockaddr_in client;
	int clientLength = sizeof(client);
	ZeroMemory(&client, clientLength);

	char buf[1024];

	printf("beginning server loop...");
	// enter a loop;
	while (true)
	{
		// zero buff b4 using again
		ZeroMemory(&buf, 1024);
		// wait for msg
		int bytesIn = recvfrom(in, buf, 1024, 0, (sockaddr*)&client, &clientLength);
		if (sizeof(bytesIn) > 0)
		{
			if (bytesIn == SOCKET_ERROR) {
				printf("error recieved from client!: %d!", WSAGetLastError());
				continue;
			}
			// display msg
			char clientIP[256];
			ZeroMemory(&clientIP, 256);
			// convert IP struct to string 
			inet_ntop(AF_INET, &client.sin_addr, clientIP, 256);
			printf("\n Message recv from %s : %s", clientIP, buf);
			//Deserialize(buf);
		}
	}

	//close socket
	closesocket(in);

	//shudoen winsock
	WSACleanup();




}

void Server::Serialize(eNetMessage)
{
	
}

void Server::Deserialize(char* data)
{
	// base message
	eNetMessageBase msg = (*(eNetMessageBase*)(data));
	switch (msg)
	{
	case eNetMessageBase::worldData:
		break;
	case eNetMessageBase::playerData:
		break;
	case eNetMessageBase::networkStatus: {

		eNetMessageStatus netMsg = (*(eNetMessageStatus*)(data + sizeof(eNetMessageStatus)));
		switch (netMsg)
		{
		case eNetMessageStatus::fullStack:
			break;
		case eNetMessageStatus::connectedDevices: {

			unsigned playerID = (*(unsigned*)(data + (sizeof(unsigned)*2)));
			printf("Player with ID#%d trying to join!", playerID);
		}
			break;
		case eNetMessageStatus::deviceDisconnect:
			break;
		case eNetMessageStatus::ping:
			break;
		case eNetMessageStatus::UNKNOWN:
			break;
		default:
			break;
		}
	}
		break;
	case eNetMessageBase::UNKNOWN:
		break;
	default:
		break;
	}
	



}
