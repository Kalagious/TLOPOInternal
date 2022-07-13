#pragma once
#include "hookmanager.h"
#include "allmodules.h"
#include "module.h"
#include "allclasses.h"

class Cheats {
public:
	Cheats();
	void tick();
	void keybinds();
	void recalculateAddresses();
	void cleanup();

	bool serverCheatsEnabled;
	bool uninject;
	bool addressesAreValid;

	Player* localPlayer;

	void* tlopoExe;

	std::vector<Module*> modules;

	HookManager* hookManager;

	Speed* speed;
};