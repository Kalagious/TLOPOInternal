#pragma once
#include "hookmanager.h"
#include "functionmanager.h"
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

	std::vector<Module*> modules;

	HookManager* hookManager;
	FunctionManager* functionManager;
	RoguePython* roguePython;

	Fly* fly;
	Zoooom* zoooom;
	ZoooomShipEdition* zoooomShipEdition;
	MinigunGoBurr* minigunGoBurr;
	TurnyBoi* turnyBoi;
};