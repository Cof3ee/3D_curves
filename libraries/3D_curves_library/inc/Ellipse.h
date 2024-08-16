#pragma once
#include "Curve3D.h"

// Class for ellipse
class Ellipse :public Curve3D
{
public:
    Ellipse(float radiusX, float radiusY);

    Point3D getPoint(float t) const override;

    Vector3D getDerivative(float t) const override;

private:
    float radiusX;
    float radiusY;
};

