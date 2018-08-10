#include "listview.h"
#include <vita2d.h>
#include "constants/screen.h"

ListView::ListView(const View* parent):
    View(parent, Point(0,0), SCREEN_HEIGHT, SCREEN_WIDTH, PriorityLevel::Normal) {

}

int ListView::Draw() {
    // Background
    // vita2d_draw_rectangle(0, 0, SCREEN_WIDTH, STATUSBAR_HEIGHT, Color::Red);
    return 0;
}
