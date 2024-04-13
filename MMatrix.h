#pragma once


#include "MVector.h"


class MMatrix4
{
public:
	MMatrix4() 
	{
		Identity();
	}

public:
	void Identity()
	{
		memset(M, 0, sizeof(M));
		M[0][0] = 1;
		M[1][1] = 1;
		M[2][2] = 1;
		M[3][3] = 1;
	}


	MVector3 operator*(const MVector3& inVector) const;
	MMatrix4 operator*(const MMatrix4& inMatrix) const;



	void MakeScale(const MVector3& inScale);
	void MakeScale(MFLOAT inX, MFLOAT inY, MFLOAT inZ);

	void MakeLocation(const MVector3& inLocation);
	void MakeLocation(MFLOAT inX, MFLOAT inY, MFLOAT inZ);

	void MakeRotationFromEuler(MFLOAT inX, MFLOAT inY, MFLOAT inZ);
	

public:
	MFLOAT M[4][4];
};