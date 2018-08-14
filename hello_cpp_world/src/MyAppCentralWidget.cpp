#include "MyAppCentralWidget.h"
#include "widgets/Button.h"

MyAppCentralWidget::MyAppCentralWidget(View* parent):
    View(parent),
    button(new Button(static_cast<View*>(this)))
{
    button->setHeight(30);
    button->setWidth(80);
}

int MyAppCentralWidget::draw() {
    button->draw();
    return 0;
}
