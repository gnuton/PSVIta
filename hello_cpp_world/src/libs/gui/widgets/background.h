#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <texture.h>
#include "view.h"

class Background : public View
{
public:
	Background();

	int Draw() override;
private:
	Texture img_bg;
};
#endif

