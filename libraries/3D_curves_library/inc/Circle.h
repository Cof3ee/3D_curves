#pragma once
#include "Curve3D.h"

// Class for circle
class Circle : public Curve3D
{
public:
    Circle(float radius); 

    Point3D getPoint(float t) const override;
   
    Vector3D getDerivative(float t) const override;

private:
    float radius;
};

