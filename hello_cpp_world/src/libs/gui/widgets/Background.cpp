#include "Background.h"
#include <constants/Screen.h>

extern unsigned char _binary_assets_spr_img_bg_png_start;

Background::Background(std::shared_ptr<Object> parent) :
    View(parent,
         Point(0,0),
         SCREEN_HEIGHT,
         SCREEN_WIDTH,
         PriorityLevel::Min),
    img_bg(Texture(&_binary_assets_spr_img_bg_png_start))
{
}

void Background::draw()
{
    img_bg.Draw(pos);
}
