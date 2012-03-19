//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: Shared util code between client and server.
//
//=============================================================================//

#ifndef L4D2SDK_TIMERS_H
#define L4D2SDK_TIMERS_H

struct IntervalTimer {
	void * vtableptr; // Because hl2sdk's timers don't use the networkvar magic
	float m_timestamp;
};


//--------------------------------------------------------------------------------------------------------------
/**
 * Simple class for counting down a short interval of time.
 * Upon creation, the timer is invalidated.  Invalidated countdown timers are considered to have elapsed.
 */
struct CountdownTimer {
	void * vtableptr; // Because hl2sdk's timers don't use the networkvar magic
	float m_duration;
	float m_timestamp;
};

#endif // L4D2SDK_TIMERS_H
