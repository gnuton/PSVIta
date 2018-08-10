#ifndef VIEW_H
#define VIEW_H
#include <input.h>

/**
 * @brief This class represents the basic building block for user interface components.
 * A View occupies a rectangular area on the screen and is responsible for drawing and event handling.
 * View is the base class for widgets, which are used to create interactive UI components
 * (buttons, text fields, etc.).
 */
class View
{
public:
    View(const Point& pos= Point(0,0), int height = 0, int width = 0, unsigned int priority = 100);
    virtual ~View();

    virtual int HandleInput(int focus, const Input& input);
    virtual int Draw();

    inline unsigned int getPriority() const { return priority; }
    inline bool isDestroyable() const { return request_destroy; }

    const Point getPos() const{ return pos; }
    void setPos(const Point& topLeftPoint) { pos = topLeftPoint; }

    const int getHeight() const { return height; }
    void setHeight(const int height) { this->height = height; }

    const int getWidth() const { return width; }
    void setWidth(const int width) { this->width = width; }

protected:
    // FIXME Not a good way to signal it needs to be destroyed
    bool request_destroy = false;
    unsigned int priority;
    Point pos;
    int height;
    int width;
};
#endif
