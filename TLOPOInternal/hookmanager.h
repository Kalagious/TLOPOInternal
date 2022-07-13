#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include <tlHelp32.h>
#include <stdint.h>
#include <tchar.h>
#include "testinghook.h"
//#include "setclientviewangleshook.h"

class HookManager
{
public:

	//SetClientViewAnglesHook* setClientViewAnglesHook;
	HookManager(void* tlopoExeIn);
	void removeAll();
	void InitalizeHooks();
	TestingHook* testingHook;

	void* tlopoExe;

};