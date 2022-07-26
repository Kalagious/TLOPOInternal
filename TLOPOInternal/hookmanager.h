#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include <tlHelp32.h>
#include <stdint.h>
#include <tchar.h>
#include "testinghook.h"
#include "PyFunction_NewWithQualNameHook.h"
#include "PyObject_SetAttrHook.h"

class HookManager
{
public:

	//SetClientViewAnglesHook* setClientViewAnglesHook;
	HookManager(void* tlopoExeIn);
	void removeAll();
	void InitalizeHooks();
	TestingHook* testingHook;
	PyFunction_NewWithQualNameHook* pyFunction_NewWithQualNameHook;
	PyObject_SetAttrHook* pyObject_SetAttrHook;
	void* tlopoExe;

};