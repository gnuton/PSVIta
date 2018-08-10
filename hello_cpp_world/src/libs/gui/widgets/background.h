#ifndef BACKGROUND_H
#define BACKGROUND_H

#pragma once

#include "view.h"
#include <texture.h>

class Background : public View
{
public:
	Background();

	int Draw() override;
private:
	Texture img_bg;
};
#endif

