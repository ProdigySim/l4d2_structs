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

#define CUTLMEMORY(type) struct \
	{\
		type * m_pMemory;\
		int m_nAllocationCount;\
		int m_nGrowSize;\
	}
	
#ifdef PLATFORM_LINUX
#define CUTLMEMORYCONSERVATIVE(type) struct \
	{\
		type * m_pMemory;\
		unsigned int m_nCurAllocSize;\
	}
#else
#define CUTLMEMORYCONSERVATIVE(type) struct \
	{\
		type * m_pMemory;\
	}
#endif

#define DECLARE_CUTLVECTOR_FULL(name,type,allocator) struct name \
	{\
		allocator m_memory;\
		int m_Size;\
		type * m_pElements;\
	}

#define DECLARE_CUTLVECTOR(name,type) DECLARE_CUTLVECTOR_FULL( name , type , CUTLMEMORY( type ) )

#define CUTLVECTOR_FULL(type,allocator) struct \
	{\
		allocator m_memory;\
		int m_Size;\
		type * m_pElements;\
	}

#define CUTLVECTOR(type) CUTLVECTOR_FULL( type , CUTLMEMORY( type ) )
	
#endif // _UTIL_H_