#ifndef INET
#define INET
#pragma once

#include <memory>
#include "Core/Framework/Networking/NetworkTypes.h"
#include "Core/Framework/Networking/NetworkTypes.h"

class INet
{
protected:
	explicit INet(eNetType type) : m_type(type) {};

public:

	/// build udp connection 
	virtual void InitUDP() = 0;
	/// build tcp connection 
	virtual void InitTCP() = 0;
	/// Update Interface
	virtual void Update() = 0;
	/// add user to interface
	virtual void AddUser() = 0;
	/// For thread - serialize incomming data
	virtual void Serialize(eNetMessage) = 0;
	/// For Thread - deserialize data to be sent off to users/server
	virtual void Deserialize(char*) = 0;
	/// get the Interface type
	virtual eNetType& getNetType() { return m_type; };

private:

	eNetType & m_type;
	
};

#endif // !INET