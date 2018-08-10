#ifndef LISTVIEW_H
#define LISTVIEW_H

#include "view.h"

class ListView : public View
{
public:
    ListView(const View* parent);
    int Draw() override;
};

#endif // LISTVIEW_H
