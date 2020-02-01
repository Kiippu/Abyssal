#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H
#pragma once

#include "Core/Framework/Networking/INet.h"
#include "Core/Framework/Networking/NetworkTypes.h"


class NetworkManager
{
public:
	static NetworkManager & getInstance() {
		static NetworkManager instance;
		return instance;
	}

private:
	// private constructor to impl singleton
	NetworkManager() {};

public:
	// Safety to delete any copies or new instances
	NetworkManager(const NetworkManager&)	= delete;
	void operator=(NetworkManager const&)		= delete;
	
	bool Update();

	bool isClient();

	bool isHost();

	bool isSolo();

	void setLocalInterface(std::unique_ptr<INet>);

	void Serialize(eNetMessage msg);

	INet& getlocalInterface() const;

	/// getNetworkInterface() - client or server class

private:

	/// abstrct class of network or client member
	std::unique_ptr<INet> m_localInterface = nullptr;

};

#endif // !NETWORK_MANAGER_H