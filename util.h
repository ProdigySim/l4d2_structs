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

#define CUTLMEMORY_FULL(T,I) struct \
	{\
		T * m_pMemory;\
		I m_nAllocationCount;\
		I m_nGrowSize;\
	}

#define CUTLMEMORY(T) CUTLMEMORY_FULL( T , int )

#define CUTLMEMORYFIXEDGROWABLE_FULL(T,SIZE,I) struct \
	{\
		CUTLMEMORY_FULL( T , I ) CUtlMemory;\
		int m_nMallocGrowSize;\
		T m_pFixedMemory[ SIZE ];\
	}

#define CUTLMEMORYFIXEDGROWABLE(T,SIZE) CUTLMEMORYFIXEDGROWABLE_FULL( T , SIZE , int )

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

#define CUTLVECTORFIXEDGROWABLE(type,size) CUTLVECTOR_FULL( type , CUTLMEMORYFIXEDGROWABLE( type , size ))

#define CUTLRBTREELINKS(I) struct \
	{\
		I m_Left;\
		I m_Right;\
		I m_Parent;\
		I m_Tag;\
	}

#define CUTLRBTREENODE(T,I) struct \
	{\
		CUTLRBTREELINKS( I ) m_Links;\
		T m_Data;\
	}

#define CUTLRBTREE_FULL(T,I,L,M) struct \
	{\
		L m_LessFunc;\
		M m_Elements;\
		I m_Root;\
		I m_NumElements;\
		I m_FirstFree;\
		I m_LastAlloc;\
		CUTLRBTREENODE( T , I ) *m_pElements;\
	}

#define CUTLRBTREE(T,I) CUTLRBTREE_FULL( T , I , void * , CUTLMEMORY( T ) )

#endif // _UTIL_H_