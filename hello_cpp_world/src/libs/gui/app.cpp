#include "app.h"
#include <psp2/kernel/processmgr.h>
#include <psp2/display.h>
#include <vita2d.h>
#include "widgets/splash.h"
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

void App::run(){
    this->logger->Log(LoggerFormat::debug, "Starting main loop");
    Input input;


    while (1) {
        vita2d_start_drawing();
        vita2d_clear_screen();

        input.Get();

        this->activity->FlushQueue();
        this->activity->handleInput(1, input);
        this->activity->draw();

        vita2d_end_drawing();
        vita2d_swap_buffers();
        sceDisplayWaitVblankStart();
    }
}

void App::AddWindow(std::shared_ptr<Window> window){
    this->activity->AddWindow(window);
}

void App::showSplashScreen(){
    this->logger->Log(LoggerFormat::debug, "Showing splash screen");

    auto splash = std::make_shared<Splash>(this->activity);
    this->activity->AddWindow(splash);
}




