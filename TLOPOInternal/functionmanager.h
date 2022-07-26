#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include <tlHelp32.h>
#include <stdint.h>
#include <tchar.h>
#include "PyMarshal_ReadObjectFromString.h"

class FunctionManager
{
public:

	FunctionManager(void* tlopoExeIn);
	void scanFunctions();

	void* tlopoExe;
	PyMarshal_ReadObjectFromStringG* pyMarshal_ReadObjectFromString;
};