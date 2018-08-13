#include "view.h"

View::View(View* parent, const Point& pos, int height, int width, unsigned int priority):
    Object(parent),
    pos(pos),
    height(height),
    width(width),
    priority(priority)
{

}

View::~View() {}

int View::handleInput(const Input& input) {

    for (auto child : children) {
        View* v = static_cast<View*>(child);
        if (v && v->hasFocus())
            v->handleInput(input);
    }
}

int View::draw() {
    for (auto child : children) {
        View* v = static_cast<View*>(child);
        if (v && v->isVisible())
            v->draw();
    }
}
