#include "Circle.h"

void Circle::setR(double r)
{
    radius = r;
}

double Circle::getR()
{
    return radius;
}

double Circle::getGrius()
{
    return 2 * 3.14f * radius;
}

double Circle::getArea()
{
    return 3.14f * radius * radius;
}