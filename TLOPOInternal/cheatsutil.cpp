#include "cheats.h"
#include "windows.h"
#include "offsets.h"

#define gModule(x) (void*)GetModuleHandle(x)


Cheats::Cheats()
{
	uninject = true;
	serverCheatsEnabled = true;


	tlopoExe = gModule(L"tlopo.exe");

	// Set up different function managers

	hookManager = new HookManager(tlopoExe);
	localPlayer = (Player*)0x000001B9732C48B0;
	speed = new Speed(localPlayer);


	uninject = false;
	addressesAreValid = false;
}

void Cheats::tick()
{
	keybinds();
	if (addressesAreValid)
	{
		//speed->tick();
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
	addressesAreValid = true;
}

void Cheats::cleanup()
{
	printf(" [!] Exiting!\n");
	hookManager->removeAll();
}