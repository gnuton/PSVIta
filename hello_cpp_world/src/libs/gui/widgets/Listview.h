#ifndef LISTVIEW_H
#define LISTVIEW_H

#include "View.h"

class ListView : public View
{
public:
    explicit ListView(View* parent);
    void draw() override;
};

#endif // LISTVIEW_H
