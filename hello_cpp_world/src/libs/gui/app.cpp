#include "app.h"
#include <psp2/kernel/processmgr.h>
#include <psp2/display.h>
#include <vita2d.h>
#include "Views/splash.h"
#include "input.h"

App::App(){
    vita2d_init();
    vita2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
    this->activity = Activity::create_instance();
    this->logger = Logger::create_instance();
    this->logger->Log(debug, "Initializing App");
}

App::~App(){
    this->logger->Log(LoggerFormat::debug, "Destroying App");
    this->activity->FlushQueue();
    delete this->activity;
    this->activity = NULL;
    sceKernelExitProcess(0);
}

void App::start(){
    this->logger->Log(LoggerFormat::debug, "Starting main loop");
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

void App::AddView(std::shared_ptr<View> view){
    this->activity->AddView(view);
}

void App::showSplashScreen(){
    this->logger->Log(LoggerFormat::debug, "Showing splash screen");

    auto splash = std::make_shared<Splash>();
    splash->priority = 200;
    this->activity->AddView(splash);
}




