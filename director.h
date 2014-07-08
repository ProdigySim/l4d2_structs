#ifndef _INCLUDE_DIRECTOR_H_
#define _INCLUDE_DIRECTOR_H_

#include "typestuff.h"
#include "director_vtables.h"
#include "timers.h"
#include "util.h"
#include "handle.h"

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

enum CustomFinaleStageType {
	CFST_PANIC = 0,
	CFST_TANK = 1,
	CFST_DELAY = 2,
	CFST_ONSLAUGHT = 3,
};

// Actual name used by l4d2
enum FinaleStageType {
	FINALE_HORDE_ATTACK_1 = 0,
	FINALE_DELAY_PRE_HALFTIME = 1,
	FINALE_HALFTIME_BOSS = 2,
	FINALE_HORDE_ATTACK_2 = 3,
	FINALE_DELAY_PRE_FINAL_TANK = 4,
	FINALE_FINAL_TANK = 5,
	FINALE_HORDE_ESCAPE = 6,
	FINALE_CUSTOM_PANIC = 7,
	FINALE_CUSTOM_TANK = 8,
	FINALE_CUSTOM_SCRIPTED = 9,
	FINALE_CUSTOM_DELAY = 10,
	FINALE_GAUNTLET_START = 11,
	FINALE_GAUNTLET_HORDE = 12,
	FINALE_GAUNTLET_HORDE_BONUSTIME = 13,
	FINALE_GAUNTLET_BOSS_INCOMING = 14,
	FINALE_GAUNTLET_BOSS = 15,
	FINALE_GAUNTLET_ESCAPE = 16	
};

enum FinaleType_t {
	FINALETYPE_STANDARD = 0,
	FINALETYPE_GAUNTLET = 1, // parish finale
	FINALETYPE_CUSTOM = 2, // uses script
	FINALETYPE_PANICEVENT = 3, // map-invoked panic event.
	FINALETYPE_SCAVENGE = 4,
	FINALETYPE_NONE = 5
};

enum PanicEventStage {
	STAGE_INITIAL_DELAY = 0,
	STAGE_MEGA_MOB = 1,
	STAGE_WAIT_FOR_COMBAT_TO_END = 2,
	STAGE_PAUSE = 3,
	STAGE_DONE = 4	
};

// 156 bytes
// new size 340 bytes
// INDIVIDUAL OFFSETS HAVE NOT BEEN UPDATED/VERIFIED FOR v2125
struct CDirectorScriptedEventManager {
	FinaleType_t m_FinaleType; // 0x00 should have some sort of enum, 5==no script
	FinaleStageType m_CurrentFinaleStage; // 0x04 there are 16 valid values
	bool m_bUnknown8; // 0x08
	bool m_bNotifiedPlayersOfEscape; // 0x09
	char m_bFinaleTankInPlay; // 0x0A
	bool m_bSpawningFinaleTank; // 0x0B
	float m_fGauntletBossStartFlow; // 0x0C furthest survivor flow at the time of (starting) spawning the tank
	CountdownTimer m_FinaleStageDelayTimer; // 0x10
	float m_fNextGauntletMovementCheckpoint; // 0x1C if survivors reach this absolute flow distance before timer expires, they gain bonus time
	float m_fCurrentGauntletMovementBonus; // 0x20 extra time to be added between horde waves (script/cvar)
	CountdownTimer m_GauntletMovementTimer; // 0x24
	CountdownTimer m_GauntletBonusMovementTimer; // 0x30 counts down the extra time added between horde waves
	IntervalTimer m_CurrentStageStartTime; // 0x3C
	CustomFinaleStageType m_InitialFinaleStageType; // 0x44
	int m_iCurrentCustomFinaleStage; // 0x48
	int m_iCurrentCustomFinaleStageValue; // 0x4C
	char m_cCustomFinaleType; // 0x50 e.g. "[A|B|C|D]_CustomFinale1"
	CountdownTimer m_TankStageSpawnTimer; // 0x54 when elapsed, spawn tank.
	int m_iUnknown96;
	CountdownTimer m_MinimumStageTimeCoundtown; // 0x64
	bool m_bUnknown112; // 0x70
	bool m_bPanicEventInProgress; // 0x71
	PanicEventStage m_PanicEventStage; // 0x74
	CountdownTimer m_PostMobDelayTimer; // 0x78
	int m_iPendingPanicWaves; // 0x84
	int m_iWavesForPanicEvent; // 0x88
	bool m_bInSacrificeFinale; // 0x8C
	bool m_bSacrificeFinaleSucceeded; // 0x8D
	bool m_bSurvivorsWiped; // 0x8E
	CountdownTimer m_SacrificeEndScenarioTimer; // 0x90 initiates the end of the scenario after failure
};

// 92 bytes
struct CDirectorVersusMode {
	CDirectorVersusMode_vtable *vptr; // 0x00
	bool m_bVersusRoundInProgress; // 0x04
	bool m_bAreTeamsFlipped; // 0x05
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
	/* Everything beyond this point seems to be for Linear Scavenge (Follow The Liter)
	 And it's very hard for me to care about it.
	 Names are mostly bullshit but they almost seem to make sense. Best test would be to read
	 them during gameplay. */
	CUTLVECTOR(CUTLVECTOR(CHandle)) m_scavengeClusterHandles; // 44
	CUTLVECTOR(int) m_custerCounts; // 64 yaoright.jpg
	float m_vecPourTargetOrigin[3]; // 84 point_prop_use_target's abs origin
	int m_iCurrentCluster; // 96
	int m_iNumClearedClusters; // 100
};

