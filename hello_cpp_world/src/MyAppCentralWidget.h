#ifndef MYAPPCENTRALWIDGET_H
#define MYAPPCENTRALWIDGET_H
#include "widgets/Widget.h"

class Button;

class MyAppCentralWidget : public Widget
{
public:
    MyAppCentralWidget(Widget* parent);
    void draw() override;

    void onButtonClicked();

private:
    Button *button;
};

#endif // MYAPPCENTRALWIDGET_H
