// Copyright (C) 1999-2000 Id Software, Inc.
//

//===========================================================================
//
// Name:         l_memory.c
// Function:     memory management
// Programmer:   Mr Elusive
// Last update:  1997-12-16
// Tab Size:     3
//===========================================================================

#include <malloc.h>
#include "qcc.h"
#include "l_log.h"


/*
=================
MemorySize
=================
*/
int MemorySize(void *ptr)
{
#ifdef __WATCOMC__
	//Intel 32 bits memory addressing, 16 bytes aligned
	return (_msize(ptr) + 15) >> 4 << 4;
#else
 #ifndef LCC
	return _msize(ptr);
 #endif
#endif
} //end of the function MemorySize

/*
=================
GetClearedMemory
=================
*/
void *GetClearedMemory(int size)
{
	void *ptr;

	ptr = (void *) malloc(size);
	if (!ptr) Error("out of memory");
	memset(ptr, 0, size);
	return ptr;
} //end of the function GetClearedMemory

/*
=================
GetMemory
=================
*/
void *GetMemory(unsigned long size)
{
	void *ptr;
	ptr = malloc(size);
	if (!ptr)
		Error("out of memory");
	return ptr;
} //end of the function GetMemory

/*
=================
FreeMemory
=================
*/
void FreeMemory(void *ptr)
{
	free(ptr);
} //end of the function FreeMemory

/*
=================
PrintMemorySize
=================
*/
void PrintMemorySize(unsigned long size)
{
	unsigned long number1, number2, number3;
	number1 = size >> 20;
	number2 = (size & 0xFFFFF) >> 10;
	number3 = (size & 0x3FF);
	if (number1) Log_Print("%ld MB", number1);
	if (number2) Log_Print(" and %ld KB", number2);
	if (number3) Log_Print(" and %ld bytes", number3);
} //end of the function PrintFileSize

