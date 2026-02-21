#include "Segment3D.h"

Vector3D Segment3D::direction() const 
{
	return end - start;
}

double Segment3D::length() const 
{
    return direction().length();
}
