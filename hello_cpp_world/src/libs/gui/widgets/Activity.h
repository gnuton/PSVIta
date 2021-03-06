#ifndef ACTIVITY_H
#define ACTIVITY_H

#include "utils/Singleton.h"
#include "widgets/Window.h"
#include <mutex>
#include <list>
#include <memory>
#include <core/Font.h>

class Activity: public Singleton<Activity>, public Widget {
    friend class Singleton<Activity>;
public:
    ~Activity();

    void handleInput();
    void draw();

    void addWindow(std::shared_ptr<Window> window);
    bool hasWindows();
private:
    Activity();
    void onWindowDestroyed(Object* window);

    std::mutex mtx;
    std::list<std::shared_ptr<Window>> windows;
    Font debugFont;
};
#endif
