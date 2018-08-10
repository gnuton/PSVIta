#ifndef STATUSBAR_H
#define STATUSBAR_H
#pragma once

#include <texture.h>
#include "view.h"
#include "font.h"
#include "constants/screen.h"

class StatusBar: public View {
public:
    StatusBar(const View* parent = NULL);
    int Draw() override;

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
