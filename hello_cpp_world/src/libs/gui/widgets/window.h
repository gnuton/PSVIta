#ifndef WINDOW_H
#define WINDOW_H
#include "view.h"
#include "constants/screen.h"

/**
 * @brief The Window class
 * A View which usually do not have any parent.
 * A Window is just a container for widgets (views).
 * It's the parent of its views.
 * It's handled by the activity instance.
 */

class Window : public View
{
public:
    Window(View *parent,
           const Point& pos= Point(0,0),
           int height = SCREEN_HEIGHT,
           int width = SCREEN_WIDTH,
           unsigned int priority = PriorityLevel::Normal);
    virtual ~Window();

    int draw() override;
    virtual bool isWidget() const { return true; }
    virtual bool isWindow() const { return true; }
};

#endif // WINDOW_H
