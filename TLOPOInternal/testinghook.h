#pragma once
#include "hooks.h"


class TestingHook : public Hook
{
public:

	bool initialize();
	TestingHook(void* moduleBaseIn);
	typedef void(__fastcall* tTargetPtr)(int64_t a1, int64_t a2, int64_t a3);
	static void __fastcall hookFunction(int64_t a1, int64_t a2, int64_t a3);
	static tTargetPtr oFunction;
};

