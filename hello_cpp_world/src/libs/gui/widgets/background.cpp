#include "background.h"
#include <constants/screen.h>

extern unsigned char _binary_assets_spr_img_bg_png_start;

Background::Background() :
	img_bg(Texture(&_binary_assets_spr_img_bg_png_start))
{
}

int Background::Draw()
{
    img_bg.Draw(this->pos);
	return 0;
}
