#include "speed.h"

Speed::Speed(Player* localPlayerIn)
{
	name = "Speed";
	horzSpeedMult = 0.1;
	vertSpeedMult = 0.1;
	enable = false;
	localPlayer = localPlayerIn;
}


bool Speed::tick()
{
	NextPosObject* nextPos = localPlayer->nextPosObject;
	printf("X: %f.2  Y: %f.2\n", nextPos->x, nextPos->y);
	if (enable)
	{
		if (GetAsyncKeyState(VK_SPACE))
			virtualPos.z += vertSpeedMult;
		if (GetAsyncKeyState(VK_LCONTROL))
			virtualPos.z -= vertSpeedMult;
		nextPos->z = virtualPos.z;
	}
	else
	{
		virtualPos.x = nextPos->x;
		virtualPos.y = nextPos->y;
		virtualPos.z = nextPos->z;
	}
	return true;
}