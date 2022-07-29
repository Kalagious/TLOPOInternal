#include "zoooom.h"
#include "cheats.h"


extern Cheats* cheatsGlobal;


MinigunGoBurr::MinigunGoBurr(Cheats* cheatsIn)
{
	name = "MinigunGoBurr";
	enable = false;
	cheats = cheatsIn;
	pRechargeFloat = NULL;
}


bool MinigunGoBurr::tick()
{
	if (!pRechargeFloat)
	{
		pRechargeFloat = cheats->roguePython->createFloat(0);
		if (!pRechargeFloat)
			return false;
	}
	return true;
}