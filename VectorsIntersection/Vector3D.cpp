#include "Vector3D.h"

Vector3D Vector3D::operator+(const Vector3D& other) const 
{
    return Vector3D(X + other.X, Y + other.Y, Z + other.Z);
}

Vector3D Vector3D::operator-(const Vector3D& other) const
{
	return Vector3D(X - other.X, Y - other.Y, Z - other.Z);
}

Vector3D Vector3D::operator*(double scalar) const
{
	return Vector3D(X * scalar, Y * scalar, Z * scalar);
}

double Vector3D::dot(const Vector3D& other) const
{
    return X * other.X + Y * other.Y + Z * other.Z;
}

Vector3D Vector3D::cross(const Vector3D& other) const 
{
	return Vector3D(
		Y * other.Z - Z * other.Y,
		Z * other.X - X * other.Z,
		X * other.Y - Y * other.X
	);
}

double Vector3D::length() const {
	return std::sqrt(X * X + Y * Y + Z * Z);
}

Vector3D Vector3D::normalized() const {
	double len = length();
	if (len < 1e-10) return Vector3D(0, 0, 0);
	return Vector3D(X / len, Y / len, Z / len);
}

//class Vector3D
//{
//public:
//
//    double X;
//    double Y;
//    double Z;
//
//    Vector3D(double x = 0, double y = 0, double z = 0)
//        : X(x), Y(y), Z(z)
//    {
//    }
//
//    // Операторы для работы с векторами
//    
//
//    Vector3D operator-(const Vector3D& other) const
//    {
//        return Vector3D(X - other.X, Y - other.Y, Z - other.Z);
//    }
//
//    Vector3D operator*(double scalar) const
//    {
//        return Vector3D(X * scalar, Y * scalar, Z * scalar);
//    }
//
//    double dot(const Vector3D& other) const
//    {
//        return X * other.X + Y * other.Y + Z * other.Z;
//    }
//
//    Vector3D cross(const Vector3D& other) const {
//        return Vector3D(
//            Y * other.Z - Z * other.Y,
//            Z * other.X - X * other.Z,
//            X * other.Y - Y * other.X
//        );
//    }
//
//    double length() const {
//        return std::sqrt(X * X + Y * Y + Z * Z);
//    }
//
//    Vector3D normalized() const {
//        double len = length();
//        if (len < 1e-10) return Vector3D(0, 0, 0);
//        return Vector3D(X / len, Y / len, Z / len);
//    }
//};
