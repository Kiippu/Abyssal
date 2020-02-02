#ifndef NETWORK_TYPES_H
#define NETWORK_TYPES_H
#pragma once

enum class eNetType : unsigned {
	server,
	client
};

enum class eNetMessage : unsigned {
	strafeLeft,
	strafeRight,
	strafeForward,
	strafeBackward,
	resetCamera,

	UNKNOWN = UINT_MAX
};

/// first Message caught by network Managed deserializer
enum class eNetMessageBase : unsigned {
	worldData,
	playerData,
	networkStatus,

	UNKNOWN = UINT_MAX
};

/// player specific messages
enum class eNetMessagePlayer : unsigned {
	fullReset,
	input,
	worldPosiiton,

	UNKNOWN = UINT_MAX
};

/// world/game level specific messages
enum class eNetMessageWorld : unsigned {
	fullReset,

	UNKNOWN = UINT_MAX
};

enum class eNetMessageStatus : unsigned {
	fullStack,
	connectedDevices,
	deviceDisconnect,
	ping,

	UNKNOWN = UINT_MAX
};

#endif // !NETWORK_TYPES_H