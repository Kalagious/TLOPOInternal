#pragma once
#include "general.h"

class Cheats;

class RogueFloat
{
public:
	uint64_t iRefCnt;
	void* PyType;
	uint32_t padding;
	float fValue;
};

class RoguePython
{
public:
	RoguePython(Cheats* cheatsIn);
	void init();
	RogueFloat* createFloat(float fValue);
	Cheats* cheats;
	void* pFloatType;
};