#ifndef ACTIVITY_H
#define ACTIVITY_H

#include "singleton.h"
#include "widgets/window.h"
#include <mutex>
#include <vector>
#include <memory>

#pragma once

class Activity: public Singleton<Activity>, public View {
    friend class Singleton<Activity>;
public:
    ~Activity();

    int handleInput(int focus, const Input& input);
    int draw();

    void AddWindow(std::shared_ptr<Window> window);
    void FlushQueue();
    bool HasActivity();


private:
    Activity();
    std::mutex mtx_;
    std::vector<std::shared_ptr<Window>> windows_;
    std::vector<std::shared_ptr<Window>> windows_queue;
};
#endif
