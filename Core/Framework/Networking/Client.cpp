#include "Client.h"


struct Client::PImpl
{
	PImpl()
	{}


};

Client::Client()
	: INet(eNetType::client), m_impl(new PImpl) {};

void Client::Update()
{
}

void Client::AddUser()
{
}

void Client::Init()
{
}

void Client::Serialize()
{
}

void Client::Deserialize()
{
}