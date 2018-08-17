#include "Window.h"

Window::Window(Widget *parent, const Point &pos, int height, int width) :
        Widget(parent,
             pos,
             height,
             width)
{

}

Window::~Window() {
}

