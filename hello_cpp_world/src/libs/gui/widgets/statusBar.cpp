#include "statusBar.h"
#include <psp2/system_param.h>
#include <psp2/power.h>
#include <psp2/rtc.h>

#include "utils.h"
#include "font.h"

#include "constants/color.h"

extern unsigned char _binary_assets_spr_img_statsbar_battery_png_start;
extern unsigned char _binary_assets_spr_img_statsbar_battery_charge_png_start;

void getDateString(char *string, int date_format, SceDateTime *time);
void getTimeString(char *string, int time_format, SceDateTime *time);
int displayBattery();
int displayDate();

StatusBar::StatusBar() :
    font_22(Font(std::string(Font::FontDir() + "segoeui.ttf"), 22)),
    img_statsbar_battery(Texture(&_binary_assets_spr_img_statsbar_battery_png_start)),
    img_statsbar_battery_charge(Texture(&_binary_assets_spr_img_statsbar_battery_charge_png_start))
{
#if 0

    SceNetCtlInfo info;
    if(sceNetCtlInetGetInfo(SCE_NETCTL_INFO_GET_IP_ADDRESS, &info) < 0) {
        dbg_printf(DBG_ERROR, "Failed to obtain Vita IP address");
    } else {
        strncpy(vitaip, (char *)&(info.ip_address), 16);
    }

#endif
}


int StatusBar::Draw()
{
    // Background
    vita2d_draw_rectangle(0, 0, SCREEN_WIDTH, STATUSBAR_HEIGHT, Color::Black);

    font_22.Draw(Point(15, 22), "Vita HomeBrew Browser", Color::White);

    displayBattery();
    displayDate();

#if 0
    font_22.Draw(Point(400, 22), vitaip, Color::White);
#endif
    return 0;
}


void StatusBar::getDateString(char *string, int date_format, SceDateTime *time)
{
    switch (date_format) {
    case SCE_SYSTEM_PARAM_DATE_FORMAT_YYYYMMDD:
        sprintf(string, "%04d/%02d/%02d", time->year, time->month, time->day);
        break;

    case SCE_SYSTEM_PARAM_DATE_FORMAT_DDMMYYYY:
        sprintf(string, "%02d/%02d/%04d", time->day, time->month, time->year);
        break;

    case SCE_SYSTEM_PARAM_DATE_FORMAT_MMDDYYYY:
        sprintf(string, "%02d/%02d/%04d", time->month, time->day, time->year);
        break;
    }
}

void StatusBar::getTimeString(char *string, int time_format, SceDateTime *time)
{
    switch (time_format) {
    case SCE_SYSTEM_PARAM_TIME_FORMAT_12HR:
        sprintf(string, "%02d:%02d %s", (time->hour > 12) ? (time->hour - 12) : ((time->hour == 0) ? 12 : time->hour), time->minute, time->hour >= 12 ? "PM" : "AM");
        break;

    case SCE_SYSTEM_PARAM_TIME_FORMAT_24HR:
        sprintf(string, "%02d:%02d", time->hour, time->minute);
        break;
    }
}

int StatusBar::displayBattery()
{
    float battery_x = align_left(949, vita2d_texture_get_width(img_statsbar_battery.texture.get()));

    float percent = scePowerGetBatteryLifePercent();
    float width = ((29.0f * percent) / 100.0f);

    unsigned int battery_color = RGBA8(91, 223, 38, 255);

    // FIXME Not sure if it's good performance-wise to do that 60 times per second
    if (scePowerIsLowBattery())
        battery_color = RGBA8(255, 48, 48, 255);
    vita2d_draw_rectangle((947.0f - width), 4, width, 16, battery_color);

    if (scePowerIsBatteryCharging())
        img_statsbar_battery_charge.Draw(Point(battery_x, 2));
    else
        img_statsbar_battery.Draw(Point(battery_x, 2));

    return 0;
}

int StatusBar::displayDate()
{
    SceDateTime time;
    sceRtcGetCurrentClockLocalTime(&time);

    char date_string[16];
    // FIXME: Get the date format from the system
    getDateString(date_string, SCE_SYSTEM_PARAM_DATE_FORMAT_DDMMYYYY, &time);

    char time_string[24];
    // FIXME: Get the time format from the system
    getTimeString(time_string, SCE_SYSTEM_PARAM_TIME_FORMAT_24HR, &time);

    char string[64];
    sprintf(string, "%s  %s", date_string, time_string);

    font_22.Draw(Point(700, 22), string, Color::White);

    return 0;
}


