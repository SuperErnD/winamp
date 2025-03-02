#ifndef NULLSOFT_UTILITY_THREADNAME_H
#define NULLSOFT_UTILITY_THREADNAME_H

#ifdef _DEBUG
#include <windows.h>

typedef struct tagTHREADNAME_INFO
{
	DWORD dwType; // must be 0x1000
	LPCSTR szName; // pointer to name (in user addr space)
	DWORD dwThreadID; // thread ID (-1=caller thread)
	DWORD dwFlags; // reserved for future use, must be zero
}
THREADNAME_INFO;

__inline void SetThreadName(DWORD dwThreadID, const char *szThreadName)
{
	THREADNAME_INFO info;
	info.dwType = 0x1000;
	info.szName = szThreadName;
	info.dwThreadID = dwThreadID;
	info.dwFlags = 0;

	__try
	{
	    RaiseException( 0x406D1388, 0, sizeof(info) / sizeof(DWORD), (const ULONG_PTR *)&info );
	}
	__except(EXCEPTION_CONTINUE_EXECUTION)
	{}
}

#else
#define SetThreadName(x,y)
#endif

#endif
