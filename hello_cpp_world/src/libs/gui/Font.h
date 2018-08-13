#ifndef FONT_H
#define FONT_H

#include "Shapes.h"
#include "constants/color.h"
#include <unordered_map>
#include "UnorderedMapPairHash.h"

class Font {
public:
    Font(const std::string &path, unsigned int fSize);

    int Draw(const Point &pt, const std::string &text, int color = Color::White);
    int DrawCentered(const Rectangle &rect, const std::string &text, int color = Color::White);

    inline static std::string FontDir(){ return "app0:resources/fonts/"; }
    static std::unordered_map<std::pair<std::string, unsigned int>, vita2d_font*> fontCache;

private:
    vita2d_font *font;
    unsigned int size;
};
#endif
