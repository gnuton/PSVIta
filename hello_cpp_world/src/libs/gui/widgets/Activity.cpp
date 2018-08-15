#include "Activity.h"
#include <algorithm>

#include "constants/Screen.h"
#include "utils/ReversedIterable.h"

Activity::Activity() :
        View(NULL, Point(0, 0), SCREEN_HEIGHT, SCREEN_WIDTH, PriorityLevel::Normal) {
}

Activity::~Activity() {
}


void Activity::handleInput() {
    std::lock_guard<std::mutex> lock(mtx);

    if (windows.size() > 1) {
        for (auto it = begin(windows), it_last = --end(windows); it != it_last;) {
            (*it)->handleInput();
            if ((*it)->isDestroyable()) {
                it = windows.erase(it);
            } else {
                ++it;
            }

        }
    } else if (windows.size() == 0) {
        return;
    }

    windows.back()->handleInput();

    windows.erase(
            std::remove_if(windows.begin(), windows.end(),
                           [](const std::shared_ptr<Window> &win) { return win->isDestroyable(); }),
            windows.end());

    return;
}


void Activity::draw() {
    std::lock_guard<std::mutex> lock(mtx);
    for (auto &window : reverse(windows)) {
        window->draw();
        // do not draws stuff which cannot be seen
        if (window->isFullscreen())
            break;
    }
}


void Activity::addWindow(std::shared_ptr<Window> window) {
    std::lock_guard<std::mutex> lock(mtx);
    windows.push_back(window);
}

bool Activity::hasWindows() {
    std::lock_guard<std::mutex> lock(mtx);
    return !windows.empty();
}
