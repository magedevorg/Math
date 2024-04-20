#pragma once

#include "MPrerequisites.h"
#include "MMatrix.h"

class MQuaternion
{
public:
	MQuaternion()
		:X(0), Y(0), Z(0), W(1)
	{}

	MQuaternion(MFLOAT inX, MFLOAT inY, MFLOAT inZ, MFLOAT inW)
		:X(inX), Y(inY), Z(inZ), W(inW)
	{}

public:
	// 오일러각 -> 쿼터니옴
	void FromEuler(MFLOAT inX, MFLOAT inY, MFLOAT inZ);

	// 행렬을 얻는다
	MMatrix4 ToMatrix() const;


	void Set(MFLOAT inX, MFLOAT inY, MFLOAT inZ, MFLOAT inW)
	{
		X = inX;
		Y = inY;
		Z = inZ;
		W = inW;
	}


	bool operator==(const MQuaternion& inOther) const
	{
		if ((inOther.X == X) && (inOther.Y == Y) && (inOther.Z == Z) && (inOther.W == W)) {
			return true;
		}

		return false;
	}

	bool operator!=(const MQuaternion& inOther) const
	{
		return !(inOther == *this);
	}

public:
	MFLOAT X;
	MFLOAT Y;
	MFLOAT Z;
	MFLOAT W;
};

