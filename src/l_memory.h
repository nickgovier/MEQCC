// Copyright (C) 1999-2000 Id Software, Inc.
//

//===========================================================================
//
// Name:         l_memory.h
// Function:     memory management
// Programmer:   Mr Elusive
// Last update:  1997-12-16
// Tab Size:     3
//===========================================================================

void *GetClearedMemory(int size);
void *GetMemory(unsigned long size);
void FreeMemory(void *ptr);
int MemorySize(void *ptr);
void PrintMemorySize(unsigned long size);

