#include "Hooks.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <tlHelp32.h>
#include <stdint.h>
#include <tchar.h>


//bool Hook::detour32(uintptr_t src, uintptr_t dst, uint32_t len)
//{
//	if (len < 5) return false;
//
//	DWORD oldProtect;
//	VirtualProtect((BYTE*)src, len, PAGE_EXECUTE_READWRITE, &oldProtect);
//
//	uintptr_t relativeAddress = dst - src - 5;
//
//	// Save the original stolen bytes to be later replaced
//	memcpy(stolenBytes, (BYTE*)src, len);
//
//	memset((BYTE*)src, 0x90, len);
//
//
//	*(uintptr_t*)src = 0xE9;
//	*(uintptr_t*)(src + 1) = relativeAddress;
//
//
//	VirtualProtect((BYTE*)src, len, oldProtect, &oldProtect);
//	return true;
//}

void Hook::PrintHookPrompt()
{
	printf("	Hooking %s\n", hookName.c_str());
}


//uintptr_t Hook::trampoline32(uintptr_t src, uintptr_t dst, uint32_t len)
//{
//	if (len < 5) return NULL;
//	uintptr_t gatewayAddr = (uintptr_t)VirtualAlloc(NULL, len, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
//
//	if (!gatewayAddr)
//	{
//		printf(" [!] Error allocating gateway\n");
//		return false;
//	}
//
//	DWORD oldProtect;
//	VirtualProtect((BYTE*)src, len, PAGE_EXECUTE_READWRITE, &oldProtect);
//	memcpy((BYTE*)gatewayAddr, (BYTE*)src, len);
//	VirtualProtect((BYTE*)src, len, oldProtect, &oldProtect);
//
//	uintptr_t relativeAddrFrGatewayToSrc = (uintptr_t)(src - 5) - gatewayAddr;
//
//	*(uintptr_t*)(gatewayAddr + len) = 0xE9;
//	*(uintptr_t*)(gatewayAddr + len + 1) = relativeAddrFrGatewayToSrc;
//
//	detour32(src, dst, len);
//
//	trampAddr = gatewayAddr;
//
//	return gatewayAddr;
//}



bool Hook::remove()
{
	printf(" [*] Unhooking %s at %#8X\n", hookName.c_str(), targetAddr);
	DWORD oldProtect;
	VirtualProtect((BYTE*)targetAddr, hookLen, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy((BYTE*)targetAddr, stolenBytes, hookLen);
	VirtualProtect((BYTE*)targetAddr, hookLen, oldProtect, &oldProtect);
	enabled = false;
	return true;
}



void* Hook::DetourFunction64(void* pSource, void* pDestination, int dwLen)
{
	DWORD MinLen = 14;

	if (dwLen < MinLen) return NULL;

	BYTE stub[] = {
	0xFF, 0x25, 0x00, 0x00, 0x00, 0x00, // jmp qword ptr [$+6]
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 // ptr
	};

	void* pTrampoline = VirtualAlloc(0, dwLen + sizeof(stub), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

	DWORD dwOld = 0;
	VirtualProtect(pSource, dwLen, PAGE_EXECUTE_READWRITE, &dwOld);
	memcpy(stolenBytes, (BYTE*)pSource, dwLen);


	DWORD64 retto = (DWORD64)pSource + dwLen;

	// trampoline
	memcpy(stub + 6, &retto, 8);
	memcpy((void*)((DWORD_PTR)pTrampoline), pSource, dwLen);
	memcpy((void*)((DWORD_PTR)pTrampoline + dwLen), stub, sizeof(stub));

	// orig
	memcpy(stub + 6, &pDestination, 8);
	memcpy(pSource, stub, sizeof(stub));

	for (int i = MinLen; i < dwLen; i++)
	{
		*(BYTE*)((DWORD_PTR)pSource + i) = 0x90;
	}

	VirtualProtect(pSource, dwLen, dwOld, &dwOld);
	return (void*)((DWORD_PTR)pTrampoline);
}