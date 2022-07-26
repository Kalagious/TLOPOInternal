#include "hookmanager.h"


HookManager::HookManager(void* tlopoExeIn)
{
	tlopoExe = tlopoExeIn;
	testingHook = new TestingHook(tlopoExe);
	pyFunction_NewWithQualNameHook = new PyFunction_NewWithQualNameHook(tlopoExe);
	pyObject_SetAttrHook = new PyObject_SetAttrHook(tlopoExe);
}


void HookManager::InitalizeHooks()
{
	printf(" [*] Initializing Game Hooks:\n");
	if (!testingHook->enabled)
		testingHook->initialize();
	if (!pyFunction_NewWithQualNameHook->enabled)
		pyFunction_NewWithQualNameHook->initialize();
	if (!pyObject_SetAttrHook->enabled)
		pyObject_SetAttrHook->initialize();
	printf(" [*] Hooks Initialized!\n\n");
}


void HookManager::removeAll()
{
	if (testingHook->enabled)
		testingHook->remove();
	if (pyFunction_NewWithQualNameHook->enabled)
		pyFunction_NewWithQualNameHook->remove();
	if (pyObject_SetAttrHook->enabled)
		pyObject_SetAttrHook->remove();
}
