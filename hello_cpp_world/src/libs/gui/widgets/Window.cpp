#include "Window.h"

Window::Window(View *parent, const Point &pos, int height, int width) :
        View(parent,
             pos,
             height,
             width)
{

}

Window::~Window() {
}

