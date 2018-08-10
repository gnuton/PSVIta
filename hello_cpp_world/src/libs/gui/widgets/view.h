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
    virtual ~View();

    virtual int HandleInput(int focus, const Input& input);
    virtual int Draw();

    inline unsigned int getPriority() const { return priority; }
    inline bool isDestroyable() const { return request_destroy; }

protected:
    // FIXME Not a good way to signal it needs to be destroyed
    bool request_destroy = false;
    unsigned int priority = 100;
};
#endif
