#include "module.h"
#include "NextPosObject.h"
#include "general.h"
#include "Player.h"

class Fly : public Module
{
public:
	Fly(Player* localPlayer);
	bool tick();
	float vertSpeedMult;
	Vector3 virtualPos;
	Player* localPlayer;
};