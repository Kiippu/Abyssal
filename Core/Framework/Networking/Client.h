#ifndef CLIENT_H
#define CLIENT_H
#pragma once

#include "Core/Framework/Networking/INet.h"

class Client : public INet
{
public:

	Client();
	~Client() {};
	
	virtual void Update();

	virtual void AddUser();

	virtual void InitUDP();

	virtual void InitTCP();

	virtual void Serialize(eNetMessage);

	virtual void Deserialize(char*data);

private:
	/// private implementation for members
	//struct PImpl;
	//std::unique_ptr<PImpl> m_impl;
};

#endif // !CLIENT_H