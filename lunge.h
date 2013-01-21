#ifndef _INCLUDE_LUNGE_H_
#define _INCLUDE_LUNGE_H_

#include "handle.h"
#include "timers.h"
#include "terror_player.h"

// base offset 1072
// size 36?
struct CBaseAbility_data
{
	char unknown[36];
};


// 1108 to 1148
struct CLunge_data
{
	CountdownTimer m_lungeAgainTimer; // 1108
	float m_fLungeStartTime; // 1120
	float m_LungeStartVector[3]; // 1124
	bool m_bLunging; // 1136
	bool m_bLungeBlocked; // 1137
	char unknown1138[2]; // 1138
	CountdownTimer m_unknownTimer; // 1140
};

struct CBaseAbility;
struct CBaseAbility_iface
{
	void (* OnOwnerLeaveActiveState)(CBaseAbility *);
	void (* OnOwnerChanged)(CBaseAbility *, CTerrorPlayer *);
	void (* IsAbilityReadyToFire)(CBaseAbility *); /* const */
	void (* ActivateAbility)(CBaseAbility *);
	void (* UpdateAbility)(CBaseAbility *);
	void (* OnCreate)(CBaseAbility *, CTerrorPlayer *);
	void (* HasAbilityTarget)(CBaseAbility *); /* const */
	void (* SetSupressionTimer)(CBaseAbility *, float);
	void (* GetActivationTimeRemaining)(CBaseAbility *); /* const */
	void (* GetButton)(CBaseAbility *); /* const */
	void (* OnButtonPressed)(CBaseAbility *);
	void (* OnButtonReleased)(CBaseAbility *);
	void (* IsActive)(CBaseAbility *); /* const */
	void (* IsPredicted)(CBaseAbility *); /* const */
	void (* GetJumpVector)(CBaseAbility *, bool);
	void (* OnTouch)(CBaseAbility *, CBaseEntity *);
	void (* OnCrouched)(CBaseAbility *);
	void (* OnCrouchStart)(CBaseAbility *);
	void (* GetSpeedOverride)(CBaseAbility *); /* const */
	void (* GetMaxSpeedOverride)(CBaseAbility *); /* const */
	void (* GetFrictionMultiplier)(CBaseAbility *); /* const */
	void (* CanPlayerMove)(CBaseAbility *); /* const */
	void (* OnOwnerTakeDamage)(CBaseAbility *, CTakeDamageInfo *);
	void (* Operator_HandleAnimEvent)(CBaseAbility *, void *,CBaseCombatCharacter *);
	void (* OnStunned)(CBaseAbility *, float);
	void (* HandleCustomCollision)(CBaseAbility *, CBaseEntity *,float[3],float[3],void *,void *);
	void (* OnDestroy)(CBaseAbility *);
	void (* AbilityDebug)(CBaseAbility *, char const*,...);
	void (* AbilityDebug)(CBaseAbility *, CTerrorPlayer *,char const*,...);
};

struct CBaseAbility
{
	CBaseAbility_iface *vptr;
	CBaseEntity_data CBaseEntity;
	CBaseAbility_data CBaseAbility;
};

struct CLunge
{
	CBaseAbility_iface *vptr;
	CBaseEntity_data CBaseEntity;
	CBaseAbility_data CBaseAbility;
	CLunge_data CLunge;
};

#endif // _INCLUDE_LUNGE_H_
