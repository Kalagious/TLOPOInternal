#include "cheats.h"
#include "windows.h"
#include "offsets.h"
#include "Python.h"

#define gModule(x) (void*)GetModuleHandle(x)


Cheats::Cheats()
{
	uninject = true;
	tlopoExe = gModule(L"tlopo.exe");

	hookManager = new HookManager(tlopoExe);
	functionManager = new FunctionManager(tlopoExe);
	roguePython = new RoguePython(this);
	printf("%p\n", roguePython->createFloat(30));
	fly = new Fly(this);
	zoooom = new Zoooom(this);
	minigunGoBurr = new MinigunGoBurr(this);
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
	hookManager->InitalizeHooks();
	roguePython->init();

	//functionManager->scanFunctions();
	addressesAreValid = true;
}

void Cheats::cleanup()
{
	printf(" [*] Exiting!\n");
	hookManager->removeAll();
}