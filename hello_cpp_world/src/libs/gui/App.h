#ifndef APP_H
#define APP_H

#include "widgets/Activity.h"
#include "utils/Logger.h"
#include <memory>

class App {


public:
    App();
    virtual ~App();
    void run();
    void AddWindow(std::shared_ptr<Window> window);
    void showSplashScreen();

private:
    Activity *activity;
    Logger *logger;
};
#endif

