#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "window.h"
#include "statusBar.h"
#include "background.h"

/**
 * @brief The MainWindow class
 * Main window have activty as parent class.
 * They have a background, a status bar and can
 * host multiple widgets.
 */
class MainWindow : public Window
{
public:
    MainWindow();
    virtual ~MainWindow();

    int Draw() override;

private:
    StatusBar *statusBar;
    Background *background;
};

#endif // MAINWINDOW_H
