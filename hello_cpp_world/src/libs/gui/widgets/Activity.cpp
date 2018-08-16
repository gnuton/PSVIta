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
    Logger::getInstance()->Debug(FORMAT("window added " << window.get()));
    window.get()->destroying.connectMember(this, &Activity::onWindowDestroyed);
}

bool Activity::hasWindows() {
    std::lock_guard<std::mutex> lock(mtx);
    return !windows.empty();
}

void Activity::onWindowDestroyed(Object* windowObj) {
    Logger::getInstance()->Debug(FORMAT("onWindowDestroyed windows:" << windows.size()));
    for (auto iter = std::end(windows); iter != std::begin(windows); iter--) {
        if (iter->get() == windowObj) {
            Logger::getInstance()->Debug("Found and removed");
            windows.erase(iter);
            break;
        } else {
            Logger::getInstance()->Debug(FORMAT("Window:" << iter->get() << " != " << windowObj));
        }
    }
}