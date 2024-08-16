#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <omp.h> 
#include "Circle.h"
#include "Curve3D.h"
#include "Ellipse.h"
#include "Helix.h"

#define M_PI (float)3.14159265358979323846 

using namespace std;

// Generate a random number in a given range
float getRandomNumber( const float min, const float max)
{
    random_device rd;
    mt19937 generator(rd());
    uniform_real_distribution<float> distribution(min, max);
    return distribution(generator);
}

int main()
{   
    // Create a container for all curves
    vector<Curve3D*> curves;

    // Create random curves
    for (int i = 0; i < 10; ++i)
    {
        int type = rand() % 3;
        switch (type)
        {
        case 0:
            curves.push_back(new Circle(getRandomNumber(1.0f, 5.0f)));
            break;
        case 1:
            curves.push_back(new Ellipse(getRandomNumber(1.0f, 5.0f), getRandomNumber(1.0f, 5.0f)));
            break;
        case 2:
            curves.push_back(new Helix(getRandomNumber(1.0f, 5.0f), getRandomNumber(1.0f, 5.0f)));
            break;
        }
    }

    // Output coordinates of points and derivatives at t = PI/4
    cout << "Coordinates of points and derivatives at t = PI/4:\n" << endl;
    for (const auto& curve : curves)
    {
        Point3D point = curve->getPoint(M_PI / 4);
        Vector3D derivative = curve->getDerivative(M_PI / 4);
        cout << "Point: (" << point.x << ", " << point.y << ", " << point.z << ")" << endl;
        cout << "Derivative: (" << derivative.x << ", " << derivative.y << ", " << derivative.z << ")" << endl;
        cout << endl;
    }

    // Create a container for circles
    vector<Circle*> circles;

    // Fill the container with circles
    for (const auto& curve : curves)
    {
        if (dynamic_cast<Circle*>(curve) != nullptr)
        {
            circles.push_back(dynamic_cast<Circle*>(curve));
        }
    }

    // Sort circles by radius
    sort(circles.begin(), circles.end(), [](const Circle* a, const Circle* b)
    {
            return a->getPoint(0).x < b->getPoint(0).x;
    });

    // Calculate the total sum of radii using OpenMP
    float sumRadiusOpenMP = 0.0f;
    #pragma omp parallel for reduction(+: sumRadiusOpenMP)
    for (size_t i = 0; i < circles.size(); ++i) 
    {
        if (dynamic_cast<Circle*>(circles[i]) != nullptr)
        {
            // Get the radius from a point on the circle at t = 0
            float radius = circles[i]->getPoint(0.0f).x;
            sumRadiusOpenMP += radius;
        }
    }

    // Output the total sum of radii
    std::cout << "Sum of circle radii: " << sumRadiusOpenMP << std::endl;

    // Free memory
    for (const auto& curve : curves)
    {
        delete curve;
    }

	return 0;
}