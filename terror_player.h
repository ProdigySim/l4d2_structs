#ifndef _INCLUDE_TERROR_PLAYER_H_
#define _INCLUDE_TERROR_PLAYER_H_

#include "terror_player_vtables.h"
#include "timers.h"

struct CBaseEntity_data
{
	char unknown[1068];
};

struct CBaseAnimating_data
{
	char unknown[4024]; // 1072
};

struct CBaseFlex_data
{
	char unknown[996]; // 5096
};


struct CAI_MoveMonitor
{
	float m_vMark[3]; // Vector
	float m_flMarkTolerance;
};

// size 644, offset 6092 in CTerrorPlayer
struct CBaseCombatCharacter_data
{
	bool m_bForceServerRagdoll; // 0
	bool m_bPreventWeaponPickup; // 1
	float m_flNextAttack; // 4 CNetworkVar( float, m_flNextAttack );
	unsigned int m_eHull; // 8 Hull_t
	int m_bloodColor; // 12
	float m_flFieldOfView; // 16
	float m_HackedGunPos[3]; // 20 Vector
	char * m_RelationshipString; // 32 string_t
	float m_impactEnergyScale; // 36
	unsigned char m_weaponIDToIndex[38]; // 40
	
	char padding78[2]; // 78, padding will probably be automatic
	
	char unknown80[76]; // 80 I'll do these later
	
	// later
	/*
	int m_LastHitGroup;
	float m_flDamageAccumulator;
	int m_iDamageCount;
	unsigned int m_CurrentWeaponProficiency; // WeaponProficiency_t
	CUtlVector m_iRelationship;	// CUtlVector<Relationship_t> m_Relationship;
	int	m_nFaction;
	CUtlVector m_hTriggerFogList; // CUtlVector<EHANDLE>
	unsigned int m_hLastFogTrigger; // EHANDLE */
	
	int m_iAmmo[32]; // 156 CNetworkArrayForDerived( int, m_iAmmo, MAX_AMMO_SLOTS );
	unsigned int m_hMyWeapons[64]; // 284 CNetworkArray( CBaseCombatWeaponHandle, m_hMyWeapons, MAX_WEAPONS );
	int m_hActiveWeapon; // 540 CNetworkHandle( CBaseCombatWeapon, m_hActiveWeapon );
	
	IntervalTimer UnknownITimer1; // 544
	int m_iUnknown1; // 552
	int m_iUnknown2; // 556
	IntervalTimer UnknownITimer2; // 560
	int m_iUnknown3; // 568
	IntervalTimer UnknownITimer3; // 572
	int m_iUnknown4; // 580
	IntervalTimer UnknownITimer4; // 584
	int m_iUnknown5; // 592
	IntervalTimer UnknownITimer5; // 596
	
	void *m_lastNavArea; // 604 CNavArea *
	CAI_MoveMonitor m_NavAreaUpdateMonitor; // 608
	int m_registeredNavTeam; // 624
	CountdownTimer UnknownCTimer1; // 628
	int m_iLastUnknown; // 640 set to -1 in constructor
};

struct CBasePlayer_data
{
	char unknown[2344]; // 6736
};


struct CAI_ExpresserHost_data
{
	CAI_ExpresserSink_vtable * vptr; // 9080
};

// From game/server/basemultiplayerplayer.h
struct CBaseMultiplayerPlayer_data
{
	int m_iIgnoreGlobalChat; // 9084
	float m_flAreaCaptureScoreAccumulator; // 9088
	float m_flCapPointScoreRate; // 9092
	int	m_iCurrentConcept; // 9096
	void *m_pExpresser; // 9100 CMultiplayer_Expresser *
	float m_flConnectionTime; // 9104
	float m_flLastForcedChangeTeamTime; // 9108
	int m_iBalanceScore; // 9112
	void *m_pAchievementKV; // 9116 KeyValues *
};

struct CCSPlayer_data
{
	void * m_pHintMessageQueue; // 9120 CHintMessageQueue
	char unknown[1708]; // 9124
	CountdownTimer UnknownTimer; // 10832
};


struct CTerrorPlayer_data
{
	char unknown[5548]; // 10844
};

// size 16392
struct CTerrorPlayer
{
	CTerrorPlayer_vtable * vptr; // 0
	CBaseEntity_data CBaseEntity; // 4
	CBaseAnimating_data CBaseAnimating; // 1072
	CBaseFlex_data CBaseFlex; // 5096
	CBaseCombatCharacter_data CBaseCombatCharacter; // 6092
	CBasePlayer_data CBasePlayer; // 6736
	CAI_ExpresserHost_data CAI_ExpresserHost; // 9080
	CBaseMultiplayerPlayer_data CBaseMultiplayerPlayer; // 9084
	CCSPlayer_data CCSPlayer; // 9120
	CTerrorPlayer_data CTerrorPlayer; // 10844
};

#endif // _INCLUDE_TERROR_PLAYER_H_
