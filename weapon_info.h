#ifndef _INCLUDE_WEAPON_INFO_H_
#define _INCLUDE_WEAPON_INFO_H_
#include "util.h"

struct CMeleeWeaponInfo {
	void * vptr;
	float m_fRefireDelay;
	char m_aViewModel[80];
	char m_aPlayerModel[80];
	char m_aAddonAttachment[80];
	float m_vAddonOffest[3]; 
	float  m_vAddonAngles[3]; 
	char m_aAnimPrefix[16];
	float m_fDamage;
	int m_iDamageFlags;
	int m_iRumbleEffect;
	bool m_bDecapitates;
	char m_aActivityIdle[80];
	char m_aActivityWalk[80];
	char m_aActivityRun[80];
	char m_aActivityCrouchIdle[80];
	char m_aActivityCrouchWalk[80];
	char m_aActivityCrouchWalk2[80]; // possibly run + walk animations
	char m_aActivityIdleInjured[80];
	char m_aActivityWalkInjured[80];
	char m_aActivityRunInjured[80];
	char m_aActivityIdleCalm[80];
	char m_aActivityWalkCalm[80];
	char m_aActivityRunCalm[80];
	char m_aActivityJump[80];
	char m_aActivityDeploy[80];
	char m_aActivityShove[80];
	char SoundData[20][80]; // 1501
	// 3101: 3 bytes should be padding 
	CUTLVECTOR(char *) PrimaryAttacks; //3104  char[48]
	CUTLVECTOR(char *) SecondaryAttacks; //3124  char[48]
	int m_iPlayerAnimEvent; // 3144
	float m_fWeaponIdleTime; // 3148
	char src[80]; // 3152 name of the melee weapon
};


#endif