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
	// ��ġ
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
	// ȸ�� ����
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
	// ������ ����
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
	// ��Ʈ���� ó��
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


	// ��ġ ��ȯ
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
			// �������� 1�̶�� ȸ����ķ� ����
			Matrix = Rotation.ToMatrix();
		}
		else
		{
			// �������� �����Ǿ��ٸ� ������ ��İ� ȸ�� ����� ����
			MMatrix4 scaleMatrix;
			scaleMatrix.MakeScale(Scale);

			Matrix = scaleMatrix * Rotation.ToMatrix();
		}

		// ��ġ ����
		Matrix.M[3][0] = Location.X;
		Matrix.M[3][1] = Location.Y;
		Matrix.M[3][2] = Location.Z;
	}

protected:
	// ��ġ
	MVector3 Location;

	// ȸ��
	MQuaternion Rotation;

	// ������
	MVector3 Scale;

	//-----------------------------------------------------
	// ��� ����
	//-----------------------------------------------------
	MBOOL IsDirty;
	MMatrix4 Matrix;
};