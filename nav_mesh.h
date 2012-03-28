#ifndef _INCLUDE_NAV_MESH_H_
#define _INCLUDE_NAV_MESH_H_

#include "game_events.h"

struct CNavMesh_iface
{
	void * PreLoadAreas;
	void * CreateArea;
	void * DestroyArea;
	void * CreateHidingSpot;
	void * Reset;
	void * Update;
	void * Load;
	void * PostLoad;
	void * Save;
	void * GetSubVersionNumber;
	void * SaveCustomData;
	void * LoadCustomData;
	void * SaveCustomDataPreArea;
	void * LoadCustomDataPreArea;
	void * OnServerActivate;
	void * OnRoundRestart;
	void * OnRoundRestartPreEntity;
	void * OnBreakableCreated;
	void * OnBreakableBroken;
	void * OnAreaBlocked;
	void * OnAreaUnblocked;
	void * OnAvoidanceObstacleEnteredArea;
	void * OnAvoidanceObstacleLeftArea;
	void * OnEditCreateNotify;
	void * OnEditDestroyNotify;
	void * OnEditDestroyNotify;
	void * OnNodeAdded;
	void * AddWalkableSeeds;
	void * CommandNavFloodSelect;
	void * StripNavigationAreas;
	void * PostCustomAnalysis;
	void * RemoveNavArea;
	void * BeginCustomAnalysis;
	void * EndCustomAnalysis;

};

struct TerrorNavMesh_iface
{
	void * OnDoorCreated; // lol
};

struct CNavMesh_vtable
{
	void * dtor1;
	void * dtor0;
	IGameEventListener2_iface IGameEventListener2;
	CNavMesh_iface CNavMesh;
};

struct TerrorNavMesh_vtable
{
	void * dtor1;
	void * dtor0;
	IGameEventListener2_iface IGameEventListener2;
	CNavMesh_iface CNavMesh;
	TerrorNavMesh_iface TerrorNavMesh;
};

// 1512?
struct CNavMesh_data
{
	char unknown0[1512];
};

// 228?
struct TerrorNavMesh_data
{
	char unknown0[228];
};

struct TerrorNavMesh
{
	TerrorNavMesh_vtable * vptr; // 0
	CNavMesh_data CNavMesh; // 4
	TerrorNavMesh_data TerrorNavMesh; // 1516
};

#endif // _INCLUDE_NAV_MESH_H_