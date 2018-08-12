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
    int draw() override;

    virtual bool isWidget() const { return true; }
    virtual bool isWindow() const { return true; }

    const View* getCentralWidget() const { return centralWidget; }
    void setCentralWidget(View* centralWidget) {
        this->centralWidget = centralWidget;
        centralWidget->setParent(this);
    }
private:
    StatusBar *statusBar;
    View *centralWidget;
    Background *background;
};

#endif // MAINWINDOW_H
