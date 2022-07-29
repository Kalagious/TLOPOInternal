#include "zoooom.h"
#include "cheats.h"


extern Cheats* cheatsGlobal;


Zoooom::Zoooom(Cheats* cheatsIn)
{
	name = "Zooooom";
	fSpeed = 3.55;
	enable = false;
	cheats = cheatsIn;
	pSpeedFloat = NULL;

}


bool Zoooom::tick()
{
	if (!pSpeedFloat)
	{
		pSpeedFloat = cheats->roguePython->createFloat(fSpeed);
	}

	if (pSpeedFloat)
	{
		if (pSpeedFloat->fValue != fSpeed)
			pSpeedFloat->fValue = fSpeed;
	}
	return true;
}