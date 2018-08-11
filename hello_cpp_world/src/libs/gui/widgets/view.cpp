#include "view.h"

View::View(View* parent, const Point& pos, int height, int width, unsigned int priority):
    parent(parent),
    pos(pos),
    height(height),
    width(width),
    priority(priority)
{

}

View::~View() {}

int View::handleInput(int focus, const Input& input) {
    return 0;
}

int View::draw() {
    return 0;
}
