#ifndef _INCLUDE_GAME_EVENTS_H_
#define _INCLUDE_GAME_EVENTS_H_

struct IGameEventListener2_iface
{
	void * FireGameEvent;
	void * GetEventDebugID;
};

struct IEventRegisterCallback_iface
{
	void * FireEvent;
};

struct IEventRegisterCallback
{
	IEventRegisterCallback_iface *vptr;
};

struct CEventRegister
{
	void *m_pEventMgr; // CTimedEventMgr
	float m_flNextEventTime;
	float m_flUpdateInterval;
	IEventRegisterCallback *m_pCallback;
	bool m_bRegistered;
};
#endif // _INCLUDE_GAME_EVENTS_H_