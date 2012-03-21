#ifndef _INCLUDE_NETWORKVAR_H_
#define _INCLUDE_NETWORKVAR_H_

struct NetworkVar_iface
{
	void * NetworkStateChanged; // NetworkStateChanged(void);
	void * NetworkStateChanged2; // NetworkStateChanged(void *pVar);
};


#endif // _INCLUDE_NETWORKVAR_H_

