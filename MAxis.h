#pragma once


#include "MVector.h"
#include "MQuaternion.h"


/*
class MAxis2
{
public:
	MAxis2()
	{
		Reset();
	}

public:

	void Set(const MVector2& )

	void Reset()
	{
		AxisList[0].Set(1.0f, 0.0f);
		AxisList[1].Set(0.0f, 1.0f);
	}


protected:
	std::array<MVector2, 2> AxisList;
};
*/




class MAxis3
{
public:
	MAxis3() {
		Reset();
	}

public:
	void Reset()
	{
		AxisList[0].Set(1.0f, 0.0f, 0.0f);
		AxisList[1].Set(0.0f, 1.0f, 0.0f);
		AxisList[2].Set(0.0f, 0.0f, 1.0f);
	}


	void Rotation(const MQuaternion& inQuaternion) {
		Rotation(inQuaternion.ToMatrix());
	}

	void Rotation(const MMatrix4& inMatrix)
	{
		for (int32 i = 0; i < 3; ++i)
		{
			AxisList[i] = inMatrix * AxisList[i];
			AxisList[i].Normalize();
		}
	}

public:
	const MVector3 GetX() const {
		return AxisList[0];
	}

	const MVector3 GetY() const {
		return AxisList[1];
	}

	const MVector3 GetZ() const {
		return AxisList[2];
	}

	const std::array<MVector3, 3>& GetAxisList() const {
		return AxisList;
	}

protected:
	std::array<MVector3,3> AxisList;
};