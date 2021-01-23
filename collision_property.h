#ifndef _INCLUDE_CCOLLISIONPROPERTY_H_
#define _INCLUDE_CCOLLISIONPROPERTY_H_


struct CCollisionProperty_vtable
{
	void * GetEntityHandle; //0
	void * OBBMins; //4
	void * OBBMaxs; //8
	void * WorldSpaceTriggerBounds; //12
	void * TestCollision; //16
	void * TestHitboxes; //20
	void * GetCollisionModelIndex; //24
	void * GetCollisionModel; //28
	void * GetCollisionOrigin; //32
	void * GetCollisionAngles; //36
	void * CollisionToWorldTransform; //40
	void * GetSolid; //44
	void * GetSolidFlags; //48
	void * GetIClientUnknown; //52
	void * GetCollisionGroup; //56
	void * WorldSpaceSurroundingBounds; //60
	void * ShouldTouchTrigger; //64
	void * GetRootParentToWorldTransform; //68
	void * GetVPhysicsObject; //72
	void * NetworkStateChanged; //76
	void * GetDataDescMap; //80
	void * GetPhysics2Actor; //84
	void * GetPhysics2ActorCount; //88
	void * GetBoundingRadius; //92
};

struct CCollisionProperty //size 92 lux
{
	CCollisionProperty_vtable * vptr; //0
	char *m_pOuter; //4
	float m_vecMins[3]; //8
	float m_vecMaxs[3]; //20
	short m_usSolidFlags; //32
	unsigned char m_nSolidType; //34
	unsigned char m_triggerBloat; //35
	float m_flRadius; //36
	char padding40[2]; //40
	unsigned char m_nSurroundType; //42
	unsigned char unknown43; //43
	float m_vecSpecifiedSurroundingMins[3]; //44
	float m_vecSpecifiedSurroundingMaxs[3]; //56
	float m_vecSurroundingMins[3]; //68
	float m_vecSurroundingMaxs[3]; //80
};

#endif //_INCLUDE_CCOLLISIONPROPERTY_H_