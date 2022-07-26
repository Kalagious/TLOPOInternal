#include "cheats.h"

void Cheats::keybinds()
{
	if (GetAsyncKeyState(VK_NUMPAD4) & 0x01)
		fly->enable = !fly->enable;
	if (GetAsyncKeyState(VK_XBUTTON2))
		zoooom->enable = true;
	else
		zoooom->enable = false;
	if (GetAsyncKeyState(VK_XBUTTON1))
		turnyBoi->enable = true;
	else
		turnyBoi->enable = false;

	if (GetAsyncKeyState(VK_NUMPAD6) & 0x01)
		minigunGoBurr->enable = !minigunGoBurr->enable;
		
}