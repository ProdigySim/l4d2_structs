#ifndef _INCLUDE_ABILITIES_H_
#define _INCLUDE_ABILITIES_H_

#include "terror_player.h"

struct CBaseAbility_iface
{
	void * OnOwnerLeaveActiveState;
	void * OnOwnerLeaveActiveState; // OnOwnerLeaveActiveState(void)
	void * OnOwnerChanged; // OnOwnerChanged(CTerrorPlayer *)
	void * IsAbilityReadyToFire; // IsAbilityReadyToFire(void)const
	void * ActivateAbility; // ActivateAbility(void)
	void * UpdateAbility; // UpdateAbility(void)
	void * OnCreate; // OnCreate(CTerrorPlayer *)
	void * HasAbilityTarget; // HasAbilityTarget(void)const
	void * SetSupressionTimer; // SetSupressionTimer(float)
	void * GetActivationTimeRemaining; // GetActivationTimeRemaining(void)const
	void * GetButton; // GetButton(void)const
	void * OnButtonPressed; // OnButtonPressed(void)
	void * OnButtonReleased; // OnButtonReleased(void)
	void * IsActive; // IsActive(void)const
	void * IsPredicted; // IsPredicted(void)const
	void * GetJumpVector; // GetJumpVector(bool)
	void * OnTouch; // OnTouch(CBaseEntity *)
	void * OnCrouched; // OnCrouched(void)
	void * OnCrouchStart; // OnCrouchStart(void)
	void * GetSpeedOverride; // GetSpeedOverride(void)const
	void * GetMaxSpeedOverride; // GetMaxSpeedOverride(void)const
	void * GetFrictionMultiplier; // GetFrictionMultiplier(void)const
	void * CanPlayerMove; // CanPlayerMove(void)const
	void * OnOwnerTakeDamage; // OnOwnerTakeDamage(CTakeDamageInfo  const&)
	void * Operator_HandleAnimEvent; // Operator_HandleAnimEvent(animevent_t *,CBaseCombatCharacter *)
	void * OnStunned; // OnStunned(float)
	void * HandleCustomCollision; // HandleCustomCollision(CBaseEntity *,Vector  const&,Vector  const&,CGameTrace *,CMoveData *)
	void * OnDestroy; // OnDestroy(void)
	void * AbilityDebug; // AbilityDebug(char  const*,...)
	void * AbilityDebug; // AbilityDebug(CTerrorPlayer *,char  const*,...)
};

struct CBaseAbility_vtable {
	void * dtor1; // 0
	void * dtor0; // 4
	IHandleEntity_iface IHandleEntity; // 8
	IServerUnknown_iface IServerUnknown; // 16
	IServerEntity_iface IServerEntity; // 28
	CBaseEntity_iface CBaseEntity; // 40
	CBaseAbility_iface CBaseAbility;
};


struct CBaseAbility_data
{
	char unknown1072[16];
	CountdownTimer m_activationSupressedTimer; // 1088
	int m_owner; // 1100 set to -1 in constructor
	CountdownTimer _m_nextActivationTimer; // 1104
	bool m_hasBeenUsed; // 1116
}; //1120

struct CCharge_data
{
	int m_chargeStartTime; // 1120
	bool m_isCharging; // 1124
	int m_unknown1128;
	float m_initialVelocity[3]; //1132
	float m_initialOrigin[3]; // 1144
	CountdownTimer m_unknownTimer1156;
	CountdownTimer m_unknownTimer1168; // set to 0.1 in begincharge
	bool m_hitSurvivors[8]; // 1180
	bool m_Unknown1188; // 1188
	float m_carryStartVelocity[3]; // 1192
};

struct CBaseAbility
{
	CBaseAbility_vtable *vptr;
	CBaseEntity_data CBaseEntity; // 4
	CBaseAbility_data CBaseAbility; // 1072
};

struct CCharge
{
	CBaseAbility_vtable *vptr;
	CBaseEntity_data CBaseEntity; // 4
	CBaseAbility_data CBaseAbility; // 1072
	CCharge_data CCharge;
};

#endif // _INCLUDE_ABILITIES_H_