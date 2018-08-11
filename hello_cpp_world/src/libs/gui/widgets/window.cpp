#include "window.h"

Window::Window(const View *parent,
               const Point& pos,
               int height,
               int width,
               unsigned int priority) :
    View(parent,
         pos,
         height,
         width,
         parent ? parent->getPriority() : PriorityLevel::Normal)
{

}

Window::~Window() {
}


int Window::Draw() {
    return 0;
}
