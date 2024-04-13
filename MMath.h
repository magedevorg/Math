#pragma once


#include "MPrerequisites.h"



class MMath
{
public:
	static MFLOAT DegreeToRadian(MFLOAT inDegree)
	{
		return inDegree * DegreeToRadianValue;
	}

	static MFLOAT RadianToDegree(MFLOAT inRadian)
	{
		return inRadian* RadianToDegreeValue;
	}

private:
	static MFLOAT PI_VALUE;
	static MFLOAT RadianToDegreeValue;
	static MFLOAT DegreeToRadianValue;
};