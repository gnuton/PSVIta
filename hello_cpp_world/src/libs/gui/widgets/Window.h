#ifndef WINDOW_H
#define WINDOW_H
#include "View.h"
#include "constants/Screen.h"

/**
 * @brief The Window class
 * A View which usually do not have any parent.
 * A Window is just a container for widgets (views).
 * It's the parent of its views.
 * It's handled by the activity instance.
 *
 * Widgets in the window can register for key press events.
 * Key press events are sent by the Vita pad.
 *
 * If fullscreen flag is set, windows below will not be drawn
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

    virtual bool isWidget() const { return true; }
    virtual bool isWindow() const { return true; }
    bool isFullscreen() const { return fullscreen; }

protected:
    bool fullscreen;
};

#endif // WINDOW_H
