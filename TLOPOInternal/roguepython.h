#pragma once
#include "general.h"

class Cheats;

class RogueObject
{
public:
	uint64_t iRefCnt;
	void* PyType;
};

class RogueFloat
{
public:
	uint64_t iRefCnt;
	void* PyType;
	uint32_t padding;
	float fValue;
};

class RoguePython
{
public:
	RoguePython(Cheats* cheatsIn);
	void init();
	void readType(PyObject* pAttributeValue);
	void readAttribute(PyObject* pAttributeName);
	RogueFloat* createFloat(float fValue);
	Cheats* cheats;

	struct _attributes
	{
		static const uint32_t SPEED = 0;
		static const uint32_t SHIPSPEED = 1;
		static const uint32_t SHIPROTATIONSPEED = 2;
		static const uint32_t CANNONRECHARGE = 3;
	} ATTRIBUTES;

	struct _types
	{
		static const uint32_t FLOAT = 0;
		static const uint32_t INT = 1;
		static const uint32_t STRING = 2;
		static const uint32_t DICT = 3;
		static const uint32_t LIST = 4;
		static const uint32_t FUNCTION = 5;
		static const uint32_t METHOD = 6;
		static const uint32_t BUILTIN = 7;



	} TYPES;


	std::vector<uint64_t> vPyTypes;
	std::vector<uint64_t> vAttr2Str;
};