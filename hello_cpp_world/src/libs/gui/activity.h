#ifndef ACTIVITY_H
#define ACTIVITY_H

#include "singleton.h"
#include "widgets/view.h"
#include <mutex>
#include <vector>
#include <memory>

#pragma once

class Activity: public Singleton<Activity>, public View {
    friend class Singleton<Activity>;
public:
    ~Activity();

    int HandleInput(int focus, const Input& input);
    int Draw();

    void AddView(std::shared_ptr<View> view);
    void FlushQueue();
    bool HasActivity();


private:
    Activity();
    std::mutex mtx_;
    std::vector<std::shared_ptr<View>> views_;
    std::vector<std::shared_ptr<View>> views_queue;
};
#endif
