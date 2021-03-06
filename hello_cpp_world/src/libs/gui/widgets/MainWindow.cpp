#include "MainWindow.h"
#include "Activity.h"

MainWindow::MainWindow() :
        Window(Activity::getInstance()),
    background(new Background(this)),
    centralWidget(new Widget(this)),
    statusBar(new StatusBar(this))
{
    this->fullscreen = true;
}

MainWindow::~MainWindow() {
}


