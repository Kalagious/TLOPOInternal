#pragma once
#include "hooks.h"


class __pypperoni_IMPL_call_funcHook : public Hook
{
public:

	bool initialize();
	__pypperoni_IMPL_call_funcHook(void* moduleBaseIn);
	typedef uint64_t (__fastcall* tTargetPtr)(PyObject*** pStackPointer, int64_t iOpArg, PyObject* pKwargs);
	static uint64_t __fastcall hookFunction(PyObject*** pStackPointer, int64_t iOpArg, PyObject* pKwargs);
	static tTargetPtr oFunction;
};

