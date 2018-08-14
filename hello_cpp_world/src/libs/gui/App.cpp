#include "App.h"
#include <psp2/kernel/processmgr.h>
#include <psp2/display.h>
#include <vita2d.h>
#include "widgets/Splash.h"
#include "input/VitaPad.h"
#include "input/VitaTouch.h"
#include "widgets/Activity.h"
#include "utils/Logger.h"

App::App():
    logger(Logger::createInstance()),
    pad(VitaPad::createInstance()),
    touch(VitaTouch::createInstance())
{
    vita2d_init();
    vita2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
    //NOTE: Activity is a view and required pad and touch instances. Hence it must be instantiated after them
    this->activity = Activity::createInstance();
    this->logger->Log(debug, "Initializing App");
}

App::~App(){
    this->logger->Log(LoggerFormat::debug, "Destroying App");
    this->activity->FlushQueue();

    //TODO Delete should be automatically handled by the object tree. for this to happen App and everything else should be an object
    this->activity->destroyInstance();
    this->touch->destroyInstance();
    this->pad->destroyInstance();
    this->logger->destroyInstance();

    sceKernelExitProcess(0);
}

void App::run(){
    this->logger->Log(LoggerFormat::debug, "Starting main loop");

    while (1) {
        vita2d_start_drawing();
        vita2d_clear_screen();

        pad->Read();
		    touch->readTouch();

        this->activity->FlushQueue();
        this->activity->handleInput();
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




