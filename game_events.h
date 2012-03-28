#ifndef _INCLUDE_GAME_EVENTS_H_
#define _INCLUDE_GAME_EVENTS_H_

struct IGameEventListener2_iface
{
	void * FireGameEvent;
	void * GetEventDebugID;
};

#endif // _INCLUDE_GAME_EVENTS_H_