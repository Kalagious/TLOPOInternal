#include "hookmanager.h"


HookManager::HookManager(void* tlopoExeIn)
{
	tlopoExe = tlopoExeIn;
	testingHook = new TestingHook(tlopoExe);
}


void HookManager::InitalizeHooks()
{
	printf(" [*] Initializing Game Hooks:\n");
	if (!testingHook->enabled)
		testingHook->initialize();
	printf(" [*] Hooks Initialized!\n\n");
}


void HookManager::removeAll()
{
	if (testingHook->enabled)
		testingHook->remove();
}