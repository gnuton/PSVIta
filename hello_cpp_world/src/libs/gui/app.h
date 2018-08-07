#include "activity.h"

class App {
public:
    App();
    virtual ~App();
    void start();
    void dbgInit();

private:
    void showSplashScreen();

    Activity *activity;
};

