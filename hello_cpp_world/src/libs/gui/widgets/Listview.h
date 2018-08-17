#ifndef LISTVIEW_H
#define LISTVIEW_H

#include "Widget.h"

class ListView : public Widget
{
    NO_COPY_AND_ASSIGN(ListView)

public:
    explicit ListView(Widget* parent);
    void draw() override;
};

#endif // LISTVIEW_H
