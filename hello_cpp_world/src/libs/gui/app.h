#include "activity.h"
#include "logger.h"

class App {
    Logger logger;

public:
    App();
    virtual ~App();
    void start();

private:
    void showSplashScreen();

    Activity *activity;
};

