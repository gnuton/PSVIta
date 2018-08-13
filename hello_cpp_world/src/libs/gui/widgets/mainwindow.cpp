#include "mainwindow.h"
#include "activity.h"

MainWindow::MainWindow() :
    Window(Activity::get_instance()),
    background(new Background(this)),
    centralWidget(new View(this)),
    statusBar(new StatusBar(this))
{
}

MainWindow::~MainWindow() {
}


