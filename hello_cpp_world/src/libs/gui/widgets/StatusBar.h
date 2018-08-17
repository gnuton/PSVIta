#ifndef STATUSBAR_H
#define STATUSBAR_H
#pragma once

#include <core/Texture.h>
#include "Widget.h"
#include "core/Font.h"
#include "constants/Screen.h"
/**
 * @brief The StatusBar class
 * Displays a status bar similar to the system one.
 * It can give information to the user like app name,
 * battery status and current time.
 * It never gets the focus, so it cannot handle input.
 */
class StatusBar: public Widget {
    NO_COPY_AND_ASSIGN(StatusBar)

public:
    explicit StatusBar(Widget* parent = NULL);
    void draw() override;

private:
    Font font_22;

    Texture img_statsbar_battery;
    Texture img_statsbar_battery_charge;

    void getDateString(char *string, int date_format, SceDateTime *time);
    void getTimeString(char *string, int time_format, SceDateTime *time);
    int displayBattery();
    int displayDate();
};
#endif
