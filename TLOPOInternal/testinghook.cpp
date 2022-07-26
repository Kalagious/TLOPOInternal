#include "testinghook.h"
#include <vector>
#include <string>
#include <sstream>
#include "cheats.h"
#include "GeneralObject.h"


extern Cheats* cheatsGlobal;

TestingHook::tTargetPtr TestingHook::oFunction;


void __fastcall TestingHook::hookFunction(int64_t a1, int64_t a2, int64_t a3)
{
	Object* tmp = (Object*)a1;
	std::string tmpStr;
	if (tmp->iNameLen > 16)
		tmpStr = (char*)tmp->pName;
	else
		tmpStr = (char*)&tmp->pName;
	

	if (!cheatsGlobal->localPlayer && tmpStr.find("Ricardo-") != std::string::npos)
	{
		cheatsGlobal->localPlayer = (Player*)a1;
		
	}

	if ((uint64_t)cheatsGlobal->localPlayer && (Player*)a1 == cheatsGlobal->localPlayer)
	{
		cheatsGlobal->fly->tick();
		//printf("%s  -  %p  -  %p  -  %p\n", tmpStr.c_str(), a1, a2, a3);
	}
	TestingHook::oFunction(a1, a2, a3);
}


TestingHook::TestingHook(void* moduleBaseIn)
{
	hookName = "Testing Hook";
	hookLen = 16;
	viSig = { 0x48, 0x89, 0x5C, 0x24, 0x08, 0x48, 0x89, 0x6C, 0x24, 0x10, 0x48, 0x89, 0x74, 0x24, 0x18, 0x57, 0x48, 0x83, 0xEC, 0x20, 0x48, 0x8B, 0xB1, 0xE0, 0x00, 0x00, 0x00, 0x49, 0x8B, 0xE8, 0x48, 0x8B, 0xFA, 0x48, 0x8B, 0xD9, 0x48, 0x3B, 0xF2 };
	moduleBase = moduleBaseIn;
	iSigOffset = 0;
	enabled = false;
}


bool TestingHook::initialize()
{
	targetAddr = signatureScan(viSig, iSigOffset, moduleBase);
	if (!targetAddr)
		return false;

	TestingHook::oFunction = (tTargetPtr)(targetAddr);
	TestingHook::oFunction = (tTargetPtr)DetourFunction64((void*)TestingHook::oFunction, (void*)TestingHook::hookFunction, hookLen);
	enabled = true;
	return true;
}