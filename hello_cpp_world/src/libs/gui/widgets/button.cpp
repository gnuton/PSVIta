#include "button.h"
#include <vita2d.h>
#include "constants/color.h"

Button::Button(View* parent,
               const std::string& text,
               const Point& point,
               int height,
               int size):
    View(parent,
         Point(0,0),
         height,
         width,
         parent ? parent->getPriority() : PriorityLevel::Normal)
{

}

int Button::draw() {
    if (!this->isVisible())
        return -1;

    // Background
    vita2d_draw_rectangle(this->pos.x, this->pos.y, this->width, this->height, Color::Red);

    // font_22.Draw(Point(15, 22), "Vita HomeBrew Browser", Color::White);

    return 0;
}
