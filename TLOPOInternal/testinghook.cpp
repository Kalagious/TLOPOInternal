#include "testinghook.h"
#include <vector>
#include <string>
#include <sstream>
#include "cheats.h"


extern Cheats* cheatsGlobal;

TestingHook::tTargetPtr TestingHook::oFunction;


void __fastcall TestingHook::hookFunction(int64_t a1, int64_t a2, int64_t a3)
{
	printf("This->%p  A3->%p\n", a1, a3);



	//if (a1 == (uint64_t)cheatsGlobal->localPlayer)
	//{

	//	cheatsGlobal->speed->tick();
	//}
	TestingHook::oFunction(a1, a2, a3);
}



TestingHook::TestingHook(void* moduleBaseIn)
{
	hookName = "Testing Hook";
	hookLen = 16;
	moduleBase = moduleBaseIn;
	targetAddr = (void*)((uint64_t)moduleBase + testingHookOffset);
	enabled = false;
	TestingHook::oFunction = (tTargetPtr)(targetAddr);
}


bool TestingHook::initialize()
{
	PrintHookPrompt();
	TestingHook::oFunction = (tTargetPtr)DetourFunction64((void*)TestingHook::oFunction, (void*)TestingHook::hookFunction, hookLen);
	enabled = true;
	return true;
}