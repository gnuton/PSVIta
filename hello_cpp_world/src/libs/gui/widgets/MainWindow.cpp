#include "MainWindow.h"
#include "Activity.h"

MainWindow::MainWindow() :
    Window(Activity::getInstance()),
    background(new Background(this)),
    centralWidget(new View(this)),
    statusBar(new StatusBar(this))
{
}

MainWindow::~MainWindow() {
}


