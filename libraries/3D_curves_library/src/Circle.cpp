#include "Circle.h"
#include <cmath> 

using namespace std;

Circle::Circle(float radius) : radius(radius) 
{}

Point3D Circle::getPoint(float t) const
{
    return { radius * cos(t), radius * sin(t), 0.0f };
}

Vector3D Circle::getDerivative(float t) const
{
    return { -radius * sin(t), radius * cos(t), 0.0f };
}


