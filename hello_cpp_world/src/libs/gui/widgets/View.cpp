#include "View.h"
#include "input/VitaPad.h"
#include "input/VitaTouch.h"

View::View(std::shared_ptr<Object> parent, const Point& pos, int height, int width, unsigned int priority):
    Object(parent),
    pos(pos),
    height(height),
    width(width),
    priority(priority)
{
    pad = VitaPad::getInstance();
    touch = VitaTouch::getInstance();
}

View::~View() {}

void View::handleInput() {
    for (auto child : children) {
        View* v = static_cast<View*>(child.get()); //FIXME use smart pointers
        if (v && v->hasFocus())
            v->handleInput();
    }
}

void View::draw() {
    for (auto child : children) {
        View* v = static_cast<View*>(child.get());//FIXME use smart pointers
        if (v && v->isVisible())
            v->draw();
    }
}
