#ifndef _INCLUDE_HANDLE_H_
#define _INCLUDE_HANDLE_H_

struct IHandleEntity_iface
{
	void * SetRefEHandle;
	void * GetRefEHandle;
};

struct CBaseHandle_vtable
{
	void * dtor1;
	void * dtor0;
	IHandleEntity_iface IHandleEntity;
};

struct CHandle
{
	CBaseHandle_vtable * vptr;
	unsigned long m_Index;
};

#endif // _INCLUDE_MISC_H_
