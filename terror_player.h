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
	// 1160 m_nSequence
};

// 5096 in CTerrorPlayer
// size 996
struct CBaseFlex_data
{
	char unknown0[516]; // 0
	float m_flexWeight[96]; // 516
	float m_viewtarget[3]; // 900
	int m_blinktoggle; // 912
	char unknown916[80]; // 916
}; // 996


struct CAI_MoveMonitor
{
	float m_vMark[3]; // Vector
	float m_flMarkTolerance;
};

struct Relationship_t
{
	int entity; // 0 EHANDLE
	int classType; // 4 Class_T (shareddefs.h)
	int disposition; // 8 Disposition_t (basecombatcharacter.h)
	int priority; // 12
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
	
	char unknown80[32]; // 80 I'll do these later
	
	CUTLVECTOR(Relationship_t) m_Relationship; // 112
	char unknown132[24]; // 132
	
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
	int mm_carryVictim; // 0
	int m_carryAttacker; // 4
	char unknown8[8]; // 8
	float m_mainSequenceStarttime; // 16
	int m_grenadeLayerSequence; // 20
	int m_fireLayerSequence; // 24
	int m_flinchLayerSequence;
	int m_fidgetLayerSequence;
	int m_reloadLayerSequence;
	int m_reloadAltLayerSequence;
	int m_reloadLayerNumShells;
	float m_grenadeLayerStartTime;
	float m_fireLayerStartTime;
	float m_flinchLayerStartTime;
	float m_fidgetLayerStartTime;
	float m_reloadLayerStartTime;
	float m_reloadAltLayerStartTime; // 68
	char unknown72[56]; // 72
	int m_NetGestureActivity[7]; // 128
	float m_NetGestureStartTime[7]; // 156
	float m_fServerAnimStartTime; // 184
	CCallback m_AchievementStatus; // 188
	_DWORD m_Unknown208; // 208 
	int m_useActionTarget; // 212
	int m_useActionOwner; // 216
	int m_iCurrentUseAction; // 220 
	_DWORD m_Unknown224; // 224
	_DWORD m_Unknown228; // 228
	_DWORD m_Unknown232;
	_DWORD m_Unknown236;
	_DWORD m_Unknown240;
	float m_burnPercent; // 244
	float m_bbqPercent; // 248
	int m_vocalizationSubject; // 252 set to -1 in ctor
	CountdownTimer m_vocalizationSubjectTimer; // 256 doubly network'd? vtable overwritten twice in ctor
	CountdownTimer m_unknownCTimer268; // 268
	CountdownTimer m_unknownCTimer280; // 280
	char unknown292[20]; // 292
	int m_survivorCharacter; // 312
	int m_zombieClass; // 316
	char unknown320[8]; // 320
	int m_iUnknown328; // 328 set to -1 in ctor
	CountdownTimer m_unknownCTimer332; // 332
	char unknown344[8]; // 344
	float m_lineOfScrimmagePos[3]; // 352 Vector
	float m_lineOfScrimmageAngle[3]; // 364 Vector
	char unknown376[8]; // 376
	float m_rearLineOfScrimmagePos[3]; // 384
	float m_rearLineOfScrimmageAngle[3]; // 396
	char unknown408[4]; // 408
	float m_scrimmageSphereCenter[3]; // 412
	float m_scrimmageSphereInitialRadius; // 424
	int m_scrimmageType; // 428
	float m_scrimmageStartTime; // 432
	float m_survivorsLineOfScrimmageDistance; // 436
	CountdownTimer m_unknownCTimer440; // 440
	float m_yardLinePos[3]; // 452
	char unknown464[48]; // 464
	float m_yardLineAngles[3]; // 512
	char unknown524[48]; // 524
	bool m_bUnknown572; // 572 could be any other byte struct
	bool m_bIsGhost; // 573
	char padding[2]; // 574
	int m_ghostSpawnState; // 576
	int m_ghostSpawnClockMaxDelay; // 580
	int m_ghostSpawnClockCurrentDelay; // 584
	CountdownTimer m_unknownCTimer588; // 588
	CountdownTimer m_unknownCTimer600; // 600
	char unknown612[12]; // 612
	float m_flNextShoveTime; // 624
	int m_iShovePenalty; // 628
	bool m_isInMissionStartArea; // 632
	CountdownTimer m_unknownCTimer636; // 636
	char unknown648[36]; // 648
	int m_classSpawnCount[9]; // 684
	char unknown720[24]; // 720
	float m_maxDeadDuration; // 744
	float m_totalDeadDuration; // 748
	char unknown752[12]; // 752
	int m_dragTarget; // 764
	char unknown768[16]; // 768
	short m_siUnknownArray[6]; // 784 set to -1s/0s in ctor
	_DWORD m_Unknown796; // 796
	char unknown800[12]; // 800
	bool m_isIncapacitated; // 812
	char padding813[3]; // 813
	char unknown816[4]; // 816
	CountdownTimer m_unknownCTimer820; // 820
	int m_iUnknown832; // 832 set to -1 in ctor
	IntervalTimer m_unknownITimer836;
	CountdownTimer m_unknownCTimer844;
	CTakeDamageInfo m_takedamageinfo; // 856
	char unknown948[8]; // 948
	int m_reviveOwner; // 956
	int m_reviveTarget; // 960
	CountdownTimer m_unknownCTimer964; // 964
	char unknown976[28]; // 976
	int m_currentReviveCount; // 1004
	bool m_bIsOnThirdStrike; // 1008
	bool m_bIsFirstManOut; // 1009
	char padding1010[2]; // 1010
	char unknown1012[4]; // 1012
	CountdownTimer m_unknownCTimer1016; // 1016
	CountdownTimer m_noAvoidanceTimer; // 1028
	bool m_isCalm; // 1040
	CountdownTimer m_unknownCTimer1044; // 1044
	int m_zombieState; // 1056
	char unknown1060[112]; // 1060
	int m_clientIntensity; // 1172
	bool m_isAutoCrouchEnabled; // 1176
	IntervalTimer m_autoCrouchTimer; // 1180
	char unknown1188[368]; // 1188
	int m_checkpointSurvivorDamage; // 1556
	int m_missionSurvivorDamage; // 1560
	char unknown1564[52]; // 1564
	int m_customAbility; // 1616
	char unknown1620[136]; // 1620
	bool m_hasVisisbleThreats; // 1756
	char padding1757[3]; // 1757
	char unknown1760[164]; // 1760
	CountdownTimer m_staggerTimer; // 1924
	float m_staggerStart[3]; // 1936
	float m_staggerDir[3]; // 1948
	float m_staggerDist; // 1960
	char unknown1964[4]; // 1964
	CountdownTimer m_tugTimer; // 1968
	float m_tugStart[3]; // 1980
	float m_tugDir[3]; // 1992
	float m_tugDist; // 2004
	char unknown2008[20]; // 2008
	CountdownTimer m_itTimer; // 2028
	char unknown2040[20]; // 2040
	bool m_bAdrenalineActive; // 2060
	char padding2061[3]; // 2061
	char unknown2064[72]; // 2064
	bool m_isCulling; // 2136
	bool m_isRelocating; // 2137
	char padding2138[2];
	char unknown2140[12]; // 2140
	CountdownTimer m_stunTimer; // 2152
	char unknown2164[12]; // 2164
	bool m_holdingObject; // 2176
	float m_healthBuffer; // 2180
	float m_healthBufferTime; // 2184
	char unknown2188[4]; // 2188
	bool m_isGoingToDie; // 2192
	float m_noiseLevel; // 2196
	float m_noiseLevelLatch; // 2200
	int m_iBloodyHandsLevel; // 2204
	char unknown2208[132]; // 2208
	float m_shoveForce[3]; // 2340
	bool m_airMovementRestricted; // 2352
	int m_positionEntity; // 2356
	bool m_bSurvivorPositionHidingWeapons; // 2360
	int m_pushEntity; // 2364
	float m_pushDistance; // 2368
	char unknown2372[8]; // 2372
	bool m_usingMountedGun; // 2380
	bool m_usingMountedWeapon; // 2381
	int m_tongueVictim; // 2384
	int m_tongueOwner; // 2388
	IntervalTimer m_tongueVictimTimer; // 2392
	float m_initialTonguePullDir[3]; // 2400
	bool m_isHangingFromTongue; // 2412
	bool m_reachedTongueOwner; // 2413
	char padding2414[2]; // 2414
	char unknown[4]; // 2416
	bool m_isProneTongueDrag; // 2420
	char padding2421[3]; // 2421
	char unknown2424[40]; // 2424
	int m_checkpointAwardCounts[149]; // 2464 lots of awards
	int m_missionAwardCounts[149]; // 3060
	int m_checkpointZombieKills[9]; // 3656
	int m_missionZombieKills[9]; // 3692
	int m_checkpointMedkitsUsed; // 3728
	int m_checkpointPillsUsed; // 3732
	int m_missionMedkitsUsed; // 3736
	int m_missionPillsUsed; // 3740
	int m_checkpointMolotovsUsed; // 3744
	int m_missionMolotovsUsed; // 3748
	int m_checkpointPipebombsUsed; // 3752
	int m_missionPipebombsUsed; // 3756
	int m_checkpointBoomerBilesUsed; // 3760
	int m_missionBoomerBilesUsed; // 3764
	int m_checkpointAdrenalinesUsed; // 3768
	int m_missionAdrenalinesUsed; // 3772
	int m_checkpointDefibrillatorsUsed; // 3776
	int m_missionDefibrillatorsUsed; // 3780
	int m_checkpointDamageTaken; // 3784
	int m_missionDamageTaken; // 3788
	int m_checkpointReviveOtherCount; // 3792
	int m_missionReviveOtherCount; // 3796
	int m_checkpointFirstAidShared; // 3800
	int m_missionFirstAidShared; // 3804
	int m_checkpointIncaps; // 3808
	int m_missionIncaps; // 3812
	int m_checkpointDamageToTank; // 3816
	int m_checkpointDamageToWitch; // 3820
	char unknown3824[4]; // 3824
	int m_checkpointHeadshots; // 3828
	int m_checkpointHeadshotAccuracy; // 3832
	int m_missionHeadshotAccuracy; // 3836
	int m_missionAccuracy; // 3840
	int m_checkpointDeaths; // 3844
	int m_missionDeaths; // 3848
	int m_checkpointMeleeKills; // 3852
	int m_missionMeleeKills; // 3856
	char unknown3860[8]; // 3860
	int m_checkpointPZIncaps; // 3868
	int m_checkpointPZTankDamage; // 3872
	int m_checkpointPZHunterDamage; // 3876
	int m_checkpointPZSmokerDamage; // 3880
	int m_checkpointPZBoomerDamage; // 3884
	int m_checkpointPZJockeyDamage; // 3888
	int m_checkpointPZSpitterDamage; // 3892
	int m_checkpointPZChargerDamage; // 3896
	int m_checkpointPZKills; // 3900
	int m_checkpointPZPounces; // 3904
	int m_checkpointPZPushes; // 3908
	int m_checkpointPZTankPunches; // 3912
	int m_checkpointPZTankThrows; // 3916
	int m_checkpointPZHung; // 3920
	int m_checkpointPZPulled; // 3924
	int m_checkpointPZBombed; // 3928
	int m_checkpointPZVomited; // 3932
	int m_checkpointPZHighestDmgPounce; // 3936
	int m_checkpointPZLongestSmokerGrab; // 3940
	int m_checkpointPZLongestJockeyRide; // 3944
	int m_checkpointPZNumChargeVictims; // 3948
	float m_jumpSupressedUntil; // 3952
	char unknown3956[12]; // 3956
	bool m_bUnknown3968; // 3968
	bool m_isHangingFromLedge; // 3969
	bool m_isFallingFromLedge; // 3970
	IntervalTimer m_hangTimer; // 3972
	float m_hangAirPos[3]; // 3980
	float m_hangPos[3]; // 3992
	float m_hangStandPos[3]; // 4004
	float m_hangNormal[3]; // 4016
	char unknown4028[76]; // 4028
	int m_frustration; // 4104
	char unknown4108[968]; // 4108
	int m_pummelVictim; // 5076
	int m_pummelAttacker; // 5080
	char unknown5084[24]; // 5084
	int m_pounceVictim; // 5108
	int m_pounceAttacker; // 5112
	char unknown5116[12]; // 5116
	bool m_isAttemptingToPounce; // 5128
	char padding5129[3]; // 5129
	char unknown5132[4]; // 5132
	float m_pounceStartPosition[3]; // 5136
	char unknown5148[80]; // 5148
	int m_jockeyVictim; // 5228
	int m_jockeyAttacker; // 5232
	char unknown5236[36]; //5236
	float m_jockeyDesiredMove[3]; // 5272
	bool m_jockeyRotatedDesire; // 5284
	float m_vomitStart; // 5288
	float m_vomitFadeStart; // 5292
	float m_bashedStart; // 5296
	float m_salivaStart; // 5300
	int m_knockdownReason; // 5304
	IntervalTimer m_knockdownTimer; // 5308
	char unknown5316[128]; // 5316
	int m_iVersusTeam; // 5444
	char unknown5448[36]; // 5448
	int m_lookatPlayer; // 5484
	bool m_bSurvivorGlowEnabled; //5488
	char padding5489[3]; // 5489
	char unknown5492[12]; // 5492
	bool m_bWasPresentAtSurvivalStart; // 5504
	char padding5505[3]; // 5505
	char unknown5508[24]; // 5508
	int m_nVariantType; //5532
	float m_TimeForceExternalView; // 5536
	char unknown5540[8]; // 5540
}; // 5548

struct CBaseEntity
{
	CBaseEntity_vtable * vptr; // 0
	CBaseEntity_data CBaseEntity; // 4
};

// size 16392
struct CBaseCombatCharacter
{
	CBaseCombatCharacter_vtable * vptr; // 0
	CBaseEntity_data CBaseEntity; // 4
	CBaseAnimating_data CBaseAnimating; // 1072
	CBaseFlex_data CBaseFlex; // 5096
	CBaseCombatCharacter_data CBaseCombatCharacter; // 6092
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
