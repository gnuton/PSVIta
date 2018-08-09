#ifndef FONT_H
#define FONT_H

#include "shapes.h"
#include "constants.h"
#include <sstream>
#include <string>
#include <unordered_map>
#include "unordered_map_pair_hash.h"

class Font {
public:
	Font(const std::string &path, unsigned int fSize);

        int Draw(const Point &pt, const std::string &text, int color = Color::White);
        int DrawCentered(const Rectangle &rect, const std::string &text, int color = Color::White);

	static std::unordered_map<std::pair<std::string, unsigned int>, vita2d_font*> fontCache;

        static std::string FontDir() {

            std::stringstream ss;
            ss << "ux0:/app/" << VITA_TITLEID << "/resources/fonts/";
            return ss.str();
        }

private:
	vita2d_font *font;
	unsigned int size;
};
#endif
