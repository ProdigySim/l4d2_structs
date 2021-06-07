#ifndef _INCLUDE_ZOMBIE_MANAGER_H_
#define _INCLUDE_ZOMBIE_MANAGER_H_

#include "timers.h"

enum PreferredMobDirection
{
    SPAWN_NO_PREFERENCE = -1,
    SPAWN_ANYWHERE = 0,
    SPAWN_BEHIND_SURVIVORS = 1,
    SPAWN_NEAR_IT_VICTIM = 2,
    SPAWN_FAR_AWAY_FROM_SURVIVORS = 5,
    SPAWN_ABOVE_SURVIVORS = 6,
    SPAWN_IN_FRONT_OF_SURVIVORS = 7,
    SPAWN_LARGE_VOLUME = 9
};

struct ZombieManager_UnknownStruct // 0x14, I guess it can be NavArea or CTerrorNavArea
{
    int m_iUnknown[5];
};

struct ZombieManager
{
    void *vptr; // 0x0, virtual destructor only
    bool unknown[4]; // 0x4, first two bytes are used 
    int m_nFallenSurvivors; // 0x8
    CountdownTimer m_FallenSurvivorTimer; // 0xC - 0x14
    bool m_bJimmyTimerExpired; // 0x18
    CountdownTimer m_JimmyTimer; // 0x1C - 0x24
    char unknown40[4]; // 0x28
    int m_iUnknown44; // 0x2C
    CountdownTimer m_MegaMobTimer; // 0x30 - 0x38
    char unknown60[52]; // 0x3C - 0x6C
    ZombieManager_UnknownStruct m_unknownStruct[11]; // 0x70 - 0x138
    CountdownTimer m_unknownTimer332[11]; // 0x14C - 0x1C4
    int m_iUnknown464[10]; // 0x1D0 - 0x1F4
    CountdownTimer m_unknownTimer504; // 0x1F8 - 0x200
    CountdownTimer m_unknownTimer516; // 0x204 - 0x20C
    int m_nPendingMobCount; // 0x210
    PreferredMobDirection m_PreferredMobDirection; // 0x214
    int m_PreferredMobPosition; // 0x218
    int m_PreferredMobPositionRange; // 0x21C
    int m_iUnknown544; // 0x220
    int m_iUnknown548; // 0x224
    CountdownTimer m_unknownTimer552; // 0x228 - 0x230
    int m_nAmbientMobCount; // 0x234
    int m_nAmbientMobUnknown; // 0x238
    int m_iUnknown572[16]; // 0x23C - 0x278
    char unknown636[12]; // 0x27C
    char unknown648[4]; // 0x288
    int m_iUnknown652; // 0x28C
};

#endif
