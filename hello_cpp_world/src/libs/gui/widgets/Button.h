#ifndef BUTTON_H
#define BUTTON_H
#include "View.h"
#include <string>
#include <core/Signal.h>

/**
 *  Button
 *  Thi class represent a basic button widget.
 *
 *  Usage:
 *  Once you have instantiated this class you can connect its onClicked signal to the function (slot) which
 *  will be triggered by the onClicked event.
 *  eg:    button->onClick.connectMember(pointer_to_instance_with_the_slot, &instante_with_the_slot::onButtonClicked);
 *
 *  Signals:
 *   - onClicked()
 *
 */
class Button : public View
{
public:
    explicit Button(View* parent,
           const std::string& text = "",
           const Point& topLeft = Point(0,0),
           int height=0,
           int width = 0);
    virtual ~Button();
    void draw() override;
    void handleInput();

    const std::string getLabel() const{ return label; }
    void setLabel(const std::string& label) { this->label = label; }

    Signal<> onClick;

private:
    std::string label;
};

#endif // BUTTON_H
