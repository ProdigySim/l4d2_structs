#ifndef _INCLUDE_DIRECTOR_VTABLES_H_
#define _INCLUDE_DIRECTOR_VTABLES_H_

#include "game_events.h"

struct CDirectorItemManager_vtable
{
	void * Reset; // CDirectorItemManager::Reset(void)
	void * OnBeginChangeLevel; // CDirectorItemManager::OnBeginChangeLevel(void)
	void * OnMapLoaded; // CDirectorItemManager::OnMapLoaded(void)
};

struct CDirectorMusicBanks_vtable
{
	void * OnBeginTransition; // CDirectorMusicBanks::OnBeginTransition(bool)
	void * OnRoundStart; // CDirectorMusicBanks::OnRoundStart(void)
	void * OnServerShutdown; // CDirectorMusicBanks::OnServerShutdown(void)
};

struct CDirectorSessionManager_vtable
{
	void * OnServerShutdown; // CDirectorSessionManager::OnServerShutdown(void)
	void * OnMapLoaded; // CDirectorSessionManager::OnMapLoaded(void)
	void * UpdateSession; // CDirectorSessionManager::UpdateSession(void)
	void * UpdateTeamReadiness; // CDirectorSessionManager::UpdateTeamReadiness(void)
	void * OnBeginChangeLevel; // CDirectorSessionManager::OnBeginChangeLevel(void)
	void * OnGameplayStart; // CDirectorSessionManager::OnGameplayStart(void)
	void * OnFirstSurvivorLeftSafeArea; // CDirectorSessionManager::OnFirstSurvivorLeftSafeArea(CTerrorPlayer *)
	void * OnPlayerFullyConnected; // CDirectorSessionManager::OnPlayerFullyConnected(CTerrorPlayer *)
	void * OnPlayerDisconnected; // CDirectorSessionManager::OnPlayerDisconnected(CTerrorPlayer *)
	void * DrawDebug; // CDirectorSessionManager::DrawDebug(int)
};

struct CDirectorVersusMode_vtable
{
	void * ShouldReselectCustomFinale; // CDirectorVersusMode::ShouldReselectCustomFinale(void)
	void * SurvivorsCanLevelChange; // CDirectorVersusMode::SurvivorsCanLevelChange(void)
};

struct CDirector;
struct CDirector_vtable
{
	void * CDirector_dtor1; // CDirector::~CDirector() (D1)
	void * CDirector_dtor0; // CDirector::~CDirector() (D0)
	IGameEventListener2_iface IGameEventListener2;
	void (* OnBeginChangeLevel)(CDirector*);
	void (* Reset)(CDirector*);
	void (* UpdateTempo)(CDirector*);
	void (* OnMapLoaded)(CDirector*);
	void (* OnRoundStart)(CDirector*);
	void (* OnServerShutdown)(CDirector*);
	void (* OnBeginTransition)(CDirector*, bool);
	void (* OnGameplayStart)(CDirector*);
	int	 (* GetMaxPlayerZombies)(CDirector*);
	bool (* IsClassAllowed)(CDirector*, ZombieClassType);
	void (* OnPlayerDisconnected)(CDirector*, CTerrorPlayer *);
	void (* SurvivorsCanLevelChange)(CDirector*);
	void (* OnRestartMap)(CDirector*);
	void (* ShouldLockTempo)(CDirector*);
	void (* InitScripts)(CDirector*);
	void (* OnForcedRestart)(CDirector*);
	void (* CheckForSurvivorsLeavingSafeArea)(CDirector*);
	void (* OnTeamsReady)(CDirector*);
	void (* UpdateSpecialSpawns)(CDirector*);
	void (* ShouldAllowSpecialSpawns)(CDirector*);
	void (* ShuffleThreatRoster)(CDirector*, ZombieClassType);
	void (* ShouldReselectCustomFinale)(CDirector*);
	void (* ShouldShowCredits)(CDirector*);
	void (* DiscardOrphanInfected)(CDirector*);
	void (* GetBaseSpecialLimit)(CDirector*, ZombieClassType);
	void (* GetDominatorLimit)(CDirector*);
	void (* DrawDebug)(CDirector*, int);
};

#endif // _INCLUDE_DIRECTOR_VTABLES_H_
