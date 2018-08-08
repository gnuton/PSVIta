#ifndef APP_H
#define APP_H

#include "activity.h"
#include "logger.h"

class App {


public:
    App();
    virtual ~App();
    void start();

private:
    void showSplashScreen();

    Activity *activity;
    Logger *logger;
};
#endif

