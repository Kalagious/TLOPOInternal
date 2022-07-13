#include "cheats.h"

void Cheats::keybinds()
{
	if (GetAsyncKeyState(VK_NUMPAD4) & 0x01)
		speed->enable = !speed->enable;
}