// 8 bytes
// new size 412 bytes
// INDIVIDUAL OFFSETS HAVE NOT BEEN UPDATED/VERIFIED FOR v2125
struct CDirectorChallengeMode {
	bool m_ChallengeModeActive; // 0
	int m_hRescueTrigger; // 4 EHANDLE
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
	RESTART_FINALE_WON=3,
	RESTART_VERSUS_SOMETHING1=5,
	RESTART_VERSUS_FROMVOTE=7,
	RESTART_VERSUS_SOMETHING2=8,
	RESTART_SCAVENGE_ROUND=9, // Halftime or round end
	RESTART_SCAVENGE_ROUND_TIE=10, // exact tie (cans+time
	RESTART_VERSUS_CHANGELEVEL,
	RESTART_SCAVENGE_MATCH_FINISHED=12,
	RESTART_SCAVENGE_SOMETHING3=13,
	RESTART_SURVIVAL_ROUND1=14,
	RESTART_SURVIVAL_ROUND2=16,
	RESTART_MISSION_ABORTED=18,
};

// Win32: 1420 bytes
// Lin: 1420 bytes
struct CDirector {
	CDirector_vtable * vptr; // 0x0
	char unknown4[156]; // 0x04
	bool m_bHasSurvivorLeftSafeArea; // 160
	bool m_bUknown161; // 161 set to 0in CDirector::Reset()
	char padding162[2]; // 161
	int m_iFinaleEscapeState; // 164
	char unknown168[4]; // 168
	CountdownTimer TankProhibitionTimer; // 172 see director_tank_checkpoint_interval, director_tank_min/max_interval
	CountdownTimer TankLotteryEntryTimer; // 184
	CountdownTimer TankLotterySelectionTimer; // 196
	char unknown184[4]; // 208
	DirectorTempoState m_iTempoState; // 212
	CountdownTimer m_ChangeTempoTimer; // 216 Set to various values depending on current state, see CDirector::UpdateTempo()
	float m_flEndFadeFlowDistance; // 228 Highest survivor flow stored here on transition to PEAK_FADE, goes to to RELAX after director_relax_max_flow_travel distance made
	char unknown232[20]; // 232
	int m_iWitchCount; // 252
	int m_iTankCount; // 256
	float m_fTankFlowDistance; // 0x104
	char unknown264[8]; // 264
	CountdownTimer ZombieGhostSpawnTimer; // 272 Started with z_ghost_spawn_interval whenever SI dies during normal gameplay
	bool m_bTankFrustrationEnabled; // 284
	char padding285[3]; // 285
	char unknown288[100]; // 284
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
	float m_fMobSpawnSize; // 708
	char unknown712[4];
	float m_fMobSpawnInterval; // 716 I think that's what this is
	float m_fTankProhibitionInterval; // 720
	_DWORD m_iUnknown724; // 724 some kind of userid
	int m_iSelectedTankPlayerId; // 728
	int m_iNumReservedWanderers; // 732
	int m_iScavengeItemsRemaining; // 736 For scavenge mode/finales I assume
	char unknown740[4];
	IntervalTimer ElapsedMissionTimer; // 744 Should be timing playtime on this map
	float m_fCumulativeMissionTime; // 752 Add this to timer duration from above to get TotalElapsedMissionTime
	char m_sCurrentMap[0x20]; // 756
	CountdownTimer m_rescueCheckTimer; // 788 see rescue_interval cvar
	char unknown800[52];
	void * m_kvPopulationData; // 852 KeyValues *
	char unknown856[8];
	int m_iMapNumber; // 864, should be 0 indexed into current campaign
	int m_iSessionStartMapNumber; // 868
	char unknown872[24];
	int m_iMissionWipes; // 896 number of wipes on this mission (coop)
	ZombieClassType m_zThreatRoster[3]; // 900 Threat roster for coop
	int m_iNextThreatIdx; // 912 Which threat will be used next?
	char unknown916[20];
	CountdownTimer unknownCTimer936;
	char unknown948[96]; // "forbidden targets" starts here 
	CountdownTimer unknownCTimer1044;
	float m_flUnknown1056; // 1056
	bool m_bUnknown1160;
	bool m_bIsFirstRoundFinished; // 0x425 Fuck naming this var
	bool m_bIsSecondRoundFinished; // This one too
	bool m_bUnknownJunk; // probably related
	CountdownTimer TransitionTimeoutTimer; // 0x428
	char unknown1076[308]; // 0x434
	CDirectorTacticalServices * TacticalServicesPtr;
	CDirectorItemManager * ItemManagerPtr; // 0x56c
	CDirectorMusicBanks * MusicBanksPtr; 
	CDirectorSessionManager * SessionManagerPtr; 
	CDirectorScriptedEventManager * ScriptedEventManagerPtr; 
	CDirectorVersusMode * VersusModePtr; 
	CDirectorSurvivalMode * SurvivalModePtr;
	CDirectorScavengeMode * ScavengeModePtr; 
	CDirectorChallengeMode * ChallengeModePtr;
	char unknown1420[8];
};

#endif //_INCLUDE_DIRECTOR_H_
