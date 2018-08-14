#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <core/Texture.h>
#include "View.h"

class Background : public View
{
public:
    Background(View *parent);

    int draw() override;
private:
	Texture img_bg;
};
#endif

