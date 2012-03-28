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

struct CDirector_vtable
{
	void * CDirector_dtor1; // CDirector::~CDirector() (D1)
	void * CDirector_dtor0; // CDirector::~CDirector() (D0)
	IGameEventListener2_iface IGameEventListener2;
	void * OnBeginChangeLevel; // CDirector::OnBeginChangeLevel(void)
	void * Reset; // CDirector::Reset(void)
	void * UpdateTempo; // CDirector::UpdateTempo(void)
	void * OnMapLoaded; // CDirector::OnMapLoaded(void)
	void * OnRoundStart; // CDirector::OnRoundStart(void)
	void * OnServerShutdown; // CDirector::OnServerShutdown(void)
	void * OnBeginTransition; // CDirector::OnBeginTransition(bool)
	void * OnGameplayStart; // CDirector::OnGameplayStart(void)
	void * GetMaxPlayerZombies; // CDirector::GetMaxPlayerZombies(void)const
	void * IsClassAllowed; // CDirector::IsClassAllowed(ZombieClassType)const
	void * OnPlayerDisconnected; // CDirector::OnPlayerDisconnected(CTerrorPlayer *)
	void * SurvivorsCanLevelChange; // CDirector::SurvivorsCanLevelChange(void)
	void * OnRestartMap; // CDirector::OnRestartMap(void)
	void * ShouldLockTempo; // CDirector::ShouldLockTempo(void)
	void * InitScripts; // CDirector::InitScripts(void)
	void * OnForcedRestart; // CDirector::OnForcedRestart(void)
	void * CheckForSurvivorsLeavingSafeArea; // CDirector::CheckForSurvivorsLeavingSafeArea(void)
	void * OnTeamsReady; // CDirector::OnTeamsReady(void)
	void * UpdateSpecialSpawns; // CDirector::UpdateSpecialSpawns(void)
	void * ShouldAllowSpecialSpawns; // CDirector::ShouldAllowSpecialSpawns(void)
	void * ShuffleThreatRoster; // CDirector::ShuffleThreatRoster(ZombieClassType)
	void * ShouldReselectCustomFinale; // CDirector::ShouldReselectCustomFinale(void)
	void * ShouldShowCredits; // CDirector::ShouldShowCredits(void)
	void * DiscardOrphanInfected; // CDirector::DiscardOrphanInfected(void)
	void * GetBaseSpecialLimit; // CDirector::GetBaseSpecialLimit(ZombieClassType)const
	void * GetDominatorLimit; // CDirector::GetDominatorLimit(void)const
	void * DrawDebug; // CDirector::DrawDebug(int)
};

#endif // _INCLUDE_DIRECTOR_VTABLES_H_
