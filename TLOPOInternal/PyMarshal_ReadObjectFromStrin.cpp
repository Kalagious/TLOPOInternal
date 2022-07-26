#include "PyMarshal_ReadObjectFromString.h"
#include <vector>
#include <string>
#include <sstream>
#include "cheats.h"
#include "GeneralObject.h"


extern Cheats* cheatsGlobal;

PyMarshal_ReadObjectFromStringG::tTargetPtr PyMarshal_ReadObjectFromStringG::oFunction;


PyMarshal_ReadObjectFromStringG::PyMarshal_ReadObjectFromStringG(void* moduleBaseIn)
{
	functionName = "PyMarshal_ReadObjectFromString";
	viSig = { 0x0B, 0x48, 0x33, 0xC4, 0x48, 0x89, 0x84, 0x24, 0x90, 0x00, 0x00, 0x00, 0xB8, 0xEF, 0xBE, 0xAD, 0xDE, 0x4D, 0x8B, 0xD0, 0x4C, 0x0F, 0xAF, 0xD0, 0x48, 0x8B, 0xF1, 0xB8, 0x40, 0x00, 0x00, 0x00, 0x48, 0x8B, 0xDA, 0x48, 0x8D, 0x4C, 0x24, 0x70, 0x88, 0x01, 0x48, 0x8D, 0x49, 0x01, 0xFF, 0xC0, 0x83, 0xF8, 0x60 };
	iSigOffset = 0x13; 
	moduleBase = moduleBaseIn;
}


bool PyMarshal_ReadObjectFromStringG::scanFunction()
{
	targetAddr = signatureScan(viSig, iSigOffset, moduleBase);
	if (!targetAddr)
		return false;

	PyMarshal_ReadObjectFromStringG::oFunction = (tTargetPtr)(targetAddr);



	static const unsigned char sSerializedOb[9] = { 231, 51, 51, 51, 51, 51, 51, 36, 64 };
	int64_t t = PyMarshal_ReadObjectFromStringG::oFunction((uint64_t)((uint64_t)moduleBase+0xC5F29D0), (uint64_t)34096, (uint64_t)1356);
	
	return true;
}