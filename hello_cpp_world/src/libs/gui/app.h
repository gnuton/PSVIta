#ifndef APP_H
#define APP_H

#include "activity.h"
#include "logger.h"
#include <memory>

class App {


public:
    App();
    virtual ~App();
    void Start();
    void AddWindow(std::shared_ptr<Window> window);
    void ShowSplashScreen();

private:
    Activity *activity;
    Logger *logger;
};
#endif

