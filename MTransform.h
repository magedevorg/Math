#pragma once


#include "MQuaternion.h"


class MTransform
{
public:
	MTransform()
		: Location(0,0,0)
		, Scale(1, 1, 1)
		, IsDirty(true)
	{}


	//-----------------------------------------------------
	// 위치
	//-----------------------------------------------------
	void SetLocation(const MVector3& inLocation) 
	{
		IsDirty = true;
		Location = inLocation;
	}

	void SetLocation(MFLOAT inX, MFLOAT inY, MFLOAT inZ) 
	{
		IsDirty = true;
		Location.Set(inX, inY, inZ);
	}

	const MVector3& GetLocation() const {
		return Location;
	}


	//-----------------------------------------------------
	// 회전 설정
	//-----------------------------------------------------
	void SetRotation(const MQuaternion& inRotation)
	{
		IsDirty = true;
		Rotation = inRotation;
	}

	void SetRotationFromEuler(MFLOAT inX, MFLOAT inY, MFLOAT inZ)
	{
		IsDirty = true;
		Rotation.FromEuler(inX, inY, inZ);
	}

	const MQuaternion& GetRotation() const {
		return Rotation;
	}
	
	//-----------------------------------------------------
	// 스케일 설정
	//-----------------------------------------------------
	void SetScale(const MVector3& inScale)
	{
		IsDirty = true;
		Scale = inScale;
	}

	void SetScale(MFLOAT inX, MFLOAT inY, MFLOAT inZ)
	{
		IsDirty = true;
		Scale.Set(inX, inY, inZ);
	}

	const MVector3& GetScale() const {
		return Scale;
	}
	

	//-----------------------------------------------------
	// 매트릭스 처리
	//-----------------------------------------------------
	const MMatrix4& GetMatrix()
	{
		if (true == IsDirty)
		{
			IsDirty = false;
			UpdateMatrix();
		}

		return Matrix;
	}


	// 위치 변환
	MVector3 TransformPosition(const MVector3 inPos)
	{
		const MMatrix4& matrix = GetMatrix();
		return matrix * inPos;
	}


protected:
	void UpdateMatrix()
	{
		Matrix.Identity();

		if (1.0f == Scale.X && 1.0f == Scale.Y && 1.0f == Scale.Z)
		{
			// 스케일이 1이라면 회전행렬로 설정
			Matrix = Rotation.ToMatrix();
		}
		else
		{
			// 스케일이 설정되었다면 스케일 행렬과 회전 행렬을 곱함
			MMatrix4 scaleMatrix;
			scaleMatrix.MakeScale(Scale);

			Matrix = scaleMatrix * Rotation.ToMatrix();
		}

		// 위치 설정
		Matrix.M[3][0] = Location.X;
		Matrix.M[3][1] = Location.Y;
		Matrix.M[3][2] = Location.Z;
	}

protected:
	// 위치
	MVector3 Location;

	// 회전
	MQuaternion Rotation;

	// 스케일
	MVector3 Scale;

	//-----------------------------------------------------
	// 행렬 정보
	//-----------------------------------------------------
	MBOOL IsDirty;
	MMatrix4 Matrix;
};