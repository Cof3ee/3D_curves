#include "Ellipse.h"
#include <cmath>

Ellipse::Ellipse(float radiusX, float radiusY) : radiusX(radiusX), radiusY(radiusY) 
{}

Point3D Ellipse::getPoint(float t) const
{
    return { radiusX * cos(t), radiusY * sin(t), 0.0f };
}

Vector3D Ellipse::getDerivative(float t) const
{
    return { -radiusX * sin(t), radiusY * cos(t), 0.0f };
}

