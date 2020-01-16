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

void Server::Init()
{
	printf("\nInit Server begin\n");
	// Port number
	const unsigned short PORT_NUMBER = 54000;

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
		if (bytesIn == SOCKET_ERROR) {
			printf("error recieved from client!: %d!", WSAGetLastError());
			continue;
		}
		// display msg
		char clientIP[256];
		ZeroMemory(&clientIP, 256);
		// convert IP struct to string 
		inet_ntop(AF_INET, &client.sin_addr, clientIP, 256);
		printf("Message recv from %s : %s", clientIP, buf);

	}

	//close socket
	closesocket(in);

	//shudoen winsock
	WSACleanup();




}

void Server::Serialize()
{
}

void Server::Deserialize()
{
}
