#include "roguepython.h"
#include "cheats.h"
#include "offsets.h"

RoguePython::RoguePython(Cheats* cheatsIn)
{
	cheats = cheatsIn;
	pFloatType = (void*)((uint64_t)cheats->tlopoExe+oPyFloatOffset);
}


void RoguePython::init()
{
	pFloatType = (void*)((uint64_t)cheats->tlopoExe + oPyFloatOffset);
}


RogueFloat* RoguePython::createFloat(float fValue)
{
	if (!pFloatType)
		return NULL;

	RogueFloat* tmpFloat = new RogueFloat();
	printf("%p\n", tmpFloat);
	if (!tmpFloat)
		return NULL;
	tmpFloat->iRefCnt = 10;
	tmpFloat->PyType = pFloatType;
	tmpFloat->fValue = fValue;

	return tmpFloat;
}