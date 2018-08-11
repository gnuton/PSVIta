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
    delete background;
    delete statusBar;
    if (centralWidget)
        delete centralWidget;
}

int MainWindow::draw(){
    if (!this->isVisible())
        return -1;
    background->draw();
    statusBar->draw();
    if (centralWidget)
        centralWidget->draw();
    return 0;
}
