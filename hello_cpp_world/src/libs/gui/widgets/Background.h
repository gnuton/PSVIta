#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <core/Texture.h>
#include "Widget.h"

class Background : public Widget
{
	NO_COPY_AND_ASSIGN(Background)

public:
    explicit Background(Widget *parent);

    void draw() override;
private:
	Texture img_bg;
};
#endif

