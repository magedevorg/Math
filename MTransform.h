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
	// Transform에 대한 행렬을 얻는다
	MMatrix4 GetMatrix()
	{
		MMatrix4 transformMatrix;

		if (1.0f == Scale.X && 1.0f == Scale.Y && 1.0f == Scale.Z)
		{
			// 스케일이 1이라면 회전행렬로 설정
			transformMatrix = Rotation.ToMatrix();
		}
		else
		{
			// 스케일이 설정되었다면 스케일 행렬과 회전 행렬을 곱함
			MMatrix4 scaleMatrix;
			scaleMatrix.MakeScale(Scale);

			transformMatrix = scaleMatrix * Rotation.ToMatrix();
		}

		// 위치 설정
		transformMatrix.M[3][0] = Position.X;
		transformMatrix.M[3][1] = Position.Y;
		transformMatrix.M[3][2] = Position.Z;

		return transformMatrix;
	}

public:
	MVector3 Position;			// 위치
	MQuaternion Rotation;		// 회전
	MVector3 Scale;				// 스케일
};