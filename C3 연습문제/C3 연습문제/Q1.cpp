#include "Common.h"

bool IsLittleEndian()
{
	int num = 1;

	char* c = reinterpret_cast<char*>(&num);

	if (*c == 1)
	{
		return true;
	}

	return false;
}

bool IsBigEndian()
{
	int num = 1;

	char* c = reinterpret_cast<char*>(&num);

	if (*c == 0)
	{
		return true;
	}

	return false;
}
