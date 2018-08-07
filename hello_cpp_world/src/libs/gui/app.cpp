#include "app.h"
#include <vita2d.h>
#include "Views/splash.h"
#include "input.h"
#include "debug.h"

App::App(){
    dbg_printf(DBG_DEBUG, "Initializing app");

    vita2d_init();
    vita2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
    this->activity = Activity::create_instance();
}

App::~App(){
    dbg_printf(DBG_DEBUG, "Destroying App");
    this->activity->FlushQueue();
    delete this->activity;
    this->activity = NULL;
    sceKernelExitProcess(0);
}

void App::start(){
    dbg_printf(DBG_DEBUG, "Starting main loop");
    Input input;
    this->showSplashScreen();

    while (1) {
      vita2d_start_drawing();
      vita2d_clear_screen();

      input.Get();

      this->activity->FlushQueue();
      this->activity->HandleInput(1, input);
      this->activity->Display();

      vita2d_end_drawing();
      vita2d_swap_buffers();
      sceDisplayWaitVblankStart();
    }
}

void App::dbgInit(){
    dbg_init();
}

void App::showSplashScreen(){
    dbg_printf(DBG_DEBUG, "Showing splash screen");

    auto splash = std::make_shared<Splash>();
    splash->priority = 200;
    this->activity->AddView(splash);
}


