#include "function.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <tlHelp32.h>
#include <stdint.h>
#include <tchar.h>
#include <psapi.h>


void* Function::signatureScan(std::vector<uint8_t> bpSig, int32_t iOffset, void* pBase)
{
	if (bpSig.size() <= 0)
	{
		printf("	[!] Sig is empty!\n");
		return NULL;
	}


	MODULEINFO miModule;
	GetModuleInformation(GetCurrentProcess(), (HMODULE)pBase, &miModule, sizeof(miModule));
	uint64_t iModuleSize = miModule.SizeOfImage;

	if (!pBase || !iModuleSize)
	{
		printf(" [!] Error finding module during Sig Scan!\n");
		return NULL;
	}

	void* pCurrRegion = 0;
	void* pCurrRegionEnd = 0;
	MEMORY_BASIC_INFORMATION miMemInfo;
	int32_t iSuccessiveMatches = 0;
	for (uint64_t iBaseOffset = 0; iBaseOffset < iModuleSize; iBaseOffset++)
	{
		if ((uint64_t)pBase + iBaseOffset > (uint64_t)pCurrRegionEnd)
		{
			VirtualQuery((void*)((uint64_t)pBase + iBaseOffset), &miMemInfo, sizeof(miMemInfo));
			if (miMemInfo.State == 0x1000 && miMemInfo.Protect == 0x40)
			{
				pCurrRegion = miMemInfo.BaseAddress;
				pCurrRegionEnd = (void*)((uint64_t)pCurrRegion + miMemInfo.RegionSize);
			}
		}


		if (pCurrRegion < (void*)((uint64_t)pBase + iBaseOffset) && (void*)((uint64_t)pBase + iBaseOffset) < pCurrRegionEnd)
		{

			if (*(uint8_t*)((uint64_t)pBase + iBaseOffset) == bpSig.at(iSuccessiveMatches) || bpSig.at(iSuccessiveMatches) == 0x3F)
				iSuccessiveMatches++;
			else
				iSuccessiveMatches = 0;

			if (iSuccessiveMatches >= bpSig.size())
			{
				printf(" 	[*] Found %s at %p\n", functionName.c_str(), (void*)((uint64_t)pBase + iBaseOffset - bpSig.size() - iOffset + 1));
				return (void*)((uint64_t)pBase + iBaseOffset - bpSig.size() - iOffset + 1);
			}
		}
	}
	return NULL;
}
