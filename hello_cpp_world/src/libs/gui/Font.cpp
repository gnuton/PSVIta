#include "Font.h"
#include <vita2d.h>
#include <sstream>
#include <string>
#include "Logger.h"

std::unordered_map<std::pair<std::string, unsigned int>, vita2d_font*> Font::fontCache;

Font::Font(const std::string &path, unsigned int fSize) {
    {
        std::stringstream msg;
        msg << "Looking for size "<< fSize << ", path: " << path.c_str();
        Logger::get_instance()->Log(LoggerFormat::debug, msg.str());
    }
    auto key = std::make_pair(path, fSize);
    if (fontCache[key]) {
        Logger::get_instance()->Log(LoggerFormat::debug,"Found it in cache");
        this->font = fontCache[key];
        this->size = fSize;
        return;
    }
    this->font = vita2d_load_font_file(path.c_str());
    if (!this->font){
        Logger::get_instance()->Log(LoggerFormat::warning, "Font not loaded!!!");
        std::abort();
    }
    Logger::get_instance()->Log(LoggerFormat::debug, "Storing in cache...");
    fontCache[key] = this->font;
    size = fSize;
}

int Font::Draw(const Point &pt, const std::string &text, int color) {
    return vita2d_font_draw_text(font, pt.x, pt.y, color, size, text.c_str());
}

int Font::DrawCentered(const Rectangle &rect, const std::string &text, int color) {
    //dbg_printf(DBG_DEBUG, "DrawCentered: %f,%f:%f,%f", rect.topLeft.x, rect.topLeft.y, rect.bottomRight.x, rect.bottomRight.y);
    int width, height;
    vita2d_font_text_dimensions(font, size, text.c_str(), &width, &height);
    //dbg_printf(DBG_DEBUG, "Dimensions: %d, %d", width, height);

    int posX = rect.topLeft.x + (rect.bottomRight.x - rect.topLeft.x - width)/2;

    // FIXME Should be height/2 but it doesn't look good with it
    int posY = rect.topLeft.y + (rect.bottomRight.y - rect.topLeft.y)/2 + height/3;

    //dbg_printf(DBG_DEBUG, "Pos: %d, %d", posX, posY);

    return Draw(Point(posX, posY), text, color);
}
