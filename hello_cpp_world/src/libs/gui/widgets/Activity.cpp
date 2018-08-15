#include "Activity.h"
#include <algorithm>

#include "constants/Screen.h"
#include "utils/ReversedIterable.h"
#include "utils/Logger.h"

Activity::Activity() :
        View(NULL, Point(0, 0), SCREEN_HEIGHT, SCREEN_WIDTH, PriorityLevel::Normal),
        debugFont(Font(std::string(Font::FontDir() + "segoeui.ttf"), 11)) {
}

Activity::~Activity() {
}


void Activity::handleInput() {
    std::lock_guard<std::mutex> lock(mtx);
    for (auto &window : reverse(windows)) {
        window->handleInput();
        if (window->isFullscreen())
            break;
    }
    /*
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

    return;*/
}


void Activity::draw() {
    std::lock_guard<std::mutex> lock(mtx);

    for (auto &window : reverse(windows)) {
        window->draw();
        if (window->isFullscreen())
            break;
    }
#ifdef DEBUGNET
    debugFont.Draw(Point(50, 50), Logger::getInstance()->readLogs(), Color::BlueGray);
#endif
}


void Activity::addWindow(std::shared_ptr<Window> window) {
    std::lock_guard<std::mutex> lock(mtx);
    windows.push_back(window);
    window.get()->destroyed.connectMember(this, &Activity::onWindowDestroyed);
}

bool Activity::hasWindows() {
    std::lock_guard<std::mutex> lock(mtx);
    return !windows.empty();
}

void Activity::onWindowDestroyed(const Object* windowObj) {
    Logger::getInstance()->Debug("onWindowDestroyed");
    for (auto iter = std::end(windows); iter != std::begin(windows); --iter) {
        if (iter->get() == windowObj) {
            windows.erase(iter);
            break;
        }
    }
}