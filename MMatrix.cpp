#pragma once


#include "MMatrix.h"
#include "MQuaternion.h"


MVector3 MMatrix4::operator*(const MVector3& inVector) const
{
	MVector3 result;

	result.X = M[0][0] * inVector.X;
	result.X += M[1][0] * inVector.Y;
	result.X += M[2][0] * inVector.Z;
	result.X += M[3][0] * 1;

	result.Y = M[0][1] * inVector.X;
	result.Y += M[1][1] * inVector.Y;
	result.Y += M[2][1] * inVector.Z;
	result.Y += M[3][1] * 1;

	result.Z = M[0][2] * inVector.X;
	result.Z += M[1][2] * inVector.Y;
	result.Z += M[2][2] * inVector.Z;
	result.Z += M[3][2] * 1;

	return result;
}


MMatrix4 MMatrix4::operator*(const MMatrix4& inMatrix) const
{
	MMatrix4 result;

	for (MINT32 x = 0; x < 4; ++x)
	{
		for (MINT32 y = 0; y < 4; ++y)
		{
			float temp = 0;
			for (MINT32 i = 0; i < 4; ++i)
			{
				temp += M[x][i] * inMatrix.M[i][y];
			}
			result.M[x][y] = temp;
		}
	}

	return result;
}



void MMatrix4::MakeScale(const MVector3& inScale)
{
	MakeScale(inScale.X, inScale.Y, inScale.Z);	
}

void MMatrix4::MakeScale(MFLOAT inX, MFLOAT inY, MFLOAT inZ)
{
	Identity();
	M[0][0] = inX;
	M[1][1] = inY;
	M[2][2] = inZ;
}

void MMatrix4::MakeLocation(const MVector3& inLocation)
{
	MakeLocation(inLocation.X, inLocation.Y, inLocation.Z);
}

void MMatrix4::MakeLocation(MFLOAT inX, MFLOAT inY, MFLOAT inZ)
{
	Identity();

	M[3][0] = inX;
	M[3][1] = inY;
	M[3][2] = inZ;
}


void MMatrix4::MakeRotationFromEuler(MFLOAT inX, MFLOAT inY, MFLOAT inZ)
{
	MQuaternion quat;
	quat.FromEuler(inX, inY, inZ);

	*this = quat.ToMatrix();
}