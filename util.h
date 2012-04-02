#ifndef _UTIL_H_
#define _UTIL_H_


struct CUtlMemory
{
	void * m_pMemory;
	int m_nAllocationCount;
	int m_nGrowSize;
};

#endif // _UTIL_H_