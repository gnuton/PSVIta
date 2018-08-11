#ifndef BUTTON_H
#define BUTTON_H
#include "view.h"

class Button : public View
{
public:
    Button(View* parent, const std::string& text, const Point& point, int height, int size);
    int draw() override;
};

#endif // BUTTON_H
