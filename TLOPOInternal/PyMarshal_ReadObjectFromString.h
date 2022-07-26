#pragma once
#include "function.h"


class PyMarshal_ReadObjectFromStringG : public Function
{
public:
	PyMarshal_ReadObjectFromStringG(void* moduleBaseIn);
	bool scanFunction();
	typedef int64_t(__fastcall* tTargetPtr)(int64_t a1, int64_t a2, int64_t a3);
	static tTargetPtr oFunction;
};

