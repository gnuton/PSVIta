#include "MyAppCentralWidget.h"
#include "widgets/Button.h"
#include "utils/Logger.h"

MyAppCentralWidget::MyAppCentralWidget(View* parent):
        View(parent),
    button(new Button(static_cast<View*>(this)))
{
    button->setHeight(30);
    button->setWidth(80);
    button->onClick.connectMember(this, &MyAppCentralWidget::onButtonClicked);
}

void MyAppCentralWidget::draw() {
    button->draw();
}

void MyAppCentralWidget::onButtonClicked() {
    Logger::getInstance()->Info("The button has been clicked!!");
}
