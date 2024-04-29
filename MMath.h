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

	template<typename T>
	static T Max(const T& inLeft, const T& inRight) {
		return (inLeft > inRight) ? inLeft : inRight;
	}

	template<typename T>
	static T Min(const T& inLeft, const T& inRight) {
		return (inLeft < inRight) ? inLeft : inRight;
	}

	template<typename T>
	static T ABS(const T& inValue) {
		return ::abs(inValue);
	}

	template<typename T>
	static void Swap(T& inLeft, T& inRight) 
	{
		T temp = inLeft;
		inLeft = inRight;
		inRight = temp;
	}

public:
	static const MINT32 MINT32_MAX;

private:
	static MFLOAT PI_VALUE;
	static MFLOAT RadianToDegreeValue;
	static MFLOAT DegreeToRadianValue;
};