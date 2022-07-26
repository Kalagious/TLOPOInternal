#pragma once
#include <vector>
#include <windows.h>
#include <tlHelp32.h>
#include <stdint.h>
#include <tchar.h>
#include <iostream>
#include "general.h"

#pragma warning(disable:26495)
class Function
{
public:
	std::string functionName;
	void* moduleBase;
	void* targetAddr;
	std::vector<uint8_t> viSig;
	int32_t iSigOffset;
	void* signatureScan(std::vector<uint8_t> bpSig, int32_t iOffset, void* pBase);
};
#pragma warning(default:26495)
