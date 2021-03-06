#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Window.h"
#include "StatusBar.h"
#include "Background.h"

/**
 * @brief The MainWindow class
 * Main window are top level widgets which occupy the full screen.
 * As other windows, they are handled by the activity class which always is their parent.
 * Usually one application should have a single mainwindow class, but that's not enforced.
 * You want to use this covinient class if you want a window with a background,
 * a status bar and that can host multiple widgets in its central widget.
 */
class MainWindow : public Window
{
    NO_COPY_AND_ASSIGN(MainWindow)

public:
    MainWindow();
    virtual ~MainWindow();

    virtual bool isWidget() const { return true; }
    virtual bool isWindow() const { return true; }

    const Widget* getCentralWidget() const { return centralWidget; }
    void setCentralWidget(Widget* centralWidget) {
        this->centralWidget = centralWidget;
        centralWidget->setParent(this);
    }
private:
    StatusBar *statusBar;
    Widget *centralWidget;
    Background *background;
};

#endif // MAINWINDOW_H
