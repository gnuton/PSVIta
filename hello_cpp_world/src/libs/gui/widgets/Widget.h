#ifndef VIEW_H
#define VIEW_H
#include "core/Object.h"
#include "core/Geometry.h"

/**
 * @brief the View class
 * This class represents the basic building block for user interface components.
 * A View occupies a rectangular area on the screen and is responsible for drawing and event handling.
 * View is the base class for widgets, which are used to create interactive UI components
 * (buttons, text fields, etc.).
 * Top level view do not have parents and they are called "windows".
 * Windows are handled by Activity class. (Naming is temporary since it will be cleaned ASAP).
 */

 class VitaTouch;
 class VitaPad;

class Widget : public Object
{
public:
    Widget(Widget *parent, const Point &pos = Point(0, 0), int height = 0, int width = 0);
    virtual ~Widget();

    virtual void handleInput();
    virtual void draw();

    virtual bool isWidget() const { return true; }
    virtual bool isWindow() const { return false; }

    const Point getPos() const{ return pos; }
    void setPos(const Point& topLeftPoint) { pos = topLeftPoint; }

    const int getHeight() const { return height; }
    void setHeight(const int height) { this->height = height; }

    const int getWidth() const { return width; }
    void setWidth(const int width) { this->width = width; }

    const Rectangle getRectangleArea() const { return Rectangle(pos, Point(width + pos.x, height + pos.y)); }
    void setRectangleArea(const Rectangle& area) {
        this->pos = area.topLeft;
        this->width = area.bottomRight.x - this->pos.x;
        this->height = area.bottomRight.y - this->pos.y;
    }

    const bool isVisible() const { return visible; }
    void setVisibility(const bool visible) { this->visible = visible; }

    const bool hasFocus() const { return focus; }
    void setFocus(const bool focus) { this->focus = focus; }

protected:
    Point pos;
    int height;
    int width;
    bool visible = true;
    bool focus = true;
    VitaTouch *touch;
    VitaPad *pad;
};
#endif
