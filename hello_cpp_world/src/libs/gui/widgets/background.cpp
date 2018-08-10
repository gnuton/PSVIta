#include "background.h"

extern unsigned char _binary_assets_spr_img_bg_png_start;

Background::Background() :
	img_bg(Texture(&_binary_assets_spr_img_bg_png_start))
{
}

int Background::Draw()
{
	img_bg.Draw(Point(0, 0));
	return 0;
}
