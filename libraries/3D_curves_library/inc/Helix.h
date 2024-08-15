#pragma once
#include "Curve3D.h"


class Helix : public Curve3D
{
public:
    Helix(float radius, float pitch);

    Point3D getPoint(float t) const override;

    Vector3D getDerivative(float t) const override;

private:
    float radius;
    float pitch;
};

