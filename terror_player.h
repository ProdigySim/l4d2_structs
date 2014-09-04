#ifndef _INCLUDE_TERROR_PLAYER_H_
#define _INCLUDE_TERROR_PLAYER_H_

struct CBaseEntity;

#include "terror_player_vtables.h"
#include "handle.h"
#include "timers.h"
#include "steam_api.h"
#include "network_var.h"
#include "util.h"


struct thinkfunc_t
{
	void * m_pfnThink;
	char * m_iszContext;
	int m_nNextThinkTick;
	int m_nLastThinkTick;
};

struct ResponseContext_t
{
	char * m_iszName;
	char * m_iszValue;
	float m_fExpirationTime;
};

struct color32
{
	unsigned char r, g, b, a;
};

// base offset 4
// size 1068
struct CBaseEntity_data
{
	char unknown0[24]; // 0
	CServerNetworkProperty m_Network; // 24
	char unknown104[8]; // 104
	char * m_iClassname; // 112
	char * m_iGlobalname; // 116
	char * m_iParent; // 120
	int m_iHammerID; // 124
	float m_flPrevAnimTime; // 128
	float m_flAnimTime; // 132
	float m_flSimulationTime; // 136
	float m_flCreateTime; // 140
	int m_nLastThinkTick; // 144
	int m_touchStamp; // 148
	CUTLVECTOR(thinkfunc_t) m_aThinkFunctions; // 152
	CUTLVECTOR(ResponseContext_t) m_ResponseContexts; // 172
	char *m_iszResponseContext; // 192
	int m_nNextThinkTick; // 196
	int m_fEffects; // 200
	
	void * m_pfnTouch; // 204 
	void * m_pfnUse; // 208
	void * m_pfnBlocked; // 212
	char unknown216[16]; // 216
	CBaseEntity * m_pLink; // 232
	char *m_target; // 236
	int m_iMaxHealth; // 240
	int m_iHealth; // 244
	char m_lifeState; // 248
	char m_takedamage; // 249
	char *m_iszDamageFilterName; // 252
	int m_hDamageFilter; // 256 EHANDLE
	int m_debugOverlays; // 260
	void * m_pTimedOverlay; // 264 TimedOverlay_t *
	float m_flSpeed; // 268
	unsigned char m_nRenderFX; // 272
	unsigned char m_nRenderMode; // 273
	short m_nModelIndex; // 274
	color32 m_clrRender; // 276
	char unknown280[4]; // 280
	int m_nSimulationTick; // 284
	float m_vecEyeOffset[3]; // 288
	float m_EyeAngleOffset[3]; // 300
	int m_spawnFlags; // 312
	int m_iEFlags; // 316
	int m_fFlags; // 320
	char *m_iName; // 324
	char unknown328[260]; // 328
	float m_flGroundChangeTime; // 588
	char * m_ModelName; // 592
	char * m_AIAddOn; // 596
	float m_vecBaseVelocity[3]; // 600
	float m_vecAbsVelocity[3]; // 612
	float m_vecAngVelocity[3]; // 624
	float m_rgflCoordinateFrame[3][4]; // 636 matrix3x4_t
	int m_pBlocker; // 684 EHANDLE
	float m_flGravity; // 688
	float m_flFriction; // 692
	float m_flElasticity; // 696
	float m_flOverriddenFriction; // 700
	float m_flLocalTime; // 704
	float m_flVPhysicsUpdateLocalTime; // 708
	float m_flMoveDoneTime; // 712
	int m_nPushEnumCount; // 716
	float m_vecAbsOrigin[3]; // 720
	//char unknown732[144]; // 732
	float m_vecVelocity[3]; // 732
	unsigned char m_iTextureFrameIndex; // 744
	bool m_bSimulatedEveryTick; // 745
	bool m_bAnimatedEveryTick; // 746
	bool m_bAlternateSorting; // 747
	unsigned char m_nMinCPULevel; // 748
	unsigned char m_nMaxCPULevel; // 749
	unsigned char m_nMinGPULevel; // 750
	unsigned char m_nMaxGPULevel; // 751
	bool m_bClientSideRagdoll; // 752
	int m_OnUser1[6]; // 756 COutputEvent (needs writing)
	int m_OnUser2[6]; // 780
	int m_OnUser3[6]; // 804
	int m_OnUser4[6]; // 828
	int m_OnKilled[6]; // 852
	float m_angAbsRotation[3]; // 876
	int m_cellwidth; // 888
	int m_cellbits; // 892
	int m_cellX; // 896
	int m_cellY; // 900
	int m_cellZ; // 904
	float m_vecOrigin[3]; // 908
	float m_angRotation[3]; // 920
	char unknown932[136]; // 932
}; // 1068

