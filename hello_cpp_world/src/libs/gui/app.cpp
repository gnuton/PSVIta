#include "app.h"
#include <vita2d.h>

App::App(){
    vita2d_init();
    vita2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
}
