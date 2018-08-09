#ifndef APP_H
#define APP_H

#include "activity.h"
#include "logger.h"
#include <memory>

class App {


public:
    App();
    virtual ~App();
    void start();
    void AddView(std::shared_ptr<View> view);
    void showSplashScreen();

private:
    Activity *activity;
    Logger *logger;
};
#endif

