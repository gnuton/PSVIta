#include "view.h"

View::View(const View* parent, const Point& pos, int height, int width, unsigned int priority):
    parent(parent),
    pos(pos),
    height(height),
    width(width),
    priority(priority)
{

}

View::~View() {}

int View::HandleInput(int focus, const Input& input) {
    return 0;
}

int View::Draw() {
    return 0;
}
