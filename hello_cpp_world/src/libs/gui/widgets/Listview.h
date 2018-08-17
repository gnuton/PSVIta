#ifndef LISTVIEW_H
#define LISTVIEW_H

#include "Widget.h"

class ListView : public Widget
{
public:
    explicit ListView(Widget* parent);
    void draw() override;
};

#endif // LISTVIEW_H
