#pragma once
#ifndef PRIORITY_TYPE_H
#define PRIORITY_TYPE_H

typedef enum : unsigned int
{
	PRTY_LOWEST = 0,
	PRTY_LOW,
	PRTY_MID,
	PRTY_HIGH,
	PRTY_INPUT,
	PRTY_PHYSICS,
	PRTY_MAX = 100

} LABEL_PRIORITY_TYPE;



#endif // !PRIORITY_TYPE_H

