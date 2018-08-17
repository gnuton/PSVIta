#ifndef APP_H
#define APP_H

#include <memory>

class Window;
class Activity;
class Logger;
class VitaPad;
class VitaTouch;

class App {


public:
    App();
    virtual ~App();
    void run();
    void AddWindow(std::shared_ptr<Window> window);
    void showSplashScreen();
};
#endif

