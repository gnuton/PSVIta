#ifndef ACTIVITY_H
#define ACTIVITY_H

#include "utils/Singleton.h"
#include "widgets/Window.h"
#include <mutex>
#include <vector>
#include <memory>

class Activity: public Singleton<Activity>, public View {
    friend class Singleton<Activity>;
public:
    ~Activity();

    void handleInput();
    void draw();

    void AddWindow(std::shared_ptr<Window> window);
    void FlushQueue();
    bool HasActivity();


private:
    Activity();
    std::mutex mtx;
    std::vector<std::shared_ptr<Window>> windows_;
    std::vector<std::shared_ptr<Window>> windows_queue;
};
#endif
