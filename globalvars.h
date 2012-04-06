#ifndef _INCLUDE_GLOBALVARS_H_
#define _INCLUDE_GLOBALVARS_H_

struct CGlobalVarsBase
{
	float realtime;
	int framecount;
	float absoluteframetime;
	float curtime;
	float frametime;
	int maxClients;
	int tickcount;
	float interval_per_tick;
	float interpolation_amount;
	int simTicksThisFrame;
	int network_protocol;
	void *pSaveData; // CSaveRestoreData *
	bool m_bClient;
	int nTimestampNetworkingBase;
	int nTimestampRandomizeWindow;
};

enum MapLoadType_t
{
	MapLoad_NewGame = 0,
	MapLoad_LoadGame,
	MapLoad_Transition,
	MapLoad_Background,
};

struct CGlobalVars
{
	CGlobalVarsBase base;
	char * mapname;
	int mapversion;
	char * startspot;
	MapLoadType_t eLoadType;
	bool bMapLoadFailed;
	bool deathmatch;
	bool coop;
	bool teamplay;
	int maxEntities;
	int serverCount;
	void *pEdicts; // edict_t *
};

#endif // _INCLUDE_GLOBALVARS_H_