struct CBaseAnimatingOverlay;
// 76
struct CAnimationLayer
{
	int m_fFlags; // 0
	bool m_bSequenceFinished; // 4
	bool m_bLooping; // 5
	int m_nSequence; // 8 NetworkVar
	float m_flCycle; // 12 NetworkVar
	float m_flPrevCycle; // 16 NetworkVar
	float m_flWeight; // 20 NetworkVar
	float m_flPlaybackRate; // 24
	float m_flBlendIn; // 28
	float m_flBlendOut; // 32
	float m_flKillRate; // 36
	float m_flKillDelay; // 40
	float m_flLayerAnimtime; // 44
	float m_flLayerFadeOuttime; // 48
	int m_nActivity; // 52 Activity (ai_activity.h)
	int m_nPriority; // 56
	int m_nOrder; // 60 NetworkVar
	float m_flLastEventCheck; // 64
	float m_flLastAccess; // 68
	CBaseAnimatingOverlay *m_pOwnerEntity; // 72
};

// 20
struct CBaseAnimatingOverlay_data
{
	CUTLVECTOR(CAnimationLayer) m_AnimOverlay; // 0
};

struct CBaseAnimating_data
{
	char unknown[4024]; // 1072
	// 1160 m_nSequence
};

struct CSceneEventInfo 
{
	void *m_pEvent; // 0 CChoreoEvent
	void *m_pScene;
	void * m_pActor;
	CHandle m_hSceneEntity; // CHandle<CSceneEntity>
	bool m_bStarted;
	int m_iLayer;
	int m_iPriority;
	int m_nSequence;
	bool m_bIsGesture;
	float m_flWeight;
	int m_hTarget; // EHANDLE
	bool m_bIsMoving;
	bool m_bHasArrived;
	float m_flInitialYaw;
	float m_flTargetYaw;
	float m_flFacingYaw;
	int m_nType;
	float m_flNext;
	bool m_bClientSide; 
	void *m_pExpHdr; // const flexsettinghdr_t * public/studio.h
};

// 5116 in CTerrorPlayer
// size 976
struct CBaseFlex_data
{
	char unknown0[496]; // 0
	float m_flexWeight[96]; // 496
	float m_viewtarget[3]; // 880
	int m_blinktoggle; // 892
	CUTLVECTOR( CSceneEventInfo ) m_SceneEvents; // 896
	
	CUTLRBTREE(void *, unsigned short) m_LocalToGlobal; // 916 CUtlRBTree< FS_LocalToGlobal_t, ushort >
	float m_flAllowResponsesEndTime; // 944
	CUTLVECTOR(void*) m_ActiveChoreoScenes; // 948 CChoreoScene*
	bool m_bUpdateLayerPriorities; // 968
	float m_flLastFlexAnimationTime; // 972
}; // 976


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
	
	char unknown80[16]; // 80 I'll do these later
	int m_LastHitGroup; // 96
	float m_flDamageAccumulator; // 100
	int m_iDamageCount; // 104
	int m_CurrentWeaponProficiency; // 108 WeaponProficiency_t
	CUTLVECTOR(Relationship_t) m_Relationship; // 112
	CUTLVECTOR(int) m_hTriggerFogList; // 132 CUtlVector<EHANDLE>
	int m_hLastFogTrigger; // 152 EHANDLE
		
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
	
	// TODO: MOVE ME TO WHERE I BELONG
	// Anything in base classes could be wrong as well!
	char unknownNEWBYTES[12];
	#ifdef PLATFORM_WINDOWS
	char unknownWINBYTES[16];
	#endif
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

