#pragma once
#include "hookmanager.h"
#include "allmodules.h"
#include "module.h"
#include "allclasses.h"
#include "roguepython.h"


class Cheats {
public:
	Cheats();
	void tick();
	void keybinds();
	void recalculateAddresses();
	void cleanup();

	bool uninject;
	bool addressesAreValid;

	Player* localPlayer;

	void* tlopoExe;
	void* openGl32;

	std::vector<Module*> modules;

	HookManager* hookManager;
	RoguePython* roguePython;

	Fly* fly;
	Zoooom* zoooom;
	ZoooomShipEdition* zoooomShipEdition;
	MinigunGoBurr* minigunGoBurr;
	TurnyBoi* turnyBoi;
};