#ifndef _INCLUDE_TERRORBOTS_H_
#define _INCLUDE_TERRORBOTS_H_

#include "terror_player.h"

struct SurvivorBot
{
	SurvivorBot_vtable * vptr;
	SurvivorBot_data SurvivorBot;
};

struct SurvivorBot_vtable
{
	void * dtor1; // 0
	void * dtor0; // 4
	IHandleEntity_iface IHandleEntity; // 8
	IServerUnknown_iface IServerUnknown; // 16
	IServerEntity_iface IServerEntity; // 28
	CBaseEntity_iface CBaseEntity; // 40
	CBaseAnimating_iface CBaseAnimating; // 800
	CBaseFlex_iface CBaseFlex; // 924
	CBaseCombatCharacter_iface CBaseCombatCharacter; // 956
	CBasePlayer_iface CBasePlayer; // 1372
	CAI_ExpresserHost_CBasePlayer__iface CAI_ExpresserHost; // 1948
	CBaseMultiplayerPlayer_iface CBaseMultiplayerPlayer; // 1964
	CCSPlayer_iface CCSPlayer; // 2000
	CTerrorPlayer_iface CTerrorPlayer; // 2224
};

struct SurvivorBot_data
{
	CBaseEntity_data CBaseEntity; // 4
	CBaseAnimating_data CBaseAnimating; // 1072
	CBaseAnimatingOverlay_data CBaseAnimatingOverlay; // 5096
	CBaseFlex_data CBaseFlex; // 5116
	CBaseCombatCharacter_data CBaseCombatCharacter; // 6092
	CBasePlayer_data CBasePlayer; // 6736
	CAI_ExpresserHost_data CAI_ExpresserHost; // 9080
	CBaseMultiplayerPlayer_data CBaseMultiplayerPlayer; // 9084
	CCSPlayer_data CCSPlayer; // 9120
	CTerrorPlayer_data CTerrorPlayer; // 10844

	char unknown0[744];
	int m_humanSpectatorUserID;
	int m_humanSpectatorEntIndex;
};


#endif //_INCLUDE_TERRORBOTS_H_