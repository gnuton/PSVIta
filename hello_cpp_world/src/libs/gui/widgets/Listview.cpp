#include "Listview.h"
#include <vita2d.h>
#include "constants/Screen.h"

ListView::ListView(std::shared_ptr<Object>  parent):
    View(parent, Point(0,0), SCREEN_HEIGHT, SCREEN_WIDTH, PriorityLevel::Normal) {

}

void ListView::draw() {
    // Background
    // vita2d_draw_rectangle(0, 0, SCREEN_WIDTH, STATUSBAR_HEIGHT, Color::Red);
}
