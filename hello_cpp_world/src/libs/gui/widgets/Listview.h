#ifndef LISTVIEW_H
#define LISTVIEW_H

#include "View.h"

class ListView : public View
{
public:
    explicit ListView(std::shared_ptr<Object>  parent);
    void draw() override;
};

#endif // LISTVIEW_H
