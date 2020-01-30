#include "NetworkManager.h"

bool NetworkManager::Update()
{
	return false;
}

bool NetworkManager::isClient()
{
	return false;
}

bool NetworkManager::isHost()
{
	return false;
}

bool NetworkManager::isSolo()
{
	return false;
}

void NetworkManager::setLocalInterface()
{
}

void NetworkManager::Serialize(eNetMessage msg)
{
	if (isClient())
		m_localInterface->Serialize(msg);
}

const INet & NetworkManager::getlocalInterface() const
{
	return *m_localInterface.get();
}
