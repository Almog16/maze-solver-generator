
#include <iostream>
using namespace std;
#include "Point.h"

Point::Point( unsigned int x,  unsigned int y)
{
    setX(x);
    setY(y);
}

void Point::setX( unsigned int x)
{
    this->x = x;
}

void Point::setY( unsigned int y)
{
    this->y = y;
}

 unsigned int Point::getX() const
{
    return x;
}
 
 unsigned int Point::getY() const
{
    return y;
}
