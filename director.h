#ifndef _INCLUDE_DIRECTOR_H_
#define _INCLUDE_DIRECTOR_H_

#include "typestuff.h"
#include "director_vtables.h"
#include "timers.h"
#include "util.h"

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
	CDirectorVersusMode_vtable *vptr; // 0x00
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
	bool m_bUnknown; // 0
	float m_flLastCanPouredTime; // 4
	bool m_bScavengeRoundInProgress; // 8
	bool m_bUnk2; // 9
	bool m_bAreTeamsSwapped; // 10
	bool m_bInOvertime; // 11
	bool m_bInOvertime2; // 12
	char padding13[3]; // 13
	CountdownTimer RoundSetupTimer; // 16 (see: scavenge_round_setup_time)
	CountdownTimer OvertimeGraceTimer; // 28 (see: scavenge_overtime_grace_time)
	int m_iMusicIntensityCheckpoint; // 40
	char unknown44[60]; // 44
};

// 8 bytes
struct CDirectorChallengeMode {
	char unknown[8];
};

// 1 byte
struct CDirectorTacticalServices {
	char unknown; // does this even exist? blah.
};


enum DirectorTempoState
{
	TEMPO_BUILDUP=0,
	TEMPO_SUSTAIN_PEAK=1,
	TEMPO_PEAK_FADE=2,
	TEMPO_RELAX=3
};

enum ScenarioRestartReason
{
	RESTART_VERSUS_SOMETHING1=5,
	RESTART_VERSUS_FROMVOTE=7,
	RESTART_VERSUS_SOMETHING2=8,
	RESTART_SCAVENGE_SOMETHING1=9,
	RESTART_SCAVENGE_SOMETHING2=10,
	RESTART_SCAVENGE_MATCHFINISHED=12,
	RESTART_SCAVENGE_SOMETHING3=13,
	RESTART_SURVIVAL_ROUND1=14,
	RESTART_SURVIVAL_ROUND2=16	
};

// Win32: 1460 bytes
// Lin: 1480 bytes
struct CDirector {
	CDirector_vtable * vptr; // 0x0
	char unknown4[156]; // 0x04
	bool m_bHasSurvivorLeftSafeArea; // 160
	bool m_bUknown161; // 161 set to 0in CDirector::Reset()
	char padding162[2]; // 161 
	char unknown164[8]; // 164
	CountdownTimer TankProhibitionTimer; // 172 see director_tank_checkpoint_interval, director_tank_min/max_interval
	char unknown184[28]; // 184
	DirectorTempoState m_iTempoState; // 212
	CountdownTimer m_ChangeTempoTimer; // 216 Set to various values depending on current state, see CDirector::UpdateTempo()
	float m_flEndFadeFlowDistance; // 228 Highest survivor flow stored here on transition to PEAK_FADE, goes to to RELAX after director_relax_max_flow_travel distance made
	char unknown232[20]; // 232
	int m_iWitchCount; // 252
	int m_iTankCount; // 256
	float m_fTankFlowDistance; // 0x104
	char unknown264[8]; // 264
	CountdownTimer ZombieGhostSpawnTimer; // 272 Started with z_ghost_spawn_interval whenever SI dies during normal gameplay
	char unknown284[104]; // 284
	float m_fAvgSurvivorSpan; // 388
	float m_fAvgSurvivorSpeed; // 392
	float m_fFurthestSurvivorFlow; // 396
	char unknown400[24]; // 400
	CountdownTimer RestartScenarioTimer; // 424 Counts down to a scenario restart (UpdateScenarioState)
	CountdownTimer EndScenarioTimer; // 436 Counts down to a scenario end (UpdateScenarioState)
	bool m_bUnknown448;
	bool m_bUnknown449;
	bool m_bUnknown450;
	ScenarioRestartReason m_iScenarioExitReason; // 452 Set in EndScenario(), read in various
	char unknown456[8]; // 456
	bool m_bInIntro; // 464
	bool m_bUnknown465; // 465 set to 0 in CDirector::Reset()
	// should be padded
	CountdownTimer MobSpawnTimer; // 468
	CountdownTimer unknownCTimer480; // 480
	IntervalTimer m_ClassDeathTimers[7]; // 492 ZC_NONE=0 through ZC_CHARGER=6
	IntervalTimer unknownITimer548; // 548
	IntervalTimer unknownITimer556; // 556
	CountdownTimer SmokerSpawnTimer; // 0x234
	CountdownTimer BoomerSpawnTimer;
	CountdownTimer HunterSpawnTimer;
	CountdownTimer SpitterSpawnTimer;
	CountdownTimer JockeySpawnTimer;
	CountdownTimer ChargerSpawnTimer;
	CUTLVECTORFIXEDGROWABLE(CountdownTimer,3) m_pzSpawnTimers; // 636
	// 3*12 + 4 + 20 = 60
	char unknown696[12]; // 696
	bool m_bWitchInPlay; // 708
	// padding
	float m_fMobSpawnSize; // 712
	char unknown716[4]; // 0x2cc
	float m_fMobSpawnInterval; // 720 I think that's what this is
	float m_fTankProhibitionInterval; // 724
	_DWORD m_iUnknown728; // 728 some kind of userid
	_DWORD m_iUnknown732; // 732
	int m_iNumReservedWanderers; // 736
	int m_iScavengeItemsRemaining; // 740 For scavenge mode/finales I assume
	char unknown744[4]; // 744
	IntervalTimer ElapsedMissionTimer; // 748 Should be timing playtime on this map
	float m_fCumulativeMissionTime; // 756 Add this to timer duration from above to get TotalElapsedMissionTime
	char m_sCurrentMap[0x20]; // 760
	CountdownTimer m_rescueCheckTimer; // 792 see rescue_interval cvar
	char unknown804[52]; // 804
	void * m_kvPopulationData; // 856 KeyValues *
	char unknown860[8]; // 860
	int m_iMapNumber; // 868, should be 0 indexed into current campaign
	int m_iSessionStartMapNumber; // 872
	char unknown876[24]; // 876
	int m_iMissionWipes; // 900 number of wipes on this mission (coop)
	ZombieClassType m_zThreatRoster[3]; // 904 Threat roster for coop
	int m_iNextThreatIdx; // 916 Which threat will be used next?
	char unknown920[20]; // 920
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
