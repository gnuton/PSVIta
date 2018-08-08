#ifndef BACKGROUND_H
#define BACKGROUND_H

#pragma once

#include "View.h"
#include <texture.h>

class Background : public View
{
public:
	Background();

	int Display() override;
private:
	Texture img_bg;
};
#endif

