#ifndef MYAPPCENTRALWIDGET_H
#define MYAPPCENTRALWIDGET_H
#include "widgets/view.h"

class MyAppCentralWidget : public View
{
public:
    MyAppCentralWidget(View* parent);
    int draw() override;
};

#endif // MYAPPCENTRALWIDGET_H
