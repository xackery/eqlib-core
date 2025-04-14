#pragma once
#include <windows.h>

#include "_options.h"
#include "eqlib.h"
#include "eqlib/eqgame.h"
#include "gamma.h"
#include <mq/base/Detours.h>

uintptr_t fdebug_addr = FixEQGameOffset(0x808E50);
FUNCTION_AT_ADDRESS(void, fdebug(const char*, ...), fdebug_addr);

// Debugf accepts a formatted string and does not add a newline
// Debugf writes echos to an attached debugger, and not to dbg.txt
void Debugf(const char* fmt, ...)
{
    char prefixedFmt[1024];
    snprintf(prefixedFmt, sizeof(prefixedFmt), "%s %s", OptionServerPrefix.c_str(), fmt);
    va_list args;
    va_start(args, fmt);
    OutputDebugStringA(prefixedFmt);
    va_end(args);
}

// Debugln accepts a string and adds a newline
// Debugln writes echos to an attached debugger, and not to dbg.txt
void Debugln(const char* msg)
{
	char prefixedFmt[1024];
	snprintf(prefixedFmt, sizeof(prefixedFmt), "%s %s\n", OptionServerPrefix.c_str(), msg);
	OutputDebugStringA(prefixedFmt);
}

// Printf accepts a formatted string and does not add a newline
// Printf writes to an attached debugger and to dbg.txt
void Printf(const char* fmt, ...)
{
    char prefixedFmt[1024];
    snprintf(prefixedFmt, sizeof(prefixedFmt), "%s %s", OptionServerPrefix.c_str(), fmt);
    va_list args;
    va_start(args, fmt);
    fdebug(prefixedFmt, args);
    OutputDebugStringA(prefixedFmt);
    va_end(args);
}

// Println accepts a string and adds a newline
// Println writes to an attached debugger and to dbg.txt
void Println(const char* msg)
{
	char prefixedFmt[1024];
	snprintf(prefixedFmt, sizeof(prefixedFmt), "%s %s\n", OptionServerPrefix.c_str(), msg);
	fdebug(prefixedFmt);
	OutputDebugStringA(prefixedFmt);
}