#ifndef NETWORK_TYPES_H
#define NETWORK_TYPES_H
#pragma once

enum class eNetType : unsigned {
	server,
	client
};

enum class eNetMessage : unsigned {
	UNKNOWN,
	strafeLeft,
	strafeRight,
	strafeForward,
	strafeBackward,
	resetCamera
};

#endif // !NETWORK_TYPES_H