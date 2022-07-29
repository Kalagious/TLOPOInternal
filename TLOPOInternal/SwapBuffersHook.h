#pragma once
#include "hooks.h"


class SwapBuffersHook : public Hook
{
public:

	bool initialize();
	SwapBuffersHook(void* moduleBaseIn);
	typedef int64_t(__fastcall* tTargetPtr)(int64_t a1);
	static int64_t __fastcall hookFunction(int64_t a1);
	static tTargetPtr oFunction;
};

