#include "activity.h"
#include "constants/screen.h"

Activity::Activity() :
    View(NULL, Point(0,0), SCREEN_HEIGHT, SCREEN_WIDTH, PriorityLevel::Normal)
{
}

Activity::~Activity(){
}


int Activity::handleInput(const Input& input)
{
    std::lock_guard<std::mutex> lock(mtx_);

    if (windows_.size() > 1) {
        for (auto it = begin(windows_), it_last = --end(windows_); it != it_last; ) {
            (*it)->handleInput(input);
            if ((*it)->isDestroyable()) {
                it = windows_.erase(it);
            } else {
                ++it;
            }

        }
    } else if (windows_.size() == 0) {
        return 0;
    }

    windows_.back()->handleInput(input);

    windows_.erase(
                std::remove_if(windows_.begin(), windows_.end(),
                               [](const std::shared_ptr<Window> &win) { return win->isDestroyable(); }),
                windows_.end());

    return 0;
}


int Activity::draw()
{
    std::lock_guard<std::mutex> lock(mtx_);

    if (windows_.empty()) return 0;

    for (auto it = begin(windows_), it_last = end(windows_); it != it_last; ++it) {
        (*it)->draw();
    }

    return 0;
}


void Activity::AddWindow(std::shared_ptr<Window> window)
{
    std::lock_guard<std::mutex> lock(mtx_);
    windows_queue.push_back(window);
}

void Activity::FlushQueue()
{
    std::lock_guard<std::mutex> lock(mtx_);

    std::move(windows_queue.begin(), windows_queue.end(), std::back_inserter(windows_));
    windows_queue.erase(windows_queue.begin(),windows_queue.end());

    std::sort(windows_.begin(), windows_.end(),
              [] (std::shared_ptr<Window> const& win1, std::shared_ptr<Window> const& win2) { return win1->getPriority() < win2->getPriority(); });
}

bool Activity::HasActivity()
{
    std::lock_guard<std::mutex> lock(mtx_);
    return !windows_.empty();
}
