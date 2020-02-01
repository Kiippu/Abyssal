#include "NetworkManager.h"
#include "Core/Framework/Networking/Server.h"
#include "Core/Framework/Networking/Client.h"

bool NetworkManager::Update()
{
	return false;
}

bool NetworkManager::isClient()
{
	return (dynamic_cast<Client*>(m_localInterface.get()));
}

bool NetworkManager::isHost()
{
	return (dynamic_cast<Server*>(m_localInterface.get()));
}

bool NetworkManager::isSolo()
{
	return (m_localInterface == nullptr);
}

void NetworkManager::setLocalInterface(std::unique_ptr<INet> netTypeObj)
{
	m_localInterface = std::move(netTypeObj);
}

void NetworkManager::Serialize(eNetMessage msg)
{
	if (isClient())
		m_localInterface->Serialize(msg);
}

 INet& NetworkManager::getlocalInterface() const
{
	return *m_localInterface;
}
