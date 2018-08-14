#include "Listview.h"
#include <vita2d.h>
#include "constants/Screen.h"

ListView::ListView(View* parent):
    View(parent, Point(0,0), SCREEN_HEIGHT, SCREEN_WIDTH, PriorityLevel::Normal) {

}

int ListView::draw() {
    if (!this->isVisible())
        return -1;
    // Background
    // vita2d_draw_rectangle(0, 0, SCREEN_WIDTH, STATUSBAR_HEIGHT, Color::Red);
    return 0;
}
