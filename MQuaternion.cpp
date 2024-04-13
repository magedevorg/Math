#include "MQuaternion.h"
#include "MMath.h"



void MQuaternion::FromEuler(MFLOAT inX, MFLOAT inY, MFLOAT inZ)
{
	MFLOAT x = MMath::DegreeToRadian(inX);
	MFLOAT y = MMath::DegreeToRadian(inY);
	MFLOAT z = MMath::DegreeToRadian(inZ);

	MFLOAT c1 = cos(x / 2);
	MFLOAT c2 = cos(y / 2);
	MFLOAT c3 = cos(z / 2);

	MFLOAT s1 = sin(x / 2);
	MFLOAT s2 = sin(y / 2);
	MFLOAT s3 = sin(z / 2);

	X = -(s1 * c2 * c3 - c1 * s2 * s3);
	Y = -(c1 * s2 * c3 + s1 * c2 * s3);
	Z = c1 * c2 * s3 - s1 * s2 * c3;
	W = c1 * c2 * c3 + s1 * s2 * s3;
}





MMatrix4 MQuaternion::ToMatrix() const
{
	MMatrix4 matrix;

	double sqw = W * W;
	double sqx = X * X;
	double sqy = Y * Y;
	double sqz = Z * Z;

	double invs = 1 / (sqx + sqy + sqz + sqw);
	matrix.M[0][0] = (sqx - sqy - sqz + sqw) * invs; // since sqw + sqx + sqy + sqz =1/invs*invs
	matrix.M[1][1] = (-sqx + sqy - sqz + sqw) * invs;
	matrix.M[2][2] = (-sqx - sqy + sqz + sqw) * invs;


	double tmp1 = X * Y;
	double tmp2 = Z * W;
	matrix.M[0][1] = 2.0 * (tmp1 + tmp2) * invs;
	matrix.M[1][0] = 2.0 * (tmp1 - tmp2) * invs;

	tmp1 = X * Z;
	tmp2 = Y * W;
	matrix.M[0][2] = 2.0 * (tmp1 - tmp2) * invs;
	matrix.M[2][0] = 2.0 * (tmp1 + tmp2) * invs;
	tmp1 = Y * Z;
	tmp2 = X * W;
	matrix.M[1][2] = 2.0 * (tmp1 + tmp2) * invs;
	matrix.M[2][1] = 2.0 * (tmp1 - tmp2) * invs;

	return matrix;
}