#ifndef _INCLUDE_DIRECTOR_H_
#define _INCLUDE_DIRECTOR_H_

#include "director_vtables.h"
#include "timers.h"

// 1128 bytes
struct CDirectorItemManager {
	CDirectorItemManager_vtable * vptr;
	char unknown[1124];
};

// 92 bytes
struct CDirectorMusicBanks {
	CDirectorMusicBanks_vtable * vptr;
	char unknown[88];
};

// 76 bytes
struct CDirectorSessionManager {
	CDirectorSessionManager_vtable * vptr;
	char unknown[72];
};

// 156 bytes
struct CDirectorScriptedEventManager {
	char unknown[156];
};

// 92 bytes
struct CDirectorVersusMode {
	void *vtableptr; // 0x00
	bool m_bVersusRoundInProgress; // 0x04
	bool m_bFirstMap; // 0x05 idk
	bool m_bTransitioning; // 0x06 still making shit up
	// alignment padding
	int m_iCampaignScores[2]; // 0x08
	int m_iOldCampaignScores[2]; // 0x10 Used when a Chapter Restart vote is called
	bool m_bChapterRestartInProgress; // 0x18 This is set to true during the map restart from a Chapter Restart vote
	// alignment padding here afaik
	CountdownTimer VersusStartTimer; // 0x1c Timer controlling saferoom door open, allowing PZ spawning.
	float m_fTankSpawnFlowPercent[2]; // 0x28 Tank spawn flow percent for rounds 1 and 2
	float m_fWitchSpawnFlowPercent[2]; // 0x30 Witch spawn flow percent for rounds 1 and 2
	bool m_bTankThisRound[2]; // 0x38 One for each round!
	bool m_bWitchThisRound[2]; // 0x3a One for each round!
	float m_fFinaleTravelCompletionValue; // 0x3c 5660 in CFinaleTrigger
	int m_iFinaleTriggerVar2; // 0x40 5656 in CFinaleTrigger
	bool m_bInFinaleMap; // 0x44
	int m_iNumMarkersReached; // 0x48
	int m_iMarkersCount; // 0x4c
	CountdownTimer UpdateMarkersTimer; // 0x50 Timer controlling when to check if survivors have passed markers. Normally set to 1s duration
};

// 160 bytes
struct CDirectorSurvivalMode {
	char unknown[160];
};

// 104 bytes
struct CDirectorScavengeMode {
	bool m_bUnknown; 
	char padding[3]; 
	float m_fUnknown; // 0x04
	bool m_bScavengeRoundInProgress; // 0x08
	bool m_bUnk2; // 0x09
	bool m_bAreTeamsSwapped; // 0x0a
	bool m_bInOvertime; // 0x0b
	bool m_bInOvertime2; // 0x0c
	char padding2[3];
	CountdownTimer RoundSetupTimer; // 0x10 (see: scavenge_round_setup_time)
	CountdownTimer OvertimeGraceTimer; // 0x1c (see: scavenge_overtime_grace_time)
	char unknown[64];
};

// 8 bytes
struct CDirectorChallengeMode {
	char unknown[8];
};

// 1 byte
struct CDirectorTacticalServices {
	char unknown; // does this even exist? blah.
};


// Win32: 1460 bytes
// Lin: 1480 bytes

