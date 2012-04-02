#ifndef _INCLUDE_NAV_MESH_H_
#define _INCLUDE_NAV_MESH_H_

#include "game_events.h"
#include "util.h"

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

struct CNavArea_iface
{
	void * OnServerActivate;
	void * OnRoundRestart;
	void * OnRoundRestartPreEntity;
	void * OnEnter;
	void * OnExit;
	void * OnDestroyNotify;
	void * OnDestroyNotify;
	void * OnEditCreateNotify;
	void * OnEditDestroyNotify;
	void * OnEditDestroyNotify;
	void * Save;
	void * Load;
	void * PostLoad;
	void * SaveToSelectedSet;
	void * RestoreFromSelectedSet;
	void * Dump;
	void * UpdateBlocked;
	void * GetDangerDecayRate;
	void * Draw;
	void * DrawFilled;
	void * DrawSelectedSet;
	void * ComputeHidingSpots;
	void * ComputeSniperSpots;
	void * ComputeSpotEncounters;
	void * ComputeEarliestOccupyTimes;
	void * CustomAnalysis;
	void * ComputeLighting;
	void * IsAbleToMergeWith;
	void * InheritAttributes;
};

struct TerrorNavArea_iface
{
	void * OnEnterActiveSet;
	void * OnLeaveActiveSet;
	void * ResetPotentiallyVisibleAreas;
};

struct CNavArea_vtable
{
	void * dtor1;
	void * dtor0;
	CNavArea_iface CNavArea;
};

struct TerrorNavArea_vtable
{
	void * dtor1;
	void * dtor0;
	CNavArea_iface CNavArea;
	TerrorNavArea_iface TerrorNavArea;
};

struct CNavArea;

struct NavConnect
{
	union
	{
		unsigned int id;
		CNavArea * area;
	};
	float length;
};

struct CNavLadder 
{
	float m_top[3]; // 0
	float m_bottom[3]; // 12
	float m_length; // 24
	float m_width; // 28
	CNavArea * m_topForwardArea; // 32
	CNavArea * m_topLeftArea; // 36
	CNavArea * m_topRightArea; // 40
	CNavArea * m_topBehindArea; // 44
	CNavArea * m_bottomArea; // 48
	int m_ladderEntity; // 52
	int m_dir; // 56 0=up, 1=down
	float m_normal[3]; // 60
	unsigned int m_id; // 64
};

struct CNavNode
{
	float m_pos[3];
	float m_normal[3];
	CNavNode *m_to[4];
	float m_obstacleHeight[4];
	float m_obstacleStartDist[4];
	float m_obstacleEndDist[4];
	unsigned int m_id;
	int m_attributeFlags;
	CNavNode *m_next;
	CNavNode *m_nextAtXY;
	unsigned char m_visited;
	CNavNode *m_parent;
	bool m_isCovered;
	CNavArea *m_area;
	bool m_isBlocked[4];
	bool m_crouch[4];
	float m_groundHeightAboveNode[4];
	bool m_isOnDisplacement;
};

struct AreaBindInfo
{
	union
	{
		CNavArea *area;
		unsigned int id;
	};
	//unsigned char attributes;
};

struct CNavArea_data
{
	float m_nwCorner[3];
	float m_seCorner[3];
	float m_invDxCorners;
	float m_invDyCorners;
	float m_neZ;
	float m_swZ;
	float m_center[3];
	unsigned char m_playerCount[2];
	bool m_isBlocked[2]; // Goofy
	unsigned int m_marker;
	float m_totalCost;
	float m_costSoFar;
	CNavArea * m_nextOpen;
	CNavArea * m_prevOpen;
	unsigned int m_openMarker;
	int m_attributeFlags;
	NavConnect **m_connect[4];
	CNavLadder **m_ladder[2];
	int m_damagingTickCount;
	unsigned int m_nearNavSearchMarker;
	CNavArea * m_parent;
	int m_parentHow; // NavTraverseType Also goofy
	float m_pathLengthSoFar;
	void * m_elevator; // CFunElevator
	NavConnect **m_elevatorAreas;
	unsigned int m_id;
	unsigned int m_debugid;
	unsigned int m_place; // Place
	CountdownTimer m_blockedTimer;
	bool m_isUnderwater;
	bool m_isBattlefront;
	//float m_avoidanceObstacleHeight;
	CountdownTimer m_avoidanceObstacleTimer;
	float m_clearedTimestamp[2];
	float m_danger[2];
	float m_dangerTimestamp[2];
	void **m_hidingSpots; // HidingSpot
	void **m_spotEncounters; // SpotEncounter
	float m_earliestOccupyTime[2];
	float m_lightIntensity[ 4 ];
	CNavNode *m_node[4];
	CNavArea *m_prevHash;
	CNavArea *m_nextHash;
	
	char unknownxx[16];
	NavConnect **m_incomingConnect[4];
};


struct CUtlVectorAreaBindInfo
{
	CUtlMemoryConservative m_memory;
	int m_Size;
	AreaBindInfo *m_pElements;
};

struct TerrorNavArea_data
{
	int m_TerrorMarker;  // 292
	_DWORD unknown296;  // 296
	unsigned int m_spawnAttributes; // 300
	AreaBindInfo m_inheritVisibilityFrom; // 304
	CUtlVectorAreaBindInfo m_potentiallyVisibleAreas; // 308
	bool m_isInheritedFrom; // 324
	bool m_isCleared; // 325 might just be byte/uchar
	IntervalTimer m_clearedTimer; // 328 starts when nav area is cleared by player
	char unknown332[20]; // 332
	short m_siUnknown352[2]; // 352
	IntervalTimer m_unclearedTimer; // 356 starts when nav area is uncleared
	char unknown364[4];
	int m_hDoorEntity;
};

struct CNavArea
{
	CNavArea_vtable *vptr;
	CNavArea_data CNavArea;
};

struct TerrorNavArea
{
	TerrorNavArea_vtable *vptr;
	CNavArea_data CNavArea;
	TerrorNavArea_data TerrorNavArea;
};

// 24
struct Extent
{
	float lo[3]; // 0
	float hi[3]; // 12
};

// 95
struct Checkpoint 
{
	CNavArea ** m_containedAreas; // 0
	char unknown4[8]; // 4
	int m_iNumContainedAreas; // 12
	char unknown16[8]; // 16
	Extent m_extent; // 24 (default +/-99999.0)
	char unknown48[47];
};

// 1512?
struct CNavMesh_data
{
	char unknown0[1512];
};

// 228?
struct TerrorNavMesh_data
{
	char unknown0[120];
	Checkpoint **m_checkpoints; // 1636 nav areas?
	char unknown128[8]; // 1640
	int m_iNumCheckpoints; // 1648 Checkpoint == saferoom
};

struct TerrorNavMesh
{
	TerrorNavMesh_vtable * vptr; // 0
	CNavMesh_data CNavMesh; // 4
	TerrorNavMesh_data TerrorNavMesh; // 1516
};

#endif // _INCLUDE_NAV_MESH_H_