#ifndef L4D2SDK_TIMERS_H
#define L4D2SDK_TIMERS_H

#include "network_var.h"

struct IntervalTimer {
	NetworkVar_iface *vptr;
	float m_timestamp;
};

struct CountdownTimer {
	NetworkVar_iface *vptr;
	float m_duration;
	float m_timestamp;
};

#endif // L4D2SDK_TIMERS_H
