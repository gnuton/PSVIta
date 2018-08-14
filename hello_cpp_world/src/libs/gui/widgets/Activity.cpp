#include "Activity.h"
#include <algorithm>

#include "constants/Screen.h"

Activity::Activity() :
    View(NULL, Point(0,0), SCREEN_HEIGHT, SCREEN_WIDTH, PriorityLevel::Normal)
{
}

Activity::~Activity(){
}


void Activity::handleInput()
{
    std::lock_guard<std::mutex> lock(mtx);

    if (windows_.size() > 1) {
        for (auto it = begin(windows_), it_last = --end(windows_); it != it_last; ) {
            (*it)->handleInput();
            if ((*it)->isDestroyable()) {
                it = windows_.erase(it);
            } else {
                ++it;
            }

        }
    } else if (windows_.size() == 0) {
        return;
    }

    windows_.back()->handleInput();

    windows_.erase(
                std::remove_if(windows_.begin(), windows_.end(),
                               [](const std::shared_ptr<Window> &win) { return win->isDestroyable(); }),
                windows_.end());

    return;
}


void Activity::draw()
{
    std::lock_guard<std::mutex> lock(mtx);

    if (windows_.empty()) return;

    for (auto it = begin(windows_), it_last = end(windows_); it != it_last; ++it) {
        (*it)->draw();
    }
}


void Activity::AddWindow(std::shared_ptr<Window> window)
{
    std::lock_guard<std::mutex> lock(mtx);
    windows_queue.push_back(window);
}

void Activity::FlushQueue()
{
    std::lock_guard<std::mutex> lock(mtx);

    std::move(windows_queue.begin(), windows_queue.end(), std::back_inserter(windows_));
    windows_queue.erase(windows_queue.begin(),windows_queue.end());

    std::sort(windows_.begin(), windows_.end(),
              [] (std::shared_ptr<Window> const& win1, std::shared_ptr<Window> const& win2) { return win1->getPriority() < win2->getPriority(); });
}

bool Activity::HasActivity()
{
    std::lock_guard<std::mutex> lock(mtx);
    return !windows_.empty();
}
