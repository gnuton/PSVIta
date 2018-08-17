#include "Widget.h"
#include "input/VitaPad.h"
#include "input/VitaTouch.h"

Widget::Widget(Widget *parent, const Point &pos, int height, int width) :
    Object(parent),
    pos(pos),
    height(height),
    width(width),
    pad(VitaPad::getInstance()),
    touch(VitaTouch::getInstance())
{

}

Widget::~Widget() {}

void Widget::handleInput() {
    for (auto child : children) {
        Widget* v = static_cast<Widget*>(child);
        if (v && v->hasFocus())
            v->handleInput();
    }
}

void Widget::draw() {
    for (auto child : children) {
        Widget* v = static_cast<Widget*>(child);
        if (v && v->isVisible())
            v->draw();
    }
}
