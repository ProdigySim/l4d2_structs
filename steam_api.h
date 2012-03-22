#ifndef _INCLUDE_STEAM_API_H_
#define _INCLUDE_STEAM_API_H_


struct CCallbackBase_iface
{
	void * Run; // Run( void * pvParam );
	void * Run2; // Run( void *pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall );
	void * GetCallbackSizeBytes;
};

struct CCallbackBase_data
{
	unsigned char m_nCallbackFlags;
	int m_iCallback;
};

// template< class T, class P, bool bGameServer >
// should be size 20
struct CCallback
{
	CCallbackBase_iface *vptr;
	CCallbackBase_data base;
	void * m_pObj; // T*
	void * m_Func; // Callback function (T::*func_t)( *P )
};

#endif // _INCLUDE_STEAM_API_H_