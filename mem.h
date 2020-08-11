#ifndef __MEM_H__
#define __MEM_H__


struct IMemAlloc_iface
{
	//not sure why there is 2 of each in parent fork I thought was CTRL+D mistake
	void * Alloc;
	void * Realloc;
	void * Free;
	void * Expand_NoLongerSupported;
	void * Alloc2;
	void * Realloc2;
	void * Free2;
	void * Expand_NoLongerSupported2;
	void * GetSize;
	void * PushAllocDbgInfo;
	void * PopAllocDbgInfo;
	void * CrtSetBreakAlloc;
	void * CrtSetReportMode;
	void * CrtIsValidHeapPointer;
	void * CrtIsValidPointer;
	void * CrtCheckMemory;
	void * CrtSetDbgFlag;
	void * CrtMemCheckpoint;
	void * DumpStats;
	void * DumpStatsFileBase;
	void * ComputeMemoryUsedBy;
	void * CrtSetReportFile;
	void * CrtSetReportHook;
	void * CrtDbgReport;
	void * heapchk;
	void * IsDebugHeap;
	void * GetActualDbgInfo;
	void * RegisterAllocation;
	void * RegisterDeallocation;
	void * GetVersion;
	void * CompactHeap;
	void * SetAllocFailHandler;
	void * DumpBlockStats;
	void * MemoryAllocFailed;
	void * CompactIncremental;
	void * OutOfMemory;
	void * RegionAlloc;
	void * RegionAlloc2;
	void * GlobalMemoryStatus;
};

struct IMemAlloc
{
	IMemAlloc_iface *vptr;
};

#endif // __MEM_H__