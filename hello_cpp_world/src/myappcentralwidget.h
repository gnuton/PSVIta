#ifndef MYAPPCENTRALWIDGET_H
#define MYAPPCENTRALWIDGET_H
#include "widgets/view.h"

class Button;

class MyAppCentralWidget : public View
{
public:
    MyAppCentralWidget(View* parent);
    int draw() override;

private:
    Button *button;
};

#endif // MYAPPCENTRALWIDGET_H
