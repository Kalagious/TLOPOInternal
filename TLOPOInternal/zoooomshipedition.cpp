#include "zoooom.h"
#include "cheats.h"


extern Cheats* cheatsGlobal;


ZoooomShipEdition::ZoooomShipEdition(Cheats* cheatsIn)
{
	name = "Zooooom (Ship Ed.)";
	fSpeed = 3.8;
	enable = false;
	cheats = cheatsIn;
	pSpeedFloat = NULL;

}


PyObject* ZoooomShipEdition::tick()
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


	return NULL;
}