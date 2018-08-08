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

private:
    void showSplashScreen();
    Activity *activity;
    Logger *logger;
};
#endif

