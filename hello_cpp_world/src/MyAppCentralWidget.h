#ifndef MYAPPCENTRALWIDGET_H
#define MYAPPCENTRALWIDGET_H
#include "widgets/View.h"

class Button;

class MyAppCentralWidget : public View
{
public:
    MyAppCentralWidget(View* parent);
    void draw() override;

    void onButtonClicked();

private:
    Button *button;
};

#endif // MYAPPCENTRALWIDGET_H