struct CDirector {
	CDirector_vtable * vptr; // 0x0
	char unknown4[156]; // 0x04
	bool m_bHasSurvivorLeftSafeArea; // 160
	char padding[3]; // 161
	char unknown164[8]; // 164
	CountdownTimer TankProhibitionTimer; // 172 see director_tank_checkpoint_interval, director_tank_min/max_interval
	char unknown184[72]; // 184
	int m_iTankCount; // 256
	float m_fTankFlowDistance; // 0x104
	char unknown264[8]; // 264
	CountdownTimer ZombieGhostSpawnTimer; // 272 Started with z_ghost_spawn_interval whenever SI dies during normal gameplay
	char unknown284[104]; // 284
	float m_fAvgSurvivorSpan; // 388
	float m_fAvgSurvivorSpeed; // 392
	float m_fFurthestSurvivorFlow; // 396
	char unknown400[24]; // 400
	CountdownTimer unknownCTimer424; // 424
	CountdownTimer unknownCTimer436; // 436
	char unknown448[16]; // 448
	bool m_bInIntro; // 464
	// should be padded
	CountdownTimer MobSpawnTimer; // 468
	CountdownTimer unknownCTimer480; // 480
	IntervalTimer unknownITimer492; // 492
	IntervalTimer SmokerDeathTimer; // 500
	IntervalTimer BoomerDeathTimer;
	IntervalTimer HunterDeathTimer;
	IntervalTimer SpitterDeathTimer;
	IntervalTimer JockeyDeathTimer;
	IntervalTimer ChargerDeathTimer;
	IntervalTimer unknownITimer548; // 548
	IntervalTimer unknownITimer556; // 556
	CountdownTimer SmokerSpawnTimer; // 0x234
	CountdownTimer BoomerSpawnTimer;
	CountdownTimer HunterSpawnTimer;
	CountdownTimer SpitterSpawnTimer;
	CountdownTimer JockeySpawnTimer;
	CountdownTimer ChargerSpawnTimer;
	char unknown636[76]; // 0x27c
	float m_fMobSpawnSize; // 0x2c8
	char unknown716[4]; // 0x2cc
	float m_fMobSpawnInterval; // 720 I think that's what this is
	float m_fTankProhibitionInterval; // 724
	_DWORD m_iUnknown728; // 728 some kind of userid
	_DWORD m_iUnknown732; // 732
	int m_iNumReservedWanderers; // 736
	char unknown740[8]; // 740
	IntervalTimer ElapsedMissionTimer; // 748 Should be timing playtime on this map
	float m_fCumulativeMissionTime; // 756 Add this to timer duration from above to get TotalElapsedMissionTime
	char m_sCurrentMap[0x20]; // 760
	char unknown792[64]; // 792
	void * m_kvPopulationData; // 856 KeyValues *
	char unknown860[8]; // 860
	int m_iMapNumber; // 868, should be 0 indexed into current campaign?
	char unknown872[28]; // 872
	int m_iMissionWipes; // 900 number of wipes on this mission (coop)
	char unknown904[36]; // 904
	CountdownTimer unknownCTimer940; // 940
	char unknown952[116]; // 952  "forbidden targets" starts here
	int m_iDirectorScriptIdx; // 1068 gets passed to g_pScriptVM calls
	char unknown1072[20]; // 1072
	int m_iScriptingInts[4]; // 1092 Don't ask me. More scripting contexts?
	CountdownTimer unknownCTimer1108; // 1108
	bool m_bUnknown1120; // 1120 0x460
	bool m_bIsFirstRoundFinished; // 0x461 Fuck naming this var
	bool m_bIsSecondRoundFinished; // This one too
	bool m_bUnknownJunk; // probably related
	CountdownTimer TransitionTimeoutTimer; // 0x464
	char unknown1136[284]; // 0x470
#ifdef PLATFORM_LINUX
	char unknown_linonly1420[20]; // 0x58c
#endif
	char unknown1440[4]; // win 0x58c lin 0x5a0
	CDirectorTacticalServices * TacticalServicesPtr;
	CDirectorItemManager * ItemManagerPtr; // win 0x594 lin 0x5a8
	CDirectorMusicBanks * MusicBanksPtr; 
	CDirectorSessionManager * SessionManagerPtr; 
	CDirectorScriptedEventManager * ScriptedEventManagerPtr; 
	CDirectorVersusMode * VersusModePtr; 
	CDirectorSurvivalMode * SurvivalModePtr; 
	CDirectorScavengeMode * ScavengeModePtr; 
	CDirectorChallengeMode * ChallengeModePtr; // win 0x5a8 lin 0x5bc
	char unknown1472[8]; // win 0x5ac lin 0x5c0
};

#endif //_INCLUDE_DIRECTOR_H_
