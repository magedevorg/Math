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
	// ���Ϸ��� -> ���ʹϿ�
	void FromEuler(MFLOAT inX, MFLOAT inY, MFLOAT inZ);

	// ����� ��´�
	MMatrix4 ToMatrix() const;

public:
	MFLOAT X;
	MFLOAT Y;
	MFLOAT Z;
	MFLOAT W;
};

