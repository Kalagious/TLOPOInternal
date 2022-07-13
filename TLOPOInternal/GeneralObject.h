#pragma once
#include "general.h"

class Object
{
public:
	char pad_0008[40]; //0x0008
	uint64_t pName; //0x0038
	char pad_0040[8]; //0x0040
	int8_t iNameLen; //0x0048
	char pad_0049[432]; //0x0049

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
}; //Size: 0x01F9
