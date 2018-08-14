#include "Geometry.h"

Point::Point(int _x, int _y)
{
    x = _x;
    y = _y;
}


int Rectangle::isInside(const Point &pt) const
{
    //dbg_printf(DBG_DEBUG, "isInside point: %f,%f", pt.x, pt.y);
    //dbg_printf(DBG_DEBUG, "Cond is %d", (int)(pt.x >= topLeft.x && pt.x <= bottomRight.x
    //&& pt.y >=topLeft.y && pt.y <= bottomRight.y));
    return pt.x >= topLeft.x && pt.x <= bottomRight.x
            && pt.y >=topLeft.y && pt.y <= bottomRight.y;
}
