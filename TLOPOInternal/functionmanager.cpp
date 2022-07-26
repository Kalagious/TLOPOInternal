#include "functionmanager.h"


FunctionManager::FunctionManager(void* tlopoExeIn)
{
	tlopoExe = tlopoExeIn;
	pyMarshal_ReadObjectFromString = new PyMarshal_ReadObjectFromStringG(tlopoExe);
}


void FunctionManager::scanFunctions()
{
	printf(" [*] Scanning for Game Functions:\n");
	pyMarshal_ReadObjectFromString->scanFunction();
	printf(" [*] Functions Found!\n\n");
}
