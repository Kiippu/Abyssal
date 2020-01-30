#ifndef CLIENT_H
#define CLIENT_H
#pragma once

#include "Core/Framework/Networking/INet.h"

class Client : public INet
{
public:

	Client();
	~Client() {};

	// Safety to delete any copies or new instances
	Client(const Client&)	= delete;
	void operator=(Client const&)		= delete;
	
	virtual void Update();

	virtual void AddUser();

	virtual void Init();

	virtual void Serialize(eNetMessage);

	virtual void Deserialize(eNetMessage);

private:
	/// private implementation for members
	//struct PImpl;
	//std::unique_ptr<PImpl> m_impl;
};

#endif // !CLIENT_H