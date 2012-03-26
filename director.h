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
	char unknown4[252]; // 0x04
	int m_iTankCount; // 0x100
	float m_fTankFlowDistance; // 0x104
	char unknown264[160]; // 0x108
	CountdownTimer unk_Timer1; // 0x1a8
	char unknown436[32]; // 0x1b4
	CountdownTimer MobSpawnTimer; // 0x1d4
	char unknown480[20]; // 0x1e0
	IntervalTimer SmokerDeathTimer; // 0x1f4
	IntervalTimer BoomerDeathTimer;
	IntervalTimer HunterDeathTimer;
	IntervalTimer SpitterDeathTimer;
	IntervalTimer JockeyDeathTimer;
	IntervalTimer ChargerDeathTimer;
	char unknown548[16]; // 0x224
	CountdownTimer SmokerSpawnTimer; // 0x234
	CountdownTimer BoomerSpawnTimer;
	CountdownTimer HunterSpawnTimer;
	CountdownTimer SpitterSpawnTimer;
	CountdownTimer JockeySpawnTimer;
	CountdownTimer ChargerSpawnTimer;
	char unknown636[76]; // 0x27c
	float m_fMobSpawnSize; // 0x2c8
	char unknown716[44]; // 0x2cc
	char m_sCurrentMap[0x20]; // 0x2f8
	char unknown792[329]; // 0x318
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
	char unknown1468[8]; // win 0x5a8 lin 0x5bc
	CDirectorChallengeMode * ChallengeModePtr; // win 0x5b0 lin 0x5c4
};

#endif //_INCLUDE_DIRECTOR_H_
