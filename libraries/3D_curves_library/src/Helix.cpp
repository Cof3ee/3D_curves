#include "Helix.h"
#include <cmath>

#define M_PI (float)3.14159265358979323846 

Helix::Helix(float radius, float pitch) : radius(radius), pitch(pitch)
{}

Point3D Helix::getPoint(float t) const 
{
    return { radius * cos(t), radius * sin(t), pitch * t / (2 * M_PI) };
}

Vector3D Helix::getDerivative(float t) const
{
    return { -radius * sin(t), radius * cos(t), pitch / (2 * M_PI) };
}
