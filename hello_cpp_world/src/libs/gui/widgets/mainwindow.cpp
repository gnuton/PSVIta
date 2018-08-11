#include "mainwindow.h"
#include "activity.h"

MainWindow::MainWindow() :
    Window(Activity::get_instance()),
    background(new Background(this)),
    statusBar(new StatusBar(this))
{
}

MainWindow::~MainWindow() {
    delete background;
    delete statusBar;
}

int MainWindow::Draw(){
    background->Draw();
    statusBar->Draw();
    return 0;
}
