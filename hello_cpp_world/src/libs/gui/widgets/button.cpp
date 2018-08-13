#include "button.h"
#include <vita2d.h>
#include "constants/color.h"
#include "logger.h"
#include <sstream>

Button::Button(View* parent,
               const std::string& text,
               const Point& topLeft,
               int height,
               int width):
    View(parent,
         topLeft,
         height,
         width,
         parent ? parent->getPriority() : PriorityLevel::Normal),
    label(label)
{

}

Button::~Button() {
}

int Button::handleInput(const Input& input) {
    {
        std::ostringstream s;
        s << "Input got: " << input.TouchInRectangle(this->getRectangleArea());
        Logger::get_instance()->Log(LoggerFormat::debug, s.str());

    }
    return input.TouchInRectangle(this->getRectangleArea());
}

int Button::draw() {
    if (!this->isVisible())
        return -1;

    // Background
    vita2d_draw_rectangle(this->pos.x, this->pos.y, this->width, this->height, Color::Red);

    // font_22.Draw(Point(15, 22), "Vita HomeBrew Browser", Color::White);

    return 0;
}
