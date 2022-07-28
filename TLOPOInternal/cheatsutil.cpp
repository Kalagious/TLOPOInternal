#include "cheats.h"
#include "windows.h"
#include "Python.h"

#define gModule(x) (void*)GetModuleHandle(x)


Cheats::Cheats()
{
	uninject = true;
	tlopoExe = gModule(L"tlopo.exe");
	roguePython = new RoguePython(this);
	hookManager = new HookManager(tlopoExe);
	functionManager = new FunctionManager(tlopoExe);
	fly = new Fly(this);
	zoooom = new Zoooom(this);
	zoooomShipEdition = new ZoooomShipEdition(this);
	minigunGoBurr = new MinigunGoBurr(this);
	minigunGoBurr->enable = true;
	turnyBoi = new TurnyBoi(this);

	uninject = false;
	addressesAreValid = false;
}

void Cheats::tick()
{
	keybinds();
	if (addressesAreValid)
	{
		//Blah
	}
	else
	{
		recalculateAddresses();
	}
}

void Cheats::recalculateAddresses()
{
	printf(" [!] Recalculating Addresses\n");
	roguePython->init();
	hookManager->InitalizeHooks();

	//functionManager->scanFunctions();
	addressesAreValid = true;
}

void Cheats::cleanup()
{
	printf(" [*] Exiting!\n");
	hookManager->removeAll();
}