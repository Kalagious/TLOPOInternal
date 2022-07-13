#include "module.h"
#include "NextPosObject.h"
#include "general.h"
#include "Player.h"

class Speed : public Module
{
public:
	Speed(Player* localPlayer);
	bool tick();
	float vertSpeedMult, horzSpeedMult;
	Vector3 virtualPos;
	Player* localPlayer;
};