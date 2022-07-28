#include "hookmanager.h"

HookManager::HookManager(void* tlopoExeIn)
{
	tlopoExe = tlopoExeIn;
	testingHook = new TestingHook(tlopoExe);
	pyFunction_NewWithQualNameHook = new PyFunction_NewWithQualNameHook(tlopoExe);
	pyObject_SetAttrHook = new PyObject_SetAttrHook(tlopoExe);
	pyDict_SetItemHook = new PyDict_SetItemHook(tlopoExe);
	pypperoni_IMPL_call_funcHook = new __pypperoni_IMPL_call_funcHook(tlopoExe);
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
	if (!pyDict_SetItemHook->enabled)
		pyDict_SetItemHook->initialize();
	if (!pypperoni_IMPL_call_funcHook->enabled)
		pypperoni_IMPL_call_funcHook->initialize();
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
	if (pyDict_SetItemHook->enabled)
		pyDict_SetItemHook->remove();
	if (pypperoni_IMPL_call_funcHook->enabled)
		pypperoni_IMPL_call_funcHook->remove();

	Sleep(10);
}
