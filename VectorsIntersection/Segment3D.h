#include "Vector3D.h"


#pragma once
class Segment3D
{
public:
    Vector3D start;
    Vector3D end;

    Segment3D(const Vector3D& s, const Vector3D& e) : start(s), end(e) {}

    Vector3D direction() const;
    double length() const;     
};

