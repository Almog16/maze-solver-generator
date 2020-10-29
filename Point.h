/*
Point class holds the coordinates of a certain square in the maze
*/

using namespace std;
#ifndef POINT_H
#define POINT_H
#include "Point.h"
class Point
{
    private:
        unsigned int x;
        unsigned int y;
	public:
        void setX(unsigned int x);
        void setY(unsigned int y);
        unsigned int getX() const;
        unsigned int getY() const;
        Point() = default;
		Point(unsigned int x, unsigned int y);
};

#endif


