#ifndef _INCLUDE_CGLOWPROPERTY_H_
#define _INCLUDE_CGLOWPROPERTY_H_

struct CGlowProperty //size 17 lux
{
	CGlowProperty_vtable * vptr; //0
	int m_iGlowType; //4
	float m_nGlowRange; //8
	float m_nGlowRangeMin; //12
	int m_glowColorOverride; //16
	unsigned char m_bFlashing; //17
};

struct CGlowProperty_vtable
{
	void * NetworkStateChanged; //0
	void * GetDataDescMap; //4
};

#endif //_INCLUDE_CGLOWPROPERTY_H_