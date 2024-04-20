#pragma once


#include "MQuaternion.h"


class MTransform
{
public:
	MTransform()
		: Scale(1, 1, 1)
	{}

	MTransform(const MVector3& inPosition, const MQuaternion& inRotation, const MVector3& inScale)
		: Position(inPosition)
		, Rotation(inRotation)
		, Scale(inScale)
	{}

public:
	// Transform�� ���� ����� ��´�
	MMatrix4 GetMatrix()
	{
		MMatrix4 transformMatrix;

		if (1.0f == Scale.X && 1.0f == Scale.Y && 1.0f == Scale.Z)
		{
			// �������� 1�̶�� ȸ����ķ� ����
			transformMatrix = Rotation.ToMatrix();
		}
		else
		{
			// �������� �����Ǿ��ٸ� ������ ��İ� ȸ�� ����� ����
			MMatrix4 scaleMatrix;
			scaleMatrix.MakeScale(Scale);

			transformMatrix = scaleMatrix * Rotation.ToMatrix();
		}

		// ��ġ ����
		transformMatrix.M[3][0] = Position.X;
		transformMatrix.M[3][1] = Position.Y;
		transformMatrix.M[3][2] = Position.Z;

		return transformMatrix;
	}

public:
	MVector3 Position;			// ��ġ
	MQuaternion Rotation;		// ȸ��
	MVector3 Scale;				// ������
};