#include "App.h"
#include <psp2/kernel/processmgr.h>
#include <psp2/display.h>
#include <vita2d.h>
#include "widgets/Splash.h"
#include "input/VitaPad.h"
#include "input/VitaTouch.h"
#include "widgets/Activity.h"
#include "utils/Logger.h"

App::App()
{
    vita2d_init();
    vita2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
    Logger::createInstance();
    VitaPad::createInstance();
    VitaTouch::createInstance();
    Activity::createInstance();

    //NOTE: Activity is a view and required pad and touch instances. Hence it must be instantiated after them
    Logger::getInstance()->Debug("Initializing App");
}

App::~App(){
    Logger::getInstance()->Debug( "Destroying App");

    //TODO Delete should be automatically handled by the object tree. for this to happen App and everything else should be an object
    Activity::getInstance()->destroyInstance();
    VitaTouch::getInstance()->destroyInstance();
    VitaPad::getInstance()->destroyInstance();
    Logger::getInstance()->destroyInstance();

    sceKernelExitProcess(0);
}

void App::run(){
    Logger::getInstance()->Debug("Starting main loop");

    while (1) {
        vita2d_start_drawing();
        vita2d_clear_screen();

        VitaPad::getInstance()->Read();
        VitaTouch::getInstance()->readTouch();

        Activity::getInstance()->handleInput();
        Activity::getInstance()->draw();

        vita2d_end_drawing();
        vita2d_swap_buffers();
        sceDisplayWaitVblankStart();
    }
}

void App::AddWindow(std::shared_ptr<Window> window){
    Activity::getInstance()->addWindow(window);
}

void App::showSplashScreen(){
    Logger::getInstance()->Debug( "Showing splash screen");

    auto splash = std::make_shared<Splash>(Activity::getInstance());
    Activity::getInstance()->addWindow(splash);
}




