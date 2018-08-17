#include "Splash.h"

#include <core/Texture.h>
#include <algorithm>
#include "constants/Screen.h"

extern unsigned char _binary_assets_spr_img_splash_png_start;
extern unsigned char _binary_assets_spr_gekihen_splash_png_start;


Splash::Splash(View* parent) :
        Window(parent, Point(0, 0), SCREEN_HEIGHT, SCREEN_WIDTH),
    vhbb_splash(Texture(&_binary_assets_spr_img_splash_png_start)),
    gekihen_splash(Texture(&_binary_assets_spr_gekihen_splash_png_start))
{
    this->setFocus(false);
    this->fullscreen = true;
}

void Splash::draw()
{
    Texture splashes[] = {
        vhbb_splash,
        gekihen_splash
    };

    if (splash_index >= 2)
        return this->destroy();

    splashes[splash_index].DrawExt(Point(0, 0), alpha);

    switch(step) {
    case STEP_FADING_IN:
        alpha = std::min<unsigned int>(255, alpha+32);
        if (alpha >= 255) {
            step = STEP_STATIC;
            alpha = 255;
            frame_count = 0;
        }
        break;
    case STEP_STATIC:
        if (frame_count >= 5*10) {
            step = STEP_FADING_OUT;
        }
        frame_count += 1;
        break;
    case STEP_FADING_OUT:
        alpha = std::max<int>(0, ((int)alpha)-32);
        if (alpha <= 0) {
            alpha = 0;
            splash_index += 1;
            step = STEP_FADING_IN;
        }
        break;
    default:
        break;
    }
}
