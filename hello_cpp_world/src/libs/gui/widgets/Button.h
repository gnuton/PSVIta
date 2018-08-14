#ifndef BUTTON_H
#define BUTTON_H
#include "View.h"
#include <string>

class Button : public View
{
public:
    Button(View* parent,
           const std::string& text = "",
           const Point& topLeft = Point(0,0),
           int height=0,
           int width = 0);
    virtual ~Button();
    int draw() override;
    int handleInput();

    const std::string getLabel() const{ return label; }
    void setLabel(const std::string& label) { this->label = label; }

private:
    std::string label;
};

#endif // BUTTON_H
