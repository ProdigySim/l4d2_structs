#ifndef _INCLUDE_TERROR_PLAYER_H_
#define _INCLUDE_TERROR_PLAYER_H_

#include "terror_player_vtables.h"
#include "timers.h"
#include "steam_api.h"

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
	
	IntervalTimer UnknownITimer544; // 544
	int m_iUnknown552; // 552
	int m_iUnknown556; // 556
	IntervalTimer UnknownITimer560; // 560
	int m_iUnknown568; // 568
	IntervalTimer UnknownITimer572; // 572
	int m_iUnknown580; // 580
	IntervalTimer UnknownITimer584; // 584
	int m_iUnknown592; // 592
	IntervalTimer UnknownITimer596; // 596
	
	void *m_lastNavArea; // 604 CNavArea *
	CAI_MoveMonitor m_NavAreaUpdateMonitor; // 608
	int m_registeredNavTeam; // 624
	CountdownTimer UnknownCTimer628; // 628
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
// size 92
struct CTakeDamageInfo
{
	float m_vecDamageForce[3]; // 0 Vector
	float m_vecDamagePosition[3]; // 12 Vector
	float m_vecReportedPosition[3];	// 24 Vector
	float m_vecUnknown36[3]; // 36 someone thinks it's a vector I guess
	int m_hInflictor; // 48 EHANDLE
	int m_hAttacker; // 52 EHANDLE
	int m_hWeapon; // 56 EHANDLE
	float m_flDamage; // 60
	float m_flMaxDamage; // 64
	float m_flBaseDamage;	// 68
	int m_bitsDamageType; // 72
	int m_iDamageCustom; // 76
	int m_iDamageStats;// 80
	int m_iAmmoType; // 84
	float m_flRadius; // 88
};

// offset 10844 in CTerrorPlayer
// size 5548
struct CTerrorPlayer_data
{
	int m_iUnknown0; // 0
	int m_iUnknown4; // 4
	char unknown8[180]; // 8
	CCallback m_AchievementStatus; // 188
	_DWORD m_Unknown208; // 208 
	int m_iUnknown212; // 212 set to -1 in ctor
	int m_iUnknown216; // 216 set to -1 in ctor
	char unknown220[4]; // 220 
	_DWORD m_Unknown224; // 224
	_DWORD m_Unknown228; // 228
	_DWORD m_Unknown232;
	_DWORD m_Unknown236;
	_DWORD m_Unknown240;
	char unknown244[8]; // 244
	int m_iUnknown252; // 252 set to -1 in ctor
	CountdownTimer m_vocalizationSubjectTimer; // 256 doubly network'd? vtable overwritten twice in ctor
	CountdownTimer m_unknownCTimer268; // 268
	CountdownTimer m_unknownCTimer280; // 280
	char unknown292[36]; // 292
	int m_iUnknown328; // 328 set to -1 in ctor
	CountdownTimer m_unknownCTimer332; // 332
	char unknown344[96]; // 344
	CountdownTimer m_unknownCTimer440; // 440
	char unknown452[136]; // 452
	CountdownTimer m_unknownCTimer588; // 588
	CountdownTimer m_unknownCTimer600; // 600
	char unknown612[24]; // 612
	CountdownTimer m_unknownCTimer636; // 636
	char unknown648[112]; // 648
	int m_iUnknownArray760[6]; // 760 set to -1s/0s in ctor
	short m_siUnknownArray[6]; // 784 set to -1s/0s in ctor
	_DWORD m_Unknown796; // 796
	char unknown800[20]; // 800
	CountdownTimer m_unknownCTimer820; // 820
	int m_iUnknown832; // 832 set to -1 in ctor
	IntervalTimer m_unknownITimer836;
	CountdownTimer m_unknownCTimer844;
	CTakeDamageInfo m_takedamageinfo; // 856
	char unknown948[8]; // 948
	int m_iUnknown956; // set to -1 in ctor
	int m_iUnknown960; // set to -1 in ctor
	CountdownTimer m_unknownCTimer964; // 964
	char unknown976[40]; // 976
	CountdownTimer m_unknownCTimer1016; // 1016
	CountdownTimer m_noAvoidanceTimer; // 1028
	char unknown1040[4]; // 1040
	CountdownTimer m_unknownCTimer1044; // 1044
	char unknown1056[4492]; // 1056
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
