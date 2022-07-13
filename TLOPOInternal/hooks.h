#pragma once
#include <vector>
#include <windows.h>
#include <tlHelp32.h>
#include <stdint.h>
#include <tchar.h>
#include <iostream>
#include "HookOffsets.h"

#pragma warning(disable:26495)
class Hook
{
public:
	std::string hookName;
	uint32_t hookLen;
	void* moduleBase;
	void* targetAddr;
	void* trampAddr;
	uint32_t stolenBytes[30];
	bool enabled;

	/*bool detour32(uintptr_t src, uintptr_t dst, uint32_t len);
	uintptr_t trampoline32(uintptr_t src, uintptr_t dst, uint32_t len);*/
	void* DetourFunction64(void* pSource, void* pDestination, int dwLen);

	bool remove();
	void PrintHookPrompt();
};
#pragma warning(default:26495)
