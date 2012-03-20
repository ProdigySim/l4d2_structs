#ifndef _INCLUDE_TERROR_PLAYER_H_
#define _INCLUDE_TERROR_PLAYER_H_

#include "terror_player_vtables.h"

// size 16392
struct CTerrorPlayer
{
	CTerrorPlayer_vtable * vptr;
	char unknown[16388]; // 0x04 TODO: other classes :P
};

#endif // _INCLUDE_TERROR_PLAYER_H_