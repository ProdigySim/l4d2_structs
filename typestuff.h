#ifndef __TYPESTUFF_H__
#define __TYPESTUFF_H__

#define bool unsigned char

// Define these types for Ghidra so you don't have to add them as -D flags

#ifndef _DWORD
#define _DWORD unsigned int
#endif

#ifndef _BYTE
#define _BYTE unsigned char
#endif

enum ZombieClassType
{
	ZC_NONE,
	ZC_SMOKER,
	ZC_BOOMER,
	ZC_HUNTER,
	ZC_SPITTER,
	ZC_JOCKEY,
	ZC_CHARGER,
	ZC_WITCH,
	ZC_TANK
};

#endif
