#ifndef _INCLUDE_NETWORKVAR_H_
#define _INCLUDE_NETWORKVAR_H_

struct NetworkVar;

#include "game_events.h"
#include "terror_player.h"



struct NetworkVar_iface
{
	void (* NetworkStateChanged)(NetworkVar*); // NetworkStateChanged(void);
	void (* NetworkStateChanged2)(NetworkVar*, void *); // NetworkStateChanged(void *pVar);
};

struct NetworkVar
{
	NetworkVar_iface * vptr;
};

struct IServerNetworkable_iface
{
	void * GetEntityHandle;
	void * GetServerClass;
	void * GetEdict;
	void * GetClassName;
	void * Release;
	void * AreaNum;
	void * GetBaseNetworkable;
	void * GetBaseEntity;
	void * GetPVSInfo;
	void * dtor;
};

struct CServerNetworkProperty_vtable1
{
	IServerNetworkable_iface IServerNetworkable;
	void * dtor;
	void * GetDataDescMap;
};
struct CServerNetworkProperty_vtable2
{
	IEventRegisterCallback_iface IEventRegisterCallback;
};

struct PVSInfo_t
{
	short m_nHeadNode;
	short m_nClusterCount;
	unsigned short *m_pClusters;
	short m_nAreaNum;
	short m_nAreaNum2;
	float m_vCenter[3];
	unsigned short m_pClustersInline[4];
};

struct CBaseEntity;
// 77
struct CServerNetworkProperty
{
	CServerNetworkProperty_vtable1 *vptr1;
	CServerNetworkProperty_vtable2 *vptr2;
	CBaseEntity *m_pOuter;
	void *m_pPrev; // edict_t
	PVSInfo_t m_PVSInfo;
	void *m_pServerClass; // ServerClass *
	int m_hParent; // EHANDLE
	CEventRegister m_TimerEvent;
	bool m_bPendingStateChange; // 76 bitfield 1
};


#endif // _INCLUDE_NETWORKVAR_H_

