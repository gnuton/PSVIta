#include "app.h"
#include <vita2d.h>
#include "Views/splash.h"

App::App(){
    vita2d_init();
    vita2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
    this->activity = Activity::create_instance();
    this->showSplashScreen();
}

void App::showSplashScreen()
{
    auto splash = std::make_shared<Splash>();
    splash->priority = 200;
    this->activity->AddView(splash);
}
