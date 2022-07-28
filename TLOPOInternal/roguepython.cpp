#include "roguepython.h"
#include "cheats.h"
#include "offsets.h"

RoguePython::RoguePython(Cheats* cheatsIn)
{
	cheats = cheatsIn;
	pFloatType = (void*)((uint64_t)cheats->tlopoExe+oPyFloatOffset);
}


void RoguePython::init()
{
	pFloatType = (void*)((uint64_t)cheats->tlopoExe + oPyFloatOffset);

	for (int i = 0; i < 20; i++)
	{
		vPyTypes.push_back(0);
		vAttr2Str.push_back(0);

	}
}


RogueFloat* RoguePython::createFloat(float fValue)
{
	if (!pFloatType)
		return NULL;
	
	RogueFloat* tmpFloat = new RogueFloat();
	if (!tmpFloat)
		return NULL;
	tmpFloat->iRefCnt = 10;
	tmpFloat->PyType = pFloatType;
	tmpFloat->fValue = fValue;

	return tmpFloat;
}

void RoguePython::readType(PyObject* pValue)
{

	char* pTypeName = (char*)((uint64_t*)((uint64_t*)pValue)[1])[3];


	if (vPyTypes.at(TYPES.METHOD) == NULL)
	{
		if (!strcmp(pTypeName, "method"))
		{
			printf(" [*] RP - Method Type Found\n");
			vPyTypes.at(TYPES.METHOD) = ((uint64_t*)pValue)[1];
		}
	}
	if (vPyTypes.at(TYPES.BUILTIN) == NULL)
	{
		if (!strcmp(pTypeName, "builtin_function_or_method"))
		{
			printf(" [*] RP - BuiltIn Type Found\n");
			vPyTypes.at(TYPES.BUILTIN) = ((uint64_t*)pValue)[1];
		}
	}
}


void RoguePython::readAttribute(PyObject* pAttributeName)
{
	PyVarObjectCust* tmp = (PyVarObjectCust*)pAttributeName;
	std::string tmpAttName(tmp->sName);

	if (vAttr2Str.at(ATTRIBUTES.SPEED) == NULL)
		if (tmpAttName.find("speed") != std::string::npos && tmpAttName.length() == 5)
			vAttr2Str.at(ATTRIBUTES.SPEED) = (uint64_t)pAttributeName;

	if (vAttr2Str.at(ATTRIBUTES.SHIPSPEED) == NULL)
		if (tmpAttName.find("_ShipPilot__speed") != std::string::npos)
			vAttr2Str.at(ATTRIBUTES.SHIPSPEED) = (uint64_t)pAttributeName;

	if (vAttr2Str.at(ATTRIBUTES.SHIPROTATIONSPEED) == NULL)
		if (tmpAttName.find("_ShipPilot__rotationSpeed") != std::string::npos)
			vAttr2Str.at(ATTRIBUTES.SHIPROTATIONSPEED) = (uint64_t)pAttributeName;

	if (vAttr2Str.at(ATTRIBUTES.CANNONRECHARGE) == NULL)
		if (tmpAttName.find("recharge") != std::string::npos)
			vAttr2Str.at(ATTRIBUTES.CANNONRECHARGE) = (uint64_t)pAttributeName;
}