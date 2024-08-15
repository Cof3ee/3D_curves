#pragma once
#include "Point3D.h"
#include "Vector3D.h"

class Curve3D
{
public:
    virtual ~Curve3D() {};

    // Returns a point on the curve given the parameter t
	virtual Point3D getPoint(float t) const = 0;

    // Returns the derivative of the curve given the parameter t
    virtual Vector3D getDerivative(float t) const = 0;
};

