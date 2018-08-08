#ifndef INPUT_H
#define INPUT_H

#include <shapes.h>
#include "texture.h"

#pragma once

class Input {
private:
    static int isInit;

    SceDateTime timer;

    SceCtrlData oldpad;
    SceCtrlData pad;

    SceTouchData old2touch;
    SceTouchData oldtouch;
    SceTouchData touch;
public:
    Input();

    int Get();
    int Propagate();

    int KeyPressed(unsigned int buttons) const;
    int KeyNewPressed(unsigned int buttons) const;

    int TouchPressed() const;
    int TouchAlreadyPressed() const;
    int TouchNewPressed() const;
    int TouchStopPressed() const;
    int TouchNewMovement() const;
    int TouchAlreadyMovement() const;
    int TouchCoordinates(double *touchX, double *touchY) const;
    int TouchDifference(double *touchDifX, double *touchDifY, unsigned long *timeDif) const;
    int TouchSpeed(double *touchSpeedX, double *touchSpeedY, double *touchSpeed) const;
    int TouchInRectangle(const Rectangle &rect) const;
    int TouchInTexture(const Point &draw_pt, const Texture &tex) const;
};
#endif
