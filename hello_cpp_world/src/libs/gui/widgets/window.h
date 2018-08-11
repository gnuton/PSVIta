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
    Window(const View *parent,
           const Point& pos= Point(0,0),
           int height = SCREEN_HEIGHT,
           int width = SCREEN_WIDTH,
           unsigned int priority = PriorityLevel::Normal);
    virtual ~Window();

    int Draw() override;
};

#endif // WINDOW_H
