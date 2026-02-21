#include<cmath>

#pragma once
class Vector3D
{
public:

	double X;
	double Y;
	double Z;

	Vector3D(double x = 0, double y = 0, double z = 0)
		: X(x), Y(y), Z(z)
	{ }

	Vector3D operator+(const Vector3D& other) const;
	Vector3D operator-(const Vector3D& other) const;
	Vector3D operator*(double scalar) const;
	double dot(const Vector3D& other) const;
	Vector3D cross(const Vector3D& other) const;
	double length() const;
	Vector3D normalized() const;
};