// offset 10856 in CTerrorPlayer
// 10872 windows (+16)
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
	int m_reloadAltLayerSequence; // 40
	int m_reloadLayerNumShells;
	float m_grenadeLayerStartTime;
	float m_fireLayerStartTime;
	float m_flinchLayerStartTime;
	float m_fidgetLayerStartTime;
	float m_reloadLayerStartTime;
	float m_reloadAltLayerStartTime; // 68
	int m_hBuildableButtonUseEnt; // 72
	int m_prevNetGestureActivity[7]; // 76
	int m_prevNetGestureStartTime[7]; // 104
	int m_NetGestureSequence[7]; // 132
	int m_NetGestureActivity[7]; // 160
	float m_NetGestureStartTime[7]; // 188
	float m_fServerAnimStartTime; // 216
	#ifdef PLATFORM_WINDOWS
	void * m_UnknownWin220;
	// Add 4 to all offsets after here on windows
	#endif
	CCallback m_AchievementStatus; // 220
	int m_useActionTarget; // 244
	int m_useActionOwner; // 248
	int m_iCurrentUseAction; // 252 
	CUTLVECTOR(int) m_trackedSounds; // 256 CTerrorPlayer::TrackedSoundType
	float m_burnPercent; // 276
	float m_bbqPercent; // 280
	int m_vocalizationSubject; // 284 set to -1 in ctor
	CountdownTimer m_vocalizationSubjectTimer; // 288 doubly network'd? vtable overwritten twice in ctor
	CountdownTimer m_nameChangeTimer; // 300
	CountdownTimer m_emotionTimer; // 312
	bool m_isMainActivityLooping; // 324
	int m_queuedBloodSplatters; // 328
	int m_queuedMeleeSlashBloodSplatters;
	int m_queuedMeleeClubBloodSplatters;
	int m_queuedMudSplatters;
	int m_survivorCharacter; // 344
	ZombieClassType m_zombieClass; // 348
	int m_spawnID;
	ZombieClassType m_randomizedClass;
	int m_hLastUsedEntity; // EHANDLE
	CountdownTimer m_tankEffectTimer;
	float m_lineOfScrimmageFlow;
	float m_initialLineOfScrimmageFlow;
	float m_lineOfScrimmagePos[3];
	float m_lineOfScrimmageAngle[3];
	float m_rearLineOfScrimmageFlow;
	float m_initialRearLineOfScrimmageFlow;
	float m_rearLineOfScrimmagePos[3];
	float m_rearLineOfScrimmageAngle[3];
	float m_flBecomeGhostAt;
	float m_scrimmageSphereCenter[3];
	float m_scrimmageSphereInitialRadius;
	int m_scrimmageType;
	float m_scrimmageStartTime;
	float m_survivorsLineOfScrimmageDistance;
	CountdownTimer m_lineOfScrimmageTimer;
	float m_yardLinePos[3]; // 484
	char unknown496[48]; // 496
	float m_yardLineAngles[3]; // 544
	char unknown556[48];
	bool m_survivorsCrossedLineOfScrimmage;
	bool m_bIsGhost;
	char padding[2];
	
	// Spawn State - These look like flags, but get used like static values quite often.
	// These names were pulled from reversing client.dll--specifically CHudGhostPanel::OnTick()'s uses of the "#L4D_Zombie_UI_*" strings
	//
	// SPAWN_OK             0
	// SPAWN_DISABLED       1  "Spawning has been disabled..." (e.g. director_no_specials 1)
	// WAIT_FOR_SAFE_AREA   2  "Waiting for the Survivors to leave the safe area..."
	// WAIT_FOR_FINALE      4  "Waiting for the finale to begin..."
	// WAIT_FOR_TANK        8  "Waiting for Tank battle conclusion..."
	// SURVIVOR_ESCAPED    16  "The Survivors have escaped..."
	// DIRECTOR_TIMEOUT    32  "The Director has called a time-out..." (lol wat)
	// WAIT_FOR_STAMPEDE   64  "Waiting for the next stampede of Infected..."
	// CAN_BE_SEEN        128  "Can't spawn here" "You can be seen by the Survivors"
	// TOO_CLOSE          256  "Can't spawn here" "You are too close to the Survivors"
	// RESTRICTED_AREA    512  "Can't spawn here" "This is a restricted area"
	// INSIDE_ENTITY     1024  "Can't spawn here" "Something is blocking this spot"
	int m_ghostSpawnState;
	
	int m_ghostSpawnClockMaxDelay;
	int m_ghostSpawnClockCurrentDelay;
	CountdownTimer m_ghostStateThrottleTimer;
	CountdownTimer m_ghostAISpawnDelayTimer;
	bool m_ghostOkForFinaleWave;
	bool m_ghostCanSpawnBeforeSurvivorsLeaveSafety;
	bool m_ghostSawSurvivorsOutsideFinaleArea;
	float m_currentGhostMaterializationTime;
	float m_nextGhostMaterializationTime;
	float m_flNextShoveTime;
	int m_iShovePenalty;
	bool m_isInMissionStartArea;
	CountdownTimer m_pzRespawnTimer; // 668
	float m_classTimestamp[9]; // 680
	int m_classSpawnCount[9]; 
	void *m_clientSettings; // 752 KeyValues *
	float m_deathPos[3]; // 756
	float m_timeOfDeath;
	float m_minDeadDuration;
	float m_maxDeadDuration;
	float m_totalDeadDuration;
	int m_deadCount;
	float m_farthestSurvivorFlowAtDeath;
	int m_tugTarget; // CHandle<CTerrorPlayer>
	int m_dragTarget;
	char unknown800[16];
	short m_siUnknownArray[6]; // set to -1s/0s in ctor
	_DWORD m_Unknown828;
	char unknown832[12];
	bool m_isIncapacitated; // 844
	char padding845[3]; // 845
	char unknown848[4]; // 848
	CountdownTimer m_incapacitatedDecayTimer; // 852
	int m_incapacitatedCause; // CHandle<CBaseEntity>
	IntervalTimer m_incapacitatedTimer;
	CountdownTimer m_selfReviveTimer;
	CTakeDamageInfo m_deathDamageInfo; 
	char unknown948[8]; 
	int m_reviveOwner;
	int m_reviveTarget;
	CountdownTimer m_reviveTimer;
	float m_reviveInitialForward[3];
	float m_reviveOrigin[3];
	int m_reviveKey;
	int m_currentReviveCount; // 1036
	bool m_bIsOnThirdStrike; 
	bool m_bIsFirstManOut; 
	int m_missionReviveCount;
	CountdownTimer m_invulnerabilityTimer; // 1048
	CountdownTimer m_noAvoidanceTimer; // 1060
	bool m_isCalm; // 1072
	CountdownTimer m_calmInhibit; // 1076
	int m_zombieState; // 1088 ZombieClassStateType
	char unknown1092[116]; // 1092
	int m_clientIntensity; // 1208
	bool m_isAutoCrouchEnabled; // 1212
	IntervalTimer m_autoCrouchTimer; 
	char unknown1220[368];
	int m_checkpointSurvivorDamage;
	int m_missionSurvivorDamage;
	int m_tankTickets; 
	CountdownTimer m_breatheTimer; 
	CountdownTimer m_vocalizeTimer;
	CountdownTimer m_vocalizePainTimer;
	float m_fNextIdleVocalizeTime;
	int m_speechPriority; // SpeechPriorityType
	int m_attemptedSpeechPriority; // SpeechPriorityType
	int m_customAbility; // 1652
	char unknown1656[100];
	IntervalTimer m_TimeSinceLastLOS;
	char unknown1764[28];
	bool m_hasVisisbleThreats; 
	char padding1793[3];
	char unknown1796[164];
	CountdownTimer m_staggerTimer;
	float m_staggerStart[3];
	float m_staggerDir[3];
	float m_staggerDist;
	int m_iQueuedStaggerType;
	CountdownTimer m_tugTimer; // 2004
	float m_tugStart[3]; 
	float m_tugDir[3];
	float m_tugDist;
	CountdownTimer m_vomitTimer;
	int m_vomitingPlayer; //  CHandle<CTerrorPlayer>
	bool m_bAttackerExploded; // 2060
	CountdownTimer m_itTimer; // 2064
	int m_itSource; // CHandle<CTerrorPlayer>
	bool m_wasIt;
	bool m_bVIPTarget;
	CountdownTimer m_adrenalineTimer;
	bool m_bAdrenalineActive;
	char padding2061[3]; 
	char unknown2064[72]; 
	bool m_isCulling; 
	bool m_isRelocating; 
	CountdownTimer m_cullTimer;
	CountdownTimer m_stunTimer;
	CountdownTimer m_stunImmunityTimer;
	bool m_holdingObject;
	float m_healthBuffer; // 2216
	float m_healthBufferTime;
	int m_healthBufferEventTick;
	bool m_isGoingToDie;
	int m_fOnFireFlags; // 2232 I'm guessing this has to do with the incendiary-extinguish bugfix
	float m_noiseLevel; // 2236
	float m_noiseLevelLatch; // 2240
	int m_iBloodyHandsLevel; // 2244
	char unknown2248[132]; 
	float m_shoveForce[3];
	bool m_airMovementRestricted;
	int m_positionEntity;
	bool m_bSurvivorPositionHidingWeapons;
	int m_pushEntity;
	float m_pushDistance;
	IntervalTimer m_useEntityTimer;
	bool m_usingMountedGun;
	bool m_usingMountedWeapon;
	int m_tongueVictim; // 2424
	int m_tongueOwner;
	IntervalTimer m_tongueVictimTimer;
	float m_initialTonguePullDir[3]; 
	bool m_isHangingFromTongue;
	bool m_reachedTongueOwner;
	int m_chokingType;
	bool m_isProneTongueDrag;
	CountdownTimer m_chokeTimer;
	IntervalTimer m_chokeDurationTimer;
	bool m_hasDonePullSounds;
	bool m_hasDoneStrainSounds;
	CountdownTimer m_tongueDragDamageTimer;
	float m_lastTimeAlive;
	int m_checkpointAwardCounts[149]; // lots of awards
	int m_missionAwardCounts[149];
	int m_checkpointZombieKills[9]; // 3696
	int m_missionZombieKills[9];
	int m_checkpointMedkitsUsed;
	int m_checkpointPillsUsed;
	int m_missionMedkitsUsed;
	int m_missionPillsUsed;
	int m_checkpointMolotovsUsed;
	int m_missionMolotovsUsed;
	int m_checkpointPipebombsUsed;
	int m_missionPipebombsUsed; 
	int m_checkpointBoomerBilesUsed; 
	int m_missionBoomerBilesUsed; 
	int m_checkpointAdrenalinesUsed; 
	int m_missionAdrenalinesUsed; 
	int m_checkpointDefibrillatorsUsed; 
	int m_missionDefibrillatorsUsed; 
	int m_checkpointDamageTaken; 
	int m_missionDamageTaken; 
	int m_checkpointReviveOtherCount; 
	int m_missionReviveOtherCount; 
	int m_checkpointFirstAidShared; 
	int m_missionFirstAidShared; 
	int m_checkpointIncaps; 
	int m_missionIncaps; 
	int m_checkpointDamageToTank; 
	int m_checkpointDamageToWitch; 
	char unknown3864[4]; 
	int m_checkpointHeadshots;  // 3868
	int m_checkpointHeadshotAccuracy; 
	int m_missionHeadshotAccuracy; 
	int m_missionAccuracy; 
	int m_checkpointDeaths; 
	int m_missionDeaths; 
	int m_checkpointMeleeKills; 
	int m_missionMeleeKills; 
	int m_checkpointRoundsFired;
	int m_checkpointRoundsHit;
	int m_checkpointPZIncaps; 
	int m_checkpointPZTankDamage; 
	int m_checkpointPZHunterDamage; 
	int m_checkpointPZSmokerDamage; 
	int m_checkpointPZBoomerDamage; 
	int m_checkpointPZJockeyDamage; 
	int m_checkpointPZSpitterDamage; 
	int m_checkpointPZChargerDamage; 
	int m_checkpointPZKills; 
	int m_checkpointPZPounces; 
	int m_checkpointPZPushes; 
	int m_checkpointPZTankPunches; 
	int m_checkpointPZTankThrows; 
	int m_checkpointPZHung; 
	int m_checkpointPZPulled; 
	int m_checkpointPZBombed; 
	int m_checkpointPZVomited; 
	int m_checkpointPZHighestDmgPounce; 
	int m_checkpointPZLongestSmokerGrab; 
	int m_checkpointPZLongestJockeyRide; 
	int m_checkpointPZNumChargeVictims; 
	float m_jumpSupressedUntil; 
	bool m_hasDoneOnLeavingCheckpoint;
	int m_preIncapacitatedHealth;
	int m_preIncapacitatedHealthBuffer;
	bool m_hasHangPos;
	bool m_isHangingFromLedge; 
	bool m_isFallingFromLedge; 
	IntervalTimer m_hangTimer; 
	float m_hangAirPos[3]; 
	float m_hangPos[3]; 
	float m_hangStandPos[3]; 
	float m_hangNormal[3]; 
	bool m_canLetGoOfLedge;
	float m_fallPos[3];
	float m_landingPos[3];
	int m_grabbedEntity; // EHANDLE
	float m_grabbedEntityOrigin[3];
	float m_grabbedEntityAngles[3];
	void *m_grabArea; // TerrorNavArea *
	CountdownTimer m_ledgeHangGroundCheckTimer;
	bool m_hasIncapBloodPool;
	int m_frustration; 
	CountdownTimer m_FrustrationUpdateTimer; // Gates CTerrorPlayer::UpdateZombieFrustration to only run once per second.
	char unknown4160[956];
	int m_pummelVictim; 
	int m_pummelAttacker; 
	int m_queuedPummelVictim; // CHandle<CTerrorPlayer>
	float m_flQueuedPummelTime;
	int m_queuedPummelAttacker; // CHandle<CTerrorPlayer>
	CountdownTimer m_getUpFromDefibTimer;
	int m_pounceVictim; 
	int m_pounceAttacker; 
	CountdownTimer m_pounceDamageTimer;
	bool m_isAttemptingToPounce; 
	bool m_isPouncedOnVictim; 
	int m_pounceHealth; 
	float m_pounceStartPosition[3]; 
	bool m_pounceScream; 
	CountdownTimer m_pounceTargetTimer; 
	IntervalTimer m_pounceDurationTimer; 
	int m_pounceAttackCancelFrame; 
	IntervalTimer m_lungeDurationTimer; 
	IntervalTimer m_pounceScreamTimer; 
	float m_jockeyStaggerValues[3]; 
	CountdownTimer m_rideDamageTimer; 
	float m_flRideStartTime; 
	int m_queuedPounceHunter; // CHandle<CTerrorPlayer>
	float m_queuedPounceTime; 
	int m_jockeyVictim; 
	int m_jockeyAttacker; 
	int m_hInstancedScene; // EHANDLE
	float m_jockeyForwardMove; 
	float m_jockeySideMove; 
	float m_jockeyYaw; 
	CountdownTimer m_specialAttachTimer; 
	float m_fSpecialAttachTime; 
	bool m_bSpecialFirmAttach; 
	// char padding[3]; 
	float m_jockeyDesiredMove[3]; 
	bool m_jockeyRotatedDesire; 
	float m_vomitStart; 
	float m_vomitFadeStart; 
	float m_bashedStart; 
	float m_salivaStart; 
	int m_knockdownReason; 
	IntervalTimer m_knockdownTimer; 
	char unknown5356[128]; 
	int m_iVersusTeam; // 5484
	float m_flSpectatingKickTime; // 5488
	float m_flFlashLightResetTimer; // 5492
	bool m_bSkippingOuttro; // 5496
	int m_PZEndGameVote; // 5500 EPZEndGamePanelVote
	unsigned int m_iPlayerReportID; // 5504
	bool m_bIdleAfterLevelTransition; // 5508
	bool m_bIdleWhenTakingOverBot;
	CountdownTimer m_GoAFKTimer; // 5512
	int m_lookatPlayer;  // 5524
	bool m_bSurvivorGlowEnabled; // 5528
	bool m_bBeingRelocated;
	int m_iRelocatedHealth;
	float m_flRelocatedAbilityTime;
	float m_flRelocatedAbilityDuration;
	bool m_bWasPresentAtSurvivalStart; 
	// padding[3]
	float m_flSurvivalRecordTime; 
	int m_nSurvivalTopMedal; 
	int m_iSpecialSlot; 
	bool m_bBeingRevivedByDefibrillator; 
	float m_flTimeIgnoreFallDamage; 
	bool m_bIgnoreFallDamageResetAfterImpact; 
	bool m_bEnableLedgeHang;
	bool m_bCommentaryStatueMode;
	// padding[1];
	int m_nVariantType;
	float m_TimeForceExternalView; 
	char unknown5580[8]; 
}; 

struct CBaseEntity
{
	CBaseEntity_vtable * vptr; // 0
	CBaseEntity_data CBaseEntity; // 4
};

struct CBaseFlex
{
	CBaseFlex_vtable * vptr; // 0
	CBaseEntity_data CBaseEntity; // 4
	CBaseAnimating_data CBaseAnimating; // 1072
	CBaseAnimatingOverlay_data CBaseAnimatingOverlay; // 5096
	CBaseFlex_data CBaseFlex; // 5116
};

struct CBaseCombatCharacter
{
	CBaseCombatCharacter_vtable * vptr; // 0
	CBaseEntity_data CBaseEntity; // 4
	CBaseAnimating_data CBaseAnimating; // 1072
	CBaseAnimatingOverlay_data CBaseAnimatingOverlay; // 5096
	CBaseFlex_data CBaseFlex; // 5116
	CBaseCombatCharacter_data CBaseCombatCharacter; // 6092
};
// size 16392
struct CTerrorPlayer
{
	CTerrorPlayer_vtable * vptr; // 0
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
};

#endif // _INCLUDE_TERROR_PLAYER_H_
