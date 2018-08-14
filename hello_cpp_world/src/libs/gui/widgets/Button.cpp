#include "Button.h"
#include <vita2d.h>
#include "constants/Color.h"
#include "utils/Logger.h"
#include <input/VitaTouch.h>

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

void Button::handleInput() {
  if (this->touch->clicking && this->getRectangleArea().isInside(this->touch->lastClickPoint)) {
    Logger::getInstance()->Debug(FORMAT("Button has been clicked" << this->touch->lastClickPoint.x << ":"  << this->touch->lastClickPoint.y));
    Logger::getInstance()->Debug("Emitting onClick");
    onClick.emit();
  }
}

void Button::draw() {
    // Background

    vita2d_draw_rectangle(this->pos.x, this->pos.y, this->width, this->height, Color::Red);

    // font_22.Draw(Point(15, 22), "Vita HomeBrew Browser", Color::White);
}
