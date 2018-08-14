#ifndef VIEW_H
#define VIEW_H
#include "core/Object.h"
#include "core/Shapes.h"

/**
 * @brief the View class
 * This class represents the basic building block for user interface components.
 * A View occupies a rectangular area on the screen and is responsible for drawing and event handling.
 * View is the base class for widgets, which are used to create interactive UI components
 * (buttons, text fields, etc.).
 * Top level view do not have parents and they are called "windows".
 * Windows are handled by Activity class. (Naming is temporary since it will be cleaned ASAP).
 */


class View : public Object
{
public:
    View(View *parent,
         const Point& pos= Point(0,0),
         int height = 0,
         int width = 0,
         unsigned int priority = 100);
    virtual ~View();

    virtual int handleInput();
    virtual int draw();

    virtual bool isWidget() const { return true; }
    virtual bool isWindow() const { return false; }

    inline unsigned int getPriority() const { return priority; }
    inline bool isDestroyable() const { return request_destroy; }

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
    enum PriorityLevel { Min = 0, Normal = 100, Max= 256 };

    // FIXME Not a good way to signal it needs to be destroyed
    bool request_destroy = false;
    unsigned int priority;
    Point pos;
    int height;
    int width;
    bool visible = true;
    bool focus = true;
};
#endif
