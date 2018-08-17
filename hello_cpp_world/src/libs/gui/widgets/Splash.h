#ifndef SPLASH_H
#define SPLASH_H

#include <core/Texture.h>
#include "Window.h"

#pragma once

typedef enum {
    STEP_FADING_IN,
    STEP_STATIC,
    STEP_FADING_OUT,
} SplashStep;

/**
 * @brief The Splash class
 * Displays a splash screen.
 * It can handle multiple splash screen shown sequentially
 * one of the other.
 * Its focus is set to false, which means it cannot handle input.
 */
class Splash : public Window
{
public:
    explicit Splash( parent = NULL);

    void draw() override;
private:
    unsigned int splash_index = 0;
    SplashStep step = STEP_FADING_IN;
    unsigned int alpha = 0;
    unsigned int frame_count = 0;

    Texture vhbb_splash;
    Texture gekihen_splash;
};
#endif
