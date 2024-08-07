﻿#pragma once

#include "MPrerequisites.h"


//--------------------------------------------------------------
// 2차원 벡터 클래스
//--------------------------------------------------------------
class MVector2
{
public:
    MVector2(){}
    MVector2(MFLOAT inX, MFLOAT inY)
        : X(inX)
        , Y(inY)
        {}

    MVector2(const MVector2& inOther)
        : X(inOther.X)
        , Y(inOther.Y)
        {}

public:
    void Set(MFLOAT inX, MFLOAT inY)
    {
        X = inX; 
        Y = inY;
    }

    // 길이
    MFLOAT GetLength() const  {
        return sqrt(X*X + Y*Y);
    }

    // 정규화
    void Normalize() 
    {
        const MFLOAT length = GetLength();
        X /= length;
        Y /= length;
    }

    MVector2 GetNormal() const
    {
        MVector2 temp(X, Y);
        temp.Normalize();
        return temp;
    }

    //---------------------------------------------------------
    // 연산자 오버로딩
    //---------------------------------------------------------
    MVector2 operator+(const MVector2& inOther) const {
        return MVector2(X + inOther.X, Y + inOther.Y);
    }

    MVector2 operator-(const MVector2& inOther) const {
        return MVector2(X - inOther.X, Y - inOther.Y);
    }

    MVector2& operator-() {
        X = -X;
        Y = -Y;
        return *this;
    }

    MVector2 operator*(float inValue) const {
        return MVector2(X * inValue, Y * inValue);
    }

    MVector2& operator*=(float inValue) 
    {   
        X *= inValue;
        Y *= inValue;
        return *this;
    }

    MVector2 operator/(float inValue) const {
        return MVector2(X / inValue, Y / inValue);
    }

    MBOOL operator==(const MVector2& inOther) const {
        return (X == inOther.X) && (Y == inOther.Y);
    }

    //---------------------------------------------------------
    // static
    //---------------------------------------------------------
    // 내적
    static MFLOAT DotProduct(const MVector2& inA, const MVector2& inB)
    {
        return (inA.X * inB.X)  + (inA.Y * inB.Y);
    }

    // 외적
    static MFLOAT CrossProduct(MVector2 inA, MVector2 inB)
    {
        return (inA.X * inB.Y) - (inA.Y * inB.X);   
    }


public:
    MFLOAT X;
    MFLOAT Y;
};




//--------------------------------------------------------------
// 3차원 벡터 클래스
//--------------------------------------------------------------
class MVector3
{
public:
    static const MVector3 Zero;
    static const MVector3 AxisX;
    static const MVector3 AxisY;
    static const MVector3 AxisZ;


public:
    MVector3(){}
    MVector3(MFLOAT inX, MFLOAT inY, MFLOAT inZ) 
        : X(inX), Y(inY), Z(inZ)
    {}

public:
    void Set(MFLOAT inX, MFLOAT inY, MFLOAT inZ)
    {
        X = inX;
        Y = inY;
        Z = inZ;
    }

    static MFLOAT DotProduct(const MVector3& inA, const MVector3& inB)
    {
        return (inA.X * inB.X) + (inA.Y * inB.Y) + (inA.Z * inB.Z);
    }

    // 외적
    static MVector3 CrossProduct(MVector3 inA, MVector3 inB)
    {
		return MVector3(
			(inA.Y * inB.Z) - (inA.Z * inB.X),
			(inA.Z * inB.X) - (inA.X * inB.Z),
			(inA.X * inB.Y) - (inA.Y * inB.X));
    }

    // 길이
    MFLOAT GetLength() const {
        return sqrt((X * X) + (Y * Y) + (Z * Z));
    }

    // 정규화
    void Normalize()
    {
        const MFLOAT length = GetLength();
        X /= length;
        Y /= length;
        Z /= length;
    }

	//---------------------------------------------------------
   // 연산자 오버로딩
   //---------------------------------------------------------
    MVector3 operator-(const MVector3& inOther) const {
        return MVector3(X - inOther.X, Y - inOther.Y, Z - inOther.Z);
    }

    MVector3 operator-() const {
        return MVector3(-X , -Y, -Z);
    }

    MVector3& operator*=(MFLOAT inValue) 
    {
        X *= inValue;
        Y *= inValue;
        Z *= inValue;
        return *this;
    }

    MVector3 operator*(MFLOAT inValue) const
    {
        return MVector3(X * inValue, Y * inValue, Z * inValue);
    }

    MBOOL operator==(const MVector3& inOther) const {
        return (X == inOther.X) && (Y == inOther.Y) && (Z == inOther.Z);
    }

public:
    MFLOAT X;
    MFLOAT Y;
    MFLOAT Z;
};