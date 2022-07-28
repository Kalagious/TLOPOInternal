#pragma once
#include "module.h"
#include "general.h"
#include "roguepython.h"

class Cheats;

class Zoooom : public Module
{
public:
	Zoooom(Cheats* cheatsIn);
	PyObject* tick();
	float fSpeed;
	Cheats* cheats;
	RogueFloat* pSpeedFloat;
};