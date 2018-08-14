#ifndef GEOMETRY_H
#define GEOMETRY_H

/**
 * This file contains primitive geometrical elements required for drawing and defining element in the Euclidian space
 */
class Point {
public:
    int x;
    int y;
    Point(int _x = 0, int _y = 0);
};

class Rectangle {
public:
    const Point &topLeft;
    const Point &bottomRight;

    Rectangle(const Point &aTopLeft, const Point &aBottomRight) : topLeft(aTopLeft), bottomRight(aBottomRight) {};

    int isInside(const Point &pt) const;
};

#endif
