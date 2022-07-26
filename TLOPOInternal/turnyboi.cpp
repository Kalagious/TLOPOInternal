#include "turnyboi.h"
#include "cheats.h"


extern Cheats* cheatsGlobal;


TurnyBoi::TurnyBoi(Cheats* cheatsIn)
{
	name = "TurnyBoi";
	enable = false;
	cheats = cheatsIn;
	pRightFloat = NULL;
	pLeftFloat = NULL;
	fTurnSpeed = 3.7;
}


PyObject* TurnyBoi::tick()
{
	if (!pRightFloat)
	{
		pRightFloat = cheats->roguePython->createFloat(-1*fTurnSpeed);
	}
	if (!pLeftFloat)
	{
		pLeftFloat = cheats->roguePython->createFloat(1*fTurnSpeed);
	}

	if (pRightFloat)
		pRightFloat->fValue = -1 * fTurnSpeed;
	if (pLeftFloat)
		pLeftFloat->fValue = 1 * fTurnSpeed;


	if (GetAsyncKeyState(0x41))
		return (PyObject*)pLeftFloat;

	if (GetAsyncKeyState(0x44))
		return (PyObject*)pRightFloat;

	return NULL;
}