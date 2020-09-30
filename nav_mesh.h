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
	void * OnEditDestroyNotify2;
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
	void * OnDestroyNotify2;
	void * OnEditCreateNotify;
	void * OnEditDestroyNotify;
	void * OnEditDestroyNotify2;
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


DECLARE_CUTLVECTOR_FULL(CAreaBindInfoArray, AreaBindInfo, CUTLMEMORYCONSERVATIVE(AreaBindInfo));

struct TerrorNavArea_data
{
	int m_TerrorMarker;  // 292
	_DWORD unknown296;  // 296
	unsigned int m_spawnAttributes; // 300
	AreaBindInfo m_inheritVisibilityFrom; // 304
	CAreaBindInfoArray m_potentiallyVisibleAreas; // 308
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

// 96
struct Checkpoint 
{
	CUTLVECTOR(TerrorNavArea*) m_containedAreas; // 0
	float m_flTotalArea; // 20
	Extent m_extent; // 24 (default +/-99999.0)
	CUTLVECTOR(TerrorNavArea*) m_containedSpawnAreas; // 48
	float m_flTotalSpawnArea; // 68
	CUTLVECTOR(int) m_containedDoors; // 72 EHANDLE vector
	bool m_bInUse; // 92
	bool m_bNoZombies; // 93
	bool m_bAllAliveHumanSurvivorsInside; // 94
	bool m_bOutward; // 95
};

DECLARE_CUTLVECTOR(NavAreaVector, CNavArea *);
DECLARE_CUTLVECTOR(NavLadderVector, CNavLadder *);

struct WalkableSeedSpot
{
	float pos[3];
	float normal[3];
};

struct INavAvoidanceObstacle_iface
{
	void * IsPotentiallyAbleToObstructNavAreas;
	void * GetNavObstructionHeight;
	void * CanObstructNavAreas;
	void * GetObstructingEntity;
	void * OnNavMeshLoaded;
};

struct INavAvoidanceObstacle
{
	INavAvoidanceObstacle_iface *vptr;
};

// 1520?
struct CNavMesh_data
{
	int unk0; // 0
	bool unk4; // 4
	bool unk5;
	bool unk6;
	/* // ERROR - SILVERSHOT
	CUTLVECTOR(CUTLVECTOR(CNavArea*)) m_grid; // 8
	float m_gridCellSize; // 28
	
	float m_gridSizeX; // 32
	float m_gridSizeY; // 36
	float m_minX; // 40
	float m_minY; // 44
	unsigned int m_areaCount; // 48

	bool m_isLoaded; // 52
	bool m_isOutOfDate; // 53
	bool m_isAnalyzed; // 54
	char padding55; // 55
	char unknown56[20]; // 56
	CNavArea *m_hashTable[256]; // 76
	char **m_placeName; // 1100
	unsigned int m_placeCount; // 1104
	int m_editMode; // 1108
	bool m_isEditing; // 1112
	unsigned int m_navPlace; // 1116
	float m_editCursorPos[3]; // 1120
	CNavArea * m_markedArea; // 1132
	CNavArea *m_selectedArea; // 1136
	CNavArea *m_lastSelectedArea; // 1140
	int m_markedCorner; // 1144 NavCornerType
	float m_anchor[3]; // 1148
	bool m_isPlacePainting; // 1160
	bool m_splitAlongX; // 1161
	float m_splitEdge; // 1164
	bool m_climbableSurface; // 1168
	float m_surfaceNormal[3]; // 1172
	float m_ladderAnchor[3]; // 1184
	float m_ladderNormal[3]; // 1196
	CNavLadder *m_selectedLadder; // 1208
	CNavLadder *m_lastSelectedLadder; // 1212
	CNavLadder *m_markedLadder; // 1216
	CountdownTimer m_showAreaInfoTimer; // 1220
	NavAreaVector m_selectedSet; // 1232
	NavAreaVector m_dragSelectionSet; // 1252
	bool m_isContinuouslySelecting; // 1272
	bool m_isContinuouslyDeselecting; // 1273
	bool m_bIsDragDeselecting; // 1274
	int m_nDragSelectionVolumeZMax; // 1276
	int m_nDragSelectionVolumeZMin; // 1280
	CNavNode *m_currentNode; // 1284
	int m_generationDir; // 1288 NavDirType
	NavLadderVector m_ladders; // 1292
	int m_generationState; // 1312 GenerationStateType
	int m_generationMode; // 1316 GenerationModeType
	int m_generationIndex; // 1320
	int m_sampleTick; // 1324
	bool m_bQuitWhenFinished; // 1328
	float m_generationStartTime; // 1332
	Extent m_simplifyGenerationExtent; // 1336
	char *m_spawnName; // 1360
	CUTLVECTOR(WalkableSeedSpot) m_walkableSeeds; // 1364
	int m_seedIdx; // 1384
	int m_hostThreadModeRestoreValue; // 1388
	NavAreaVector m_transientAreas; // 1392
	NavAreaVector m_avoidanceObstacleAreas; // 1412
	CUTLVECTOR(INavAvoidanceObstacle) m_avoidanceObstacles; // 1432
	NavAreaVector m_blockedAreas; // 1452
	CUTLVECTOR(int) m_storedSelectedSet; // 1472
	char unknown1492[28]; // 1492
	// */
};

// starts at base + 1524
// total size 1744.
// size 220.
struct TerrorNavMesh_data
{
	// base 1524
	float m_fMapMaxFlowDistance; // 0
	char unknown4[108];
	Checkpoint **m_checkpoints; // 112 nav areas?
	char unknown116[8]; // 116
	int m_iNumCheckpoints; // 124 Checkpoint == saferoom
	char unknown128[92];
};

struct CNavMesh
{
	CNavMesh_vtable *vptr;
	CNavMesh_data CNavMesh;
};

struct TerrorNavMesh
{
	TerrorNavMesh_vtable * vptr; // 0
	CNavMesh_data CNavMesh; // 4
	TerrorNavMesh_data TerrorNavMesh; // 1516
};

#endif // _INCLUDE_NAV_MESH_H_