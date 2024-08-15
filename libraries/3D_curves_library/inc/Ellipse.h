#pragma once
#include "Curve3D.h"

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

