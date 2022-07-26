#include "PyObject_SetAttrHook.h"
#include <vector>
#include <string>
#include <sstream>
#include "cheats.h"
#include "allclasses.h"
#include "roguepython.h"


extern Cheats* cheatsGlobal;


PyObject_SetAttrHook::tTargetPtr PyObject_SetAttrHook::oFunction;


int64_t __fastcall PyObject_SetAttrHook::hookFunction(PyObject* pObject, PyObject* pAttributeName, PyObject* pValue)
{

	PyVarObjectCust* tmp = (PyVarObjectCust*)pAttributeName;
	std::string tmpAttName(tmp->sName);
	Object* tmpObject = (Object*)(pObject+8);


	if (tmpAttName.find("Inventory") != std::string::npos)
	{
		printf("%s  -  %p  -  %p  -  %p\n", tmp->sName, pObject, pAttributeName, pValue);
		//return PyObject_SetAttrHook::oFunction(pObject, pAttributeName, (PyObject*)0x0000017D90D71A88);
	}

		
	if (cheatsGlobal->turnyBoi->enable)
	{
		if (tmpAttName.find("rotation") != std::string::npos)
		{
			PyObject* tmpTurn = cheatsGlobal->turnyBoi->tick();
			if (((RogueFloat*)(pValue))->fValue != 0 && tmpTurn)
				return PyObject_SetAttrHook::oFunction(pObject, pAttributeName, tmpTurn);
		}
	}

	if (cheatsGlobal->zoooom->enable)
	{
		if (tmpAttName.find("speed") != std::string::npos)
		{
			if (tmpAttName.find("Ship") != std::string::npos)
				cheatsGlobal->zoooom->fSpeed = 4;
			else
				cheatsGlobal->zoooom->fSpeed = 3.6;
			cheatsGlobal->zoooom->tick();
			if (((RogueFloat*)(pValue))->fValue != 0)
				return PyObject_SetAttrHook::oFunction(pObject, pAttributeName, (PyObject*)cheatsGlobal->zoooom->pSpeedFloat);
		}
	}

	if (cheatsGlobal->minigunGoBurr->enable)
	{
		if (tmpAttName.find("recharge") != std::string::npos)
		{
			cheatsGlobal->minigunGoBurr->tick();
			return PyObject_SetAttrHook::oFunction(pObject, pAttributeName, (PyObject*)cheatsGlobal->minigunGoBurr->pRechargeFloat);
		}
	}
	return PyObject_SetAttrHook::oFunction(pObject, pAttributeName, pValue);
}


PyObject_SetAttrHook::PyObject_SetAttrHook(void* moduleBaseIn)
{ 
	hookName = "PyObject_SetAttrHook Hook";
	hookLen = 16;
	viSig = { 0x48, 0xFF, 0x02, 0x48, 0x8D, 0x4C, 0x24, 0x48, 0xE8, 0x3F, 0x3F, 0x3F, 0x3F, 0x48, 0x8B, 0x83, 0x98, 0x00, 0x00, 0x00, 0x48, 0x85, 0xC0, 0x74, 0x3F, 0x48, 0x8B, 0x54, 0x24, 0x48, 0x4C, 0x8B, 0xC6, 0x48, 0x8B, 0xCF, 0xFF, 0xD0, 0x48, 0x8B, 0x4C, 0x24, 0x48, 0x8B, 0xD8, 0x48, 0x83, 0x29, 0x01, 0x75, 0x3F, 0x48, 0x8B, 0x51, 0x08, 0xFF, 0x52, 0x30 };
	moduleBase = moduleBaseIn;
	iSigOffset = 0x4B;
	enabled = false;
}


bool PyObject_SetAttrHook::initialize()
{
	targetAddr = signatureScan(viSig, iSigOffset, moduleBase);
	if (!targetAddr)
		return false;

	PyObject_SetAttrHook::oFunction = (tTargetPtr)(targetAddr);
	PyObject_SetAttrHook::oFunction = (tTargetPtr)DetourFunction64((void*)PyObject_SetAttrHook::oFunction, (void*)PyObject_SetAttrHook::hookFunction, hookLen);
	enabled = true;
	return true;
}