#ifndef _UTIL_H_
#define _UTIL_H_


struct CUtlMemory
{
	void * m_pMemory;
	int m_nAllocationCount;
	int m_nGrowSize;
};

struct CUtlMemoryConservative
{
	void * m_pMemory;
	#ifdef PLATFORM_LINUX
	unsigned int m_nCurAllocSize;
	#endif
};

#endif // _UTIL_H_